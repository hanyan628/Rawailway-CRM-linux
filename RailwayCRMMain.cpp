/***************************************************************
 * Name:      RailwayCRMMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Hyan (hanyan@public.wh.hb.cn)
 * Created:   2010-11-22
 * Copyright: Hyan (http://hyan.cn)
 * License:
 **************************************************************/

#include "RailwayCRMMain.h"
#include "./sqlite3/CppSQLite3.h"
#include "./src/crm_var.h"
#include "./src/parameter.h"
#include "./src/crmlogin.h"
#include "./gui/LoginDialog.h"
#include "./gui/crmDataDefineDialog.h"
#include "./gui/ParameterDefDialog.h"
#include "./gui/crmRecordFilterDialog.h"
#include "./gui/crmImagesDialog.h"
#include "./gui/crmWelcomeRecordDialog.h"
#include "./gui/crmDayAccountDialog.h"
#include "./gui/crmReportDialog.h"
#include "./gui/crmChangePasswordDialog.h"
#include "./gui/crmMessageBox.h"
#include "./test/testDialog.h"

//(*InternalHeaders(RailwayCRMFrame)
#include <wx/xrc/xmlres.h>
#include <wx/msgdlg.h>
#include <wx/choicdlg.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(RailwayCRMFrame)
#define ID_TIMER_CRM 1000
//*)

BEGIN_EVENT_TABLE(RailwayCRMFrame,wxFrame)
    //(*EventTable(RailwayCRMFrame)
    EVT_BUTTON  (XRCID("ID_BUTTON_WELCOME"),        RailwayCRMFrame::OnbtnWelcomeRecordClick)
    EVT_MENU    (XRCID("ID_MENU_WELCOME"),          RailwayCRMFrame::OnbtnWelcomeRecordClick)
    EVT_BUTTON  (XRCID("ID_BUTTON_ACCOUNT_DAY"),    RailwayCRMFrame::OnbtnDayAccountClick)
    EVT_MENU    (XRCID("ID_MENU_ACCOUNT_DAY"),      RailwayCRMFrame::OnbtnDayAccountClick)
    EVT_BUTTON  (XRCID("ID_BUTTON_ACCOUNT_MONTH"),  RailwayCRMFrame::OnbtnMonthAccountClick)
    EVT_BUTTON  (XRCID("ID_BUTTON_DEF_TRAIN"),      RailwayCRMFrame::OnbtnTrainsDefClick)
    EVT_BUTTON  (XRCID("ID_BUTTON_DEF_OPERATOR"),   RailwayCRMFrame::OnbtnOperatorDefClick)
    EVT_BUTTON  (XRCID("ID_BUTTON_DEF_IMAGE"),      RailwayCRMFrame::OnbtnImageDefClick)
    EVT_BUTTON  (XRCID("ID_BUTTON_DEF_GUEST"),      RailwayCRMFrame::OnbtnGuestsDefClick)
    EVT_BUTTON  (XRCID("ID_BUTTON_DEF_RECORD"),     RailwayCRMFrame::OnbtnRecordModifyClick)
    EVT_BUTTON  (XRCID("ID_BUTTON_DEF_PARAMETER"),  RailwayCRMFrame::OnbtnParameterDefClick)
    EVT_BUTTON  (XRCID("ID_BUTTON_RELOGIN"),        RailwayCRMFrame::OnbtnReLoginClick)
    EVT_MENU    (XRCID("ID_MENU_RELOGIN"),          RailwayCRMFrame::OnbtnReLoginClick)
    EVT_MENU    (XRCID("ID_MENU_FULLSCREEN"),       RailwayCRMFrame::OnMenuFullScreenSelected)
    EVT_MENU    (XRCID("ID_MENU_ABOUT"),            RailwayCRMFrame::OnAbout)
    EVT_MENU    (XRCID("ID_MENU_QUIT"),             RailwayCRMFrame::OnQuit)
    EVT_MENU    (XRCID("ID_MENU_SHOW_WELCOME"),     RailwayCRMFrame::OnMenuShowWelcome)
    EVT_MENU    (XRCID("ID_MENU_CHANGE_PASSWORD"),  RailwayCRMFrame::OnMenuChangePassword)
    EVT_MENU    (XRCID("ID_MENU_TEST"),  RailwayCRMFrame::OnMenuTest)
    EVT_TIMER   (ID_TIMER_CRM,                      RailwayCRMFrame::OnTimer)
    EVT_CLOSE   (RailwayCRMFrame::OnClose)
    //*)
END_EVENT_TABLE()

RailwayCRMFrame::RailwayCRMFrame(wxWindow* parent)
    :m_timer(this,ID_TIMER_CRM),m_dlgWelcomePeopleShow(NULL),m_image_list(NULL)
{
    //(*Initialize(RailwayCRMFrame)
    wxXmlResource::Get()->LoadObject(this, parent, _T("RailwayCRMFrame"), _T("wxFrame"));

    btnWelcomeRecord    = (wxButton*)FindWindow(XRCID("ID_BUTTON_WELCOME"));
    btnDayAccount       = (wxButton*)FindWindow(XRCID("ID_BUTTON_ACCOUNT_DAY"));
    btnMonthAccount     = (wxButton*)FindWindow(XRCID("ID_BUTTON_ACCOUNT_MONTH"));
    btnTrainsDef        = (wxButton*)FindWindow(XRCID("ID_BUTTON_DEF_TRAIN"));
    btnOperatorDef      = (wxButton*)FindWindow(XRCID("ID_BUTTON_DEF_OPERATOR"));
    btnImageDef         = (wxButton*)FindWindow(XRCID("ID_BUTTON_DEF_IMAGE"));
    btnGuestsDef        = (wxButton*)FindWindow(XRCID("ID_BUTTON_DEF_GUEST"));
    btnRecordModify     = (wxButton*)FindWindow(XRCID("ID_BUTTON_DEF_RECORD"));
    btnParameterDef     = (wxButton*)FindWindow(XRCID("ID_BUTTON_DEF_PARAMETER"));
    btnReLogin          = (wxButton*)FindWindow(XRCID("ID_BUTTON_RELOGIN"));
    ctlOperatorName     = (wxStaticText*)FindWindow(XRCID("ID_OPERATOR_NAME"));
    ctlStatisticsDate   = (wxStaticText*)FindWindow(XRCID("ID_STATISTICS_DATE"));
    ctlNow              = (wxStaticText*)FindWindow(XRCID("ID_DATETIME_NOW"));
    ctlHtml             = (wxHtmlWindow*)FindWindow(XRCID("ID_HTML_LOGO"));
    //*)

    LoadParameter();
    LoadHtml(wxT("file:res/resource.zip#zip:html/crm_logo.htm"));

    DisableAllModule();
    m_timer.Start(1000);

    InitImageList();
}

RailwayCRMFrame::~RailwayCRMFrame()
{
    if (m_dlgWelcomePeopleShow)
    {
        m_dlgWelcomePeopleShow->Show(false);
        m_dlgWelcomePeopleShow->Close();
    }
    if ( m_image_list )
    {
        delete m_image_list;
    }
}

void RailwayCRMFrame::OnTimer(wxTimerEvent& event)
{
    wxDateTime dt = wxDateTime::Now();
    wxString strBuf = dt.FormatDate();
    strBuf << " ";
    strBuf << dt.FormatTime();
    ctlNow->SetLabel(strBuf);
}

void RailwayCRMFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void RailwayCRMFrame::OnAbout(wxCommandEvent& event)
{
    crmMessageBox dlg(this);
    dlg.ShowModal();
}

bool RailwayCRMFrame::Login()
{
    try
    {
        LoginDialog dlg(this);
        int ret = dlg.ShowModal();
        if ( ret == wxID_OK )
        {
            DisableAllModule();
            theOperator().Logout();
            if (dlg.VerifyPassword())
            {
                ModuleRights();
                ctlOperatorName->SetLabel(wxString::FromUTF8(theOperator().GetOperatorName()));
                DoSelectShift();
                ctlStatisticsDate->SetLabel(m_statistics_date);
            }
            else
            {
                wxMessageBox(_("Verify Password Failed!"),
                             _("tip:"),
                             wxICON_ERROR | wxOK | wxCENTRE,
                             this);
                ctlOperatorName->SetLabel(wxT(""));
                ctlStatisticsDate->SetLabel(wxT(""));
            }
        }
        else if ( ret == wxID_NO )
        {
            Close();
        }
    }
    catch(CppSQLite3Exception e)
    {
        wxLogError(wxString::FromUTF8(e.errorMessage()));
    }

    if ( theOperator().IsLogin() &&
            atoi(theParameter().Get("welcome","show_welcome_list")) == 1 )
    {
        if ( !m_dlgWelcomePeopleShow )
            m_dlgWelcomePeopleShow = new crmWelcomePeopleDialog(this);
        m_dlgWelcomePeopleShow->Show(true);
    }

    return theOperator().IsLogin();
}

void RailwayCRMFrame::DoSelectShift()
{
    wxDateTime dt = wxDateTime::Now();
    const int shift_switch = atoi(theParameter().Get("shift","switch"));
    wxArrayString choices;
    wxString shift_day = _("day");
    wxString shift_night = _("night");
    //choices.Add();
    //choices.Add(_("night"));
    choices.Add(wxString::Format(wxT("%s [%s]"),
                                 shift_day,
                                 dt.FormatDate()));
    choices.Add(wxString::Format(wxT("%s [%s]"),
                                 shift_night,
                                 (dt - wxDateSpan(0,0,0,1)).FormatDate()));
    wxString message = wxString::Format(_("'day shift' is today;\n if now time after %d:30, 'night shift' is tomorrow."),
                                        shift_switch);
    wxSingleChoiceDialog dlg(this,
                             message,
                             _("Please select shift"),
                             choices,
                             NULL,
                             wxDEFAULT_DIALOG_STYLE|wxOK|wxCENTER);
    wxDateTime dt_switch = wxDateTime::Now();
    dt_switch.SetHour(shift_switch);
    dt_switch.SetMinute(0);
    dt_switch.SetSecond(0);
    if ( dt<dt_switch )
        dlg.SetSelection(1);
    dlg.ShowModal();
    const int i = dlg.GetSelection();
    if ( i == 1 && dt < dt_switch )
        dt -= wxDateSpan(0,0,0,1);

    m_statistics_date = dt.FormatISODate();
}

void RailwayCRMFrame::OnClose(wxCloseEvent& event)
{
    if ( event.CanVeto() &&
            wxMessageBox(_("are you close system?"), _("tip:"),
                         wxICON_QUESTION|wxYES_NO,
                         this) != wxYES )
    {
        event.Veto();
        return;
    }
    event.Skip();
}

void RailwayCRMFrame::OnbtnReLoginClick(wxCommandEvent& event)
{
    Login();
}

void RailwayCRMFrame::DisableAllModule()
{
    btnWelcomeRecord    ->Disable();
    btnDayAccount       ->Disable();
    btnMonthAccount     ->Disable();
    btnTrainsDef        ->Disable();
    btnOperatorDef      ->Disable();
    btnImageDef         ->Disable();
    btnGuestsDef        ->Disable();
    btnRecordModify     ->Disable();
    btnParameterDef     ->Disable();
    btnReLogin          ->Enable(true);
}

void RailwayCRMFrame::ModuleRights()
{
    if (!theOperator().IsLogin())
        return;
    crmRight r = theOperator().GetLoginRights();

    btnWelcomeRecord    ->Enable(r.HasRight(maskWelcomeRecord));
    btnDayAccount       ->Enable(r.HasRight(maskDayAccount));
    btnMonthAccount     ->Enable(r.HasRight(maskMonthAccount));
    btnTrainsDef        ->Enable(r.HasRight(maskTrainsDef));
    btnOperatorDef      ->Enable(r.HasRight(maskOperatorDef));
    btnImageDef         ->Enable(r.HasRight(maskImageDef));
    btnGuestsDef        ->Enable(r.HasRight(maskGuestsDef));
    btnRecordModify     ->Enable(r.HasRight(maskRecordModify));
    btnParameterDef     ->Enable(r.HasRight(maskParameterDef));
    btnReLogin          ->Enable(true);
}

void RailwayCRMFrame::OnMenuFullScreenSelected(wxCommandEvent& event)
{
    ShowFullScreen(!IsFullScreen());
    GetMenuBar()->Check(XRCID("ID_MENU_FULLSCREEN"), IsFullScreen());
    LoadParameter();
}

void RailwayCRMFrame::OnbtnOperatorDefClick(wxCommandEvent& event)
{
    crmDataDefineDialog dlg(this);
    dlg.SetTableMask(maskOperatorDef);
    dlg.ShowModal();
}

void RailwayCRMFrame::OnbtnTrainsDefClick(wxCommandEvent& event)
{
    crmDataDefineDialog dlg(this);
    dlg.SetTableMask(maskTrainsDef);
    dlg.ShowModal();
}

void RailwayCRMFrame::OnbtnImageDefClick(wxCommandEvent& event)
{
    crmDataDefineDialog dlg(this);
    dlg.SetTableMask(maskImageDef);
    dlg.ShowModal();
}

void RailwayCRMFrame::OnbtnGuestsDefClick(wxCommandEvent& event)
{
    crmDataDefineDialog dlg(this);
    dlg.SetTableMask(maskGuestsDef);
    dlg.ShowModal();
}

void RailwayCRMFrame::OnbtnRecordModifyClick(wxCommandEvent& event)
{
    crmDataDefineDialog dlg(this);
    dlg.SetTableMask(maskRecordModify);
    dlg.ShowModal();
}

void RailwayCRMFrame::OnbtnParameterDefClick(wxCommandEvent& event)
{
    ParameterDefDialog dlg(this);
    dlg.ShowModal();
}

void RailwayCRMFrame::OnbtnWelcomeRecordClick(wxCommandEvent& event)
{
    wxString szGroup    = wxT("");
    wxString szUser     = wxT("");
    wxString szCard     = wxT("");
    while( wxEmptyString != (szGroup = DoSelectGroup()) )
    {
        while( wxEmptyString != (szUser = DoSelectUser(szGroup)) )
        {
            while( wxEmptyString != (szCard = DoSelectCard(szGroup,szUser)) )
            {
                if ( DoInputRecord(szGroup,szUser,szCard) )  break;
                szCard = wxT("");
            }
            szUser = wxT("");
            szCard = wxT("");
        }
        szGroup     = wxT("");
        szUser      = wxT("");
        szCard      = wxT("");
    }
}

void RailwayCRMFrame::OnbtnDayAccountClick(wxCommandEvent& event)
{
    crmDayAccountDialog dlg(this);
    dlg.ShowModal();
}

void RailwayCRMFrame::OnbtnMonthAccountClick(wxCommandEvent& event)
{
    crmReportDialog dlg(this);
    dlg.ShowModal();
}

void RailwayCRMFrame::OnMenuShowWelcome(wxCommandEvent& event)
{
    if (!m_dlgWelcomePeopleShow)
        m_dlgWelcomePeopleShow = new crmWelcomePeopleDialog(this);
    m_dlgWelcomePeopleShow->Show(true);
    //this->SetFocus();
}

void RailwayCRMFrame::OnMenuChangePassword(wxCommandEvent& event)
{
    if ( !theOperator().IsLogin() )
    {
        wxLogError(_("please login first!"));
        return;
    }

    crmChangePasswordDialog dlg(this);
    while( dlg.ShowModal() == wxID_OK )
    {
        wxString old_password = dlg.get_oldPassword();
        wxString new_password = dlg.get_newPassword();
        wxString confirm_password = dlg.get_confirmPassword();

        if ( !new_password.IsSameAs(confirm_password) )
        {
            wxMessageBox(_("confirm password failed!"),
                         _("tip:"),
                         wxICON_ERROR | wxOK | wxCENTRE,
                         this);
            continue;
        }

        if ( theOperator().Login(theOperator().GetOperatorName(), old_password.ToUTF8()) )
        {
            theOperator().ChangePassword(old_password.ToUTF8(), new_password.ToUTF8());
            break;
        }
        else
        {
            wxMessageBox(_("verify old password failed!"),
                         _("tip:"),
                         wxICON_ERROR | wxOK | wxCENTRE,
                         this);
            continue;
        }
    }
}

void RailwayCRMFrame::LoadParameter()
{
    if (!IsFullScreen())
    {
        const int w = atoi(theParameter().Get("application","max_screen_width"));
        const int h = atoi(theParameter().Get("application","max_screen_height"));
        SetSize(1,1,w,h);
        Center();
    }
}

void RailwayCRMFrame::LoadHtml(const wxString& utl)
{
    ctlHtml->LoadPage(utl);
    wxSize size = ctlHtml->GetSize();
    size.SetHeight(ctlHtml->GetInternalRepresentation()->GetHeight());
    ctlHtml->SetSize(size.GetWidth(),size.GetHeight());
}

const wxString RailwayCRMFrame::DoSelectGroup()
{
    crmImagesDialog dlg(this);
    dlg.setLargeImage();
    dlg.setFilter();
    if ( dlg.IsOK() && dlg.ShowModal() == wxID_OK )
    {
        return dlg.getSelectLabel();
    }
    return wxEmptyString;
}

const wxString RailwayCRMFrame::DoSelectUser(const wxString& szGroup)
{
    crmImagesDialog dlg(this);
    dlg.setLargeImage();
    dlg.setFilter(szGroup);
    if ( dlg.IsOK() && dlg.ShowModal() == wxID_OK )
    {
        return dlg.getSelectLabel();
    }
    return wxEmptyString;
}

const wxString RailwayCRMFrame::DoSelectCard(const wxString& szGroup, const wxString& szUser)
{
    crmImagesDialog dlg(this);
    dlg.setSmallImage();
    dlg.setPresetImage();
    dlg.setFilter(szGroup,szUser);
    if ( dlg.IsOK() && dlg.ShowModal() == wxID_OK )
    {
        return dlg.getSelectLabel();
    }
    return wxEmptyString;
}

const bool RailwayCRMFrame::DoInputRecord(const wxString& szGroup, const wxString& szUser, const wxString& szCard)
{
    wxDateTime dt = wxDateTime::Now();
    const wxString str_nowtime = dt.FormatISODate();
    const int shift_switch = atoi(theParameter().Get("shift","switch"));
    if ( str_nowtime>m_statistics_date && dt.GetHour() > shift_switch &&
            wxMessageBox(_("now time is large than shift time, are you continue?"),
                         _("tip:"),
                         wxICON_QUESTION|wxYES_NO,
                         this) == wxNO )
    {
        return false;
    }
    crmWelcomeRecordDialog welcomeDlg(this);
    crmRecordDef dsRecords;
    crmObject* pObj     = dsRecords.getNewData();

    strucRecord* rd     = static_cast<strucRecord*>(pObj);
    rd->group_name      = szGroup.ToUTF8();
    rd->user_name       = szUser.ToUTF8();
    rd->card_name       = szCard.ToUTF8();
    rd->statistics_date = m_statistics_date.ToUTF8();

    welcomeDlg.SetDataObject(pObj);
    if ( welcomeDlg.ShowModal()==wxID_OK &&
            ValidateRecord(dsRecords, rd) )
    {
        try
        {
            dsRecords.Insert(pObj);
            DoWelcomeChanged();
            return true;
        }
        catch(CppSQLite3Exception e)
        {
            wxLogError(e.errorMessage());
        }
    }
    return false;
}

void RailwayCRMFrame::DoWelcomeChanged()
{
    if ( atoi(theParameter().Get("welcome","always_show_welcome")) == 1 )
    {
        if ( !m_dlgWelcomePeopleShow )
            m_dlgWelcomePeopleShow = new crmWelcomePeopleDialog(this);
        m_dlgWelcomePeopleShow->Show(true);
    }
    if (m_dlgWelcomePeopleShow)
        m_dlgWelcomePeopleShow->DoChange();
}

bool RailwayCRMFrame::ValidateRecord(crmRecordDef& ds, strucRecord* rd)
{
    //expense user not validate
    if (rd->user_name.compare(theParameter().Get("application", "expense_user_name")) == 0)
    {
        return true;
    }
    //card id is null
    if (rd->card_id.length() == 0)
    {
        return true;
    }
    //validate
    CppSQLite3Buffer szSQL;
    szSQL.format("SELECT COUNT(*) FROM crm_welcome_record "
                 "WHERE group_name=%Q AND user_name=%Q AND card_name=%Q "
                 "AND card_id=%Q AND statistics_date>=%Q",
                 rd->group_name.c_str(),
                 rd->user_name.c_str(),
                 rd->card_name.c_str(),
                 rd->card_id.c_str(),
                 rd->statistics_date.c_str());
    try
    {
        CppSQLite3Table* tbl = ds.GetTable(szSQL);
        const int i = tbl->getIntField(0);
        const wxString str =
            _("card_id '%s', is already used with %d times today, are you continue?");
        if (i>0 &&
                wxMessageBox(wxString::Format(str, rd->card_id.c_str(), i), _("tip:"),
                             wxICON_QUESTION|wxYES_NO, this) != wxYES)
        {
            return false;
        }
        return true;
    }
    catch(CppSQLite3Exception e)
    {
        wxLogError(e.errorMessage());
    }
    return false;
}

void RailwayCRMFrame::InitImageList()
{
    const int       width       = 37;
    const int       height      = 37;
    const int       cols        = 4;
    const int       rows        = 5;
    const int       imgs        = 20;

    if ( m_image_list )
    {
        delete m_image_list;
    }
    m_image_list = new wxImageList(width, height);

    wxString        archive     = wxT("res/resource.zip");
    wxString        archiveURL( wxFileSystem::FileNameToURL(archive) );
    wxFileSystem*   fileSystem  = new wxFileSystem;
    wxFSFile*       file        = fileSystem->OpenFile( archiveURL + wxT("#zip:images/reflection_full.png") );

    wxInputStream*  stream      = file->GetStream();
    wxImage         allBmp(*stream, wxBITMAP_TYPE_PNG);
    delete file;

    if ( !allBmp.IsOk() )
    {
        wxLogError(wxT("load images faild!"));
        return;
    }

    wxColour mask_color(255,255,255);
    if ( allBmp.HasMask() )
    {
        mask_color = wxColour(allBmp.GetMaskRed(),
                           allBmp.GetMaskGreen(),
                           allBmp.GetMaskBlue());
    }
    allBmp.Rescale(width*cols, height*rows);
    wxBitmap        back_bmp(allBmp);

    for(int i=0; i<imgs; ++i)
    {
        const int row = trunc(i*1.0/cols);
        const int col = i - row*cols;
        const wxRect rc(col*width, row*height, width, height);
        m_image_list->Add(back_bmp.GetSubBitmap(rc), mask_color);
    }

    delete fileSystem;

    //set button image
    btnImageDef     ->SetBitmap(m_image_list->GetBitmap(14));
    btnReLogin      ->SetBitmap(m_image_list->GetBitmap( 0));
    btnTrainsDef    ->SetBitmap(m_image_list->GetBitmap(15));
    btnMonthAccount ->SetBitmap(m_image_list->GetBitmap( 6));
    btnOperatorDef  ->SetBitmap(m_image_list->GetBitmap( 2));
    btnParameterDef ->SetBitmap(m_image_list->GetBitmap( 4));
    btnRecordModify ->SetBitmap(m_image_list->GetBitmap( 9));
    btnDayAccount   ->SetBitmap(m_image_list->GetBitmap(17));
    btnGuestsDef    ->SetBitmap(m_image_list->GetBitmap(16));
    btnWelcomeRecord->SetBitmap(m_image_list->GetBitmap( 1));
}

void RailwayCRMFrame::OnMenuTest(wxCommandEvent& event)
{
#ifdef __WXDEBUG__
    testDialog dlg(this, m_image_list);
    dlg.ShowModal();
#endif
}
