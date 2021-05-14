#include "crmReportDialog.h"
#include "../datamodule/crm_backup.h"
#include "../src/parameter.h"
//(*InternalHeaders(crmReportDialog)
#include <wx/notifmsg.h>
#include <wx/filedlg.h>
#include <wx/app.h>
#include <wx/xrc/xmlres.h>
#include <wx/html/htmprint.h>
//*)

//(*IdInit(crmReportDialog)
//*)

BEGIN_EVENT_TABLE(crmReportDialog,wxDialog)
	//(*EventTable(crmReportDialog)
    EVT_INIT_DIALOG(crmReportDialog::OnInit)
    EVT_BUTTON(XRCID("ID_BUTTON_FILTER"),   crmReportDialog::OnbtnFilterClick)
    EVT_BUTTON(XRCID("ID_BUTTON_ACCOUNT"),  crmReportDialog::OnbtnAccountClick)
    EVT_BUTTON(XRCID("ID_BUTTON_SAVEAS"),   crmReportDialog::OnbtnSaveasClick)
    EVT_BUTTON(XRCID("ID_BUTTON_PRINT"),    crmReportDialog::OnbtnPrintClick)
	//*)
END_EVENT_TABLE()

crmReportDialog::crmReportDialog(wxWindow* parent)
{
	//(*Initialize(crmReportDialog)
	wxXmlResource::Get()->LoadObject(this,parent,_T("crmReportDialog"),_T("wxDialog"));
	ctlCategory = (wxRadioBox*)FindWindow(XRCID("ID_RADIOBOX_ACCOUNTCATEGORY"));
	ctlReportFoot = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT_FOOT"));

	ctlReport =  new wxDataViewCtrl(this, XRCID("ID_DATAVIEW_REPORT"), wxDefaultPosition,
                wxDefaultSize, wxDV_ROW_LINES | wxDV_MULTIPLE );
    wxXmlResource::Get()->AttachUnknownControl(wxT("ID_DATAVIEW_REPORT"), ctlReport, this);
	//*)

	m_filter_dlg = new crmRecordFilterDialog(this);
}

crmReportDialog::~crmReportDialog()
{
	//(*Destroy(crmReportDialog)
	//*)
	if (m_filter_dlg)
        delete m_filter_dlg;
}


void crmReportDialog::OnInit(wxInitDialogEvent& event)
{
    wxFont ft = ctlReport->GetFont();
    ft.SetPixelSize(wxSize(16,16));
    ft.SetFaceName("Sans");
    ctlReport->SetFont(ft);

    if (!m_data_list)
    {
        m_data_list = new crmDataModel;
        ctlReport->AssociateModel(m_data_list.get());
        InitViewColumns();
    }
    event.Skip();
}

void crmReportDialog::OnbtnFilterClick(wxCommandEvent& event)
{
    m_filter_dlg->ShowModal();
}

void crmReportDialog::OnbtnAccountClick(wxCommandEvent& event)
{
    wxWindowDisabler disableAll;
    wxNotificationMessage info(_("tip:"),_("accountting, please wait ..."),this);
    info.Show(wxNotificationMessage::Timeout_Never);
    wxBusyCursor wait;
    Update();
#if 1
    wxSafeYield(this, true);
#endif

    try
    {
        if ( m_filter_dlg && m_filter_dlg->IsFilter() )
        {
            m_account.Set(m_filter_dlg->getFilter(),
                          ctlCategory->GetSelection());
            m_account.DoSumReport(m_filter_dlg->getFilter());
        }
        else
        {
            m_account.Set("1=1", ctlCategory->GetSelection());
            m_account.DoSumReport("1=1");
        }
        wxString szFoot = wxString::Format(_("people count: %d  price: %.2f"),
                                           m_account.SumPeople(),
                                           m_account.SumPrice());
        ctlReportFoot->SetLabel(szFoot);

        if ( m_data_list )
        {
            m_data_list->RetrieveData(m_account.Get());
        }
        else
        {
            m_data_list = new crmDataModel(m_account.Get());
            ctlReport->AssociateModel(m_data_list.get());
        }
        InitViewColumns();

    }
    catch(CppSQLite3Exception e)
    {
        wxLogError(wxString::FromUTF8(e.errorMessage()));
    }

    info.Close();
}

void crmReportDialog::OnbtnSaveasClick(wxCommandEvent& event)
{
    crmReportBackup bcp(m_data_list.get(), this);

	if ( bcp.DoExportConfigure() )
	{
        wxWindowDisabler disableAll;
        wxBusyCursor wait;
        bcp.setFoot( ctlReportFoot->GetLabel().c_str() );
        bcp.bcpout();
	}
}

void crmReportDialog::OnbtnPrintClick(wxCommandEvent& event)
{
    wxWindowDisabler disableAll;
    wxNotificationMessage info(_("tip:"),_("prepare report for printer, please wait ..."),this);
    info.Show(wxNotificationMessage::Timeout_Never);
    wxBusyCursor wait;
    Update();
#if 1
    wxSafeYield(this, true);
#endif

    wxHtmlEasyPrinting prn(_("report print"), this);
    wxString szHtml = wxT("");
    szHtml << "<html>"
           << "<title>" << _("report") << "</title>"
           << "<body bgcolor="
           << theParameter().Get("report", "html_bgcolor")
           << ">";

    if (m_filter_dlg && m_filter_dlg->IsFilter())
    {
        InitHtmlTitle(szHtml);
    }
    else
    {
        szHtml << "<h1>" << _("all") << "</h1>";
    }
    szHtml << "<hr/>";

    if ( m_data_list )
    {
        szHtml << "<table><small>";
        InitHtmlTableHead(szHtml);
        InitHtmlTableData(szHtml);
        szHtml << "</small></table>";
    }

    szHtml << "</body></html>";
    prn.PreviewText(szHtml);
    event.Skip();
}

void crmReportDialog::InitViewColumns()
{
    ctlReport->ClearColumns();
    const crmDataViewColumn* columns = m_data_list->GetColumns();
    for( unsigned int col=0; col<columns->GetCount(); ++col)
    {
        //wxDataViewColumn* pColumn =
        ctlReport->AppendTextColumn(columns->GetColumnName(col), col,
                  wxDATAVIEW_CELL_INERT,
                  columns->GetColumnWidth(col),
                  columns->GetColumnType(col) == "long" || columns->GetColumnType(col) == "double" ?
                  wxALIGN_RIGHT : wxALIGN_LEFT,
                  wxDATAVIEW_COL_RESIZABLE);
//                                      wxDATAVIEW_COL_SORTABLE | wxDATAVIEW_COL_REORDERABLE | wxDATAVIEW_COL_RESIZABLE);

        //wxLogError(columns->GetColumnType(col));
    }
}

void crmReportDialog::InitHtmlTitle(wxString& source)
{
    source << "<table><B>"
           << "<tr><td>" << _("date range:") << "</td>"
           << "<td bgcolor=" << theParameter().Get("report","table_head_bgcolor") << ">"
           << m_filter_dlg->GetStartStatisticsDate() << _(" to ") << m_filter_dlg->GetEndStatisticsDate()
           << "</td></tr>"
           << "<tr><td>" << _("operator name:") << "</td>"
           << "<td bgcolor=" << theParameter().Get("report","table_head_bgcolor") << ">"
           << m_filter_dlg->GetSelectOperator()
           << "</td></tr>"
           << "<tr><td>" << _("group name:") << "</td>"
           << "<td bgcolor=" << theParameter().Get("report","table_head_bgcolor") << ">"
           << m_filter_dlg->GetSelectGroup()
           << "</td></tr>"
           << "<tr><td>" << _("user name:") << "</td>"
           << "<td bgcolor=" << theParameter().Get("report","table_head_bgcolor") << ">"
           << m_filter_dlg->GetSelectUser()
           << "</td></tr>"
           << "<tr><td>" << _("card name:") << "</td>"
           << "<td bgcolor=" << theParameter().Get("report","table_head_bgcolor") << ">"
           << m_filter_dlg->GetSelectCard()
           << "</td></tr>"
           << "</B><table>";
}

void crmReportDialog::InitHtmlTableHead(wxString& source)
{
    source << "<thead><tr bgcolor=" << theParameter().Get("report", "table_head_bgcolor") << ">";
    crmDataViewColumn* columns = m_data_list->GetColumns();
    for(unsigned int i = 0; i<columns->GetCount(); ++i)
    {
        source << "<th>"
               << columns->GetColumnName(i)
               << "</th>";
    }
    source << "</tr></thead>";
}

void crmReportDialog::InitHtmlTableData(wxString& source)
{
    crmDataViewColumn* columns = m_data_list->GetColumns();
    crmDataBuffer* buffer = m_data_list->GetDataBuffer();

    for(unsigned int i = 0; i<buffer->GetCount(); ++i)
    {
        source << "<tr>";
        for(unsigned int j=0; j<columns->GetCount(); ++j)
        {
            source << ( columns->GetColumnType(j) == "string" ?
                        "<td><font>" :  wxString::Format("<td align=right bgcolor=%s><font color=#0000FF>",
                                                         theParameter().Get("report", "table_data_bgcolor")) )
                   << buffer->GetValue(i,j)
                   << "</font></td>";
        }
        source << "</tr>";
    }
}

