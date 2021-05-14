#ifndef CRM_ACCOUNT_H_INCLUDED
#define CRM_ACCOUNT_H_INCLUDED
#include "./crm_dataset.h"

enum ACCOUNT_CATEGORY{
    typeAccountDefault = 0,
    typeAccountByGroup = 1,
    typeAccountByUser  = 2,
    typeAccountByCard  = 3,
    typeAccountByTrain = 4,
    typeAccountByDate  = 5,
    typeAccountByOperator = 6
};

class crmAccount
{
    public:
        crmAccount();
        virtual ~crmAccount();

        void                DoSumAccount   (const char* statistics_date, const char* operator_name);
        void                DoSumReport    (const char* filter);
        void                Set            (const char* statistics_date, const char* operator_name, const int account_category);
        void                Set            (const char* filter, const int account_category);
        CppSQLite3Query*    Get();
        const int           SumPeople();
        const double        SumPrice();
    private:
        void AccountFoot();
        void AccountReport();

        crmRecordDef        m_dsRecord;
        CppSQLite3Query     m_data;
        CppSQLite3Buffer    m_sql;
        std::string         m_filter;
        int                 m_people_count;
        double              m_price_count;
};

#endif // CRM_ACCOUNT_H_INCLUDED
