#include "crmOperatorDefDialog.h"
#include "./crmvalidator.h"
#include<wx/msgdlg.h>
//(*InternalHeaders(crmOperatorDefDialog)
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

BEGIN_EVENT_TABLE(crmOperatorDefDialog,crmEditDataDialog)
    //(*EventTable(crmOperatorDefDialog)
    EVT_BUTTON(XRCID("ID_BUTTON_RESET"),crmOperatorDefDialog::OnbtnResetClick)
    //*)
END_EVENT_TABLE()

crmOperatorDefDialog::crmOperatorDefDialog(wxWindow* parent)
{
    //(*Initialize(crmOperatorDefDialog)
    wxXmlResource::Get()->LoadObject(this, parent, _T("crmOperatorDefDialog"), _T("wxDialog"));

    ctlID           = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_ID"));
    ctlOperatorName = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_NAME"));
    ctlPassword     = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_PASSWORD"));
    ctlRights       = (wxCheckListBox*)FindWindow(XRCID("ID_CHECKLISTBOX_RIGHTS"));
    //*)
    createRightList();
}

crmOperatorDefDialog::~crmOperatorDefDialog()
{
    //(*Destroy(crmOperatorDefDialog)
    //*)
}

void crmOperatorDefDialog::SetDataObject(crmObject*  pObj)
{
    m_data = static_cast<strucOperator*>(pObj);
    ctlID           ->SetValidator(crmValidator(crmFILTER_NUMERIC,  &m_data->id));
    ctlOperatorName ->SetValidator(crmValidator(crmFILTER_EMPTY,    &m_data->operator_name));
    ctlPassword     ->SetValidator(crmValidator(crmFILTER_EMPTY,    &m_data->operator_password));
}

bool crmOperatorDefDialog::TransferDataFromWindow()
{
    m_data->operator_right = getRights();
    return wxDialog::TransferDataFromWindow();
}

bool crmOperatorDefDialog::TransferDataToWindow()
{
    loadRights();
    return wxDialog::TransferDataToWindow();
}

void crmOperatorDefDialog::loadRights()
{
    for(unsigned int i = 0; i<ctlRights->GetCount(); ++i)
    {
        ctlRights->Check(i, m_data->operator_right & m_rights_mask[i]);
    }
}

int crmOperatorDefDialog::getRights()
{
    int ret = 0;
    for(unsigned int i = 0; i<ctlRights->GetCount(); ++i)
    {
        if (ctlRights->IsChecked(i))
        {
            ret |= m_rights_mask[i];
        }
    }
    return ret;
}

void crmOperatorDefDialog::OnbtnResetClick(wxCommandEvent& event)
{
    TransferDataToWindow();
}

void crmOperatorDefDialog::createRightList()
{
    m_rights_mask.Clear();

    m_rights_mask.Add(maskWelcomeRecord);
    ctlRights->Append(_("maskWelcomeRecord"));

    m_rights_mask.Add(maskDayAccount);
    ctlRights->Append(_("maskDayAccount"));

    m_rights_mask.Add(maskMonthAccount);
    ctlRights->Append(_("maskMonthAccount"));

    m_rights_mask.Add(maskTrainsDef);
    ctlRights->Append(_("maskTrainsDef"));

    m_rights_mask.Add(maskImageDef);
    ctlRights->Append(_("maskImageDef"));

    m_rights_mask.Add(maskGuestsDef);
    ctlRights->Append(_("maskGuestsDef"));

    m_rights_mask.Add(maskOperatorDef);
    ctlRights->Append(_("maskOperatorDef"));

    m_rights_mask.Add(maskRecordModify);
    ctlRights->Append(_("maskRecordModify"));

    m_rights_mask.Add(maskParameterDef);
    ctlRights->Append(_("maskParameterDef"));
}
