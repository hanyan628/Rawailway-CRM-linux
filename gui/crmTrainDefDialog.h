#ifndef CRMTRAINDEFDIALOG_H
#define CRMTRAINDEFDIALOG_H

#include "./crmEditDataDialog.h"

//(*Headers(crmTrainDefDialog)
#include <wx/textctrl.h>
#include <wx/dialog.h>
//*)

class crmTrainDefDialog: public crmEditDataDialog
{
    //----------------------------------------------------------------
    //             My progrman
    //----------------------------------------------------------------
public:
    virtual void SetDataObject(crmObject* pObj);
private:
    strucTrain* m_data;
    //----------------------------------------------------------------


public:

    crmTrainDefDialog(wxWindow* parent,wxWindowID id=wxID_ANY);
    virtual ~crmTrainDefDialog();

    //(*Declarations(crmTrainDefDialog)
    wxTextCtrl* ctlTrainCode;
    wxTextCtrl* ctlStartStationName;
    wxTextCtrl* ctlEndStationName;
    wxTextCtrl* ctlStartTime;
    //*)

protected:

    //(*Identifiers(crmTrainDefDialog)
    //*)

private:

    //(*Handlers(crmTrainDefDialog)
    void OnButtonReset(wxCommandEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
