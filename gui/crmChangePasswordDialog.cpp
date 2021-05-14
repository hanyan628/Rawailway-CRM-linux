#include "crmChangePasswordDialog.h"

//(*InternalHeaders(crmChangePasswordDialog)
#include <wx/xrc/xmlres.h>
#include <wx/valtext.h>
//*)

//(*IdInit(crmChangePasswordDialog)
//*)

BEGIN_EVENT_TABLE(crmChangePasswordDialog,wxDialog)
    //(*EventTable(crmChangePasswordDialog)
    //*)
END_EVENT_TABLE()

crmChangePasswordDialog::crmChangePasswordDialog(wxWindow* parent)
{
    //(*Initialize(crmChangePasswordDialog)
    wxXmlResource::Get()->LoadObject(this,parent,_T("crmChangePasswordDialog"),_T("wxDialog"));
    ctlOldPassword = (wxTextCtrl*)FindWindow(XRCID("ID_OLD_PASSWORD"));
    ctlNewPassword = (wxTextCtrl*)FindWindow(XRCID("ID_NEW_PASSWORD"));
    ctlConfirmPassword = (wxTextCtrl*)FindWindow(XRCID("ID_CONFIRM_PASSWORD"));
    //*)
    m_oldPassword = wxT("");
    m_newPassword = wxT("");
    m_confirmPassword = wxT("");

    const long style = wxFILTER_ASCII|wxFILTER_EMPTY;
    ctlOldPassword->SetValidator(wxTextValidator(style, &m_oldPassword));
    ctlNewPassword->SetValidator(wxTextValidator(style, &m_newPassword));
    ctlConfirmPassword->SetValidator(wxTextValidator(style, &m_confirmPassword));
}

crmChangePasswordDialog::~crmChangePasswordDialog()
{
    //(*Destroy(crmChangePasswordDialog)
    //*)
}

