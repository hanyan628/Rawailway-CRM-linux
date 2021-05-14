#ifndef CRMRECORDMODIFYDIALOG_H
#define CRMRECORDMODIFYDIALOG_H
#include "./crmEditDataDialog.h"
//(*Headers(crmRecordModifyDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/combobox.h>
//*)

class crmRecordModifyDialog: public crmEditDataDialog
{
//---------------------------------------------------------------------------------------
//          My Progrman
//---------------------------------------------------------------------------------------
public:
    virtual void SetDataObject(crmObject* pObj) ;
private:
    strucRecord* m_data;
    crmGuestDef m_dsGuest;
    void initListGroup();
    void initListUser(const char* szGroup);
    void initListCard(const char* szGroup, const char* szUser);

//---------------------------------------------------------------------------------------

public:

    crmRecordModifyDialog(wxWindow* parent);
    virtual ~crmRecordModifyDialog();

    //(*Declarations(crmRecordModifyDialog)
    wxTextCtrl* ctlTrainCode;
    wxTextCtrl* ctlStatisticsDate;
    wxComboBox* ctlCardName;
    wxComboBox* ctlGroupName;
    wxTextCtrl* ctlCardID;
    wxTextCtrl* ctlPresenceName;
    wxTextCtrl* ctlPrice;
    wxTextCtrl* ctlComment;
    wxTextCtrl* ctlOperatorName;
    wxTextCtrl* ctlRecordTime;
    wxTextCtrl* ctlPeopleCount;
    wxComboBox* ctlUserName;
    wxTextCtrl* ctlTrainDate;
    //*)

protected:

    //(*Identifiers(crmRecordModifyDialog)
    //*)

private:

    //(*Handlers(crmRecordModifyDialog)
    void OnInit(wxInitDialogEvent& event);
    void OnbtnResetClick(wxCommandEvent& event);
    void OnctlGroupNameDropDown(wxCommandEvent& event);
    void OnctlUserNameDropDown(wxCommandEvent& event);
    void OnctlCardNameDropDown(wxCommandEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
