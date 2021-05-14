#ifndef CRMOPERATORDEFDIALOG_H
#define CRMOPERATORDEFDIALOG_H

#include "./crmEditDataDialog.h"
#include <wx/dynarray.h>

//(*Headers(crmOperatorDefDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checklst.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class crmOperatorDefDialog: public crmEditDataDialog
{
    //---------------------------------------------------------------------------------------
    //          My Progrman
    //---------------------------------------------------------------------------------------
public:
    virtual void SetDataObject(crmObject* pObj) ;
private:
    strucOperator* m_data;
    virtual bool TransferDataToWindow();
    virtual bool TransferDataFromWindow();
    void loadRights();
    int getRights();
    wxArrayInt m_rights_mask;
    void createRightList();
    //---------------------------------------------------------------------------------------

public:

    crmOperatorDefDialog(wxWindow* parent);
    virtual ~crmOperatorDefDialog();

    //(*Declarations(crmOperatorDefDialog)
    wxTextCtrl* ctlID;
    wxTextCtrl* ctlPassword;
    wxCheckListBox* ctlRights;
    wxTextCtrl* ctlOperatorName;
    //*)

private:

    //(*Handlers(crmOperatorDefDialog)
    void OnbtnResetClick(wxCommandEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
