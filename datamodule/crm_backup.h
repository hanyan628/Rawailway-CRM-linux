#ifndef CRM_BACKUP_H_INCLUDED
#define CRM_BACKUP_H_INCLUDED

#include "./crm_dataset.h"
#include "../src/crmDataModel.h"

class crmBackup
{
    public:
        crmBackup(const bool bTruncateOldDate = false, wxWindow* parent = NULL)
            :m_isTruncateOldData(bTruncateOldDate),
            m_parent(parent),
            m_insert_rows(0),
            m_error_rows(0),
            m_sql_filter(""),
            m_file_name("")
        {

        };

        void setTruncateFlag(const bool bTruncateOldDate)
        {
            m_isTruncateOldData = bTruncateOldDate;
        }
        const int getRows() { return m_insert_rows; };
        const int getErrRows() { return m_error_rows; };
        void setFilter(const char* filter)
        {
            m_sql_filter = filter;
        }
        virtual const bool DoImportConfigure();
        virtual const bool DoExportConfigure();
        virtual const int  bcpin() = 0;
        virtual const int  bcpout() = 0;

        virtual ~crmBackup() {};

    protected:
        bool        m_isTruncateOldData;
        wxWindow*   m_parent;
        int         m_insert_rows;
        int         m_error_rows;
        std::string m_sql_filter;
        std::string m_file_name;
};

class crmReportBackup : public crmBackup
{
    public:
        crmReportBackup(crmDataModel* tbl, wxWindow* parent = NULL)
            :crmBackup(false, parent),m_data(tbl->GetDataBuffer()),
             m_columns(tbl->GetColumns()),m_title(""),m_foot(""),m_symbol(",")
        {

        };
        virtual ~crmReportBackup() {};
        void setTitle(const char* value) { m_title = value; };
        void setFoot(const char* value) { m_foot = value; };
        void setSymbol(const char* value) { m_symbol = value; };
        virtual const int bcpout();
    private:
        virtual const int bcpin() {return -1;};
        crmDataBuffer* m_data;
        crmDataViewColumn* m_columns;
        std::string m_title;
        std::string m_foot;
        std::string m_symbol;
};

class crmTrainDirBackup : public crmBackup
{
    public:
        crmTrainDirBackup(const bool bTruncateOldDate = true, wxWindow* parent = NULL)
            :crmBackup(bTruncateOldDate, parent) {};
        virtual ~crmTrainDirBackup() {};
        virtual const int bcpin();
        virtual const int bcpout();
    private:
        crmTrainDef m_dsTrainDir;
};

class crmRecordBackup : public crmBackup
{
    public:
        crmRecordBackup(const bool bTruncateOldData = false, wxWindow* parent = NULL)
            :crmBackup(bTruncateOldData, parent)    { };
        virtual ~crmRecordBackup()                  { };
        virtual const int bcpin();
        virtual const int bcpout();
    private:
        crmRecordDef m_dsRecord;
};

class crmGuestBackup : public crmBackup
{
    public:
        crmGuestBackup(const bool bTruncateOldData = true, wxWindow* parent = NULL)
            :crmBackup(bTruncateOldData, parent)    { };
        virtual ~crmGuestBackup()                   { };
        virtual const int bcpin();
        virtual const int bcpout();
    private:
        crmGuestDef m_dsGuestDef;
};

class crmOperatorDefBackup : public crmBackup
{
    public:
        crmOperatorDefBackup(const bool bTruncateOldData = true, wxWindow* parent = NULL)
            :crmBackup(bTruncateOldData, parent)    { };
        virtual ~crmOperatorDefBackup()             { };
        virtual const int bcpin();
        virtual const int bcpout();
    private:
        crmOperatorDef m_dsOperatorDef;
};

class crmImageDefBackup : public crmBackup
{
    public:
        crmImageDefBackup(const bool bTruncateOldData = false, wxWindow* parent = NULL)
        :crmBackup(bTruncateOldData, parent)        { };
        virtual ~crmImageDefBackup()                { };

        virtual const bool  DoImportConfigure();
        virtual const int   bcpin();
        virtual const bool  DoExportConfigure()     {return false;};
        virtual const int   bcpout()                {return -1;};
    protected:
    private:
        crmImageDef     m_dsImageDef;
        wxString        m_dir;
        wxArrayString   m_files;
};


#endif // CRM_BACKUP_H_INCLUDED
