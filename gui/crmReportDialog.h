#ifndef CRMREPORTDIALOG_H
#define CRMREPORTDIALOG_H
#include "./crmRecordFilterDialog.h"
#include "../src/crmDataModel.h"
#include "../datamodule/crm_account.h"
//(*Headers(crmReportDialog)
#include <wx/stattext.h>
#include <wx/radiobox.h>
#include <wx/button.h>
#include <wx/dataview.h>
#include <wx/dialog.h>
//*)

class crmReportDialog: public wxDialog
{
private:
    wxObjectDataPtr<crmDataModel> m_data_list;
    crmRecordFilterDialog* m_filter_dlg;
    crmAccount m_account;
    void InitViewColumns();
    void InitHtmlTitle(wxString& source);
    void InitHtmlTableHead(wxString& source);
    void InitHtmlTableData(wxString& source);

public:
    crmReportDialog(wxWindow* parent);
    virtual ~crmReportDialog();

    //(*Declarations(crmReportDialog)
    wxRadioBox* ctlCategory;
    wxStaticText* ctlReportFoot;
    wxDataViewCtrl* ctlReport;
    wxButton* btnAccount;
    //*)

protected:

    //(*Identifiers(crmReportDialog)
    //*)

private:

    //(*Handlers(crmReportDialog)
    void OnInit(wxInitDialogEvent& event);
    void OnbtnFilterClick(wxCommandEvent& event);
    void OnbtnAccountClick(wxCommandEvent& event);
    void OnbtnSaveasClick(wxCommandEvent& event);
    void OnbtnPrintClick(wxCommandEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
