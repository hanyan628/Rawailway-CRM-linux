#ifndef CRMWELCOMEPEOPLEDIALOG_H
#define CRMWELCOMEPEOPLEDIALOG_H

//(*Headers(crmWelcomePeopleDialog)
#include <wx/checkbox.h>
#include <wx/grid.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/timer.h>
#include <wx/app.h>
#include "../datamodule/crm_account.h"
//*)

class crmWelcomePeopleDialog: public wxDialog
{
public:

    crmWelcomePeopleDialog(wxWindow* parent);
    virtual ~crmWelcomePeopleDialog();

    void DoChange()
    {
        m_isTaskFinished = false;
        wxWakeUpIdle();
    };

    //(*Declarations(crmWelcomePeopleDialog)
    wxGrid*     ctlWelcomeList;
    wxCheckBox* ctlLocked;
    //*)

protected:

    //(*Identifiers(crmWelcomePeopleDialog)
    //*)

private:
    void    OnInit(wxInitDialogEvent& event);
    void    OnButtonRetrieve(wxCommandEvent& event);
    void    OnButtonHide(wxCommandEvent& event);
    void    OnCheckLocked(wxCommandEvent& event);
    void    OnIdle(wxIdleEvent& event);

    int     Retrieve();
    void    AutoSizeAndPos();
    void    InitGrid();
    bool    DoTask();

    bool    m_isTaskFinished;
    int     m_current_row;


    DECLARE_EVENT_TABLE()
};

#endif
