#include "crmlogin.h"
#include "./parameter.h"


crmLogin::crmLogin()
{
    //ctor
    m_operator = "";
    m_password = "";
    m_islogin = false;
}

crmLogin::~crmLogin()
{
    //dtor
}

bool crmLogin::Login(const char* operator_name,
                     const char* operator_password)
{
    m_operator = operator_name;
    m_password = operator_password;
    m_islogin = false;

    m_islogin = VerifyPassword();

    return m_islogin;
}

bool crmLogin::VerifyPassword()
{
    CppSQLite3DB db;
    db.open( theParameter().Get("datamodule", "dbname_login") );
    CppSQLite3Buffer sqlBuf;
    sqlBuf.format("SELECT count(*) FROM crm_operator_def "
                      "WHERE operator_name=%Q AND operator_password=%Q;",
                  m_operator.c_str(),
                  m_password.c_str());
    int nCount = db.execScalar( sqlBuf );
    return nCount == 1;
}

void crmLogin::ChangePassword(const char* old_password,
                                       const char* new_password)
{
    CppSQLite3DB db;
    db.open( theParameter().Get("datamodule", "dbname_login") );
    CppSQLite3Buffer sqlBuf;
    sqlBuf.format("UPDATE crm_operator_def SET operator_password=%Q "
                      "WHERE operator_name=%Q AND operator_password=%Q;",
                      new_password, m_operator.c_str(), old_password);
    db.execDML(sqlBuf);
}

CppSQLite3Table crmLogin::GetOperators()
{
    CppSQLite3DB db;
    db.open( theParameter().Get("datamodule", "dbname_login") );
    return db.getTable("SELECT operator_name, operator_right FROM crm_operator_def;");
}

crmRight crmLogin::GetLoginRights()
{
    if ( !IsLogin() )
        return 0;
    CppSQLite3DB db;
    db.open( theParameter().Get("datamodule", "dbname_login") );
    CppSQLite3Buffer sqlBuf;
    sqlBuf.format("SELECT operator_right FROM crm_operator_def WHERE operator_name=%Q;",
                  m_operator.c_str());
    int rights = db.execScalar(sqlBuf);
    return crmRight(rights);
}
