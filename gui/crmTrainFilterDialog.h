#ifndef CRMTRAINFILTERDIALOG_H
#define CRMTRAINFILTERDIALOG_H
#include "./crmFilterDataDialog.h"

//(*Headers(crmTrainFilterDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class crmTrainFilterDialog: public crmFilterDataDialog
{
    //---------------------------------------------------------------------------------------
    //          My Progrman
    //---------------------------------------------------------------------------------------
public:
    virtual const char* getFilter();
    virtual bool IsFilter();
private:
    virtual bool TransferDataToWindow();
    virtual bool TransferDataFromWindow();

    wxString szStartStationName;
    wxString szEndStationName;
    wxString szTrainCode;
    //---------------------------------------------------------------------------------------


public:

    crmTrainFilterDialog(wxWindow* parent);
    virtual ~crmTrainFilterDialog();

    //(*Declarations(crmTrainFilterDialog)
    wxTextCtrl* ctlTrainCode;
    wxTextCtrl* ctlStartStationName;
    wxTextCtrl* ctlEndStationName;
    //*)

protected:

    //(*Identifiers(crmTrainFilterDialog)
    //*)

private:

    //(*Handlers(crmTrainFilterDialog)
    void OnbtnResetClick(wxCommandEvent& event);
    void OnInit(wxInitDialogEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
