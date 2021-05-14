#include "LoginDialog.h"
#include "../src/crmlogin.h"
#include "../src/crm_var.h"
//(*InternalHeaders(LoginDialog)
#include <wx/bitmap.h>
#include <wx/wfstream.h>
#include <wx/xrc/xmlres.h>
#include <wx/filesys.h>
#include <wx/button.h>
//*)

BEGIN_EVENT_TABLE(LoginDialog,wxDialog)
    EVT_INIT_DIALOG(LoginDialog::OnInit)
    EVT_BUTTON(wxID_NO, LoginDialog::OnButtonShutdown)
    EVT_TEXT_ENTER(XRCID("ID_CHOICE_OPERATOR"),   LoginDialog::OnNavigate)
    EVT_TEXT_ENTER(XRCID("ID_TEXTCTRL_PASSWORD"), LoginDialog::OnNavigate)
END_EVENT_TABLE()

LoginDialog::LoginDialog(wxWindow* parent)
{
    wxXmlResource::Get()->LoadObject(this,parent,_T("LoginDialog"),_T("wxDialog"));

    StaticBitmap1   = (wxStaticBitmap       *)FindWindow(XRCID("ID_STATICBITMAP1"));
    ctlOperators    = (wxBitmapComboBox     *)FindWindow(XRCID("ID_CHOICE_OPERATOR"));
    ctlPassword     = (wxTextCtrl           *)FindWindow(XRCID("ID_TEXTCTRL_PASSWORD"));

    InitImageList();
    InitButtonBitmap();
}

LoginDialog::~LoginDialog()
{
    //(*Destroy(LoginDialog)
    if ( m_image_list )
    {
        delete m_image_list;
    }
    //*)
}

void LoginDialog::InitImageList()
{
    m_image_list = new wxImageList(16,16);

    wxString        archive = wxT("res/resource.zip");
    wxString        archiveURL( wxFileSystem::FileNameToURL(archive) );
    wxFileSystem*   fileSystem = new wxFileSystem;
    wxFSFile*       file = fileSystem->OpenFile( archiveURL + wxT("#zip:images/operator_mask.bmp") );
    wxInputStream*  stream = file->GetStream();
    wxImage         mask_bmp(*stream, wxBITMAP_TYPE_BMP);
    delete file;

    wxImage bmp;

    file    = fileSystem->OpenFile( archiveURL + wxT("#zip:images/01.bmp") );
    stream  = file->GetStream();
    bmp.LoadFile(*stream, wxBITMAP_TYPE_BMP);
    delete file;
    if ( bmp.IsOk() )
    {
        bmp.SetMaskFromImage(mask_bmp, 0, 0, 0);
        bmp.Rescale(16,16);
        m_image_list->Add(wxBitmap(bmp));
    }

    file    = fileSystem->OpenFile( archiveURL + wxT("#zip:images/02.bmp") );
    stream  = file->GetStream();
    bmp.LoadFile(*stream, wxBITMAP_TYPE_BMP);
    delete file;
    if ( bmp.IsOk() )
    {
        bmp.SetMaskFromImage(mask_bmp, 0, 0, 0);
        bmp.Rescale(16,16);
        m_image_list->Add(wxBitmap(bmp));
    }

    file    = fileSystem->OpenFile( archiveURL + wxT("#zip:images/07.bmp") );
    stream  = file->GetStream();
    bmp.LoadFile(*stream, wxBITMAP_TYPE_BMP);
    delete file;
    if ( bmp.IsOk() )
    {
        bmp.SetMaskFromImage(mask_bmp, 0, 0, 0);
        bmp.Rescale(16,16);
        m_image_list->Add(wxBitmap(bmp));
    }

    delete fileSystem;

}

bool LoginDialog::VerifyPassword()
{
    const int nSelected = ctlOperators->GetCurrentSelection();
    if ( nSelected < 0 )
        return false;
    return theOperator().Login(ctlOperators->GetString(nSelected).ToUTF8(),
                               ctlPassword->GetValue().ToUTF8());
}

void LoginDialog::OnInit(wxInitDialogEvent& event)
{
    event.Skip();
    ctlOperators->Clear();
    CppSQLite3Table tbl = theOperator().GetOperators();
    for(int i=0; i<tbl.numRows(); ++i)
    {
        tbl.setRow(i);
        const int right_mask = tbl.getIntField(1);
        const wxString operator_name = wxString::FromUTF8(tbl.fieldValue(0));
        if (        right_mask & maskParameterDef )
        {
            ctlOperators->Append(operator_name, m_image_list->GetBitmap(2));
        }else if (  right_mask & maskGuestsDef )
        {
            ctlOperators->Append(operator_name, m_image_list->GetBitmap(1));
        }else
        {
            ctlOperators->Append(operator_name, m_image_list->GetBitmap(0));
        }
    }
}

void LoginDialog::OnButtonShutdown(wxCommandEvent& event)
{
    EndModal(wxID_NO);
}

void LoginDialog::OnNavigate(wxCommandEvent& event)
{
    DoNavigate(wxNavigationKeyEvent::IsForward | wxNavigationKeyEvent::FromTab);
}

void LoginDialog::InitButtonBitmap()
{
#ifdef __WXGTK__
    wxButton* btn = (wxButton*)FindWindow(wxID_NO);
    wxBitmap bmp = wxArtProvider::GetBitmap(wxART_QUIT);
    btn->SetBitmap(bmp);
    Fit();
#endif
}
