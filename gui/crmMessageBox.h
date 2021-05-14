#ifndef CRMMESSAGEBOX_H
#define CRMMESSAGEBOX_H

//(*Headers(crmMessageBox)
#include <wx/stattext.h>
#include <wx/statline.h>
#include <wx/dialog.h>
//*)

class crmMessageBox: public wxDialog
{
public:

    crmMessageBox(wxWindow* parent);
    virtual ~crmMessageBox();

    //(*Declarations(crmMessageBox)
    wxStaticText* ctlAppName;
    wxStaticText* ctlVersion;
    wxStaticText* ctlAuthor;
    wxStaticText* ctlEmail;
    wxStaticText* ctlPhone;
    wxStaticText* ctlBuildInfo;
    //*)

protected:

    //(*Identifiers(crmMessageBox)
    //*)

private:

    //(*Handlers(crmMessageBox)
    void OnInit(wxInitDialogEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
