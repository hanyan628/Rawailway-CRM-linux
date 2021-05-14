#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

//(*Headers(LoginDialog)
#include <wx/dialog.h>
#include <wx/textctrl.h>
#include <wx/statbmp.h>
#include <wx/bmpcbox.h>
#include <wx/imaglist.h>
#include <wx/log.h>
//*)


class LoginDialog: public wxDialog
{
public:

    LoginDialog(wxWindow* parent);
    virtual ~LoginDialog();

    //(*Declarations(LoginDialog)
    wxBitmapComboBox        *ctlOperators;
    wxStaticBitmap          *StaticBitmap1;
    wxTextCtrl              *ctlPassword;
    //*)
    //------------------------------------------------------------------
    //      Hyan's program
    //------------------------------------------------------------------
public:
    bool VerifyPassword();

private:
    void InitImageList();
    void DoNavigate(const int flags)
    {
        if ( !this->NavigateIn(flags) )
        {
            wxLogError(wxT("Navigation event ignored"));
        }
    };

    void InitButtonBitmap();

    wxImageList             *m_image_list;
    //------------------------------------------------------------------
private:

    //(*Handlers(LoginDialog)
    void OnInit(wxInitDialogEvent& event);
    void OnButtonShutdown(wxCommandEvent& event);
    void OnNavigate(wxCommandEvent& event);
    //*)
    DECLARE_EVENT_TABLE()
};

#endif
