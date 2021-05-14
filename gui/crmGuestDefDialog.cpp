#include "crmGuestDefDialog.h"
#include "./crmvalidator.h"
#include "../src/crmFileInfo.h"
#include <wx/mstream.h>
#include <wx/image.h>
//#include <fstream>
//(*InternalHeaders(crmGuestDefDialog)
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

BEGIN_EVENT_TABLE(crmGuestDefDialog,crmEditDataDialog)
    //(*EventTable(crmGuestDefDialog)
    EVT_INIT_DIALOG(crmGuestDefDialog::OnInit)
    EVT_BUTTON(XRCID("ID_BUTTON_RESET"),crmGuestDefDialog::OnbtnResetClick)
    EVT_BUTTON(XRCID("ID_BUTTON_LOAD_LARGE"),crmGuestDefDialog::OnbtnLoadLFromClick)
    EVT_BUTTON(XRCID("ID_BUTTON_LOAD_SMALL"),crmGuestDefDialog::OnbtnLoadSFromClick)
    EVT_COMMAND(XRCID("ID_COMBOBOX_USER"),wxEVT_COMMAND_COMBOBOX_DROPDOWN,
                crmGuestDefDialog::OnctlUserNameDropDown)
    //*)
END_EVENT_TABLE()

crmGuestDefDialog::crmGuestDefDialog(wxWindow* parent)
{
    //(*Initialize(crmGuestDefDialog)
    wxXmlResource::Get()->LoadObject(this,parent,_T("crmGuestDefDialog"),_T("wxDialog"));
    ctlID           = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_ID"));
    ctlGroupName    = (wxComboBox*)FindWindow(XRCID("ID_COMBOBOX_GROUP"));
    ctlUserName     = (wxComboBox*)FindWindow(XRCID("ID_COMBOBOX_USER"));
    ctlCardName     = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_CARD"));
    ctlPeopleLimit  = (wxSpinCtrl*)FindWindow(XRCID("ID_SPINCTRL_PEOPLE"));
    ctlPriceDefault = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_PRICE"));
    ctlImage1       = (wxStaticBitmap*)FindWindow(XRCID("ID_STATICBITMAP1"));
    ctlImage2       = (wxStaticBitmap*)FindWindow(XRCID("ID_STATICBITMAP2"));
//	ctlStartDate = (wxDatePickerCtrl*)FindWindow(XRCID("ID_DATEPICKERCTRL1"));
//	ctlEndDate = (wxDatePickerCtrl*)FindWindow(XRCID("ID_DATEPICKERCTRL2"));
    //*)

    ctlPeopleLimit  ->SetValue(1);
    ctlPriceDefault ->SetValue("0.00");

    imgsDlg = new crmImagesSelectDialog(this);
}

crmGuestDefDialog::~crmGuestDefDialog()
{
    //(*Destroy(crmGuestDefDialog)
    //*)
    if (imgsDlg)
        delete imgsDlg;
}

void crmGuestDefDialog::SetDataObject(crmObject* pObj)
{
    m_data = static_cast<strucGuest*>(pObj);

    ctlGroupName    ->SetValidator(crmValidator(crmFILTER_EMPTY,   &m_data->group_name));
    ctlUserName     ->SetValidator(crmValidator(crmFILTER_EMPTY,   &m_data->user_name));
    ctlCardName     ->SetValidator(crmValidator(crmFILTER_EMPTY,   &m_data->card_name));
    ctlPeopleLimit  ->SetValidator(crmValidator(crmFILTER_NUMERIC, &m_data->people_limit));
    ctlPriceDefault ->SetValidator(crmValidator(crmFILTER_FLOAT,   &m_data->price_default));
    ctlID           ->SetValidator(crmValidator(crmFILTER_NUMERIC, &m_data->id));
}

bool crmGuestDefDialog::TransferDataFromWindow()
{
    wxDateTime dt = wxDateTime::Now();
    m_data->start_date = dt.FormatISOCombined().c_str();
    m_data->end_date   = dt.FormatISOCombined().c_str();
    m_data->image_l_id = m_imageL_id;
    m_data->image_s_id = m_imageS_id;

    return wxDialog::TransferDataFromWindow();
}

bool crmGuestDefDialog::TransferDataToWindow()
{
    /*
        wxDateTime dt = wxDateTime::Now();
        if (!dt.ParseISOCombined(m_data->start_date.c_str()))
        {
            dt = wxDateTime::Now();
        }
        ctlStartDate->SetValue(dt);
        if (!dt.ParseISOCombined(m_data->end_date.c_str()))
        {
            dt = wxDateTime::Now();
        }
        ctlEndDate->SetValue(dt);
    */
    m_imageL_id = m_data->image_l_id;
    m_imageS_id = m_data->image_s_id;
    showSImage();
    showLImage();
    return wxDialog::TransferDataToWindow();
}

void crmGuestDefDialog::OnInit(wxInitDialogEvent& event)
{
    initListGroup();
    ctlUserName->AppendString(wxT("-"));
    //initListUser(m_data->group_name.c_str());
    event.Skip();
}

void crmGuestDefDialog::OnbtnResetClick(wxCommandEvent& event)
{
    TransferDataToWindow();
}

void crmGuestDefDialog::initListGroup()
{
    wxString szGroup = ctlGroupName->GetValue();
    ctlGroupName->Clear();
    ctlGroupName->SetValue(szGroup);

    CppSQLite3Table* tbl =
        m_dsGuest.GetTable("SELECT DISTINCT group_name FROM crm_guest_def ORDER BY group_name;");
    for(int i=0; i<tbl->numRows(); ++i)
    {
        tbl->setRow(i);
        ctlGroupName->AppendString(wxString::FromUTF8(tbl->fieldValue(0)));
    }
    tbl->finalize();
}

void crmGuestDefDialog::initListUser(const char* szGroup)
{
    wxString szUser = ctlUserName->GetValue();
    ctlUserName->Clear();
    ctlUserName->SetValue(szUser);

    CppSQLite3Buffer szSQL;
    szSQL.format("SELECT DISTINCT user_name FROM crm_guest_def "
                 "WHERE group_name=%Q AND user_name<>'-' ORDER BY user_name;",
                 szGroup);
    ctlUserName->AppendString(wxT("-"));
    CppSQLite3Table* tbl = m_dsGuest.GetTable(szSQL);
    for(int i=0; i<tbl->numRows(); ++i)
    {
        tbl->setRow(i);
        ctlUserName->AppendString(wxString::FromUTF8(tbl->fieldValue(0)));
    }
    tbl->finalize();
}

void crmGuestDefDialog::showLImage()
{
    ctlImage2->SetBitmap(getBitmap(m_imageL_id));
    Refresh();
    Fit();
    Center();
}

void crmGuestDefDialog::showSImage()
{
    ctlImage1->SetBitmap(getBitmap(m_imageS_id));
    Refresh();
    Fit();
    Center();
}

wxBitmap crmGuestDefDialog::getBitmap(const int id)
{
    strucImage* obj = (strucImage*)m_dsImage.getData(id);
    if ( obj && obj->image_size>0 )
    {
        wxMemoryInputStream stream((const char*)obj->GetImageBody(), obj->image_size);
        wxImage img(stream, crmFileInfo::getImageType(obj->image_type));
        if ( img.IsOk() )
        {
            return wxBitmap(img);
        }
    }
    return wxArtProvider::GetBitmap(wxART_HELP);
}

void crmGuestDefDialog::OnctlUserNameDropDown(wxCommandEvent& event)
{
    initListUser(ctlGroupName->GetValue().ToUTF8());
    event.Skip();
}

void crmGuestDefDialog::OnbtnLoadSFromClick(wxCommandEvent& event)
{
    imgsDlg->setSmallImage();
    if ( imgsDlg->ShowModal()==wxID_OK )
    {
        m_imageS_id = imgsDlg->getSelectedID();
        showSImage();
    }
}

void crmGuestDefDialog::OnbtnLoadLFromClick(wxCommandEvent& event)
{
    imgsDlg->setLargeImage();
    if ( imgsDlg->ShowModal()==wxID_OK )
    {
        m_imageL_id = imgsDlg->getSelectedID();
        showLImage();
    }
}
