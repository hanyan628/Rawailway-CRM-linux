#include "crm_account.h"

crmAccount::crmAccount()
    :m_filter(""), m_people_count(0), m_price_count(0.0)
{

}

crmAccount::~crmAccount()
{

}

void crmAccount::Set(const char* statistics_date,
                     const char* operator_name,
                     const int account_category)
{
    CppSQLite3Buffer filter;
    filter.format("statistics_date=%Q AND operator_name=%Q",
                  statistics_date,
                  operator_name);
    Set(filter, account_category);
}

void crmAccount::Set(const char* filter,
                     const int account_category)
{
    m_filter.clear();
    m_sql.clear();

    std::string sqlFmt("");
    switch(account_category)
    {
    case typeAccountDefault:
        sqlFmt =
            "SELECT id, operator_name AS '操作员', "
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
            "FROM crm_welcome_record "
            "WHERE %s;";
        break;
    case typeAccountByGroup:
        sqlFmt =
            "SELECT group_name AS '客户分组',"
            "SUM(people_count) AS '乘车人数',"
            "SUM(price) AS '收费金额' FROM crm_welcome_record "
            "WHERE %s "
            "GROUP BY group_name;";
        break;
    case typeAccountByUser:
        sqlFmt =
            "SELECT group_name AS '客户分组',"
            "user_name AS '客户名称',"
            "SUM(people_count) AS '乘车人数',"
            "SUM(price) AS '收费金额' FROM crm_welcome_record "
            "WHERE %s "
            "GROUP BY group_name,user_name;";
        break;
    case typeAccountByCard:
        sqlFmt =
            "SELECT group_name AS '客户分组',"
            "user_name AS '客户名称',"
            "card_name AS '贵宾卡名称',"
            "SUM(people_count) AS '乘车人数',"
            "SUM(price) AS '收费金额' FROM crm_welcome_record "
            "WHERE %s "
            "GROUP BY group_name,user_name,card_name;";
        break;
    case typeAccountByTrain:
        sqlFmt =
            "SELECT train_code AS '车次信息',"
            "SUM(people_count) AS '乘车人数',"
            "SUM(price) AS '收费金额' FROM crm_welcome_record "
            "WHERE %s "
            "GROUP BY train_code;";
        break;
    case typeAccountByDate:
        sqlFmt =
            "SELECT statistics_date AS '结账日期',"
            "SUM(people_count) AS '乘车人数',"
            "SUM(price) AS '收费金额' FROM crm_welcome_record "
            "WHERE %s "
            "GROUP BY statistics_date;";
        break;
    case typeAccountByOperator:
        sqlFmt =
            "SELECT operator_name AS '服务员姓名',"
            "SUM(people_count) AS '乘车人数',"
            "SUM(price) AS '收费金额' FROM crm_welcome_record "
            "WHERE %s "
            "GROUP BY operator_name;";
        break;
    default:
        return;
    }
    m_sql.format(sqlFmt.c_str(), filter);
    m_filter = filter;
}

void crmAccount::AccountReport()
{
    m_data = *m_dsRecord.GetQuery(m_sql);
}

void crmAccount::AccountFoot()
{
    m_people_count = 0;
    m_price_count = 0.0;

    std::string sqlFmt =
        "SELECT SUM(people_count),SUM(price) FROM crm_welcome_record "
        "WHERE %s;";

    CppSQLite3Buffer szSQL;
    szSQL.format(sqlFmt.c_str(), m_filter.c_str());

    CppSQLite3Table* tbl = m_dsRecord.GetTable(szSQL);

    if ( tbl->numRows() == 1 )
    {
        tbl->setRow(0);
        m_people_count = tbl->getIntField(0);
        m_price_count = tbl->getFloatField(1);
    }
}

CppSQLite3Query* crmAccount::Get()
{
    AccountReport();
    return  &m_data;
}

const int crmAccount::SumPeople()
{
    return m_people_count;
}

const double crmAccount::SumPrice()
{
    return m_price_count;
}

void crmAccount::DoSumAccount(const char* statistics_date,
                              const char* operator_name)
{
    CppSQLite3Buffer filter;
    filter.format("statistics_date=%Q AND operator_name=%Q",
                  statistics_date,
                  operator_name);
    m_filter = filter;
    AccountFoot();
}

void crmAccount::DoSumReport(const char* filter)
{
    m_filter = filter;
    AccountFoot();
}
