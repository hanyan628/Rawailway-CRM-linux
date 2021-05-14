#include "crmRightDefDialog.h"

//(*InternalHeaders(crmRightDefDialog)
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

BEGIN_EVENT_TABLE(crmRightDefDialog,crmEditDataDialog)
    //(*EventTable(crmRightDefDialog)
    //*)
END_EVENT_TABLE()

crmRightDefDialog::crmRightDefDialog(wxWindow* parent)
{
    //(*Initialize(crmRightDefDialog)
    wxXmlResource::Get()->LoadObject(this, parent, _T("crmRightDefDialog"), _T("wxDialog"));
    ctlID = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_RIGHTID"));
    ctlModuleName = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_RIGHTNAME"));
    ctlRightMask = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_RIGHTMASK"));
    //*)
}

crmRightDefDialog::~crmRightDefDialog()
{
    //(*Destroy(crmRightDefDialog)
    //*)
}

void crmRightDefDialog::SetDataObject(crmObject* pObj)
{
    m_data = static_cast<strucRight*>(pObj);
}

bool crmRightDefDialog::TransferDataFromWindow()
{
    m_data->module_name = ctlModuleName->GetValue().ToUTF8();
    m_data->right_mask = atoi( ctlRightMask->GetValue().c_str() );
    return true;
}


bool crmRightDefDialog::TransferDataToWindow()
{
    ctlID           ->SetValue( wxString::Format("%d", m_data->id) );
    ctlModuleName   ->SetValue( wxString::FromUTF8( m_data->module_name.c_str() ) );
    ctlRightMask    ->SetValue( wxString::Format("%d", m_data->right_mask) );
    return true;
}
