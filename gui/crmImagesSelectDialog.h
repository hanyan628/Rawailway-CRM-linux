#ifndef CRMIMAGESSELECTDIALOG_H
#define CRMIMAGESSELECTDIALOG_H
#include <wx/bmpbuttn.h>
#include "../datamodule/crm_dataset.h"
//(*Headers(crmImagesSelectDialog)
#include <wx/scrolwin.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class crmImagesSelectDialog: public wxDialog
{
    //-----------------------------------------------------------------
    //               My Progrman
    //-----------------------------------------------------------------
public:
    const int   getSelectedID();
    void        setLargeImage();
    void        setSmallImage();
private:
    crmImageDef m_dsImages;
    bool        m_isLargeImage;
    int         m_image_width;
    int         m_image_height;
    int         m_screen_height;
    int         m_cols;
    int         m_selected_id;
    void        CreateImages();
    void        SetBitmap(wxBitmapButton* ctlBitmap, strucImage* bmp);
    void        OnButtonClick(wxCommandEvent& event);
    void        ClearAll();
    CppSQLite3Table getTable();
    //-----------------------------------------------------------------

public:

    crmImagesSelectDialog(wxWindow* parent);
    virtual ~crmImagesSelectDialog();

    //(*Declarations(crmImagesSelectDialog)
    wxScrolledWindow* ctlImages;
    //*)

protected:

    //(*Identifiers(crmImagesSelectDialog)
    //*)

private:

    //(*Handlers(crmImagesSelectDialog)
    //*)
    void OnInit(wxInitDialogEvent& event);

    DECLARE_EVENT_TABLE()
};

#endif
