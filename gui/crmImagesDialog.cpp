#include "crmImagesDialog.h"
#include "../src/parameter.h"
#include "../src/crmFileInfo.h"
//(*InternalHeaders(crmImagesDialog)
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/mstream.h>
#include <wx/stattext.h>
//*)

//(*IdInit(crmImagesDialog)
//*)

BEGIN_EVENT_TABLE(crmImagesDialog,wxDialog)
    EVT_INIT_DIALOG(crmImagesDialog::OnInit)
END_EVENT_TABLE()

crmImagesDialog::crmImagesDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    wxXmlResource::Get()->LoadObject(this,parent,_T("crmImagesDialog"),_T("wxDialog"));
    ctlImagesWindow = (wxScrolledWindow*)FindWindow(XRCID("ID_SCROLLEDWINDOW_IMAGES"));
    m_screen_height = atoi(theParameter().Get("application","max_screen_height"));
    setLargeImage();
    m_selected_label= wxT("默认");
    m_isPresetImage = false;
    ctlImagesWindow->Connect(XRCID("ID_SCROLLEDWINDOW_IMAGES"), wxEVT_KEY_DOWN,
                             (wxObjectEventFunction)&crmImagesDialog::OnKeyDown);
}

crmImagesDialog::~crmImagesDialog()
{
    //(*Destroy(crmImagesDialog)
    //*)
}

void crmImagesDialog::CreateImages()
{
    wxGridSizer* gridSizer = new wxGridSizer(0, m_cols, 0, 0);
    for(int i=0; i<m_table.numRows(); ++i)
    {
        m_table.setRow(i);
        wxBoxSizer* sizer = new wxBoxSizer(m_isLargeImage ? wxVERTICAL : wxHORIZONTAL);
        //new bitmap button
        const int button_id = wxNewId();
        wxBitmapButton* btnNew = new wxBitmapButton(ctlImagesWindow, button_id, wxNullBitmap);
        Connect(button_id,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&crmImagesDialog::OnButtonClick);
        btnNew->Connect(button_id,wxEVT_ENTER_WINDOW,(wxObjectEventFunction)&crmImagesDialog::OnMouseEnter);

        try
        {
            int id = m_table.getIntField(1);
            if ( m_isPresetImage && id == 1 )
            {
                id = m_preset_current_id;
                m_preset_current_id++;
                if ( m_preset_current_id > m_preset_end_id )
                {
                    m_preset_current_id = m_preset_start_id;
                }
            }
            strucImage* pObj = (strucImage*)m_dsImages.getData(id);
            SetBitmap(btnNew, pObj);
        }
        catch(CppSQLite3Exception e)
        {
            wxLogError(wxString::FromUTF8(e.errorMessage()));
        }

        wxString caption = wxString::FromUTF8(m_table.fieldValue(0));
        btnNew->SetLabel(caption);
        sizer->Add(btnNew, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

        //new static text
        wxStaticText* newLabel = new wxStaticText(ctlImagesWindow, wxID_ANY, caption);
        sizer->Add(newLabel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
        gridSizer->Add(sizer, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    }
    ctlImagesWindow->SetSizerAndFit(gridSizer);
    //gridSizer->Fit(ctlImagesWindow);
    //gridSizer->SetSizeHints(ctlImagesWindow);

    //scroll window resize
    //wxSize size = ctlImagesWindow->GetSize();
    wxSize size = GetBestSize();
    if ( size.GetHeight() > m_screen_height )
    {
        SetClientSize(wxSize(size.GetWidth()+50, m_screen_height));
        ctlImagesWindow->SetScrollRate(20,20);
        ctlImagesWindow->FitInside();
    }
    else
    {
        Fit();
    }
    Center();
}

void crmImagesDialog::SetBitmap(wxBitmapButton* ctlBitmap, strucImage* bmp)
{
    if (!bmp)
    {
        ctlBitmap->SetBitmapLabel(wxArtProvider::GetBitmap(wxART_HELP));
        return;
    }

    wxMemoryInputStream stream((const char*)bmp->GetImageBody(), bmp->image_size);
    wxImage img(stream, crmFileInfo::getImageType(bmp->image_type));
    wxBitmap bmpBuf(img.IsOk() ? img.Scale(m_image_width, m_image_height) : wxArtProvider::GetBitmap(wxART_HELP));
    //bmpBuf = wxBitmap(img.Scale(m_image_width, m_image_height));
    ctlBitmap->SetBitmapLabel(bmpBuf);
}

void crmImagesDialog::OnInit(wxInitDialogEvent& event)
{
    ClearAll();
    CreateImages();
    event.Skip();
}

void crmImagesDialog::setLargeImage()
{
    m_isPresetImage     = false;
    m_isLargeImage      = true;
    m_image_height      = atoi(theParameter().Get("logo_image","large_height"));
    m_image_width       = atoi(theParameter().Get("logo_image","large_width"));
    m_cols              = atoi(theParameter().Get("logo_image","large_cols"));
}

void crmImagesDialog::setSmallImage()
{
    m_isPresetImage     = false;
    m_isLargeImage      = false;
    m_image_height      = atoi(theParameter().Get("logo_image","small_height"));
    m_image_width       = atoi(theParameter().Get("logo_image","small_width"));
    m_cols              = atoi(theParameter().Get("logo_image","small_cols"));
}

void crmImagesDialog::OnButtonClick(wxCommandEvent& event)
{
    int button_id       = event.GetId();
    wxBitmapButton* btn = (wxBitmapButton*)wxWindow::FindWindowById(button_id,this);
    if (btn)
    {
        m_selected_label    = btn->GetLabel();
        m_isPresetImage     = false;
        EndModal(wxID_OK);
    }
}

const wxString crmImagesDialog::getSelectLabel()
{
    return m_selected_label;
}

bool crmImagesDialog::IsOK()
{
    return m_table.numRows()>0;
}

void crmImagesDialog::setFilter(const wxString group, const wxString user)
{
    m_table.finalize();
    crmGuestDef dsGuest;
    CppSQLite3Buffer szSQL;
    if ( group.Length() == 0 && user.Length() == 0 )
    {
        szSQL.format("SELECT group_name, %s FROM crm_guest_def WHERE "
                     "user_name='-' AND card_name='-';",
                     m_isLargeImage ? "image_l_id" : "image_s_id");
        m_table = *(dsGuest.GetTable(szSQL));
    }
    else if ( user.Length() == 0 )
    {
        szSQL.format("SELECT user_name, %s FROM crm_guest_def "
                     "WHERE group_name = %Q AND user_name <> '-' AND card_name ='-' "
                     "ORDER BY user_name;",
                     m_isLargeImage ? "image_l_id" : "image_s_id",
                     (const char*)group.ToUTF8());
        m_table = *(dsGuest.GetTable(szSQL));
    }
    else
    {
        szSQL.format("SELECT DISTINCT card_name, %s FROM crm_guest_def "
                     "WHERE group_name = %Q AND user_name = %Q and card_name<>'-'"
                     "ORDER BY card_name;",
                     m_isLargeImage ? "image_l_id" : "image_s_id",
                     (const char*)group.ToUTF8(),
                     (const char*)user.ToUTF8());
        m_table = *(dsGuest.GetTable(szSQL));
    }
}

void crmImagesDialog::ClearAll()
{
    wxWindowList lstWin = ctlImagesWindow->GetChildren();

    for(wxWindowList::iterator it=lstWin.begin(); it!=lstWin.end(); ++it)
    {
        wxWindow* pWin = *it;
        if (pWin)
            delete pWin;
    }

    //Fit();
}

void crmImagesDialog::setPresetImage()
{
    m_preset_start_id   = atoi(theParameter().Get("application","preset_image_start_id"));
    m_preset_end_id     = atoi(theParameter().Get("application","preset_image_end_id"));
    m_preset_current_id = m_preset_start_id;
    m_isPresetImage     = true;
}

/*
void crmImagesDialog::OnMouseLeave(wxMouseEvent& event)
{
    int button_id = event.GetId();
    wxBitmapButton* btn = (wxBitmapButton*)wxWindow::FindWindowById(button_id,this);
    if (btn)
    {

    }
    event.Skip();
}
*/

void crmImagesDialog::OnMouseEnter(wxMouseEvent& event)
{
    int button_id       = event.GetId();
    wxBitmapButton* btn = (wxBitmapButton*)wxWindow::FindWindowById(button_id,this);
    if (btn)
    {
        btn->SetFocus();
    }
    event.Skip();
}

void crmImagesDialog::OnKeyDown(wxKeyEvent& event)
{
    if ( event.GetKeyCode() == WXK_UP || event.GetKeyCode() == WXK_LEFT )
    {
        DoNavigate(wxNavigationKeyEvent::IsBackward | wxNavigationKeyEvent::FromTab);
    }
    if ( event.GetKeyCode() == WXK_DOWN || event.GetKeyCode() == WXK_RIGHT )
    {
        DoNavigate(wxNavigationKeyEvent::IsForward | wxNavigationKeyEvent::FromTab);
    }
    event.Skip();
}
