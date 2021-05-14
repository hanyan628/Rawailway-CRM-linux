#ifndef PARAMETERDEFDIALOG_H
#define PARAMETERDEFDIALOG_H

//(*Headers(ParameterDefDialog)
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/dataview.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)
#include "ParameterDataModal.h"

class ParameterDefDialog: public wxDialog
{
    //----------------------------------------------------------
    //      My Progrman
    //----------------------------------------------------------
private:
    virtual bool TransferDataToWindow();
    virtual bool TransferDataFromWindow();
    void InitParameterView();
    bool SaveParameter();
    wxObjectDataPtr<ParameterDataModal> m_parameter_modal;
    //----------------------------------------------------------

public:

    ParameterDefDialog(wxWindow* parent);
    virtual ~ParameterDefDialog();
    wxDataViewCtrl* ctlParameterView;
private:

    //(*Handlers(ParameterDefDialog)
    void OnInit(wxInitDialogEvent& event);
    void OnbtnDeleteClick(wxCommandEvent& event);
    void OnbtnInsertClick(wxCommandEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
