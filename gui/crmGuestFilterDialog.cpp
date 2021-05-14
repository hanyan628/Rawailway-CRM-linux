#include "crmGuestFilterDialog.h"

//(*InternalHeaders(crmGuestFilterDialog)
#include <wx/valtext.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(crmGuestFilterDialog)
//*)

BEGIN_EVENT_TABLE(crmGuestFilterDialog,crmFilterDataDialog)
    //(*EventTable(crmGuestFilterDialog)
    EVT_INIT_DIALOG(crmGuestFilterDialog::OnInit)
    EVT_BUTTON(XRCID("ID_BUTTON_RESET"),crmGuestFilterDialog::OnbtnResetClick)
    EVT_COMMAND(XRCID("ID_COMBOBOX_GROUP"),wxEVT_COMMAND_COMBOBOX_SELECTED,
                crmGuestFilterDialog::OnctlGroupNameSelect)
    EVT_COMMAND(XRCID("ID_COMBOBOX_USER"),wxEVT_COMMAND_COMBOBOX_SELECTED,
                crmGuestFilterDialog::OnctlUserNameSelect)
    EVT_COMMAND(XRCID("ID_COMBOBOX_USER"),wxEVT_COMMAND_COMBOBOX_DROPDOWN,
                crmGuestFilterDialog::OnctlUserNameDropDown)
    EVT_COMMAND(XRCID("ID_COMBOBOX_CARD"),wxEVT_COMMAND_COMBOBOX_DROPDOWN,
                crmGuestFilterDialog::OnctlCardNameDropDown)
    //*)
END_EVENT_TABLE()

crmGuestFilterDialog::crmGuestFilterDialog(wxWindow* parent)
{
    //(*Initialize(crmGuestFilterDialog)
    wxXmlResource::Get()->LoadObject(this,parent,_T("crmGuestFilterDialog"),_T("wxDialog"));
    ctlGroupName    = (wxComboBox*)FindWindow(XRCID("ID_COMBOBOX_GROUP"));
    ctlUserName     = (wxComboBox*)FindWindow(XRCID("ID_COMBOBOX_USER"));
    ctlCardName     = (wxComboBox*)FindWindow(XRCID("ID_COMBOBOX_CARD"));
    //*)

    szGroupName     = _("ALL");
    szUserName      = _("ALL");
    szCardName      = _("ALL");
    m_isfilter      = false;
    ctlUserName     ->AppendString(_("ALL"));
    ctlCardName     ->AppendString(_("ALL"));
    ctlGroupName    ->SetValidator(wxTextValidator(wxFILTER_NONE, &szGroupName));
    ctlUserName     ->SetValidator(wxTextValidator(wxFILTER_NONE, &szUserName));
    ctlCardName     ->SetValidator(wxTextValidator(wxFILTER_NONE, &szCardName));
}

crmGuestFilterDialog::~crmGuestFilterDialog()
{
    //(*Destroy(crmGuestFilterDialog)
    //*)
}


void crmGuestFilterDialog::OnbtnResetClick(wxCommandEvent& event)
{
    m_sql_filter.clear();
    TransferDataToWindow();
}

void crmGuestFilterDialog::OnInit(wxInitDialogEvent& event)
{
    m_sql_filter.clear();
    m_isfilter = false;
    initListGroup();
    event.Skip();
}

void crmGuestFilterDialog::OnctlUserNameDropDown(wxCommandEvent& event)
{
    initListUser(ctlGroupName->GetValue().ToUTF8());
    event.Skip();
}

void crmGuestFilterDialog::OnctlCardNameDropDown(wxCommandEvent& event)
{
    initListCard(ctlGroupName->GetValue().ToUTF8(),
                 ctlUserName->GetValue().ToUTF8());
    event.Skip();
}

void crmGuestFilterDialog::OnctlGroupNameSelect(wxCommandEvent& event)
{
    ctlUserName->SetValue(_("ALL"));
    ctlCardName->SetValue(_("ALL"));
    event.Skip();
}

void crmGuestFilterDialog::OnctlUserNameSelect(wxCommandEvent& event)
{
    ctlCardName->SetValue(_("ALL"));
    event.Skip();
}

const char* crmGuestFilterDialog::getFilter()
{
    wxString szSQL = "1=1";
    m_sql_filter.clear();

    if ( !szGroupName.IsSameAs(_("ALL")) )
    {
        szSQL += wxString::Format(wxT(" AND group_name='%s'"), szGroupName);
    }

    if ( !szUserName.IsSameAs(_("ALL")) )
    {
        szSQL += wxString::Format(wxT(" AND user_name='%s'"), szUserName);
    }

    if ( !szCardName.IsSameAs(_("ALL")) )
    {
        szSQL += wxString::Format(wxT(" AND card_name='%s'"), szCardName);
    }

    m_sql_filter.format("%s", (const char*)szSQL.ToUTF8());

    return m_sql_filter;
}

bool crmGuestFilterDialog::IsFilter()
{
    return m_isfilter;
}

void crmGuestFilterDialog::initListGroup()
{
    wxString szGroup = ctlGroupName->GetValue();
    ctlGroupName->Clear();
    ctlGroupName->SetValue(szGroup);
    ctlGroupName->AppendString(_("ALL"));

    CppSQLite3Table* tbl =
        m_dsGuest.GetTable("SELECT DISTINCT group_name FROM crm_guest_def ORDER BY group_name;");
    for(int i=0; i<tbl->numRows(); ++i)
    {
        tbl->setRow(i);
        ctlGroupName->AppendString(wxString::FromUTF8(tbl->fieldValue(0)));
    }
    tbl->finalize();
}

void crmGuestFilterDialog::initListUser(const char* szGroup)
{
    wxString szUser = ctlUserName->GetValue();
    ctlUserName->Clear();
    ctlUserName->SetValue(szUser);
    ctlUserName->AppendString(_("ALL"));

    CppSQLite3Buffer szSQL;
    szSQL.format("SELECT DISTINCT user_name FROM crm_guest_def \
                  WHERE group_name=%Q ORDER BY user_name;",
                 szGroup);
    CppSQLite3Table* tbl = m_dsGuest.GetTable(szSQL);
    for(int i=0; i<tbl->numRows(); ++i)
    {
        tbl->setRow(i);
        ctlUserName->AppendString(wxString::FromUTF8(tbl->fieldValue(0)));
    }
    tbl->finalize();
}

void crmGuestFilterDialog::initListCard(const char* szGroup,
                                        const char* szUser)
{
    wxString szCard = ctlCardName->GetValue();
    ctlCardName->Clear();
    ctlCardName->SetValue(szUser);
    ctlCardName->AppendString(_("ALL"));

    CppSQLite3Buffer szSQL;
    szSQL.format("SELECT DISTINCT card_name FROM crm_guest_def "
                 "WHERE group_name=%Q AND user_name=%Q "
                 "ORDER BY card_name;",
                 szGroup, szUser);
    CppSQLite3Table* tbl = m_dsGuest.GetTable(szSQL);
    for(int i=0; i<tbl->numRows(); ++i)
    {
        tbl->setRow(i);
        ctlCardName->AppendString(wxString::FromUTF8(tbl->fieldValue(0)));
    }
    tbl->finalize();
}

bool crmGuestFilterDialog::TransferDataFromWindow()
{
    m_isfilter = true;
    return wxDialog::TransferDataFromWindow();
}

bool crmGuestFilterDialog::TransferDataToWindow()
{
    m_isfilter = false;
    return wxDialog::TransferDataToWindow();
}

