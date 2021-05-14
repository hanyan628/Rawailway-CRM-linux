#ifndef CRMFILTERDATADIALOG_H_INCLUDED
#define CRMFILTERDATADIALOG_H_INCLUDED

#include "../datamodule/crm_dataset.h"
#include "../src/crm_var.h"

//(*Headers(crmEditDataDialog)
#include <wx/dialog.h>
//*)

class crmFilterDataDialog: public wxDialog
{
public:
    virtual const char* getFilter() = 0;
    virtual bool        IsFilter() = 0;

protected:
    CppSQLite3Buffer    m_sql_filter;
    bool                m_isfilter;
};

#endif // CRMFILTERDATADIALOG_H_INCLUDED
