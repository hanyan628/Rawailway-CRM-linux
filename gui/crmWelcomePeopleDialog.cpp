#include "crmWelcomePeopleDialog.h"
#include "../datamodule/crm_welcome.h"
#include "../src/parameter.h"

//(*InternalHeaders(crmWelcomePeopleDialog)
#include <wx/xrc/xmlres.h>
#include <wx/settings.h>
#include <wx/colour.h>
#include <wx/stattext.h>
//*)

//(*IdInit(crmWelcomePeopleDialog)
#define ID_TIMER_WELCOME 1000
//*)

BEGIN_EVENT_TABLE(crmWelcomePeopleDialog,wxDialog)
    //(*EventTable(crmWelcomePeopleDialog)
    EVT_INIT_DIALOG(crmWelcomePeopleDialog::OnInit)
    EVT_BUTTON(XRCID("ID_BUTTON_RETRIEVE"),crmWelcomePeopleDialog::OnButtonRetrieve)
    EVT_BUTTON(XRCID("ID_BUTTON_HIDE"),crmWelcomePeopleDialog::OnButtonHide)
    EVT_CHECKBOX(XRCID("ID_CHECKBOX_LOCKED"),crmWelcomePeopleDialog::OnCheckLocked)
    EVT_IDLE(crmWelcomePeopleDialog::OnIdle)
    //*)
END_EVENT_TABLE()

crmWelcomePeopleDialog::crmWelcomePeopleDialog(wxWindow* parent)
    :m_isTaskFinished(true), m_current_row(0)
{
    //(*Initialize(crmWelcomePeopleDialog)
    wxXmlResource::Get()->LoadObject(this,parent,_T("crmWelcomePeopleDialog"),_T("wxDialog"));

    ctlWelcomeList  = (wxGrid*)FindWindow(XRCID("ID_GRID_WELCOME"));
    ctlLocked       = (wxCheckBox*)FindWindow(XRCID("ID_CHECKBOX_LOCKED"));
    //*)
    InitGrid();
}

crmWelcomePeopleDialog::~crmWelcomePeopleDialog()
{
    //(*Destroy(crmWelcomePeopleDialog)
    //*)
}

void crmWelcomePeopleDialog::OnInit(wxInitDialogEvent& event)
{
    Retrieve();

    ctlLocked->SetValue(true);
    long window_style   =   GetWindowStyle();
    window_style        |=  wxSTAY_ON_TOP;
    SetWindowStyle(window_style);

    event.Skip();
}

void crmWelcomePeopleDialog::OnButtonHide(wxCommandEvent& event)
{
    Show(false);
}

void crmWelcomePeopleDialog::OnButtonRetrieve(wxCommandEvent& event)
{
    Retrieve();
}

void crmWelcomePeopleDialog::OnCheckLocked(wxCommandEvent& event)
{
    long window_style = GetWindowStyle();
    if ( ctlLocked->GetValue() )
    {
        window_style |= wxSTAY_ON_TOP;
    }
    else
    {
        window_style &= ~wxSTAY_ON_TOP;
    }
    SetWindowStyle(window_style);
}

int crmWelcomePeopleDialog::Retrieve()
{
    wxWindowDisabler DisableAll;
    wxDateTime dt = wxDateTime::Now();
    wxString start = wxString::Format(wxT("%02d:%02d"), dt.GetHour(), dt.GetMinute());
    dt += wxTimeSpan::Hours(atoi(theParameter().Get("welcome","show_range")));
    wxString end = wxString::Format(wxT("%02d:%02d"), dt.GetHour(), dt.GetMinute());
    theWelcomeDisplay().Refresh(start.c_str(),end.c_str());
    dt = wxDateTime::Now();
    if ( theWelcomeDisplay().Count()<0 )
    {
        FindWindow(XRCID("ID_BUTTON_RETRIEVE"))->Enable(true);
        wxLogError(_("the train dir load faild!"));
        return -1;
    }
    ctlWelcomeList->DeleteRows(0,ctlWelcomeList->GetNumberRows(),true);
    ctlWelcomeList->AppendRows(theWelcomeDisplay().Count(),true);

    for(int i=0; i<theWelcomeDisplay().Count(); ++i)
    {
        theWelcomeDisplay().setRow(i);
        ctlWelcomeList->SetCellValue(i,0,
                                     wxString::FromUTF8(theWelcomeDisplay().getTrainInfo()));
        int people_count = 0;
        try
        {
            people_count = theWelcomeDisplay().getPeopleCount(dt.FormatISODate().c_str());
        }
        catch(CppSQLite3Exception e)
        {
            wxLogError(e.errorMessage());
        }
        ctlWelcomeList->SetCellValue(i,1,
                                     wxString::Format(wxT("%d"),people_count));
        const wxColor* cl = ( people_count > 0 ? wxRED : wxLIGHT_GREY );
        ctlWelcomeList->SetCellBackgroundColour(i,0,*cl);
        ctlWelcomeList->SetCellBackgroundColour(i,1,*cl);
    }
    AutoSizeAndPos();
    return theWelcomeDisplay().Count();
}

void crmWelcomePeopleDialog::AutoSizeAndPos()
{
    //ctlWelcomeList->Fit();
    //Fit();
    wxSize size = GetBestSize();
    wxSize szGrid = ctlWelcomeList->GetBestSize();
    szGrid += wxSize(40,0);
    if ( size.GetWidth() < szGrid.GetWidth() )
        size.SetWidth(szGrid.GetWidth());
    if ( size.GetHeight() < szGrid.GetHeight() )
        size.SetHeight(szGrid.GetHeight());
    const int screen_width = wxSystemSettings::GetMetric(wxSYS_SCREEN_X);
    const int screen_height = wxSystemSettings::GetMetric(wxSYS_SCREEN_Y);

    if ( size.GetWidth() > screen_width )
    {
        size.SetWidth(screen_width);
    }
    if ( size.GetHeight() > screen_height )
    {
        size.SetHeight(screen_height);
    }
    const int posX = screen_width - size.GetWidth();
    const int posY = (screen_height - size.GetHeight()) / 2;
    SetSize(posX,posY,size.GetWidth(),size.GetHeight());
}

void crmWelcomePeopleDialog::InitGrid()
{
    //font
    ctlWelcomeList->CreateGrid(1, 2);
    ctlWelcomeList->SetSelectionMode(wxGrid::wxGridSelectRows);
    ctlWelcomeList->SetRowLabelSize(0);
    wxFont ft = ctlWelcomeList->GetFont();
    ft = ft.Scale(0.78);
    ctlWelcomeList->SetDefaultCellFont(ft);

    //col and row
    ctlWelcomeList->SetDefaultRowSize(20, true);
    ctlWelcomeList->SetColSize(0,180);
    ctlWelcomeList->SetColSize(1,30);
    ctlWelcomeList->SetColLabelSize(0);
    ctlWelcomeList->SetRowLabelSize(0);
    ctlWelcomeList->SetDefaultCellAlignment(wxALIGN_LEFT,wxALIGN_CENTER);
    ctlWelcomeList->SetColFormatNumber(1);
    ctlWelcomeList->EnableEditing(false);
}

void crmWelcomePeopleDialog::OnIdle(wxIdleEvent& event)
{
    if ( !m_isTaskFinished && DoTask() )
    {
        event.RequestMore();
    }
    event.Skip();
}

bool crmWelcomePeopleDialog::DoTask()
{
    if ( m_current_row >= theWelcomeDisplay().Count() )
    {
        m_current_row = 0;
        m_isTaskFinished = true;
        return false;
    }

    wxWindowDisabler DisableAll;
    wxDateTime dt = wxDateTime::Now();
    wxString start = wxString::Format(wxT("%02d:%02d"), dt.GetHour(), dt.GetMinute());
    dt += wxTimeSpan::Hours(atoi(theParameter().Get("welcome","show_range")));
    wxString end = wxString::Format(wxT("%02d:%02d"), dt.GetHour(), dt.GetMinute());
    theWelcomeDisplay().Refresh(start.c_str(),end.c_str());
    if ( ctlWelcomeList->GetNumberRows() != theWelcomeDisplay().Count() )
    {
        const int n =  theWelcomeDisplay().Count() - ctlWelcomeList->GetNumberRows();
        if ( n > 0 )
            ctlWelcomeList->AppendRows(n,true);
        else
            ctlWelcomeList->DeleteRows(ctlWelcomeList->GetNumberRows() + n, n, true);

        AutoSizeAndPos();
    }

    theWelcomeDisplay().setRow(m_current_row);

    if ( ctlWelcomeList->GetCellValue(m_current_row,0) !=
            wxString::FromUTF8(theWelcomeDisplay().getTrainInfo()) )
    {
        ctlWelcomeList->SetCellValue(m_current_row,0,
                                     wxString::FromUTF8(theWelcomeDisplay().getTrainInfo()));
    }

    int people_count = 0;
    try
    {
        dt = wxDateTime::Now();
        people_count = theWelcomeDisplay().getPeopleCount(dt.FormatISODate().c_str());
    }
    catch(CppSQLite3Exception e)
    {
        wxLogError(e.errorMessage());
    }

    if ( atoi(ctlWelcomeList->GetCellValue(m_current_row,1).c_str()) != people_count )
    {
        ctlWelcomeList->SetCellValue(m_current_row,1,
                                     wxString::Format(wxT("%d"),people_count));
        const wxColor* cl = ( people_count > 0 ? wxRED : wxLIGHT_GREY );
        ctlWelcomeList->SetCellBackgroundColour(m_current_row,0,*cl);
        ctlWelcomeList->SetCellBackgroundColour(m_current_row,1,*cl);
    }

    ++m_current_row;
    return true;
}
