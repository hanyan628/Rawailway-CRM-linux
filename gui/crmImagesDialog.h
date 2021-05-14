#ifndef CRMIMAGESDIALOG_H
#define CRMIMAGESDIALOG_H
#include "../datamodule/crm_dataset.h"
//(*Headers(crmImagesDialog)
#include <wx/bmpbuttn.h>
#include <wx/xrc/xmlres.h>
#include <wx/scrolwin.h>
#include <wx/dialog.h>
#include <wx/hashmap.h>
#include <wx/log.h>
//*)
using namespace std;

class crmImagesDialog: public wxDialog
{
    //-----------------------------------------------------------------
    //               My Progrman
    //-----------------------------------------------------------------
public:
    void            setLargeImage();
    void            setSmallImage();
    void            setPresetImage();
    void            setFilter(const wxString group = wxT(""), const wxString user = wxT(""));
    bool            IsOK();
    const wxString  getSelectLabel();

private:
    CppSQLite3Table     m_table;
    crmImageDef         m_dsImages;
    bool                m_isLargeImage;
    bool                m_isPresetImage;
    int                 m_preset_start_id;
    int                 m_preset_end_id;
    int                 m_preset_current_id;
    int                 m_image_width;
    int                 m_image_height;
    int                 m_screen_height;
    int                 m_cols;
    wxString            m_selected_label;

    void CreateImages();
    void SetBitmap(wxBitmapButton* ctlBitmap, strucImage* bmp);
    void OnButtonClick(wxCommandEvent& event);
    void ClearAll();

    void DoNavigate(const int flags)
    {
        if ( !this->NavigateIn(flags) )
        {
            wxLogError(wxT("Navigation event ignored"));
        }
    };
    //-----------------------------------------------------------------
public:

    crmImagesDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~crmImagesDialog();

    //(*Declarations(crmImagesDialog)
    wxScrolledWindow* ctlImagesWindow;
    //*)

protected:

    //(*Identifiers(crmImagesDialog)
    //*)

private:

    //(*Handlers(crmImagesDialog)
    //*)
    void OnInit         (wxInitDialogEvent& event);
    void OnMouseEnter   (wxMouseEvent&      event);
    void OnKeyDown      (wxKeyEvent&        event);
    DECLARE_EVENT_TABLE()
};

#endif
