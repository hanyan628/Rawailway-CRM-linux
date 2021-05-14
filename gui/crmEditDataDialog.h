#ifndef CRMEDITDATADIALOG_H
#define CRMEDITDATADIALOG_H

#include "../datamodule/crm_dataset.h"
#include "../src/crm_var.h"

//(*Headers(crmEditDataDialog)
#include <wx/dialog.h>
//*)

class crmEditDataDialog: public wxDialog
{
public:
    virtual void SetDataObject(crmObject* pObj) = 0;
};

#endif
