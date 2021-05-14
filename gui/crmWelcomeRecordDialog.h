#ifndef CRMWELCOMERECORDDIALOG_H
#define CRMWELCOMERECORDDIALOG_H
#include "./crmEditDataDialog.h"
//(*Headers(crmWelcomeRecordDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/combobox.h>
#include <wx/log.h>
//*)

class crmWelcomeRecordDialog: public crmEditDataDialog
{
    //---------------------------------------------------------------------------------------
    //          My Progrman
    //---------------------------------------------------------------------------------------
public:
    virtual void SetDataObject(crmObject* pObj);
    void SetLogoID(const int id)
    {
        m_logo_id = id;
    };
private:
    virtual bool TransferDataToWindow();
    virtual bool TransferDataFromWindow();

    strucRecord*    m_record;
    int             m_logo_id;
    double          m_price_default;

    void initListTrainInfo();
    void initGuestInfo();
    void showLogo();
    bool selectTrainInfo();
    bool inParameter(const wxString& sub);

    void DoNavigate(const int flags)
    {
        if ( !this->NavigateIn(flags) )
        {
            wxLogError(wxT("Navigation event ignored"));
        }
    };
    //---------------------------------------------------------------------------------------

public:

    crmWelcomeRecordDialog(wxWindow* parent);
    virtual ~crmWelcomeRecordDialog();

    //(*Declarations(crmWelcomeRecordDialog)
    wxComboBox* ctlTrainInfo;
    wxSpinCtrl* ctlPeopleCount;
    wxTextCtrl* ctlUserName;
    wxTextCtrl* ctlCardID;
    wxTextCtrl* ctlGroupName;
    wxTextCtrl* ctlPresenceName;
    wxTextCtrl* ctlPrice;
    wxTextCtrl* ctlCardName;
    wxTextCtrl* ctlComment;
    //*)

protected:

    //(*Identifiers(crmWelcomeRecordDialog)
    //*)

private:

    //(*Handlers(crmWelcomeRecordDialog)
    void OnInit(wxInitDialogEvent& event);
    void OnbtnResetClick(wxCommandEvent& event);
    void OnSpinCtrlUpdate(wxSpinEvent& event);
    void OnInputTrainInfoEnter(wxCommandEvent& event);
    void OnEnter(wxCommandEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
