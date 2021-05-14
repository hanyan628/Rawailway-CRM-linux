#ifndef CRMRECORDFILTERDIALOG_H
#define CRMRECORDFILTERDIALOG_H
#include "./crmFilterDataDialog.h"
//(*Headers(crmRecordFilterDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/datectrl.h>
#include <wx/statline.h>
#include <wx/dateevt.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/combobox.h>
//*)

class crmRecordFilterDialog: public crmFilterDataDialog
{
    //---------------------------------------------------------------------------------------
    //          My Progrman
    //---------------------------------------------------------------------------------------
public:
    virtual const char*     getFilter();
    virtual bool            IsFilter();

    const wxString& GetStartStatisticsDate()
    {
        return szStartStatisticsDate;
    };
    const wxString& GetEndStatisticsDate()
    {
        return szEndStatisticsDate;
    };
    const wxString& GetSelectGroup()
    {
        return szGroupName;
    };
    const wxString& GetSelectUser()
    {
        return szUserName;
    };
    const wxString& GetSelectCard()
    {
        return szCardName;
    };
    const wxString& GetSelectOperator()
    {
        return szOperatorName;
    };
private:
    virtual bool    TransferDataToWindow();
    virtual bool    TransferDataFromWindow();
    void            initListGroup();
    void            initListUser(const char* szGroup);
    void            initListCard(const char* szGroup, const char* szUser);
    void            initListOperator();

    crmRecordDef    m_dsRecord;
    wxString        szStartStatisticsDate;
    wxString        szEndStatisticsDate;
    wxString        szOperatorName;
    wxString        szGroupName;
    wxString        szUserName;
    wxString        szCardName;
    //---------------------------------------------------------------------------------------

public:

    crmRecordFilterDialog(wxWindow* parent);
    virtual ~crmRecordFilterDialog();

    //(*Declarations(crmRecordFilterDialog)
    wxComboBox*         ctlOperatorName;
    wxComboBox*         ctlGroupName;
    wxComboBox*         ctlUserName;
    wxComboBox*         ctlCardName;
    wxDatePickerCtrl*   ctlEndStatisticsDate;
    wxDatePickerCtrl*   ctlStartStatisticsDate;
    //*)

protected:

    //(*Identifiers(crmRecordFilterDialog)
    //*)

private:

    //(*Handlers(crmRecordFilterDialog)
    void OnInit(wxInitDialogEvent& event);
    void OnbtnResetClick(wxCommandEvent& event);
    void OnctlOperatorNameDropDown(wxCommandEvent& event);
    void OnctlGroupNameDropDown(wxCommandEvent& event);
    void OnctlUserNameDropDown(wxCommandEvent& event);
    void OnctlCardNameDropDown(wxCommandEvent& event);
    void OnctlGroupNameSelect(wxCommandEvent& event);
    void OnctlUserNameSelect(wxCommandEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
