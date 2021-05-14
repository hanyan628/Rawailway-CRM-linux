#include "crmTrainFilterDialog.h"

//(*InternalHeaders(crmTrainFilterDialog)
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(crmTrainFilterDialog)
//*)

BEGIN_EVENT_TABLE(crmTrainFilterDialog,crmFilterDataDialog)
    //(*EventTable(crmTrainFilterDialog)
    EVT_INIT_DIALOG(crmTrainFilterDialog::OnInit)
    EVT_BUTTON(XRCID("ID_BUTTON_RESET"),crmTrainFilterDialog::OnbtnResetClick)
    //*)
END_EVENT_TABLE()

crmTrainFilterDialog::crmTrainFilterDialog(wxWindow* parent)
{
    //(*Initialize(crmTrainFilterDialog)
    wxXmlResource::Get()->LoadObject(this,parent,_T("crmTrainFilterDialog"),_T("wxDialog"));

    ctlStartStationName = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_STARTSTATIONNAME"));
    ctlEndStationName   = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_ENDSTATIONNAME"));
    ctlTrainCode        = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_TRAINCODE"));
    //*)
    szStartStationName  = "";
    szEndStationName    = "";
    szTrainCode         = "";
}

crmTrainFilterDialog::~crmTrainFilterDialog()
{
    //(*Destroy(crmTrainFilterDialog)
    //*)
}


void crmTrainFilterDialog::OnbtnResetClick(wxCommandEvent& event)
{
//    szStartStationName = "";
//    szEndStationName = "";
//    szTrainCode = "";
    TransferDataToWindow();
}

void crmTrainFilterDialog::OnInit(wxInitDialogEvent& event)
{
    m_isfilter = false;
    m_sql_filter.clear();
    event.Skip();
}

bool crmTrainFilterDialog::TransferDataFromWindow()
{
    szStartStationName  = ctlStartStationName->GetValue().Trim();
    szEndStationName    = ctlEndStationName->GetValue().Trim();
    szTrainCode         = ctlTrainCode->GetValue().Trim();
    m_isfilter          = true;
    return true;
}

bool crmTrainFilterDialog::TransferDataToWindow()
{
    ctlStartStationName ->SetValue(szStartStationName);
    ctlEndStationName   ->SetValue(szEndStationName);
    ctlTrainCode        ->SetValue(szTrainCode);
    return true;
}

const char* crmTrainFilterDialog::getFilter()
{
    if ( szTrainCode.Length()>0 )
    {
        m_sql_filter.format("train_code=%Q", (const char*)szTrainCode.ToUTF8());
        return m_sql_filter;
    }

    wxString szSQL = "1=1";
    if ( szStartStationName.Length()>0 )
    {
        szSQL += wxString::Format(wxT(" AND start_station_name='%s'"),
                                  szStartStationName);
    }
    if ( szEndStationName.Length()>0 )
    {
        szSQL += wxString::Format(wxT(" AND end_station_name='%s'"),
                                  szEndStationName);
    }
    m_sql_filter.clear();
    m_sql_filter.format("%s", (const char*)szSQL.ToUTF8());
    return m_sql_filter;
}

bool crmTrainFilterDialog::IsFilter()
{
    return m_isfilter;
}
