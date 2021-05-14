#ifndef CRMIMAGEDEFDIALOG_H
#define CRMIMAGEDEFDIALOG_H

#include "./crmEditDataDialog.h"

//(*Headers(crmImageDefDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class crmImageDefDialog: public crmEditDataDialog
{
    //---------------------------------------------------------------------------------------
    //          My Progrman
    //---------------------------------------------------------------------------------------
public:
    virtual void SetDataObject(crmObject* pObj) ;
private:
    strucImage*     m_data;

    virtual bool    TransferDataToWindow();
    void            loadFile(wxString szFile);
    void            saveFile(wxString szFile, const unsigned char* pBuf = NULL);
    void            showImage();
    //---------------------------------------------------------------------------------------

public:

    crmImageDefDialog(wxWindow* parent);
    virtual ~crmImageDefDialog();

    //(*Declarations(crmImageDefDialog)
    wxTextCtrl*     ctlImageSize;
    wxTextCtrl*     ctlID;
    wxTextCtrl*     ctlImageName;
    wxTextCtrl*     ctlImageType;
    wxStaticBitmap* ctlBitmap;
    //*)

private:

    //(*Handlers(crmImageDefDialog)
    void OnButtonLoadImage(wxCommandEvent& event);
    void OnButtonSaveImage(wxCommandEvent& event);
    void OnButtonReset(wxCommandEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
