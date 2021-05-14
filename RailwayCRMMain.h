/***************************************************************
 * Name:      RailwayCRMMain.h
 * Purpose:   Defines Application Frame
 * Author:    Hyan (hanyan@public.wh.hb.cn)
 * Created:   2010-11-22
 * Copyright: Hyan (http://hyan.cn)
 * License:
 **************************************************************/

#ifndef RAILWAYCRMMAIN_H
#define RAILWAYCRMMAIN_H

//(*Headers(RailwayCRMFrame)
#include <wx/menu.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/timer.h>
#include <wx/html/htmlwin.h>
#include <wx/imaglist.h>
//*)
#include "./gui/crmWelcomePeopleDialog.h"

class RailwayCRMFrame: public wxFrame
{
public:

    RailwayCRMFrame(wxWindow* parent);
    virtual ~RailwayCRMFrame();

    //------------------------------------------------------------------
    //      Hyan's program
    //------------------------------------------------------------------
public:
    bool            Login();
private:
    void            DisableAllModule();
    void            ModuleRights();
    void            LoadParameter();
    void            LoadHtml(const wxString& utl);

    const wxString  DoSelectGroup();
    const wxString  DoSelectUser(const wxString& szGroup);
    const wxString  DoSelectCard(const wxString& szGroup, const wxString& szUser);
    const bool      DoInputRecord(const wxString& szGroup, const wxString& szUser, const wxString& szCard);
    void            DoSelectShift();
    void            DoWelcomeChanged();

    bool            ValidateRecord(crmRecordDef& ds, strucRecord* rd);
    void            InitImageList();

    wxTimer                 m_timer;
    crmWelcomePeopleDialog* m_dlgWelcomePeopleShow;
    wxString                m_statistics_date;
    wxImageList*            m_image_list;
    //------------------------------------------------------------------

private:
    //(*Handlers(RailwayCRMFrame)
    void OnQuit(wxCommandEvent& event);
    void OnTimer(wxTimerEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnClose(wxCloseEvent& event);
    void OnbtnReLoginClick(wxCommandEvent& event);
    void OnMenuFullScreenSelected(wxCommandEvent& event);
    void OnbtnOperatorDefClick(wxCommandEvent& event);
    void OnbtnTrainsDefClick(wxCommandEvent& event);
    void OnbtnImageDefClick(wxCommandEvent& event);
    void OnbtnGuestsDefClick(wxCommandEvent& event);
    void OnbtnRecordModifyClick(wxCommandEvent& event);
    void OnbtnParameterDefClick(wxCommandEvent& event);
    void OnbtnMonthAccountClick(wxCommandEvent& event);
    void OnbtnWelcomeRecordClick(wxCommandEvent& event);
    void OnbtnDayAccountClick(wxCommandEvent& event);
    void OnMenuShowWelcome(wxCommandEvent& event);
    void OnMenuChangePassword(wxCommandEvent&event);
    void OnMenuTest(wxCommandEvent&event);
    //*)

    //(*Declarations(RailwayCRMFrame)
    wxButton*       btnImageDef;
    wxButton*       btnReLogin;
    wxButton*       btnTrainsDef;
    wxButton*       btnMonthAccount;
    wxButton*       btnOperatorDef;
    wxButton*       btnParameterDef;
    wxButton*       btnRecordModify;
    wxButton*       btnDayAccount;
    wxButton*       btnGuestsDef;
    wxButton*       btnWelcomeRecord;
    wxStaticText*   ctlOperatorName;
    wxStaticText*   ctlStatisticsDate;
    wxStaticText*   ctlNow;
    wxHtmlWindow*   ctlHtml;
    //*)

    DECLARE_EVENT_TABLE()
};

#endif // RAILWAYCRMMAIN_H
