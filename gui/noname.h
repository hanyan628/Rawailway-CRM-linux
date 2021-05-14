///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/font.h>
#include <wx/grid.h>
#include <wx/gdicmn.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/treelist.h>
#include <wx/html/htmlwin.h>
#include <wx/menu.h>
#include <wx/frame.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/checkbox.h>
#include <wx/statbox.h>
#include <wx/combobox.h>
#include <wx/spinctrl.h>
#include <wx/statbmp.h>
#include <wx/checklst.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class DataDefDialog
///////////////////////////////////////////////////////////////////////////////
class DataDefDialog : public wxDialog
{
	private:

	protected:
		wxGrid* ID_GRID_DATA;
		wxStaticLine* ID_STATICLINE1;
		wxButton* ID_BUTTON_EDIT;
		wxButton* ID_BUTTON_INSERT;
		wxButton* ID_BUTTON_DELETE;
		wxButton* ID_BUTTON_RETRIEVE;
		wxButton* ID_BUTTON_FILTER;
		wxButton* ID_BUTTON_EXPORT;
		wxButton* ID_BUTTON_IMPORT;
		wxButton* wxID_CANCEL;

	public:

		DataDefDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Data Dictionary Define"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 706,473 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~DataDefDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class InputParameterItemDialog
///////////////////////////////////////////////////////////////////////////////
class InputParameterItemDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* ID_STATICTEXT1;
		wxTextCtrl* ID_TEXTCTRL_CATEGORY;
		wxStaticText* ID_STATICTEXT2;
		wxTextCtrl* ID_TEXTCTRL_KEY;
		wxStaticText* ID_STATICTEXT3;
		wxTextCtrl* ID_TEXTCTRL_VALUE;
		wxStaticLine* ID_STATICLINE1;
		wxStdDialogButtonSizer* m_sdbSizer1;
		wxButton* m_sdbSizer1OK;
		wxButton* m_sdbSizer1Cancel;

	public:

		InputParameterItemDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("input"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~InputParameterItemDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ParameterDefDialog
///////////////////////////////////////////////////////////////////////////////
class ParameterDefDialog : public wxDialog
{
	private:

	protected:
		wxTreeListCtrl* ID_PARAMETER_VIEW;
		wxStaticLine* ID_STATICLINE1;
		wxButton* ID_BUTTON_DELETE;
		wxButton* ID_BUTTON_INSERT;
		wxStdDialogButtonSizer* m_sdbSizer3;
		wxButton* m_sdbSizer3OK;
		wxButton* m_sdbSizer3Cancel;

	public:

		ParameterDefDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("parameter define"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~ParameterDefDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class RailwayCRMFrame
///////////////////////////////////////////////////////////////////////////////
class RailwayCRMFrame : public wxFrame
{
	private:

	protected:
		wxHtmlWindow* ID_HTML_LOGO;
		wxButton* ID_BUTTON_WELCOME;
		wxButton* ID_BUTTON_ACCOUNT_DAY;
		wxButton* ID_BUTTON_ACCOUNT_MONTH;
		wxButton* ID_BUTTON_DEF_TRAIN;
		wxButton* ID_BUTTON_DEF_OPERATOR;
		wxButton* ID_BUTTON_DEF_IMAGE;
		wxButton* ID_BUTTON_DEF_GUEST;
		wxButton* ID_BUTTON_DEF_RECORD;
		wxButton* ID_BUTTON_DEF_PARAMETER;
		wxButton* ID_BUTTON_RELOGIN;
		wxStaticLine* ID_STATICLINE1;
		wxStaticText* ID_STATICTEXT2;
		wxStaticText* ID_OPERATOR_NAME;
		wxStaticText* ID_STATICTEXT4;
		wxStaticText* ID_STATISTICS_DATE;
		wxStaticLine* ID_STATICLINE2;
		wxStaticText* ID_STATICTEXT1;
		wxStaticText* ID_DATETIME_NOW;
		wxMenuBar* m_menubar1;
		wxMenu* m_menu1;
		wxMenu* m_menu2;

	public:

		RailwayCRMFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("RailwayCRM"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1024,768 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~RailwayCRMFrame();

};

///////////////////////////////////////////////////////////////////////////////
/// Class crmChangePasswordDialog
///////////////////////////////////////////////////////////////////////////////
class crmChangePasswordDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* ID_STATICTEXT1;
		wxTextCtrl* ID_OLD_PASSWORD;
		wxStaticText* ID_STATICTEXT2;
		wxTextCtrl* ID_NEW_PASSWORD;
		wxStaticText* ID_STATICTEXT3;
		wxTextCtrl* ID_CONFIRM_PASSWORD;
		wxStaticLine* ID_STATICLINE1;
		wxStdDialogButtonSizer* m_sdbSizer4;
		wxButton* m_sdbSizer4OK;
		wxButton* m_sdbSizer4Cancel;

	public:

		crmChangePasswordDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("change password"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~crmChangePasswordDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class crmDayAccountDialog
///////////////////////////////////////////////////////////////////////////////
class crmDayAccountDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* ID_STATICTEXT2;
		wxDatePickerCtrl* ID_DATEPICKERCTRL_STATISTICS;
		wxCheckBox* ID_CHECK_ALL;
		wxCheckBox* ID_CHECK_DETAIL;
		wxCheckBox* ID_CHECK_GROUP;
		wxCheckBox* ID_CHECK_USER;
		wxCheckBox* ID_CHECK_CARD;
		wxCheckBox* ID_CHECK_TRAIN;
		wxButton* ID_BUTTON_ACCOUNT;
		wxButton* ID_BUTTON_PRINT;
		wxButton* wxID_CANCEL;
		wxStaticLine* ID_STATICLINE1;
		wxHtmlWindow* ID_HTML_REPORT;

	public:

		crmDayAccountDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("day account"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxTAB_TRAVERSAL );
		~crmDayAccountDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class crmGuestDefDialog
///////////////////////////////////////////////////////////////////////////////
class crmGuestDefDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* ID_STATICTEXT1;
		wxTextCtrl* ID_TEXTCTRL_ID;
		wxStaticText* ID_STATICTEXT2;
		wxComboBox* ID_COMBOBOX_GROUP;
		wxStaticText* ID_STATICTEXT3;
		wxComboBox* ID_COMBOBOX_USER;
		wxStaticText* ID_STATICTEXT4;
		wxTextCtrl* ID_TEXTCTRL_CARD;
		wxStaticText* ID_STATICTEXT5;
		wxSpinCtrl* ID_SPINCTRL_PEOPLE;
		wxStaticText* ID_STATICTEXT6;
		wxTextCtrl* ID_TEXTCTRL_PRICE;
		wxStaticLine* ID_STATICLINE1;
		wxStaticText* ID_STATICTEXT8;
		wxStaticBitmap* ID_STATICBITMAP1;
		wxButton* ID_BUTTON_LOAD_SMALL;
		wxStaticLine* ID_STATICLINE3;
		wxStaticText* ID_STATICTEXT9;
		wxStaticBitmap* ID_STATICBITMAP2;
		wxButton* ID_BUTTON_LOAD_LARGE;
		wxStaticLine* ID_STATICLINE2;
		wxStdDialogButtonSizer* m_sdbSizer5;
		wxButton* m_sdbSizer5OK;
		wxButton* m_sdbSizer5Cancel;
		wxButton* ID_BUTTON_RESET;

	public:

		crmGuestDefDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Guest Define"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~crmGuestDefDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class crmGuestFilterDialog
///////////////////////////////////////////////////////////////////////////////
class crmGuestFilterDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* ID_STATICTEXT1;
		wxComboBox* ID_COMBOBOX_GROUP;
		wxStaticText* ID_STATICTEXT2;
		wxComboBox* ID_COMBOBOX_USER;
		wxStaticText* ID_STATICTEXT3;
		wxComboBox* ID_COMBOBOX_CARD;
		wxStaticLine* ID_STATICLINE1;
		wxStdDialogButtonSizer* m_sdbSizer6;
		wxButton* m_sdbSizer6OK;
		wxButton* m_sdbSizer6Cancel;
		wxButton* ID_BUTTON_RESET;

	public:

		crmGuestFilterDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("guest filter"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~crmGuestFilterDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class crmImageDefDialog
///////////////////////////////////////////////////////////////////////////////
class crmImageDefDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* ID_STATICTEXT1;
		wxTextCtrl* ID_TEXTCTRL_ID;
		wxStaticText* ID_STATICTEXT2;
		wxTextCtrl* ID_TEXTCTRL_SIZE;
		wxStaticText* ID_STATICTEXT3;
		wxTextCtrl* ID_TEXTCTRL_NAME;
		wxStaticText* ID_STATICTEXT4;
		wxTextCtrl* ID_TEXTCTRL_TYPE;
		wxStaticBitmap* ID_STATICBITMAP1;
		wxStaticLine* ID_STATICLINE1;
		wxStdDialogButtonSizer* m_sdbSizer7;
		wxButton* m_sdbSizer7OK;
		wxButton* m_sdbSizer7Cancel;
		wxButton* ID_BUTTON_LOAD;
		wxButton* ID_BUTTON_SAVE;
		wxButton* ID_BUTTON_RESET;

	public:

		crmImageDefDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~crmImageDefDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class crmMessageBox
///////////////////////////////////////////////////////////////////////////////
class crmMessageBox : public wxDialog
{
	private:

	protected:
		wxStaticText* ID_STATICTEXT1;
		wxStaticText* ID_LABEL_NAME;
		wxStaticText* ID_STATICTEXT3;
		wxStaticText* ID_LABEL_VERSION;
		wxStaticText* ID_STATICTEXT5;
		wxStaticText* ID_LABEL_AUTHOR;
		wxStaticText* ID_STATICTEXT7;
		wxStaticText* ID_LABEL_EMAIL;
		wxStaticText* ID_STATICTEXT9;
		wxStaticText* ID_LABEL_PHONE;
		wxStaticText* ID_STATICTEXT11;
		wxStaticText* ID_LABEL_BUILDINFO;
		wxStaticLine* ID_STATICLINE1;
		wxStdDialogButtonSizer* m_sdbSizer8;
		wxButton* m_sdbSizer8OK;

	public:

		crmMessageBox( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("About ..."), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~crmMessageBox();

};

///////////////////////////////////////////////////////////////////////////////
/// Class crmOperatorDefDialog
///////////////////////////////////////////////////////////////////////////////
class crmOperatorDefDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* ID_STATICTEXT1;
		wxTextCtrl* ID_TEXTCTRL_ID;
		wxStaticText* ID_STATICTEXT2;
		wxTextCtrl* ID_TEXTCTRL_NAME;
		wxStaticText* ID_STATICTEXT3;
		wxTextCtrl* ID_TEXTCTRL_PASSWORD;
		wxCheckListBox* ID_CHECKLISTBOX_RIGHTS;
		wxStaticLine* ID_STATICLINE1;
		wxStdDialogButtonSizer* m_sdbSizer9;
		wxButton* m_sdbSizer9OK;
		wxButton* m_sdbSizer9Cancel;
		wxButton* ID_BUTTON_RESET;

	public:

		crmOperatorDefDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Operator Define"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~crmOperatorDefDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class crmRecordFilterDialog
///////////////////////////////////////////////////////////////////////////////
class crmRecordFilterDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* ID_STATICTEXT1;
		wxDatePickerCtrl* ID_DATEPICKERCTRL1;
		wxStaticText* ID_STATICTEXT2;
		wxDatePickerCtrl* ID_DATEPICKERCTRL2;
		wxStaticText* ID_STATICTEXT3;
		wxComboBox* ID_COMBOBOX_OPERATOR;
		wxStaticText* ID_STATICTEXT4;
		wxComboBox* ID_COMBOBOX_GROUP;
		wxStaticText* ID_STATICTEXT5;
		wxComboBox* ID_COMBOBOX_USER;
		wxStaticText* ID_STATICTEXT6;
		wxComboBox* ID_COMBOBOX_CARD;
		wxStaticLine* ID_STATICLINE1;
		wxStdDialogButtonSizer* m_sdbSizer10;
		wxButton* m_sdbSizer10OK;
		wxButton* m_sdbSizer10Cancel;
		wxButton* ID_BUTTON_RESET;

	public:

		crmRecordFilterDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Record Filter"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxTAB_TRAVERSAL );
		~crmRecordFilterDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class hkRecordFilterDialog
///////////////////////////////////////////////////////////////////////////////
class hkRecordFilterDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* ID_STATICTEXT1;
		wxDatePickerCtrl* ID_DATEPICKERCTRL1;
		wxStaticText* ID_STATICTEXT2;
		wxDatePickerCtrl* ID_DATEPICKERCTRL2;
		wxStaticLine* ID_STATICLINE1;
		wxStdDialogButtonSizer* m_sdbSizer10;
		wxButton* m_sdbSizer10OK;
		wxButton* m_sdbSizer10Cancel;
		wxButton* ID_BUTTON_RESET;

	public:

		hkRecordFilterDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Record Filter"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxTAB_TRAVERSAL );
		~hkRecordFilterDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class crmRecordModifyDialog
///////////////////////////////////////////////////////////////////////////////
class crmRecordModifyDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* ID_STATICTEXT1;
		wxTextCtrl* ID_TEXTCTRL_OPERATORNAME;
		wxStaticText* ID_STATICTEXT2;
		wxTextCtrl* ID_TEXTCTRL_STATISTICS;
		wxStaticText* ID_STATICTEXT3;
		wxTextCtrl* ID_TEXTCTRL_RTIME;
		wxStaticText* ID_STATICTEXT4;
		wxComboBox* ID_COMBOBOX_GROUP;
		wxStaticText* ID_STATICTEXT5;
		wxComboBox* ID_COMBOBOX_USER;
		wxStaticText* ID_STATICTEXT6;
		wxComboBox* ID_COMBOBOX_CARD;
		wxStaticText* ID_STATICTEXT7;
		wxTextCtrl* ID_TEXTCTRL_CARDID;
		wxStaticText* ID_STATICTEXT8;
		wxTextCtrl* ID_TEXTCTRL_PRESENCE;
		wxStaticText* ID_STATICTEXT13;
		wxTextCtrl* ID_TEXTCTRL_PEOPLE;
		wxStaticText* ID_STATICTEXT9;
		wxTextCtrl* ID_TEXTCTRL_TDATE;
		wxStaticText* ID_STATICTEXT10;
		wxTextCtrl* ID_TEXTCTRL_TRAIN;
		wxStaticText* ID_STATICTEXT11;
		wxTextCtrl* ID_TEXTCTRL_PRICE;
		wxStaticText* ID_STATICTEXT12;
		wxTextCtrl* ID_TEXTCTRL_COMMENT;
		wxStaticLine* ID_STATICLINE1;
		wxStdDialogButtonSizer* m_sdbSizer11;
		wxButton* m_sdbSizer11OK;
		wxButton* m_sdbSizer11Cancel;
		wxButton* ID_BUTTON_RESET;

	public:

		crmRecordModifyDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Record Modify"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~crmRecordModifyDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class crmRightDefDialog
///////////////////////////////////////////////////////////////////////////////
class crmRightDefDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* ID_STATICTEXT1;
		wxTextCtrl* ID_TEXTCTRL_RIGHTID;
		wxStaticText* ID_STATICTEXT2;
		wxTextCtrl* ID_TEXTCTRL_RIGHTNAME;
		wxStaticText* ID_STATICTEXT3;
		wxTextCtrl* ID_TEXTCTRL_RIGHTMASK;
		wxStaticLine* ID_STATICLINE1;
		wxStdDialogButtonSizer* m_sdbSizer12;
		wxButton* m_sdbSizer12OK;
		wxButton* m_sdbSizer12Cancel;
		wxButton* ID_BUTTON3;

	public:

		crmRightDefDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Module Right Define"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~crmRightDefDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class crmTrainDefDialog
///////////////////////////////////////////////////////////////////////////////
class crmTrainDefDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* ID_STATICTEXT1;
		wxTextCtrl* ID_TEXTCTRL_TRAIN;
		wxStaticText* ID_STATICTEXT2;
		wxTextCtrl* ID_TEXTCTRL_STARTSTATION;
		wxStaticText* ID_STATICTEXT3;
		wxTextCtrl* ID_TEXTCTRL_ENDSTATION;
		wxStaticText* ID_STATICTEXT4;
		wxTextCtrl* ID_TEXTCTRL_TIME;
		wxStaticLine* ID_STATICLINE1;
		wxStdDialogButtonSizer* m_sdbSizer13;
		wxButton* m_sdbSizer13OK;
		wxButton* m_sdbSizer13Cancel;
		wxButton* ID_BUTTON_RESET;

	public:

		crmTrainDefDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("train define"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~crmTrainDefDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class crmWelcomePeopleDialog
///////////////////////////////////////////////////////////////////////////////
class crmWelcomePeopleDialog : public wxDialog
{
	private:

	protected:
		wxGrid* ID_GRID_WELCOME;
		wxStaticLine* ID_STATICLINE1;
		wxCheckBox* ID_CHECKBOX_LOCKED;
		wxButton* ID_BUTTON_HIDE;
		wxButton* ID_BUTTON_RETRIEVE;

	public:

		crmWelcomePeopleDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("welcome people"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxSTAY_ON_TOP|wxDEFAULT_DIALOG_STYLE );
		~crmWelcomePeopleDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class crmWelcomeRecordDialog
///////////////////////////////////////////////////////////////////////////////
class crmWelcomeRecordDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* ID_STATICTEXT1;
		wxTextCtrl* ID_TEXTCTRL_GROUP;
		wxStaticText* ID_STATICTEXT2;
		wxTextCtrl* ID_TEXTCTRL_USER;
		wxStaticText* ID_STATICTEXT3;
		wxTextCtrl* ID_TEXTCTRL_CARD;
		wxStaticBitmap* ID_STATICBITMAP1;
		wxStaticText* ID_STATICTEXT4;
		wxTextCtrl* ID_TEXTCTRL_CARDID;
		wxStaticText* ID_STATICTEXT5;
		wxTextCtrl* ID_TEXTCTRL_PRESENCE;
		wxStaticText* ID_STATICTEXT6;
		wxComboBox* ID_COMBOBOX_TRAIN;
		wxStaticText* ID_STATICTEXT7;
		wxSpinCtrl* ID_SPINCTRL_PEOPLECOUNT;
		wxStaticText* ID_STATICTEXT8;
		wxTextCtrl* ID_TEXTCTRL_PRICE;
		wxStaticText* ID_STATICTEXT9;
		wxTextCtrl* ID_TEXTCTRL_COMMENT;
		wxStaticLine* ID_STATICLINE1;
		wxStdDialogButtonSizer* m_sdbSizer14;
		wxButton* m_sdbSizer14OK;
		wxButton* m_sdbSizer14Cancel;
		wxButton* ID_BUTTON_RESET;

	public:

		crmWelcomeRecordDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("welcome input"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~crmWelcomeRecordDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class testDialog
///////////////////////////////////////////////////////////////////////////////
class testDialog : public wxDialog
{
	private:

	protected:
		wxBitmapComboBox* ID_COMBOBOX1;
		wxStaticLine* ID_STATICLINE1;
		wxButton* wxID_OK;
		wxButton* ID_BUTTON2;

	public:

		testDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~testDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class LoginDialog
///////////////////////////////////////////////////////////////////////////////
class LoginDialog : public wxDialog
{
	private:

	protected:
		wxStaticBitmap* ID_STATICBITMAP1;
		wxStaticText* ID_STATICTEXT1;
		wxBitmapComboBox* ID_CHOICE_OPERATOR;
		wxStaticText* ID_STATICTEXT2;
		wxTextCtrl* ID_TEXTCTRL_PASSWORD;
		wxStaticLine* ID_STATICLINE1;
		wxStdDialogButtonSizer* m_sdbSizer15;
		wxButton* m_sdbSizer15OK;
		wxButton* m_sdbSizer15No;
		wxButton* m_sdbSizer15Cancel;

	public:

		LoginDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~LoginDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class crmTrainFilterDialog
///////////////////////////////////////////////////////////////////////////////
class crmTrainFilterDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* ID_STATICTEXT1;
		wxTextCtrl* ID_TEXTCTRL_STARTSTATIONNAME;
		wxStaticText* ID_STATICTEXT2;
		wxTextCtrl* ID_TEXTCTRL_ENDSTATIONNAME;
		wxStaticText* ID_STATICTEXT3;
		wxTextCtrl* ID_TEXTCTRL_TRAINCODE;
		wxStaticLine* ID_STATICLINE1;
		wxStdDialogButtonSizer* m_sdbSizer15;
		wxButton* m_sdbSizer15OK;
		wxButton* m_sdbSizer15Cancel;
		wxButton* ID_BUTTON_RESET;

	public:

		crmTrainFilterDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("train filter"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~crmTrainFilterDialog();

};

