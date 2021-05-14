#include "crmTrainDefDialog.h"
#include "./crmvalidator.h"
//(*InternalHeaders(crmTrainDefDialog)
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

BEGIN_EVENT_TABLE(crmTrainDefDialog,wxDialog)
    //(*EventTable(crmTrainDefDialog)
    EVT_BUTTON(XRCID("ID_BUTTON_RESET"), crmTrainDefDialog::OnButtonReset)
    //*)
END_EVENT_TABLE()

crmTrainDefDialog::crmTrainDefDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(crmTrainDefDialog)
    wxXmlResource::Get()->LoadObject(this,parent,_T("crmTrainDefDialog"),_T("wxDialog"));

    ctlTrainCode        = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_TRAIN"));
    ctlStartStationName = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_STARTSTATION"));
    ctlEndStationName   = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_ENDSTATION"));
    ctlStartTime        = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_TIME"));
    //*)
}

crmTrainDefDialog::~crmTrainDefDialog()
{
    //(*Destroy(crmTrainDefDialog)
    //*)
}

void crmTrainDefDialog::SetDataObject(crmObject* pObj)
{
    m_data = static_cast<strucTrain*>(pObj);

    ctlTrainCode        ->SetValidator(crmValidator(crmFILTER_TRAININFO,    &m_data->train_code));
    ctlStartStationName ->SetValidator(crmValidator(crmFILTER_EMPTY,        &m_data->start_station_name));
    ctlEndStationName   ->SetValidator(crmValidator(crmFILTER_EMPTY,        &m_data->end_station_name));
    ctlStartTime        ->SetValidator(crmValidator(crmFILTER_TIME,         &m_data->start_time));
}

void crmTrainDefDialog::OnButtonReset(wxCommandEvent& event)
{
    TransferDataToWindow();
}
