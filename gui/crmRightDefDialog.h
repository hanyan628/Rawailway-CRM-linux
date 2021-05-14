#ifndef CRMRIGHTDEFDIALOG_H
#define CRMRIGHTDEFDIALOG_H

#include "./crmEditDataDialog.h"

//(*Headers(crmRightDefDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class crmRightDefDialog: public crmEditDataDialog
{
    //---------------------------------------------------------------------------------------
    //          My Progrman
    //---------------------------------------------------------------------------------------
public:
    virtual void SetDataObject(crmObject* pObj) ;
private:
    strucRight* m_data;
    virtual bool TransferDataToWindow();
    virtual bool TransferDataFromWindow();
    //---------------------------------------------------------------------------------------

public:

    crmRightDefDialog(wxWindow* parent);
    virtual ~crmRightDefDialog();

    //(*Declarations(crmRightDefDialog)
    wxTextCtrl* ctlID;
    wxTextCtrl* ctlModuleName;
    wxTextCtrl* ctlRightMask;
    //*)

private:

    //(*Handlers(crmRightDefDialog)
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
