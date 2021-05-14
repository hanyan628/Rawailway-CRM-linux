#ifndef CRM_DATASET_H_HEADER_INCLUDED
#define CRM_DATASET_H_HEADER_INCLUDED

#include <string>
#include "../sqlite3/CppSQLite3.h"

class crmObject
{
public:
    crmObject(const int id = -1);
    virtual ~crmObject();
    int id;
};

// operator table
class strucOperator : public crmObject
{
public:
    strucOperator();
    virtual ~strucOperator();

    std::string     operator_name;
    std::string     operator_password;
    unsigned long   operator_right;

};

class strucRight : public crmObject
{
public:
    strucRight();
    virtual ~strucRight();

    std::string     module_name;
    unsigned long   right_mask;
};

class strucGuest : public crmObject
{
public:
    strucGuest();
    virtual ~strucGuest();

    std::string     group_name;
    std::string     user_name;
    std::string     card_name;
    std::string     start_date;
    std::string     end_date;
    int             people_limit;
    int             image_s_id;
    int             image_l_id;
    double          price_default;
};

class strucImage : public crmObject
{
public:
    strucImage();
    virtual ~strucImage();

    int             image_size;
    std::string     comment;
    std::string     image_type;

    const unsigned char* GetImageBody();
    int SetImageBody(const unsigned char* pBuf, const int nLen);

private:
    CppSQLite3Binary m_blob;
};

class strucRecord : public crmObject
{
public:
    strucRecord();
    virtual ~strucRecord();

    std::string     operator_name;
    std::string     statistics_date;
    std::string     record_time;
    std::string     group_name;
    std::string     user_name;
    std::string     card_name;
    std::string     card_id;
    std::string     presence_name;
    std::string     comment;
    std::string     train_code;
    std::string     train_date;
    int             people_count;
    double          price;
};

class strucRailwayStation : public crmObject
{
public:
    strucRailwayStation();
    virtual ~strucRailwayStation();

    std::string     station_name;
    std::string     tele_code;
};

class strucTrain : public crmObject
{
public:
    strucTrain();
    virtual ~strucTrain();

    std::string     train_code;
    std::string     start_station_name;
    std::string     end_station_name;
    std::string     start_time;

    strucTrain& operator=(const strucTrain& tr);
};

class crmDataSet
{
public:
    crmDataSet();
    virtual ~crmDataSet();

    virtual crmObject*  getData(const int id)           = 0;
    virtual crmObject*  getNewData()                    = 0;
    virtual int         Insert(const crmObject* obj)    = 0;
    virtual int         Update(crmObject* obj)          = 0;

    virtual CppSQLite3Table* GetTable(const char* szSQL = NULL)
    {
        if (szSQL)
        {
            m_table = m_db.getTable(szSQL);
            return &m_table;
        }
        std::string szBuf = m_sql_select + m_sql_order;
        m_table = m_db.getTable(szBuf.c_str());
        return &m_table;
    };

    virtual CppSQLite3Table* GetFilterTable(const char* szFilter = NULL)
    {
        if (!szFilter)
        {
            return GetTable();
        }
        std::string szSQL = m_sql_select + " WHERE ";
        szSQL += szFilter;
        szSQL += m_sql_order;
        return GetTable(szSQL.c_str());
    };

    virtual CppSQLite3Query* GetQuery(const char* szSQL = NULL)
    {
        if (szSQL)
        {
            m_query = m_db.execQuery(szSQL);
            return &m_query;
        }
        std::string szBuf = m_sql_select + m_sql_order;
        m_query = m_db.execQuery(szBuf.c_str());
        return &m_query;
    };

    virtual CppSQLite3Query* GetFilterQuery(const char* szFilter = NULL)
    {
        if (!szFilter)
        {
            return GetQuery();
        }
        std::string szSQL = m_sql_select + " WHERE ";
        szSQL += szFilter;
        szSQL += m_sql_order;
        return GetQuery(szSQL.c_str());
    };

    virtual int Delete(const int id)
    {
        CppSQLite3Buffer szSQL;
        szSQL.format(m_sql_delete.c_str(), id);
        return m_db.execDML(szSQL);
    };

    virtual int ExecuteSQL(const char* szSQL)
    {
        return m_db.execDML(szSQL);
    };

protected:
    CppSQLite3DB    m_db;
    CppSQLite3Table m_table;
    CppSQLite3Query m_query;
    std::string     m_sql_select;
    std::string     m_sql_order;
    std::string     m_sql_delete;
    std::string     m_sql_update;
    std::string     m_sql_insert;
};

class crmOperatorDef : public crmDataSet
{
public:
    crmOperatorDef();
    virtual ~crmOperatorDef();

    virtual crmObject*  getData(const int id);
    virtual crmObject*  getNewData();
    virtual int         Insert(const crmObject* obj);
    virtual int         Update(crmObject* obj);
private:
    strucOperator       m_data;
};

class crmGuestDef : public crmDataSet
{
public:
    crmGuestDef();
    virtual ~crmGuestDef();

    virtual crmObject*  getData(const int id);
    virtual crmObject*  getNewData();
    virtual int         Insert(const crmObject* obj);
    virtual int         Update(crmObject* obj);
private:
    strucGuest          m_data;
};

class crmImageDef : public crmDataSet
{
public:
    crmImageDef();
    virtual ~crmImageDef();

    virtual crmObject*  getData(const int id);
    virtual crmObject*  getNewData();
    virtual int         Insert(const crmObject* obj);
    virtual int         Update(crmObject* obj);
private:
    strucImage          m_data;
};

class crmRecordDef : public crmDataSet
{
public:
    crmRecordDef();
    virtual ~crmRecordDef();

    virtual crmObject*  getData(const int id);
    virtual crmObject*  getNewData();
    virtual int         Insert(const crmObject* obj);
    virtual int         Update(crmObject* obj);
private:
    strucRecord         m_data;
};

// right table Control
class crmRightDef : public crmDataSet
{
public:
    crmRightDef();
    virtual ~crmRightDef();

    virtual crmObject*  getData(const int id);
    virtual crmObject*  getNewData();
    virtual int         Insert(const crmObject* obj);
    virtual int         Update(crmObject* obj);
private:
    strucRight          m_data;
};

// train table Control
class crmTrainDef : public crmDataSet
{
public:
    crmTrainDef();
    virtual ~crmTrainDef();

    virtual crmObject*  getData(const int id);
    virtual crmObject*  getNewData();
    virtual int         Insert(const crmObject* obj);
    virtual int         Update(crmObject* obj);
private:
    strucTrain          m_data;
};

#endif /* CRM_DATASET_H_HEADER_INCLUDED */
