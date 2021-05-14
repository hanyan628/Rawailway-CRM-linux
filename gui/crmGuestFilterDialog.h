#ifndef CRMGUESTFILTERDIALOG_H
#define CRMGUESTFILTERDIALOG_H
#include "./crmFilterDataDialog.h"

//(*Headers(crmGuestFilterDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/combobox.h>
//*)

class crmGuestFilterDialog: public crmFilterDataDialog
{
    //---------------------------------------------------------------------------------------
    //          My Progrman
    //---------------------------------------------------------------------------------------
public:
    virtual const char*     getFilter();
    virtual bool            IsFilter();
private:
    virtual bool            TransferDataToWindow();
    virtual bool            TransferDataFromWindow();
    void                    initListGroup();
    void                    initListUser(const char* szGroup);
    void                    initListCard(const char* szGroup, const char* szUser);

    wxString    szGroupName;
    wxString    szUserName;
    wxString    szCardName;
    crmGuestDef m_dsGuest;
    //---------------------------------------------------------------------------------------


public:

    crmGuestFilterDialog(wxWindow* parent);
    virtual ~crmGuestFilterDialog();

    //(*Declarations(crmGuestFilterDialog)
    wxComboBox* ctlGroupName;
    wxComboBox* ctlUserName;
    wxComboBox* ctlCardName;
    //*)

protected:

    //(*Identifiers(crmGuestFilterDialog)
    //*)

private:

    //(*Handlers(crmGuestFilterDialog)
    void OnbtnResetClick(wxCommandEvent& event);
    void OnInit(wxInitDialogEvent& event);
    void OnctlGroupNameSelect(wxCommandEvent& event);
    void OnctlUserNameDropDown(wxCommandEvent& event);
    void OnctlCardNameDropDown(wxCommandEvent& event);
    void OnctlUserNameSelect(wxCommandEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
