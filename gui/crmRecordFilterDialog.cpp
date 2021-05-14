#include "crmRecordFilterDialog.h"
//(*InternalHeaders(crmRecordFilterDialog)
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/msgdlg.h>
//*)

//(*IdInit(crmRecordFilterDialog)
//*)

BEGIN_EVENT_TABLE(crmRecordFilterDialog,wxDialog)
    //(*EventTable(crmRecordFilterDialog)
    EVT_INIT_DIALOG(crmRecordFilterDialog::OnInit)
    EVT_BUTTON(XRCID("ID_BUTTON_RESET"),crmRecordFilterDialog::OnbtnResetClick)
    EVT_COMMAND(XRCID("ID_COMBOBOX_OPERATOR"), wxEVT_COMMAND_COMBOBOX_DROPDOWN,
                crmRecordFilterDialog::OnctlOperatorNameDropDown)
    EVT_COMMAND(XRCID("ID_COMBOBOX_GROUP"), wxEVT_COMMAND_COMBOBOX_DROPDOWN,
                crmRecordFilterDialog::OnctlGroupNameDropDown)
    EVT_COMMAND(XRCID("ID_COMBOBOX_USER"), wxEVT_COMMAND_COMBOBOX_DROPDOWN,
                crmRecordFilterDialog::OnctlUserNameDropDown)
    EVT_COMMAND(XRCID("ID_COMBOBOX_CARD"), wxEVT_COMMAND_COMBOBOX_DROPDOWN,
                crmRecordFilterDialog::OnctlCardNameDropDown)
    EVT_COMMAND(XRCID("ID_COMBOBOX_GROUP"), wxEVT_COMMAND_COMBOBOX_SELECTED,
                crmRecordFilterDialog::OnctlGroupNameSelect)
    EVT_COMMAND(XRCID("ID_COMBOBOX_USER"), wxEVT_COMMAND_COMBOBOX_SELECTED,
                crmRecordFilterDialog::OnctlUserNameSelect)
    //*)
END_EVENT_TABLE()

crmRecordFilterDialog::crmRecordFilterDialog(wxWindow* parent)
{
    //(*Initialize(crmRecordFilterDialog)
    wxXmlResource::Get()->LoadObject(this,parent,_T("crmRecordFilterDialog"),_T("wxDialog"));

    ctlStartStatisticsDate  = (wxDatePickerCtrl*)FindWindow(XRCID("ID_DATEPICKERCTRL1"));
    ctlEndStatisticsDate    = (wxDatePickerCtrl*)FindWindow(XRCID("ID_DATEPICKERCTRL2"));
    ctlOperatorName         = (wxComboBox*)FindWindow(XRCID("ID_COMBOBOX_OPERATOR"));
    ctlGroupName            = (wxComboBox*)FindWindow(XRCID("ID_COMBOBOX_GROUP"));
    ctlUserName             = (wxComboBox*)FindWindow(XRCID("ID_COMBOBOX_USER"));
    ctlCardName             = (wxComboBox*)FindWindow(XRCID("ID_COMBOBOX_CARD"));
    //*)

    szOperatorName          = _("ALL");
    szGroupName             = _("ALL");
    szUserName              = _("ALL");
    szCardName              = _("ALL");
    wxDateTime dt           = wxDateTime::Now();
    szStartStatisticsDate   = dt.FormatISODate();
    szEndStatisticsDate     = dt.FormatISODate();
    m_isfilter              = false;

    ctlOperatorName ->AppendString(szOperatorName);
    ctlGroupName    ->AppendString(szGroupName);
    ctlUserName     ->AppendString(szUserName);
    ctlCardName     ->AppendString(szCardName);
}

crmRecordFilterDialog::~crmRecordFilterDialog()
{
    //(*Destroy(crmRecordFilterDialog)
    //*)
}


void crmRecordFilterDialog::OnInit(wxInitDialogEvent& event)
{
    m_isfilter = false;
    m_sql_filter.clear();
    Center();
    event.Skip();
}

void crmRecordFilterDialog::OnbtnResetClick(wxCommandEvent& event)
{
    TransferDataToWindow();
}

void crmRecordFilterDialog::OnctlOperatorNameDropDown(wxCommandEvent& event)
{
    initListOperator();
}

void crmRecordFilterDialog::OnctlGroupNameDropDown(wxCommandEvent& event)
{
    initListGroup();
}

void crmRecordFilterDialog::OnctlUserNameDropDown(wxCommandEvent& event)
{
    initListUser(ctlGroupName->GetValue().ToUTF8());
}

void crmRecordFilterDialog::OnctlCardNameDropDown(wxCommandEvent& event)
{
    initListCard(ctlGroupName->GetValue().ToUTF8(),
                 ctlUserName->GetValue().ToUTF8());
}

void crmRecordFilterDialog::initListGroup()
{
    wxString szGroup = ctlGroupName->GetValue();
    ctlGroupName->Clear();
    ctlGroupName->SetValue(szGroup);
    ctlGroupName->AppendString(_("ALL"));

    CppSQLite3Table* tbl =
        m_dsRecord.GetTable("SELECT DISTINCT group_name FROM crm_welcome_record ORDER BY group_name;");
    for(int i=0; i<tbl->numRows(); ++i)
    {
        tbl->setRow(i);
        ctlGroupName->AppendString(wxString::FromUTF8(tbl->fieldValue(0)));
    }
    tbl->finalize();
}

void crmRecordFilterDialog::initListUser(const char* szGroup)
{
    wxString szUser = ctlUserName->GetValue();
    ctlUserName->Clear();
    ctlUserName->SetValue(szUser);
    ctlUserName->AppendString(_("ALL"));

    CppSQLite3Buffer szSQL;
    szSQL.format("SELECT DISTINCT user_name FROM crm_welcome_record "
                 "WHERE group_name=%Q AND statistics_date BETWEEN %Q AND %Q "
                 "ORDER BY user_name;",
                 szGroup,
                 (const char*)ctlStartStatisticsDate->GetValue().FormatISODate().ToUTF8(),
                 (const char*)ctlEndStatisticsDate->GetValue().FormatISODate().ToUTF8());
    CppSQLite3Table* tbl = m_dsRecord.GetTable(szSQL);
    for(int i=0; i<tbl->numRows(); ++i)
    {
        tbl->setRow(i);
        ctlUserName->AppendString(wxString::FromUTF8(tbl->fieldValue(0)));
    }
    tbl->finalize();
}

void crmRecordFilterDialog::initListCard(const char* szGroup, const char* szUser)
{
    wxString szCard = ctlCardName->GetValue();
    ctlCardName->Clear();
    ctlCardName->SetValue(szCard);
    ctlCardName->AppendString(_("ALL"));

    CppSQLite3Buffer szSQL;
    szSQL.format("SELECT DISTINCT card_name FROM crm_welcome_record "
                 "WHERE group_name=%Q AND user_name=%Q AND statistics_date BETWEEN %Q AND %Q "
                 "ORDER BY card_name;",
                 szGroup, szUser,
                 (const char*)ctlStartStatisticsDate->GetValue().FormatISODate().ToUTF8(),
                 (const char*)ctlEndStatisticsDate->GetValue().FormatISODate().ToUTF8());
    CppSQLite3Table* tbl = m_dsRecord.GetTable(szSQL);
    for(int i=0; i<tbl->numRows(); ++i)
    {
        tbl->setRow(i);
        ctlCardName->AppendString(wxString::FromUTF8(tbl->fieldValue(0)));
    }
    tbl->finalize();
}

void crmRecordFilterDialog::initListOperator()
{
    wxString szOperator = ctlOperatorName->GetValue();
    ctlOperatorName->Clear();
    ctlOperatorName->SetValue(szOperator);
    ctlOperatorName->AppendString(_("ALL"));
    CppSQLite3Buffer szSQL;
    szSQL.format("SELECT DISTINCT operator_name FROM crm_welcome_record "
                 "WHERE statistics_date BETWEEN %Q AND %Q "
                 "ORDER BY operator_name;",
                 (const char*)ctlStartStatisticsDate->GetValue().FormatISODate().ToUTF8(),
                 (const char*)ctlEndStatisticsDate->GetValue().FormatISODate().ToUTF8());
    CppSQLite3Table* tbl =
        m_dsRecord.GetTable(szSQL);
    for(int i=0; i<tbl->numRows(); ++i)
    {
        tbl->setRow(i);
        ctlOperatorName->AppendString(wxString::FromUTF8(tbl->fieldValue(0)));
    }
    tbl->finalize();
}

bool crmRecordFilterDialog::TransferDataFromWindow()
{
    wxDateTime dt;
    dt                      = ctlStartStatisticsDate->GetValue();
    szStartStatisticsDate   = dt.FormatISODate();
    dt                      = ctlEndStatisticsDate->GetValue();
    szEndStatisticsDate     = dt.FormatISODate();
    szOperatorName          = ctlOperatorName->GetValue();
    szGroupName             = ctlGroupName->GetValue();
    szUserName              = ctlUserName->GetValue();
    szCardName              = ctlCardName->GetValue();
    m_isfilter              = true;
    return true;
}

bool crmRecordFilterDialog::TransferDataToWindow()
{
    wxDateTime dt;
    dt.ParseISODate(szStartStatisticsDate);
    ctlStartStatisticsDate->SetValue(dt);

    dt.ParseISODate(szEndStatisticsDate);
    ctlEndStatisticsDate->SetValue(dt);

    ctlOperatorName ->SetValue(szOperatorName);
    ctlGroupName    ->SetValue(szGroupName);
    ctlUserName     ->SetValue(szUserName);
    ctlCardName     ->SetValue(szCardName);
    return true;
}

const char* crmRecordFilterDialog::getFilter()
{
    wxString szBuf = wxString::Format(wxT(" statistics_date BETWEEN '%s' AND '%s'"),
                                      szStartStatisticsDate, szEndStatisticsDate);

    if ( !ctlOperatorName->GetValue().IsSameAs(_("ALL")) )
    {
        szBuf += wxString::Format(wxT(" AND operator_name='%s'"),
                                  ctlOperatorName->GetValue());
    }

    if ( !ctlGroupName->GetValue().IsSameAs(_("ALL")) )
    {
        szBuf += wxString::Format(wxT(" AND group_name='%s'"),
                                  ctlGroupName->GetValue());
    }

    if ( !ctlUserName->GetValue().IsSameAs(_("ALL")) )
    {
        szBuf += wxString::Format(wxT(" AND user_name='%s'"),
                                  ctlUserName->GetValue());
    }

    if ( !ctlCardName->GetValue().IsSameAs(_("ALL")) )
    {
        szBuf += wxString::Format(wxT(" AND card_name='%s'"),
                                  ctlCardName->GetValue());
    }

    m_sql_filter.clear();
    m_sql_filter.format("%s",(const char*)szBuf.ToUTF8());
    return m_sql_filter;
}

void crmRecordFilterDialog::OnctlGroupNameSelect(wxCommandEvent& event)
{
    ctlUserName->SetValue(_("ALL"));
    ctlCardName->SetValue(_("ALL"));
    event.Skip();
}


void crmRecordFilterDialog::OnctlUserNameSelect(wxCommandEvent& event)
{
    ctlCardName->SetValue(_("ALL"));
    event.Skip();
}

bool crmRecordFilterDialog::IsFilter()
{
    return m_isfilter;
}
