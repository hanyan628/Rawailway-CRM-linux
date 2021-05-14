#ifndef CRMCHANGEPASSWORDDIALOG_H
#define CRMCHANGEPASSWORDDIALOG_H

//(*Headers(crmChangePasswordDialog)
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class crmChangePasswordDialog: public wxDialog
{
public:

    crmChangePasswordDialog(wxWindow* parent);
    virtual ~crmChangePasswordDialog();

    //(*Declarations(crmChangePasswordDialog)
    wxTextCtrl* ctlOldPassword;
    wxTextCtrl* ctlNewPassword;
    wxTextCtrl* ctlConfirmPassword;
    //*)
    wxString get_oldPassword() const
    {
        return m_oldPassword;
    };
    wxString get_newPassword() const
    {
        return m_newPassword;
    };
    wxString get_confirmPassword() const
    {
        return m_confirmPassword;
    };

protected:

    //(*Identifiers(crmChangePasswordDialog)
    //*)

private:
    wxString m_oldPassword;
    wxString m_newPassword;
    wxString m_confirmPassword;

    //(*Handlers(crmChangePasswordDialog)
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
