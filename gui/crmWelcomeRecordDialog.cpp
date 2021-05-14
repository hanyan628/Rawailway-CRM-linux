#include "crmWelcomeRecordDialog.h"
#include "../src/crmlogin.h"
#include "../src/parameter.h"
#include "../src/crmFileInfo.h"
#include "./crmvalidator.h"
#include "../datamodule/crm_welcome.h"
//(*InternalHeaders(crmWelcomeRecordDialog)
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/statbmp.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/mstream.h>
#include <wx/msgdlg.h>
#include <wx/debug.h>
#include <wx/tokenzr.h>
//*)

//(*IdInit(crmWelcomeRecordDialog)
//*)

BEGIN_EVENT_TABLE(crmWelcomeRecordDialog,wxDialog)
    //(*EventTable(crmWelcomeRecordDialog)
    EVT_INIT_DIALOG(crmWelcomeRecordDialog::OnInit)
    EVT_BUTTON(XRCID("ID_BUTTON_RESET"),crmWelcomeRecordDialog::OnbtnResetClick)
    EVT_SPINCTRL(XRCID("ID_SPINCTRL_PEOPLECOUNT"), crmWelcomeRecordDialog::OnSpinCtrlUpdate)
    EVT_TEXT_ENTER(XRCID("ID_TEXTCTRL_CARDID"), crmWelcomeRecordDialog::OnEnter)
    EVT_TEXT_ENTER(XRCID("ID_TEXTCTRL_PRESENCE"), crmWelcomeRecordDialog::OnEnter)
    EVT_TEXT_ENTER(XRCID("ID_COMBOBOX_TRAIN"), crmWelcomeRecordDialog::OnInputTrainInfoEnter)
    EVT_TEXT_ENTER(XRCID("ID_SPINCTRL_PEOPLECOUNT"), crmWelcomeRecordDialog::OnEnter)
    EVT_TEXT_ENTER(XRCID("ID_TEXTCTRL_PRICE"), crmWelcomeRecordDialog::OnEnter)
    EVT_TEXT_ENTER(XRCID("ID_TEXTCTRL_COMMENT"), crmWelcomeRecordDialog::OnEnter)
    //*)
END_EVENT_TABLE()

crmWelcomeRecordDialog::crmWelcomeRecordDialog(wxWindow* parent)
{
    //(*Initialize(crmWelcomeRecordDialog)
    wxXmlResource::Get()->LoadObject(this,parent,_T("crmWelcomeRecordDialog"),_T("wxDialog"));

    ctlGroupName    = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_GROUP"));
    ctlUserName     = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_USER"));
    ctlCardName     = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_CARD"));
    ctlCardID       = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_CARDID"));
    ctlPresenceName = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_PRESENCE"));
    ctlTrainInfo    = (wxComboBox*)FindWindow(XRCID("ID_COMBOBOX_TRAIN"));
    ctlPeopleCount  = (wxSpinCtrl*)FindWindow(XRCID("ID_SPINCTRL_PEOPLECOUNT"));
    ctlPrice        = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_PRICE"));
    ctlComment      = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_COMMENT"));
    //*)
    m_logo_id       = 2;
    m_price_default = 0.00;

    ctlPeopleCount  ->SetValue(1);
    ctlPeopleCount  ->SetWindowStyle(ctlPeopleCount->GetWindowStyle() | wxTE_PROCESS_ENTER);
}

crmWelcomeRecordDialog::~crmWelcomeRecordDialog()
{
    //(*Destroy(crmWelcomeRecordDialog)
    //*)
}


void crmWelcomeRecordDialog::OnInit(wxInitDialogEvent& event)
{
    initGuestInfo();
    initListTrainInfo();
    showLogo();
    Fit();
    Center();
    event.Skip();
}

void crmWelcomeRecordDialog::OnbtnResetClick(wxCommandEvent& event)
{
    TransferDataToWindow();
}

void crmWelcomeRecordDialog::SetDataObject(crmObject* pObj)
{
    m_record = static_cast<strucRecord*>(pObj);

    if (m_record)
    {
        ctlCardID       ->SetValidator(crmValidator(crmFILTER_ASCII,    &m_record->card_id));
        ctlPresenceName ->SetValidator(crmValidator(crmFILTER_NONE,     &m_record->presence_name));
        ctlTrainInfo    ->SetValidator(crmValidator(crmFILTER_TRAININFO,&m_record->train_code));
        ctlPeopleCount  ->SetValidator(crmValidator(crmFILTER_NUMERIC,  &m_record->people_count));
        ctlPrice        ->SetValidator(crmValidator(crmFILTER_FLOAT,    &m_record->price));
        ctlComment      ->SetValidator(crmValidator(crmFILTER_NONE,     &m_record->comment));
    }
}

bool crmWelcomeRecordDialog::TransferDataFromWindow()
{
    wxDateTime dt = wxDateTime::Now();
    m_record->record_time   = dt.FormatISOCombined().c_str();
    m_record->operator_name = theOperator().GetOperatorName();
    m_record->train_date    = wxString::Format(wxT("%04d-%02d-%02d"),
                                            dt.GetYear(),
                                            dt.GetMonth()+1,
                                            dt.GetDay()).c_str();
    return wxDialog::TransferDataFromWindow();
}

bool crmWelcomeRecordDialog::TransferDataToWindow()
{
    ctlGroupName->SetValue(wxString::FromUTF8(m_record->group_name.c_str()));
    ctlUserName ->SetValue(wxString::FromUTF8(m_record->user_name.c_str()));
    ctlCardName ->SetValue(wxString::FromUTF8(m_record->card_name.c_str()));

    const bool ret = wxDialog::TransferDataToWindow();
#if defined(__UNIX__)
    ctlCardID->SetFocus();
    ctlCardID->SelectAll();
#endif

    return ret;
}

void crmWelcomeRecordDialog::initListTrainInfo()
{
    ctlTrainInfo->Clear();
    for(int i=0; i<theWelcomeDisplay().Count(); ++i)
    {
        theWelcomeDisplay().setRow(i);
        ctlTrainInfo->AppendString(
            wxString::FromUTF8(theWelcomeDisplay().getTrainInfo()) );
        //wxLogMessage(wxString::FromUTF8(theWelcomeDisplay().getTrainInfo()));
    }
}

void crmWelcomeRecordDialog::showLogo()
{
    wxStaticBitmap* pLogo   = (wxStaticBitmap*)FindWindow(XRCID("ID_STATICBITMAP1"));
    const int scale_height  = atoi(theParameter().Get("logo_image","large_height"));
    const int scale_width   = atoi(theParameter().Get("logo_image","large_width"));

    crmImageDef dsImages;
    strucImage* bmp = (strucImage*)dsImages.getData(m_logo_id);

    if ( bmp && bmp->image_size>0 )
    {
        wxMemoryInputStream stream((const char*)bmp->GetImageBody(), bmp->image_size);
        wxImage img(stream, crmFileInfo::getImageType(bmp->image_type));
        wxBitmap bmpBuf(img.IsOk() ? img.Scale(scale_width, scale_height) : wxArtProvider::GetBitmap(wxART_HELP));
        pLogo->SetBitmap(bmpBuf);
    }
    else
    {
        pLogo->SetBitmap(wxArtProvider::GetBitmap(wxART_ERROR));
    }

}

void crmWelcomeRecordDialog::initGuestInfo()
{
    crmGuestDef dsGuest;
    CppSQLite3Buffer szSQL;
    // logo image id
    szSQL.format("SELECT image_l_id FROM crm_guest_def WHERE "
                 "group_name=%Q AND user_name=%Q AND card_name='-';",
                 m_record->group_name.c_str(),
                 m_record->user_name.c_str());
    CppSQLite3Table* tbl = dsGuest.GetTable(szSQL);
    if ( tbl->numRows() < 1 )
    {
        m_logo_id = 2;
    }
    else
    {
        m_logo_id = tbl->getIntField(0);
    }

    // people limit
    szSQL.format("SELECT people_limit, price_default FROM crm_guest_def WHERE "
                 "group_name=%Q AND user_name=%Q AND card_name=%Q;",
                 m_record->group_name.c_str(),
                 m_record->user_name.c_str(),
                 m_record->card_name.c_str());
    tbl = dsGuest.GetTable(szSQL);

    const wxString user_name = m_record->user_name.c_str();
    if ( inParameter(user_name) )
    {
        m_price_default = tbl->getFloatField(1) > 0 ?
                          tbl->getFloatField(1) : atof( theParameter().Get("application","expense_default_price") );
        m_record->people_count = tbl->getIntField(0);
        m_record->price = m_record->people_count * m_price_default;
    }

    wxCHECK2_MSG(tbl->numRows()>0, ctlPeopleCount->SetRange(1, 1), _("this guest is not active!"));
    wxCHECK2_MSG(tbl->getIntField(0)>0, ctlPeopleCount->SetRange(1, 1), _("people limit is zero!"));
    ctlPeopleCount->SetRange(1, tbl->getIntField(0));

}

void crmWelcomeRecordDialog::OnSpinCtrlUpdate(wxSpinEvent& event)
{
    const wxString user_name = m_record->user_name.c_str();
    if ( inParameter(user_name) )
    {
        ctlPrice->SetValue(wxString::Format(wxT("%.2f"),
                                            event.GetPosition() * m_price_default));
    }
    event.Skip();
}

bool crmWelcomeRecordDialog::selectTrainInfo()
{
    if ( ctlTrainInfo->GetCurrentSelection() == wxNOT_FOUND )
    {
        wxString train_code = ctlTrainInfo->GetValue().Trim();
        train_code.MakeUpper();
        const int row = theTrainDir().Find(train_code.ToUTF8());
        if ( row<0 &&
                wxMessageBox(_("the train code not int dir, are you continue?"),
                             _("tip:"),
                             wxICON_QUESTION|wxYES_NO,
                             this) == wxNO )
        {
            ctlTrainInfo->SetFocus();
            return false;
        }
        if ( row>=0 )
        {
            ctlTrainInfo->SetValue(wxString::FromUTF8(theTrainDir().GetText(row)));
	    //wxLogMessage( wxString::FromUTF8(theTrainDir().GetText(row)) );
        }
    }
    return true;
}

bool crmWelcomeRecordDialog::inParameter(const wxString& sub)
{
    const wxString str = theParameter().Get("application", "expense_user_name");
    wxStringTokenizer tkz(str, wxT(","));
    while(tkz.HasMoreTokens())
    {
        const wxString token = tkz.GetNextToken();
        if ( token == sub )
        {
            return true;
        }
    }
    return false;
}

/***************************************************************************************
        with Enter Key ----  switch control
****************************************************************************************/
void crmWelcomeRecordDialog::OnInputTrainInfoEnter(wxCommandEvent& event)
{
    if ( selectTrainInfo() )
        DoNavigate(wxNavigationKeyEvent::IsForward | wxNavigationKeyEvent::FromTab);
}

void crmWelcomeRecordDialog::OnEnter(wxCommandEvent& event)
{
    DoNavigate(wxNavigationKeyEvent::IsForward | wxNavigationKeyEvent::FromTab);
}
