#include "ParameterDefDialog.h"
#include "./InputParameterItemDialog.h"
#include "../src/parameter.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(ParameterDefDialog)
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/xrc/xmlres.h>
#include <wx/settings.h>
//*)

BEGIN_EVENT_TABLE(ParameterDefDialog,wxDialog)
    EVT_INIT_DIALOG(ParameterDefDialog::OnInit)
    EVT_BUTTON(XRCID("ID_BUTTON_DELETE"), ParameterDefDialog::OnbtnDeleteClick)
    EVT_BUTTON(XRCID("ID_BUTTON_INSERT"), ParameterDefDialog::OnbtnInsertClick)
END_EVENT_TABLE()

ParameterDefDialog::ParameterDefDialog(wxWindow* parent)
{
    wxXmlResource::Get()->LoadObject(this,parent,_T("ParameterDefDialog"),_T("wxDialog"));
    ctlParameterView = new wxDataViewCtrl( parent, XRCID("ID_PARAMETER_VIEW"), wxDefaultPosition,
                                           wxDefaultSize, wxDV_HORIZ_RULES );
    wxXmlResource::Get()->AttachUnknownControl(wxT("ID_PARAMETER_VIEW"), ctlParameterView, this);
}

ParameterDefDialog::~ParameterDefDialog()
{
    //(*Destroy(ParameterDefDialog)
    //*)
}


void ParameterDefDialog::OnInit(wxInitDialogEvent& event)
{
    event.Skip();
}

void ParameterDefDialog::OnbtnDeleteClick(wxCommandEvent& event)
{
    wxDataViewItem item = ctlParameterView->GetSelection();
    if (item.IsOk())
        m_parameter_modal->Delete(item);
}

void ParameterDefDialog::OnbtnInsertClick(wxCommandEvent& event)
{
    InputParameterItemDialog dlg(this);
    if ( dlg.ShowModal() == wxID_OK )
    {
        wxDataViewItem item = m_parameter_modal->Add(dlg.getCategory(), dlg.getKey(), dlg.getValue());
        ctlParameterView->Select(item);
    }
}

bool ParameterDefDialog::TransferDataFromWindow()
{
    return SaveParameter();
}

bool ParameterDefDialog::TransferDataToWindow()
{
    theParameter().Save();
    InitParameterView();
    return true;
}

void ParameterDefDialog::InitParameterView()
{
    m_parameter_modal = new ParameterDataModal;
    ctlParameterView->AssociateModel( m_parameter_modal.get() );

    ctlParameterView->ClearColumns();

    // column "category" / "key"
    ctlParameterView->AppendTextColumn(wxString::Format( wxT("%s / %s"), _("category"), _("key") ),
                                       0, wxDATAVIEW_CELL_INERT, 280);

    // column "value"
    wxDataViewTextRenderer* tr = new wxDataViewTextRenderer( "string", wxDATAVIEW_CELL_EDITABLE );
    wxDataViewColumn *column1 = new wxDataViewColumn( _("value"), tr, 1, 300, wxALIGN_LEFT );
    column1->SetMinWidth(300); // this column can't be resized to be smaller
    ctlParameterView->AppendColumn( column1 );

    // expand all item
    ctlParameterView->Expand(m_parameter_modal->GetRootItem());
}

bool ParameterDefDialog::SaveParameter()
{
    if (m_parameter_modal->Save())
    {
        theParameter().Reload();
        return true;
    }
    return false;
}
