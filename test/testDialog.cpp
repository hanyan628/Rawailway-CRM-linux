#include "testDialog.h"

//(*InternalHeaders(testDialog)
#include <wx/xrc/xmlres.h>
//*)

//(*IdInit(testDialog)
//*)

BEGIN_EVENT_TABLE(testDialog,wxDialog)
	//(*EventTable(testDialog)
    EVT_COMBOBOX(XRCID("ID_COMBOBOX1"), testDialog::OnComboBoxSelected)
	//*)
END_EVENT_TABLE()

testDialog::testDialog(wxWindow* parent, wxImageList* imgs)
    :m_image_list(imgs)
{
	//(*Initialize(testDialog)
	wxXmlResource::Get()->LoadObject(this,parent,_T("testDialog"),_T("wxDialog"));
	ComboBox1 = (wxBitmapComboBox*)FindWindow(XRCID("ID_COMBOBOX1"));
	StaticLine1 = (wxStaticLine*)FindWindow(XRCID("ID_STATICLINE1"));
	Button2 = (wxButton*)FindWindow(XRCID("ID_BUTTON2"));
	//*)
	InitList();
	Fit();
}

testDialog::~testDialog()
{
	//(*Destroy(testDialog)
	//*)
}

void testDialog::InitList()
{
	if(m_image_list)
	{
        for( int i=0; i<m_image_list->GetImageCount(); ++i )
        {
            ComboBox1->Append(wxString::Format(wxT("%d"),i), m_image_list->GetBitmap(i));
        }
	}

}

void testDialog::OnComboBoxSelected(wxCommandEvent& event)
{
    const int selected = ComboBox1->GetCurrentSelection();
    if (selected>=0)
    {
        Button2->SetBitmapLabel(m_image_list->GetBitmap(selected));
        Button2->SetLabel(wxString::Format(wxT("index of %d"), selected));
        Fit();
    }
}
