#include "crmImageDefDialog.h"
#include "./crmvalidator.h"
#include "../src/crmFileInfo.h"
#include <fstream>
#include <wx/notifmsg.h>

//(*InternalHeaders(crmImageDefDialog)
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/mstream.h>
#include <wx/filedlg.h>
#include <wx/filename.h>
#include <wx/wfstream.h>
//*)

BEGIN_EVENT_TABLE(crmImageDefDialog,wxDialog)
    //(*EventTable(crmImageDefDialog)
    EVT_BUTTON(XRCID("ID_BUTTON_LOAD"),     crmImageDefDialog::OnButtonLoadImage)
    EVT_BUTTON(XRCID("ID_BUTTON_SAVE"),     crmImageDefDialog::OnButtonSaveImage)
    EVT_BUTTON(XRCID("ID_BUTTON_RESET"),    crmImageDefDialog::OnButtonReset)
    //*)
END_EVENT_TABLE()

crmImageDefDialog::crmImageDefDialog(wxWindow* parent)
{
    //(*Initialize(crmImageDefDialog)
    wxXmlResource::Get()->LoadObject(this, parent, _T("crmImageDefDialog"), _T("wxDialog"));
    ctlID           = (wxTextCtrl*)     FindWindow(XRCID("ID_TEXTCTRL_ID"));
    ctlImageSize    = (wxTextCtrl*)     FindWindow(XRCID("ID_TEXTCTRL_SIZE"));
    ctlImageName    = (wxTextCtrl*)     FindWindow(XRCID("ID_TEXTCTRL_NAME"));
    ctlImageType    = (wxTextCtrl*)     FindWindow(XRCID("ID_TEXTCTRL_TYPE"));
    ctlBitmap       = (wxStaticBitmap*) FindWindow(XRCID("ID_STATICBITMAP1"));
    //*)
}

crmImageDefDialog::~crmImageDefDialog()
{
    //(*Destroy(crmImageDefDialog)
    //*)
}

void crmImageDefDialog::SetDataObject(crmObject* pObj)
{
    m_data = static_cast<strucImage*>(pObj);

    ctlID       ->SetValidator(crmValidator(crmFILTER_NUMERIC,  &m_data->id));
    ctlImageName->SetValidator(crmValidator(crmFILTER_EMPTY,    &m_data->comment));
    ctlImageType->SetValidator(crmValidator(crmFILTER_EMPTY,    &m_data->image_type));
    ctlImageSize->SetValidator(crmValidator(crmFILTER_NUMERIC,  &m_data->image_size));
}

bool crmImageDefDialog::TransferDataToWindow()
{
    showImage();
    return wxDialog::TransferDataToWindow();
}

void crmImageDefDialog::showImage()
{
    if ( !m_data )
        return;
    if ( m_data->image_size<=0 )
        return;

    crmFileInfo fileInfo(wxString::Format(wxT("1.%s"), m_data->image_type.c_str()));
    wxMemoryInputStream stream((const char*)m_data->GetImageBody(), m_data->image_size);
    wxImage bmp(stream, fileInfo.GetImageType());
    if ( bmp.IsOk() )
    {
        ctlBitmap->SetBitmap(wxBitmap(bmp));
    }

    Fit();
    Center();
}

void crmImageDefDialog::loadFile(wxString szFile)
{
    crmFileInfo fileInfo(szFile);
    wxBitmap    bmp(szFile, fileInfo.GetImageType());

    ctlBitmap   ->SetBitmap(bmp);
    ctlImageSize->SetValue(wxString::Format("%d", fileInfo.GetSize()));
    ctlImageName->SetValue(fileInfo.GetName());
    ctlImageType->SetValue(fileInfo.GetExt().MakeLower());

    wxFileInputStream stream(szFile);
    unsigned char* buffer = new unsigned char[fileInfo.GetSize()];
    stream.Read(buffer, fileInfo.GetSize());
    m_data->SetImageBody(buffer, fileInfo.GetSize());
    delete [] buffer;
    Fit();
    Center();
}

void crmImageDefDialog::saveFile(wxString szFile, const unsigned char* pBuf /* = NULL */ )
{
    wxBitmap bmp;
    if (!pBuf)
    {
        bmp = ctlBitmap->GetBitmap();
        bmp.SaveFile(szFile, crmFileInfo(szFile).GetImageType());
        return;
    }
    std::ofstream of(szFile.c_str(), std::ios::binary | std::ios::trunc);
    //of.write((char*)pBuf, sizeof(pBuf)+1);
    //unsigned char c;
    for(int i=0; i<m_data->image_size; ++i)
    {
        of.put((char)pBuf[i]);
    }
    of.close();
}

void crmImageDefDialog::OnButtonLoadImage(wxCommandEvent& event)
{
    wxString caption        = _("Choose an bitmap file");
    wxString wildcard       =	wxT("Image files (*.*)|*.*");
    wxString defaultDir     = wxT("./");
    wxString defaultFilename= wxEmptyString;
    wxFileDialog dialog(this, caption, defaultDir,
                        defaultFilename, wildcard, wxFD_OPEN);
    if (dialog.ShowModal() == wxID_OK)
    {
        wxString path = dialog.GetPath();
        loadFile(path);
    }
}


void crmImageDefDialog::OnButtonSaveImage(wxCommandEvent& event)
{
    wxString caption            = _("Choose an image file (the file's ext must be true)");
    wxString wildcard           =	wxT("Image files (*.*)|*.*");
    wxString defaultDir         = wxT("./");
    wxString defaultFilename    = wxEmptyString;
    wxFileDialog dialog(this, caption, defaultDir,
                        defaultFilename, wildcard, wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
    if (dialog.ShowModal() == wxID_OK)
    {
        wxString path = dialog.GetPath();
        saveFile(path);
    }
}

void crmImageDefDialog::OnButtonReset(wxCommandEvent& event)
{
    TransferDataToWindow();
}
