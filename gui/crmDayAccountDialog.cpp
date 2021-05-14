#include "crmDayAccountDialog.h"
#include "../src/crmlogin.h"
#include "../src/parameter.h"
//(*InternalHeaders(crmDayAccountDialog)
#include <wx/notifmsg.h>
#include <wx/msgdlg.h>
#include <wx/xrc/xmlres.h>
#include <wx/html/htmprint.h>
//*)

//(*IdInit(crmDayAccountDialog)
//*)

BEGIN_EVENT_TABLE(crmDayAccountDialog,wxDialog)
	//(*EventTable(crmDayAccountDialog)
    EVT_INIT_DIALOG(crmDayAccountDialog::OnInit)
    EVT_BUTTON  (XRCID("ID_BUTTON_ACCOUNT"),    crmDayAccountDialog::OnbtnAccountClick)
    EVT_BUTTON  (XRCID("ID_BUTTON_PRINT"),      crmDayAccountDialog::OnbtnPrintClick)
    EVT_CHECKBOX(XRCID("ID_CHECK_ALL"),         crmDayAccountDialog::OnCheckCategoryAll)
    EVT_CHECKBOX(XRCID("ID_CHECK_DETAIL"),      crmDayAccountDialog::OnCheckCategoryItem)
    EVT_CHECKBOX(XRCID("ID_CHECK_GROUP"),       crmDayAccountDialog::OnCheckCategoryItem)
    EVT_CHECKBOX(XRCID("ID_CHECK_USER"),        crmDayAccountDialog::OnCheckCategoryItem)
    EVT_CHECKBOX(XRCID("ID_CHECK_CARD"),        crmDayAccountDialog::OnCheckCategoryItem)
    EVT_CHECKBOX(XRCID("ID_CHECK_TRAIN"),       crmDayAccountDialog::OnCheckCategoryItem)
	//*)
END_EVENT_TABLE()

crmDayAccountDialog::crmDayAccountDialog(wxWindow* parent)
{
	//(*Initialize(crmDayAccountDialog)
	wxXmlResource::Get()->LoadObject(this,parent,_T("crmDayAccountDialog"),_T("wxDialog"));
	ctlStatisticsDate   = (wxDatePickerCtrl*)FindWindow(XRCID("ID_DATEPICKERCTRL_STATISTICS"));
    ctlByAll            = (wxCheckBox*)FindWindow(XRCID("ID_CHECK_ALL"));
    ctlByDetail         = (wxCheckBox*)FindWindow(XRCID("ID_CHECK_DETAIL"));
    ctlByGroup          = (wxCheckBox*)FindWindow(XRCID("ID_CHECK_GROUP"));
    ctlByUser           = (wxCheckBox*)FindWindow(XRCID("ID_CHECK_USER"));
    ctlByCard           = (wxCheckBox*)FindWindow(XRCID("ID_CHECK_CARD"));
    ctlByTrain          = (wxCheckBox*)FindWindow(XRCID("ID_CHECK_TRAIN"));
    ctlReport           = (wxHtmlWindow*)FindWindow(XRCID("ID_HTML_REPORT"));
	//*)
}

crmDayAccountDialog::~crmDayAccountDialog()
{
	//(*Destroy(crmDayAccountDialog)
    SaveCatetoryDefault();
	//*)
}


void crmDayAccountDialog::OnInit(wxInitDialogEvent& event)
{
    LoadCatetoryDefault();
    event.Skip();
}

void crmDayAccountDialog::OnbtnPrintClick(wxCommandEvent& event)
{
    wxHtmlEasyPrinting prn(_("account report print"), this);
    prn.PreviewText(*(ctlReport->GetParser()->GetSource()));
    event.Skip();
}

void crmDayAccountDialog::OnbtnAccountClick(wxCommandEvent& event)
{
    wxWindowDisabler disableAll;
    wxNotificationMessage info(_("tip:"),_("accountting, please wait ..."),this);
    info.Show(wxNotificationMessage::Timeout_Never);
    wxBusyCursor wait;
    Update();
#if 1
    wxSafeYield(this, true);
#endif

    wxDateTime dt = ctlStatisticsDate->GetValue();
    wxString szStatisticsDate = dt.FormatISODate();

    const wxString szLine = wxT("<hr/>");
    wxString szSource = wxT("");
    szSource << "<html>"
             << "<title>" << _("account report") << "</title>"
             << "<body bgcolor=" << theParameter().Get("report", "html_bgcolor") << " >";
    ctlReport->SetPage(szSource);
    szSource.Clear();

    m_account.DoSumAccount(szStatisticsDate.c_str(), theOperator().GetOperatorName());
    szSource << "<table><B>"
             << "<tr><td>" << _("statistics date:") << "</td><td bgcolor=#F0F0F0>" << dt.FormatDate()
             << "</td></tr>"
             << "<tr><td>" << _("service name:")    << "</td><td bgcolor=#F0F0F0>" << theOperator().GetOperatorName()
             << "</td></tr>"
             << "<tr><td>" << _("welcome count:")   << "</td><td bgcolor=#F0F0F0>" << wxString::Format(_("PEOPLE %d"), m_account.SumPeople())
             << "</td></tr>"
             << "<tr><td>" << _("real price:")      << "</td><td bgcolor=#F0F0F0>" << wxString::Format(_("RMB %.2f"), m_account.SumPrice())
             << "</td></tr>"
             << "</B></table>";
    ctlReport->AppendToPage(szSource);
    szSource.Clear();

    if ( ctlByGroup->IsChecked() )
    {
        m_account.Set(szStatisticsDate.c_str(),
                      theOperator().GetOperatorName(),
                      typeAccountByGroup);
        ctlReport->AppendToPage(szLine);
        szSource << "<h5>" << _("by group") << "</h5>";
        ctlReport->AppendToPage(szSource);
        szSource.Clear();
        DoAccountReport(m_account.Get());
    }

    if ( ctlByUser->IsChecked() )
    {
        m_account.Set(szStatisticsDate.c_str(),
                      theOperator().GetOperatorName(),
                      typeAccountByUser);
        ctlReport->AppendToPage(szLine);
        szSource << "<h5>" << _("by user") << "</h5>";
        ctlReport->AppendToPage(szSource);
        szSource.Clear();
        DoAccountReport(m_account.Get());
    }

    if ( ctlByCard->IsChecked() )
    {
        m_account.Set(szStatisticsDate.c_str(),
                      theOperator().GetOperatorName(),
                      typeAccountByCard);
        ctlReport->AppendToPage(szLine);
        szSource << "<h5>" << _("by card") << "</h5>";
        ctlReport->AppendToPage(szSource);
        szSource.Clear();
        DoAccountReport(m_account.Get());
    }

    if ( ctlByTrain->IsChecked() )
    {
        m_account.Set(szStatisticsDate.c_str(),
                      theOperator().GetOperatorName(),
                      typeAccountByTrain);
        ctlReport->AppendToPage(szLine);
        szSource << "<h5>" << _("by train") << "</h5>";
        ctlReport->AppendToPage(szSource);
        szSource.Clear();
        DoAccountReport(m_account.Get());
    }

    if ( ctlByDetail->IsChecked() )
    {
        m_account.Set(szStatisticsDate.c_str(),
                      theOperator().GetOperatorName(),
                      typeAccountDefault);
        ctlReport->AppendToPage(szLine);
        szSource << "<h5>" << _("by detail") << "</h5>";
        ctlReport->AppendToPage(szSource);
        szSource.Clear();
        DoAccountReport(m_account.Get());
    }
    ctlReport->AppendToPage(wxT("</body></html>"));
}

void crmDayAccountDialog::OnCheckCategoryAll(wxCommandEvent& event)
{
    if (ctlByAll->IsChecked())
    {
        ctlByDetail->SetValue(true);
        ctlByGroup ->SetValue(true);
        ctlByCard  ->SetValue(true);
        ctlByUser  ->SetValue(true);
        ctlByTrain ->SetValue(true);
    }
    event.Skip();
}

void crmDayAccountDialog::OnCheckCategoryItem(wxCommandEvent& event)
{
    if ( ctlByDetail->IsChecked()   &&
         ctlByGroup ->IsChecked()   &&
         ctlByUser  ->IsChecked()   &&
         ctlByCard  ->IsChecked()   &&
         ctlByTrain ->IsChecked() )
    {
        ctlByAll->SetValue(true);
    }
    else
    {
        ctlByAll->SetValue(false);
    }
    event.Skip();
}

void crmDayAccountDialog::DoAccountReport(CppSQLite3Query* tbl)
{
    if (!tbl)
    {
        return;
    }
    wxString szSource = wxT("<table><small>");
    szSource << "<thead><tr bgcolor=" << theParameter().Get("report", "table_head_bgcolor") << ">";
    for(int col=0; col<tbl->numFields(); ++col)
    {
        szSource << "<th>" << wxString::FromUTF8(tbl->fieldName(col))
                 << "</th>";
    }
    szSource << "</tr></thead>";
    ctlReport->AppendToPage(szSource);
    szSource.Clear();
    int i=0;
    while(!tbl->eof())
    {
        ++i;
        szSource << "<tr>";
        for(int j=0; j<tbl->numFields(); ++j)
        {
            const int field_type = tbl->fieldDataType(j);
            szSource << (field_type == SQLITE3_TEXT ?
                         "<td><font>" : wxString::Format("<td align=right bgcolor=%s><font color=#0000FF>",
                                                         theParameter().Get("report", "table_data_bgcolor")))
                     << (field_type == SQLITE3_TEXT ?  wxString::FromUTF8(tbl->fieldValue(j)) : wxString(tbl->fieldValue(j)))
                     << "</font></td>";
        }
        szSource << "</tr>";
        if ( i%100 == 0 )
        {
            ctlReport->AppendToPage(szSource);
            szSource.Clear();
        }
        tbl->nextRow();
    }
    ctlReport->AppendToPage(szSource);
    szSource.Clear();

    ctlReport->AppendToPage(wxT("</small></table>"));
}

void crmDayAccountDialog::LoadCatetoryDefault()
{
    ctlByDetail ->SetValue(atoi(theParameter().Get("account", "default_by_detail")));
    ctlByGroup  ->SetValue(atoi(theParameter().Get("account", "default_by_group" )));
    ctlByUser   ->SetValue(atoi(theParameter().Get("account", "default_by_user"  )));
    ctlByCard   ->SetValue(atoi(theParameter().Get("account", "default_by_card"  )));
    ctlByTrain  ->SetValue(atoi(theParameter().Get("account", "default_by_train" )));

    if ( ctlByDetail->IsChecked()   &&
         ctlByGroup ->IsChecked()   &&
         ctlByUser  ->IsChecked()   &&
         ctlByCard  ->IsChecked()   &&
         ctlByTrain ->IsChecked() )
    {
        ctlByAll->SetValue(true);
    }
    else
    {
        ctlByAll->SetValue(false);
    }
}

void crmDayAccountDialog::SaveCatetoryDefault()
{
    theParameter().Set( "account", "default_by_detail", ctlByDetail->GetValue() ? "1":"0" );
    theParameter().Set( "account", "default_by_group",  ctlByGroup->GetValue()  ? "1":"0" );
    theParameter().Set( "account", "default_by_user",   ctlByUser->GetValue()   ? "1":"0" );
    theParameter().Set( "account", "default_by_card",   ctlByCard->GetValue()   ? "1":"0" );
    theParameter().Set( "account", "default_by_train",  ctlByTrain->GetValue()  ? "1":"0" );
}
