#include "crm_dataset.h"
#include "../src/parameter.h"

//##ModelId=4CF05BC101D8
crmDataSet::crmDataSet()
{

}

//##ModelId=4CF05BC101DC
crmDataSet::~crmDataSet()
{

}

//##ModelId=4CEF5A9F019F
crmOperatorDef::crmOperatorDef()
{
    m_db.open(theParameter().Get("datamodule","dbname_login"));

    // sql
    m_sql_select =      "SELECT id, operator_name AS '操作员姓名', "
                                   "operator_password AS '登陆密码', "
                                   "operator_right AS '操作员权限' "
                        "FROM crm_operator_def";

    m_sql_order =       ";";

    m_sql_update =      "UPDATE crm_operator_def SET operator_name=%Q, operator_password=%Q, "
                        "operator_right=%d WHERE id=%d;";

    m_sql_delete =      "DELETE FROM crm_operator_def WHERE id = %d;";

    m_sql_insert =      "INSERT INTO crm_operator_def VALUES(null,%Q,%Q,%d);";


}


//##ModelId=4CEF5A9F01CC
crmOperatorDef::~crmOperatorDef()
{
    m_db.close();
}

//##ModelId=4CEF5B0900B6
crmGuestDef::crmGuestDef()
{
    m_db.open(theParameter().Get("datamodule","dbname_guests"));

    // sql
    m_sql_select =      "SELECT id, group_name AS '客户分组', "
                                    "user_name AS '客户名称', "
                                    "card_name AS '贵宾卡种类', "
                                    "people_limit AS '限制人数', "
                                    "price_default AS '收费金额', "
                                    "image_s_id AS '客户LOGO（小）', "
                                    "image_l_id AS '客户LOGO（大）' "
                        "FROM crm_guest_def";

    m_sql_order =       " ORDER BY group_name,user_name,card_name;";

    m_sql_update =      "UPDATE crm_guest_def "
                        "SET group_name=%Q, user_name=%Q, "
                            "card_name=%Q, start_date=%Q, end_date=%Q, people_limit=%d, "
                            "image_s_id=%d, image_l_id=%d, price_default=%f "
                        "WHERE id=%d;";


    m_sql_delete =      "DELETE FROM crm_guest_def WHERE id = %d;";

    m_sql_insert =      "INSERT INTO crm_guest_def VALUES(null,%Q,%Q,%Q,%Q,%Q,%d,%d,%d,%f);";

}


//##ModelId=4CEF5B0900DE
crmGuestDef::~crmGuestDef()
{
    m_db.close();
}

//##ModelId=4CEF5B120386
crmImageDef::crmImageDef()
{
    m_db.open(theParameter().Get("datamodule","dbname_guests"));

    // sql
    m_sql_select =      "SELECT id, comment AS '图片说明', "
                                   "image_type AS '图片类型', "
                                   "image_size AS '图片大小' "
                        "FROM crm_image_def";

    m_sql_order =       ";";

    m_sql_update =      "UPDATE crm_image_def "
                        "SET image_size=?, image_body=?, comment=?, image_type=? "
                        "WHERE id=%d;";

    m_sql_delete =      "DELETE FROM crm_image_def WHERE id = %d;";

    m_sql_insert =      "INSERT INTO crm_image_def VALUES(null,?,?,?,?);";

}


//##ModelId=4CEF5B1203AB
crmImageDef::~crmImageDef()
{
    m_db.close();
}

//##ModelId=4CEF5B23016E
crmRecordDef::crmRecordDef()
{
    m_db.open(theParameter().Get("datamodule","dbname_records"));

    // sql
    m_sql_select =     "SELECT id, operator_name AS '操作员', "
                                   "statistics_date AS '结账日期', "
                                   "group_name AS '客户分组', "
                                   "user_name AS '客户名称', "
                                   "card_name AS '贵宾卡名称', "
                                   "card_id AS '卡号', "
                                   "presence_name AS '贵宾姓名', "
                                   "train_code AS '车次', "
                                   "train_date AS '乘车日期', "
                                   "people_count AS '乘车人数', "
                                   "price AS '收费金额', "
                                   "record_time AS '登记时间', "
                                   "comment AS '备  注' "
                        "FROM crm_welcome_record";

    m_sql_order =       ";";

    m_sql_update =      "UPDATE crm_welcome_record "
                        "SET operator_name=%Q, "
                            "statistics_date=%Q, record_time=%Q, group_name=%Q, "
                            "user_name=%Q, card_name=%Q, card_id=%Q, presence_name=%Q, "
                            "comment=%Q, train_code=%Q, train_date=%Q, people_count=%d, "
                            "price=%f "
                        "WHERE id=%d;";


    m_sql_delete =      "DELETE FROM crm_welcome_record WHERE id = %d;";

    m_sql_insert =      "INSERT INTO crm_welcome_record VALUES(null,%Q,%Q,%Q,%Q,%Q,%Q,%Q,%Q,%Q,%Q,%Q,%d,%f);";

}


//##ModelId=4CEF5B230198
crmRecordDef::~crmRecordDef()
{
    m_db.close();
}

//##ModelId=4CEF5B3A03A7
crmRightDef::crmRightDef()
{
    m_db.open(theParameter().Get("datamodule","dbname_login"));

    // sql
    m_sql_select =      "SELECT id, module_name AS '模块名称', "
                                   "right_mask AS '权限掩码' "
                        "FROM crm_right_def";

    m_sql_order =       ";";

    m_sql_update =      "UPDATE crm_right_def "
                        "SET module_name=%Q, right_mask=%d "
                        "WHERE id=%d;";

    m_sql_delete =      "DELETE FROM crm_right_def WHERE id = %d;";

    m_sql_insert =      "INSERT INTO crm_right_def VALUES(null,%Q,%d);";

}


//##ModelId=4CEF5B3A03D0
crmRightDef::~crmRightDef()
{
    m_db.close();
}

//##ModelId=4CEF5B490337
crmTrainDef::crmTrainDef()
{
    m_db.open(theParameter().Get("datamodule","dbname_trains"));

    // sql
    m_sql_select =      "SELECT id, train_code AS '车 次', "
                                   "start_station_name AS '始发站', "
                                   "end_station_name AS '终到站', "
                                   "start_time AS '本站发车时间' "
                        "FROM crm_train_dir";

    m_sql_order =       " ORDER BY start_time;";

    m_sql_update =      "UPDATE crm_train_dir "
                        "SET train_code=%Q, start_station_name=%Q, "
                            "end_station_name=%Q, start_time=%Q "
                        "WHERE id=%d;";

    m_sql_delete =      "DELETE FROM crm_train_dir WHERE id = %d;";

    m_sql_insert =      "INSERT INTO crm_train_dir VALUES(null,%Q,%Q,%Q,%Q);";

}


//##ModelId=4CEF5B490363
crmTrainDef::~crmTrainDef()
{
    m_db.close();
}

//##ModelId=4CEFA2D603BA
strucOperator::strucOperator()
    :crmObject()
{
    operator_name       = "";
    operator_password   = "";
    operator_right      = 0;
}


//##ModelId=4CEFA2D603D9
strucOperator::~strucOperator()
{
}

//##ModelId=4CEFA2DE0091
strucRight::strucRight()
    :crmObject()
{
    module_name = "";
    right_mask  = 0;
}


//##ModelId=4CEFA2DE00B0
strucRight::~strucRight()
{
}

//##ModelId=4CEFA318011E
strucGuest::strucGuest()
    :crmObject()
{
    group_name      = "";
    user_name       = "";
    card_name       = "";
    start_date      = "";
    end_date        = "";
    people_limit    = 0;
    image_s_id      = 1;
    image_l_id      = 2;
    price_default   = 0.0;
}


//##ModelId=4CEFA318014D
strucGuest::~strucGuest()
{
}

//##ModelId=4CEFA30200B5
strucImage::strucImage()
    :crmObject()
{
    image_size  = 0;
    comment     = "";
    image_type  = "";
}


//##ModelId=4CEFA30200D4
strucImage::~strucImage()
{
}

//##ModelId=4CEFD8AB0316
int strucImage::SetImageBody(const unsigned char* pBuf, const int nLen)
{
    m_blob.setBinary(pBuf, nLen);
    return m_blob.getBinaryLength();
}

//##ModelId=4CEFD8AB0314
const unsigned char* strucImage::GetImageBody()
{
    return m_blob.getBinary();
}

//##ModelId=4CEFA2E801B9
strucRecord::strucRecord()
    :crmObject()
{
    operator_name   = "";
    statistics_date = "";
    record_time     = "";
    group_name      = "";
    user_name       = "";
    card_name       = "";
    card_id         = "0000-0000-0000-0000";
    presence_name   = "";
    comment         = "";
    train_code      = "";
    train_date      = "";
    people_count    = 1;
    price           = 0.0;
}


//##ModelId=4CEFA2E801C9
strucRecord::~strucRecord()
{
}

//##ModelId=4CEFA2F10350
strucTrain::strucTrain()
    :crmObject()
{
    train_code          = "";
    start_station_name  = "";
    end_station_name    = "";
    start_time          = "";
}


//##ModelId=4CEFA2F10360
strucTrain::~strucTrain()
{
}

strucTrain& strucTrain::operator=(const strucTrain& tr)
{
    id = tr.id;
    train_code = tr.train_code;
    start_time = tr.start_time;
    start_station_name = tr.start_station_name;
    end_station_name = tr.end_station_name;
    return *this;
}

//##ModelId=4CEFA34C037A
crmObject::crmObject(const int id /* =-1 */)
{
    this->id = id;
}


//##ModelId=4CEFA34C03A9
crmObject::~crmObject()
{

}

int crmGuestDef::Insert(const crmObject* obj)
{
    const strucGuest* p = static_cast<const strucGuest*>(obj);
    CppSQLite3Buffer szSQL;
    szSQL.format(m_sql_insert.c_str(),
                 p->group_name.c_str(), p->user_name.c_str(), p->card_name.c_str(),
                 p->start_date.c_str(), p->end_date.c_str(), p->people_limit,
                 p->image_s_id, p->image_l_id, p->price_default);
    return m_db.execDML(szSQL);
}

int crmOperatorDef::Insert(const crmObject* obj)
{
    const strucOperator* p = static_cast<const strucOperator*>(obj);
    CppSQLite3Buffer szSQL;
    szSQL.format(m_sql_insert.c_str(),
                 p->operator_name.c_str(), p->operator_password.c_str(),
                 p->operator_right);
    return m_db.execDML(szSQL);
}

int crmRightDef::Insert(const crmObject* obj)
{
    const strucRight* p = static_cast<const strucRight*>(obj);
    CppSQLite3Buffer szSQL;
    szSQL.format(m_sql_insert.c_str(),
                 p->module_name.c_str(), p->right_mask);
    return m_db.execDML(szSQL);
}

int crmTrainDef::Insert(const crmObject* obj)
{
    const strucTrain* p = static_cast<const strucTrain*>(obj);
    CppSQLite3Buffer szSQL;
    szSQL.format(m_sql_insert.c_str(),
                 p->train_code.c_str(), p->start_station_name.c_str(),
                 p->end_station_name.c_str(), p->start_time.c_str());
    return m_db.execDML(szSQL);
}

int crmRecordDef::Insert(const crmObject* obj)
{
    const strucRecord* p = static_cast<const strucRecord*>(obj);
    CppSQLite3Buffer szSQL;
    szSQL.format(m_sql_insert.c_str(),
                 p->operator_name.c_str(), p->statistics_date.c_str(),
                 p->record_time.c_str(), p->group_name.c_str(),
                 p->user_name.c_str(), p->card_name.c_str(),
                 p->card_id.c_str(), p->presence_name.c_str(),
                 p->comment.c_str(), p->train_code.c_str(),
                 p->train_date.c_str(), p->people_count,
                 p->price);
    return m_db.execDML(szSQL);
}

int crmImageDef::Insert(const crmObject* obj)
{
    strucImage* p = static_cast<strucImage*>(const_cast<crmObject*>(obj));
    CppSQLite3Statement stmt =
        m_db.compileStatement(m_sql_insert.c_str());
    stmt.bind(1, p->image_size);
    stmt.bind(2, p->GetImageBody(), p->image_size);
    stmt.bind(3, p->comment.c_str());
    stmt.bind(4, p->image_type.c_str());
    return stmt.execDML();
}

crmObject* crmGuestDef::getData(const int id)
{
    CppSQLite3Buffer szSQL;
    szSQL.format("SELECT * FROM crm_guest_def WHERE id = %d", id);
    CppSQLite3Query query = m_db.execQuery(szSQL);
    if ( query.eof() )
        return NULL;

    m_data.id = query.getIntField("id");
    m_data.group_name = query.getStringField("group_name");
    m_data.user_name = query.getStringField("user_name");
    m_data.card_name = query.getStringField("card_name");
    m_data.start_date = query.getStringField("start_date");
    m_data.end_date = query.getStringField("end_date");
    m_data.people_limit = query.getIntField("people_limit");
    m_data.price_default = query.getFloatField("price_default");
    m_data.image_s_id = query.getIntField("image_s_id");
    m_data.image_l_id = query.getIntField("image_l_id");
    query.finalize();

    return &m_data;
}

crmObject* crmImageDef::getData(const int id)
{
    CppSQLite3Buffer szSQL;
    szSQL.format("SELECT * FROM crm_image_def WHERE id = %d", id);
    CppSQLite3Query query = m_db.execQuery(szSQL);
    if ( query.eof() )
        return NULL;
    m_data.id = query.getIntField("id");
    const unsigned char* pBuf = query.getBlobField("image_body", m_data.image_size);
    m_data.SetImageBody(pBuf, m_data.image_size);
    m_data.comment = query.getStringField("comment");
    m_data.image_type = query.getStringField("image_type");
    query.finalize();

    return &m_data;
}

crmObject* crmTrainDef::getData(const int id)
{
    CppSQLite3Buffer szSQL;
    szSQL.format("SELECT * FROM crm_train_dir WHERE id = %d", id);
    CppSQLite3Query query = m_db.execQuery(szSQL);
    if ( query.eof() )
        return NULL;

    m_data.id = query.getIntField("id");
    m_data.train_code = query.getStringField("train_code");
    m_data.start_station_name = query.getStringField("start_station_name");
    m_data.end_station_name = query.getStringField("end_station_name");
    m_data.start_time = query.getStringField("start_time");
    query.finalize();

    return &m_data;
}

crmObject* crmOperatorDef::getData(const int id)
{
    CppSQLite3Buffer szSQL;
    szSQL.format("SELECT * FROM crm_operator_def WHERE id = %d", id);
    CppSQLite3Query query = m_db.execQuery(szSQL);
    if ( query.eof() )
        return NULL;

    m_data.id = query.getIntField("id");
    m_data.operator_name = query.getStringField("operator_name");
    m_data.operator_password = query.getStringField("operator_password");
    m_data.operator_right = query.getIntField("operator_right");
    query.finalize();

    return &m_data;
}

crmObject* crmRightDef::getData(const int id)
{
    CppSQLite3Buffer szSQL;
    szSQL.format("SELECT * FROM crm_right_def WHERE id = %d", id);
    CppSQLite3Query query = m_db.execQuery(szSQL);
    if ( query.eof() )
        return NULL;

    m_data.id = query.getIntField("id");
    m_data.module_name = query.getStringField("module_name");
    m_data.right_mask = query.getIntField("right_mask");
    query.finalize();

    return &m_data;
}

crmObject* crmRecordDef::getData(const int id)
{
    CppSQLite3Buffer szSQL;
    szSQL.format("SELECT * FROM crm_welcome_record WHERE id = %d", id);
    CppSQLite3Query query = m_db.execQuery(szSQL);
    if ( query.eof() )
        return NULL;

    m_data.id = query.getIntField("id");
    m_data.operator_name = query.getStringField("operator_name");
    m_data.statistics_date = query.getStringField("statistics_date");
    m_data.record_time = query.getStringField("record_time");
    m_data.group_name = query.getStringField("group_name");
    m_data.user_name = query.getStringField("user_name");
    m_data.card_name = query.getStringField("card_name");
    m_data.card_id = query.getStringField("card_id");
    m_data.presence_name = query.getStringField("presence_name");
    m_data.comment = query.getStringField("comment");
    m_data.train_code = query.getStringField("train_code");
    m_data.train_date = query.getStringField("train_date");
    m_data.people_count = query.getIntField("people_count");
    m_data.price = query.getFloatField("price");
    query.finalize();

    return &m_data;
}

int crmOperatorDef::Update(crmObject* obj)
{
    strucOperator* p = static_cast<strucOperator*>(obj);

    CppSQLite3Buffer szSQL;
    szSQL.format(m_sql_update.c_str(),
                 p->operator_name.c_str(),
                 p->operator_password.c_str(),
                 p->operator_right,
                 p->id);

    return m_db.execDML(szSQL);
}

int crmGuestDef::Update(crmObject* obj)
{
    strucGuest* p = static_cast<strucGuest*>(obj);

    CppSQLite3Buffer szSQL;
    szSQL.format(m_sql_update.c_str(),
                 p->group_name.c_str(), p->user_name.c_str(),
                 p->card_name.c_str(), p->start_date.c_str(),
                 p->end_date.c_str(), p->people_limit,
                 p->image_s_id, p->image_l_id, p->price_default,
                 p->id);

    return m_db.execDML(szSQL);
}

int crmImageDef::Update(crmObject* obj)
{
    strucImage* p = static_cast<strucImage*>(obj);

    CppSQLite3Buffer szSQL;
    szSQL.format(m_sql_update.c_str(), p->id);
    CppSQLite3Statement stmt = m_db.compileStatement(szSQL);
    stmt.bind(1, p->image_size);
    stmt.bind(2, p->GetImageBody(), p->image_size);
    stmt.bind(3, p->comment.c_str());
    stmt.bind(4, p->image_type.c_str());

    return stmt.execDML();
}

int crmRecordDef::Update(crmObject* obj)
{
    strucRecord* p = static_cast<strucRecord*>(obj);

    CppSQLite3Buffer szSQL;
    szSQL.format(m_sql_update.c_str(),
                 p->operator_name.c_str(), p->statistics_date.c_str(),
                 p->record_time.c_str(), p->group_name.c_str(),
                 p->user_name.c_str(), p->card_name.c_str(),
                 p->card_id.c_str(), p->presence_name.c_str(),
                 p->comment.c_str(), p->train_code.c_str(),
                 p->train_date.c_str(), p->people_count,
                 p->price, p->id);

    return m_db.execDML(szSQL);
}

int crmRightDef::Update(crmObject* obj)
{
    strucRight* p = static_cast<strucRight*>(obj);

    CppSQLite3Buffer szSQL;
    szSQL.format(m_sql_update.c_str(),
                 p->module_name.c_str(), p->right_mask, p->id);

    return m_db.execDML(szSQL);
}

int crmTrainDef::Update(crmObject* obj)
{
    strucTrain* p = static_cast<strucTrain*>(obj);

    CppSQLite3Buffer szSQL;
    szSQL.format(m_sql_update.c_str(),
                 p->train_code.c_str(),
                 p->start_station_name.c_str(),
                 p->end_station_name.c_str(),
                 p->start_time.c_str(),
                 p->id);

    return m_db.execDML(szSQL);
}

crmObject* crmTrainDef::getNewData()
{
    return new strucTrain();
}

crmObject* crmGuestDef::getNewData()
{
    return new strucGuest();
}

crmObject* crmOperatorDef::getNewData()
{
    return new strucOperator();
}

crmObject* crmRightDef::getNewData()
{
    return new strucRight();
}

crmObject* crmImageDef::getNewData()
{
    return new strucImage();
}

crmObject* crmRecordDef::getNewData()
{
    return new strucRecord();
}
