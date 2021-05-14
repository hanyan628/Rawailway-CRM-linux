#ifndef CRMDAYACCOUNTDIALOG_H
#define CRMDAYACCOUNTDIALOG_H
#include "../datamodule/crm_account.h"

//(*Headers(crmDayAccountDialog)
#include <wx/dialog.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/html/htmlwin.h>
//*)

class crmDayAccountDialog: public wxDialog
{
private:
    crmAccount m_account;

public:

    crmDayAccountDialog(wxWindow* parent);
    virtual ~crmDayAccountDialog();

    //(*Declarations(crmDayAccountDialog)
    wxDatePickerCtrl* ctlStatisticsDate;
    wxCheckBox* ctlByAll;
    wxCheckBox* ctlByDetail;
    wxCheckBox* ctlByGroup;
    wxCheckBox* ctlByUser;
    wxCheckBox* ctlByCard;
    wxCheckBox* ctlByTrain;
    wxHtmlWindow* ctlReport;
    //*)

protected:

    //(*Identifiers(crmDayAccountDialog)
    //*)

private:

    //(*Handlers(crmDayAccountDialog)
    void OnInit(wxInitDialogEvent& event);
    void OnbtnAccountClick(wxCommandEvent& event);
    void OnbtnPrintClick(wxCommandEvent& event);
    void OnCheckCategoryAll(wxCommandEvent& event);
    void OnCheckCategoryItem(wxCommandEvent& event);
    //*)
    void DoAccountReport(CppSQLite3Query* tbl);
    void LoadCatetoryDefault();
    void SaveCatetoryDefault();
    DECLARE_EVENT_TABLE()
};

#endif
