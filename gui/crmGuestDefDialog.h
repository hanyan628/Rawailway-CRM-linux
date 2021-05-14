#ifndef CRMGUESTDEFDIALOG_H
#define CRMGUESTDEFDIALOG_H
#include "./crmEditDataDialog.h"
#include "./crmImagesSelectDialog.h"
//(*Headers(crmGuestDefDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/datectrl.h>
#include <wx/spinctrl.h>
#include <wx/statline.h>
#include <wx/dateevt.h>
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/combobox.h>
//*)

class crmGuestDefDialog: public crmEditDataDialog
{
    //---------------------------------------------------------------------------------------
    //          My Progrman
    //---------------------------------------------------------------------------------------
public:
    virtual void SetDataObject(crmObject* pObj) ;
private:
    crmImagesSelectDialog*  imgsDlg;
    strucGuest*             m_data;
    crmGuestDef             m_dsGuest;
    crmImageDef             m_dsImage;
    int                     m_imageL_id;
    int                     m_imageS_id;

    virtual bool    TransferDataToWindow();
    virtual bool    TransferDataFromWindow();
    void            initListGroup();
    void            initListUser(const char* szGroup);
    void            showLImage();
    void            showSImage();
    wxBitmap        getBitmap(const int id);
    //---------------------------------------------------------------------------------------


public:

    crmGuestDefDialog(wxWindow* parent);
    virtual ~crmGuestDefDialog();

    //(*Declarations(crmGuestDefDialog)
//		wxDatePickerCtrl* ctlStartDate;
//		wxDatePickerCtrl* ctlEndDate;
    wxSpinCtrl*     ctlPeopleLimit;
    wxTextCtrl*     ctlPriceDefault;
    wxTextCtrl*     ctlID;
    wxComboBox*     ctlGroupName;
    wxTextCtrl*     ctlCardName;
    wxStaticBitmap* ctlImage2;
    wxComboBox*     ctlUserName;
    wxStaticBitmap* ctlImage1;
    //*)

private:

    //(*Handlers(crmGuestDefDialog)
    void OnbtnResetClick(wxCommandEvent& event);
    void OnInit(wxInitDialogEvent& event);
    void OnbtnLoadSFromClick(wxCommandEvent& event);
    void OnbtnLoadLFromClick(wxCommandEvent& event);
    void OnctlUserNameDropDown(wxCommandEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
