#include "crmImagesSelectDialog.h"
#include "../src/parameter.h"
#include "../src/crmFileInfo.h"
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/mstream.h>
#include <wx/log.h>

//(*InternalHeaders(crmImagesSelectDialog)
#include <wx/xrc/xmlres.h>
//*)

//(*IdInit(crmImagesSelectDialog)
//*)

BEGIN_EVENT_TABLE(crmImagesSelectDialog,wxDialog)
    //(*EventTable(crmImagesSelectDialog)
    EVT_INIT_DIALOG(crmImagesSelectDialog::OnInit)
    //*)
END_EVENT_TABLE()

crmImagesSelectDialog::crmImagesSelectDialog(wxWindow* parent)
{
    //(*Initialize(crmImagesSelectDialog)
    wxXmlResource::Get()->LoadObject(this,parent,_T("crmImagesSelectDialog"),_T("wxDialog"));
    ctlImages = (wxScrolledWindow*)FindWindow(XRCID("ID_SCROLLEDWINDOW_IMAGES"));
    //*)
    m_screen_height = atoi(theParameter().Get("application","max_screen_height"));
    m_selected_id = -1;
    setLargeImage();
}

crmImagesSelectDialog::~crmImagesSelectDialog()
{
    //(*Destroy(crmImagesSelectDialog)
    //*)
}

void crmImagesSelectDialog::setLargeImage()
{
    m_isLargeImage  = true;
    m_image_height  = atoi(theParameter().Get("logo_image","large_height"));
    m_image_width   = atoi(theParameter().Get("logo_image","large_width"));
    m_cols          = atoi(theParameter().Get("logo_image","large_cols"));
}

void crmImagesSelectDialog::setSmallImage()
{
    m_isLargeImage  = false;
    m_image_height  = atoi(theParameter().Get("logo_image","small_height"));
    m_image_width   = atoi(theParameter().Get("logo_image","small_width"));
    m_cols          = atoi(theParameter().Get("logo_image","small_cols"));
}

const int crmImagesSelectDialog::getSelectedID()
{
    return m_selected_id;
}

void crmImagesSelectDialog::OnButtonClick(wxCommandEvent& event)
{
    int button_id = event.GetId();
    wxBitmapButton* btn = (wxBitmapButton*)wxWindow::FindWindowById(button_id,this);
    if (btn)
    {
        m_selected_id = btn->GetLabel().IsNumber() ? atoi(btn->GetLabel().c_str()) : -1;
        EndModal(wxID_OK);
    }
}

void crmImagesSelectDialog::SetBitmap(wxBitmapButton* ctlBitmap, strucImage* bmp)
{
    wxMemoryInputStream stream((const char*)bmp->GetImageBody(), bmp->image_size);
    wxImage img(stream, crmFileInfo::getImageType(bmp->image_type));
    wxBitmap bmpBuf(img.IsOk() ? img.Scale(m_image_width, m_image_height) : wxArtProvider::GetBitmap(wxART_BUTTON));
    ctlBitmap->SetBitmapLabel(bmpBuf);
}

void crmImagesSelectDialog::ClearAll()
{
    wxWindowList lstWin = ctlImages->GetChildren();
    for(wxWindowList::iterator it=lstWin.begin(); it!=lstWin.end(); ++it)
    {
        wxWindow* pWin = *it;
        if (pWin)
            delete pWin;
    }
}

void crmImagesSelectDialog::CreateImages()
{
    CppSQLite3Table tbl = getTable();
    wxGridSizer* gridSizer = new wxGridSizer(0, m_cols, 0, 0);
    for(int i=0; i<tbl.numRows(); ++i)
    {
        tbl.setRow(i);
        wxBoxSizer* sizer = new wxBoxSizer(m_isLargeImage ? wxVERTICAL : wxHORIZONTAL);
        //new bitmap button
        const long button_id = wxNewId();
        wxBitmapButton* btnNew = new wxBitmapButton(ctlImages, button_id, wxNullBitmap);
        Connect(button_id,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&crmImagesSelectDialog::OnButtonClick);

        const int id = tbl.getIntField("id");

        try
        {
            strucImage* pObj = (strucImage*)m_dsImages.getData(id);
            if (pObj)
                SetBitmap(btnNew, pObj);
        }
        catch(CppSQLite3Exception e)
        {
            wxLogError(wxString::FromUTF8(e.errorMessage()));
        }

        wxString caption = wxString::Format(wxT("%d"),id);
        btnNew->SetLabel(caption);
        sizer->Add(btnNew, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
        //new static text
        caption = wxString::Format(wxT("ID:%d, TYPE:%s\n%s"),
                                   id,
                                   tbl.getStringField("image_type"),
                                   wxString::FromUTF8(tbl.getStringField("comment")));
        wxStaticText* newLabel = new wxStaticText(ctlImages, wxID_ANY, caption);
        sizer->Add(newLabel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

        gridSizer->Add(sizer, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    }
    ctlImages->SetSizer(gridSizer);
    gridSizer->Fit(ctlImages);
    gridSizer->SetSizeHints(ctlImages);

    //scroll window resize
    wxSize size = ctlImages->GetSize();
    if ( size.GetHeight() > m_screen_height )
    {
        //ctlImagesWindow->SetVirtualSize(size);
        SetClientSize(wxSize(size.GetWidth()+50, m_screen_height));
        ctlImages->SetScrollRate(20,20);
        ctlImages->FitInside();
        //FitInside();
    }
    else
    {
        Fit();
    }
}

CppSQLite3Table crmImagesSelectDialog::getTable()
{
    CppSQLite3Buffer szSQL;
    szSQL.format("SELECT id,comment,image_type FROM crm_image_def ORDER BY image_size %s;",
                 m_isLargeImage?"DESC":"ASC" );
    return *m_dsImages.GetTable(szSQL);
}

void crmImagesSelectDialog::OnInit(wxInitDialogEvent& event)
{
    ClearAll();
    CreateImages();
    Center();
    event.Skip();
}
