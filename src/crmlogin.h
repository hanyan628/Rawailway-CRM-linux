#ifndef CRMLOGIN_H
#define CRMLOGIN_H

#include <string>
#include "../sqlite3/CppSQLite3.h"

class crmRight;

class crmLogin
{
    public:
        CppSQLite3Table GetOperators();
        crmRight GetLoginRights();
        bool Login(const char* operator_name,
                   const char* operator_password);
        //inline
        const char* GetOperatorName() { return m_operator.c_str(); };
        bool IsLogin() { return m_islogin; };
        void Logout() { m_islogin = false; };
        void ChangePassword(const char* old_password,
                                  const char* new_password);
        virtual ~crmLogin();
        friend crmLogin& theOperator();
    protected:
    private:
        crmLogin();
        bool VerifyPassword();
        std::string m_operator;
        std::string m_password;
        bool m_islogin;
};

class crmRight
{
    public:
        crmRight(const int rights):m_rights(rights){;};
        ~crmRight() {;};

        crmRight& operator=(const crmRight& rht)
        {
            this->m_rights = rht.m_rights;
            return *this;
        };

        bool HasRight(const int right_mask)
        {
            return m_rights & right_mask;
        };
    private:
        int m_rights;
};


inline crmLogin& theOperator()
{
    static crmLogin p;
    return p;
};


#endif // CRMLOGIN_H
