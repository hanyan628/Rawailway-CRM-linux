#include "InputParameterItemDialog.h"

//(*InternalHeaders(InputParameterItemDialog)
#include <wx/valtext.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/xrc/xmlres.h>
//*)

BEGIN_EVENT_TABLE(InputParameterItemDialog,wxDialog)
	//(*EventTable(InputParameterItemDialog)
    EVT_INIT_DIALOG(InputParameterItemDialog::OnInit)
	//*)
END_EVENT_TABLE()

InputParameterItemDialog::InputParameterItemDialog(wxWindow* parent)
{
    wxXmlResource::Get()->LoadObject(this,parent,_T("InputParameterItemDialog"),_T("wxDialog"));

	ctlCategory = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_CATEGORY"));
	ctlKey = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_KEY"));
	ctlValue = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL_VALUE"));

	szCategory  = wxT("");
	szKey       = wxT("");
	szValue     = wxT("");

	ctlCategory ->SetValidator(wxTextValidator(wxFILTER_EMPTY, &szCategory));
	ctlKey      ->SetValidator(wxTextValidator(wxFILTER_EMPTY, &szKey));
	ctlValue    ->SetValidator(wxTextValidator(wxFILTER_EMPTY, &szValue));
}

InputParameterItemDialog::~InputParameterItemDialog()
{
	//(*Destroy(InputParameterItemDialog)
	//*)
}

void InputParameterItemDialog::OnInit(wxInitDialogEvent& event)
{
    event.Skip();
    Fit();
    Center();
}
