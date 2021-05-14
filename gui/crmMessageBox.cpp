#include "crmMessageBox.h"
#include "../version.h"
//(*InternalHeaders(crmMessageBox)
#include <wx/xrc/xmlres.h>
//*)

//(*IdInit(crmMessageBox)
//*)

BEGIN_EVENT_TABLE(crmMessageBox,wxDialog)
    //(*EventTable(crmMessageBox)
    EVT_INIT_DIALOG(crmMessageBox::OnInit)
    //*)
END_EVENT_TABLE()

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_STL
        wxbuild << _T("-STL");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

crmMessageBox::crmMessageBox(wxWindow* parent)
{
    //(*Initialize(crmMessageBox)
    wxXmlResource::Get()->LoadObject(this,parent,_T("crmMessageBox"),_T("wxDialog"));

    ctlAppName      = (wxStaticText*)FindWindow(XRCID("ID_LABEL_NAME"));
    ctlVersion      = (wxStaticText*)FindWindow(XRCID("ID_LABEL_VERSION"));
    ctlAuthor       = (wxStaticText*)FindWindow(XRCID("ID_LABEL_AUTHOR"));
    ctlEmail        = (wxStaticText*)FindWindow(XRCID("ID_LABEL_EMAIL"));
    ctlPhone        = (wxStaticText*)FindWindow(XRCID("ID_LABEL_PHONE"));
    ctlBuildInfo    = (wxStaticText*)FindWindow(XRCID("ID_LABEL_BUILDINFO"));
    //*)
}

crmMessageBox::~crmMessageBox()
{
    //(*Destroy(crmMessageBox)
    //*)
}

void crmMessageBox::OnInit(wxInitDialogEvent& event)
{
    ctlAppName  ->SetLabel(_("RailwayCRM"));
    ctlAuthor   ->SetLabel(_("HanYan"));
    ctlEmail    ->SetLabel(wxT("hanyan@public.wh.hb.cn"));
    ctlPhone    ->SetLabel(wxT("(+86)13907113775"));

    wxString strBuf = wxT("");
    strBuf << wxbuildinfo(short_f) << " - "
           << AutoVersion::FULLVERSION_STRING;
    ctlVersion->SetLabel(strBuf);
    strBuf.clear();
    strBuf << wxbuildinfo(long_f) << " , "
           << wxT(" last build in ") << AutoVersion::YEAR << wxT("/")
           << AutoVersion::MONTH << wxT("/") << AutoVersion::DATE;
    ctlBuildInfo->SetLabel(strBuf);

    Fit();
    Center();
    event.Skip();
}
