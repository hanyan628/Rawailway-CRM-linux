/***************************************************************
 * Name:      RailwayCRMApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Hyan (hanyan@public.wh.hb.cn)
 * Created:   2010-11-22
 * Copyright: Hyan (http://hyan.cn)
 * License:
 **************************************************************/

#include "RailwayCRMApp.h"
#include "./src/parameter.h"
//(*AppHeaders
#include "RailwayCRMMain.h"
#include <wx/xrc/xmlres.h>
#include <wx/image.h>
#include <wx/fs_zip.h>
#include <wx/filesys.h>
#include <wx/log.h>
//*)
#if defined(__WXGTK__)
    #include <gtk/gtk.h>
#endif

IMPLEMENT_APP(RailwayCRMApp);

bool RailwayCRMApp::OnInit()
{
    InitGTK();
    //(*AppInitialize
    if ( !IsSingleInstance() )
    {
        return false;
    }
    loadZH();
    bool wxsOK = true;
    wxXmlResource::Get()->InitAllHandlers();
    wxInitAllImageHandlers();
    wxFileSystem::AddHandler(new wxZipFSHandler);
    wxsOK = wxsOK && wxXmlResource::Get()->Load(wxString::Format(wxT("file:%s*.xrc"), theParameter().Get("application","resource_path")));
    if ( wxsOK )
    {
        RailwayCRMFrame* Frame = new RailwayCRMFrame(0);
        if (atoi(theParameter().Get("application", "full_screen"))==1)
        {
            Frame->ShowFullScreen(true);
        }
        else
        {
            Frame->Show();
        }
        SetTopWindow(Frame);
        Frame->Login();
    }
    //*)
    return true;

}

void RailwayCRMApp::loadZH()
{
    if ( m_local.Init(wxLANGUAGE_DEFAULT, wxLOCALE_LOAD_DEFAULT) )
    {
        wxString executeDir = wxGetCwd();
        wxString resDir = executeDir + wxFILE_SEP_PATH + wxT("res");
	wxLanguage lang = wxLANGUAGE_CHINESE_SIMPLIFIED;
	wxString encoding = m_local.GetSystemEncodingName();
        m_local.AddCatalogLookupPathPrefix(resDir);
        if ( ! m_local.AddCatalog( wxT("default") ) ) //, lang, encoding) )
	{
		wxLogMessage( m_local.GetLocale() );
		wxLogMessage( encoding );
		wxLogMessage("load mo file faild!");
	}
    }
}

bool RailwayCRMApp::IsSingleInstance()
{
    if (!m_checker)
        m_checker = new wxSingleInstanceChecker;
    if ( m_checker->IsAnotherRunning() )
    {
        wxLogMessage(_("the CRM Application is already running!"));
        return false;
    }
    return true;
}

int RailwayCRMApp::OnExit()
{
    if ( m_checker )
        delete m_checker;
    wxString strCommand = wxString::FromUTF8(theParameter().Get("application","shutdown"));
    wxExecute(strCommand);
    return 0;
}

#if defined(__WXGTK__)
void RailwayCRMApp::InitGTK()
{
    GtkSettings* sets = gtk_settings_get_default();
    gtk_settings_set_long_property(sets, "gtk-button-images", 1, "LONG");
}
#endif
