#include "crmRecordModifyDialog.h"
#include "./crmvalidator.h"
//(*InternalHeaders(crmRecordModifyDialog)
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(crmRecordModifyDialog)
//*)

BEGIN_EVENT_TABLE(crmRecordModifyDialog,crmEditDataDialog)
    //(*EventTable(crmRecordModifyDialog)
    EVT_INIT_DIALOG(crmRecordModifyDialog::OnInit)
    EVT_BUTTON (XRCID("ID_BUTTON_RESET"),crmRecordModifyDialog::OnbtnResetClick)
    EVT_COMMAND(XRCID("ID_COMBOBOX_GROUP"),wxEVT_COMMAND_COMBOBOX_DROPDOWN,
                crmRecordModifyDialog::OnctlGroupNameDropDown)
    EVT_COMMAND(XRCID("ID_COMBOBOX_USER"),wxEVT_COMMAND_COMBOBOX_DROPDOWN,
                crmRecordModifyDialog::OnctlUserNameDropDown)
    EVT_COMMAND(XRCID("ID_COMBOBOX_CARD"),wxEVT_COMMAND_COMBOBOX_DROPDOWN,
                crmRecordModifyDialog::OnctlCardNameDropDown)
    //*)
END_EVENT_TABLE()

crmRecordModifyDialog::crmRecordModifyDialog(wxWindow* parent)
{
    //(*Initialize(crmRecordModifyDialog)
    wxXmlResource::Get()->LoadObject(this, parent, _T("crmRecordModifyDialog"), _T("wxDialog"));
    ctlOperatorName     = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_OPERATORNAME"));
    ctlStatisticsDate   = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_STATISTICS"));
    ctlRecordTime       = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_RTIME"));
    ctlGroupName        = (wxComboBox*)FindWindow(XRCID("ID_COMBOBOX_GROUP"));
    ctlUserName         = (wxComboBox*)FindWindow(XRCID("ID_COMBOBOX_USER"));
    ctlCardName         = (wxComboBox*)FindWindow(XRCID("ID_COMBOBOX_CARD"));
    ctlCardID           = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_CARDID"));
    ctlPresenceName     = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_PRESENCE"));
    ctlPeopleCount      = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_PEOPLE"));
    ctlTrainDate        = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_TDATE"));
    ctlTrainCode        = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_TRAIN"));
    ctlPrice            = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_PRICE"));
    ctlComment          = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_COMMENT"));
    //*)
    ctlGroupName->AppendString(wxT("-"));
    ctlUserName ->AppendString(wxT("-"));
    ctlCardName ->AppendString(wxT("-"));
}

crmRecordModifyDialog::~crmRecordModifyDialog()
{
    //(*Destroy(crmRecordModifyDialog)
    //*)
}


void crmRecordModifyDialog::OnInit(wxInitDialogEvent& event)
{
//    TransferDataToWindow();
    event.Skip();
}

void crmRecordModifyDialog::OnbtnResetClick(wxCommandEvent& event)
{
    TransferDataToWindow();
}

void crmRecordModifyDialog::SetDataObject(crmObject* pObj)
{
    m_data = static_cast<strucRecord*>(pObj);
    ctlOperatorName     ->SetValidator(crmValidator(crmFILTER_EMPTY,    &m_data->operator_name));
    ctlStatisticsDate   ->SetValidator(crmValidator(crmFILTER_DATE,     &m_data->statistics_date));
    ctlRecordTime       ->SetValidator(crmValidator(crmFILTER_DATETIME, &m_data->record_time));
    ctlGroupName        ->SetValidator(crmValidator(crmFILTER_EMPTY,    &m_data->group_name));
    ctlUserName         ->SetValidator(crmValidator(crmFILTER_EMPTY,    &m_data->user_name));
    ctlCardName         ->SetValidator(crmValidator(crmFILTER_EMPTY,    &m_data->card_name));
    ctlCardID           ->SetValidator(crmValidator(crmFILTER_EMPTY,    &m_data->card_id));
    ctlPresenceName     ->SetValidator(crmValidator(crmFILTER_NONE,     &m_data->presence_name));
    ctlTrainCode        ->SetValidator(crmValidator(crmFILTER_TRAININFO,&m_data->train_code));
    ctlTrainDate        ->SetValidator(crmValidator(crmFILTER_DATE,     &m_data->train_date));
    ctlPeopleCount      ->SetValidator(crmValidator(crmFILTER_NUMERIC,  &m_data->people_count));
    ctlPrice            ->SetValidator(crmValidator(crmFILTER_FLOAT,    &m_data->price));
    ctlComment          ->SetValidator(crmValidator(crmFILTER_NONE,     &m_data->comment));
}

void crmRecordModifyDialog::initListGroup()
{
    CppSQLite3Table* tbl =
        m_dsGuest.GetTable("SELECT DISTINCT group_name FROM crm_guest_def;");
    wxString group_name = ctlGroupName->GetValue();
    ctlGroupName->Clear();
    for(int i=0; i<tbl->numRows(); ++i)
    {
        tbl->setRow(i);
        ctlGroupName->AppendString(wxString::FromUTF8(tbl->fieldValue(0)));
    }
    tbl->finalize();
    ctlGroupName->SetValue(group_name);
}

void crmRecordModifyDialog::initListUser(const char* szGroup)
{
    CppSQLite3Buffer szSQL;
    szSQL.format("SELECT DISTINCT user_name FROM crm_guest_def \
                  WHERE group_name=%Q AND user_name<>'-';", szGroup);
    CppSQLite3Table* tbl = m_dsGuest.GetTable(szSQL);
    wxString user_name = ctlUserName->GetValue();
    ctlUserName->Clear();
    for(int i=0; i<tbl->numRows(); ++i)
    {
        tbl->setRow(i);
        ctlUserName->AppendString(wxString::FromUTF8(tbl->fieldValue(0)));
    }
    tbl->finalize();
    ctlUserName->AppendString(wxT("-"));
    ctlUserName->SetValue(user_name);
}

void crmRecordModifyDialog::initListCard(const char* szGroup, const char* szUser)
{
    CppSQLite3Buffer szSQL;
    szSQL.format("SELECT DISTINCT card_name FROM crm_guest_def \
                  WHERE group_name=%Q AND user_name=%Q AND card_name<>'-';", szGroup, szUser);
    CppSQLite3Table* tbl = m_dsGuest.GetTable(szSQL);
    wxString card_name = ctlCardName->GetValue();
    ctlCardName->Clear();
    for(int i=0; i<tbl->numRows(); ++i)
    {
        tbl->setRow(i);
        ctlCardName->AppendString(wxString::FromUTF8(tbl->fieldValue(0)));
    }
    tbl->finalize();
    ctlCardName->AppendString(wxT("-"));
    ctlCardName->SetValue(card_name);
}

void crmRecordModifyDialog::OnctlGroupNameDropDown(wxCommandEvent& event)
{
    initListGroup();
}

void crmRecordModifyDialog::OnctlUserNameDropDown(wxCommandEvent& event)
{
    initListUser(ctlGroupName->GetValue().ToUTF8());
}

void crmRecordModifyDialog::OnctlCardNameDropDown(wxCommandEvent& event)
{
    initListCard(ctlGroupName->GetValue().ToUTF8(),
                 ctlUserName->GetValue().ToUTF8());
}
