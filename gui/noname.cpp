///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "noname.h"

///////////////////////////////////////////////////////////////////////////

DataDefDialog::DataDefDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer(  );

	ID_GRID_DATA = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxSize( 723,351 ), 0 );

	// Grid
	ID_GRID_DATA->CreateGrid( 5, 5 );
	ID_GRID_DATA->EnableEditing( true );
	ID_GRID_DATA->EnableGridLines( true );
	ID_GRID_DATA->EnableDragGridSize( false );
	ID_GRID_DATA->SetMargins( 0, 0 );

	// Columns
	ID_GRID_DATA->EnableDragColMove( false );
	ID_GRID_DATA->EnableDragColSize( true );
	ID_GRID_DATA->SetColLabelSize( 30 );
	ID_GRID_DATA->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	ID_GRID_DATA->EnableDragRowSize( true );
	ID_GRID_DATA->SetRowLabelSize( 80 );
	ID_GRID_DATA->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	ID_GRID_DATA->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer2->Add( ID_GRID_DATA, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 10 );


	bSizer1->Add( bSizer2, 1, wxALL|wxEXPAND|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer(  );

	ID_STATICLINE1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxSize( 10,-1 ), wxLI_VERTICAL );
	bSizer3->Add( ID_STATICLINE1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1->Add( bSizer3, 0, wxALL|wxEXPAND|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	ID_BUTTON_EDIT = new wxButton( this, wxID_ANY, wxT("&Edit"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_EDIT->SetDefault();
	bSizer4->Add( ID_BUTTON_EDIT, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	ID_BUTTON_INSERT = new wxButton( this, wxID_ANY, wxT("&Insert"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_INSERT->SetDefault();
	bSizer4->Add( ID_BUTTON_INSERT, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	ID_BUTTON_DELETE = new wxButton( this, wxID_ANY, wxT("&Delete"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_DELETE->SetDefault();
	bSizer4->Add( ID_BUTTON_DELETE, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	ID_BUTTON_RETRIEVE = new wxButton( this, wxID_ANY, wxT("&Retrieve"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_RETRIEVE->SetDefault();
	bSizer4->Add( ID_BUTTON_RETRIEVE, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	ID_BUTTON_FILTER = new wxButton( this, wxID_ANY, wxT("&Filter"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_FILTER->SetDefault();
	bSizer4->Add( ID_BUTTON_FILTER, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	ID_BUTTON_EXPORT = new wxButton( this, wxID_ANY, wxT("Export"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_EXPORT->SetDefault();
	bSizer4->Add( ID_BUTTON_EXPORT, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	ID_BUTTON_IMPORT = new wxButton( this, wxID_ANY, wxT("I&mport"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_IMPORT->SetDefault();
	bSizer4->Add( ID_BUTTON_IMPORT, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	wxID_CANCEL = new wxButton( this, wxID_ANY, wxT("Return"), wxDefaultPosition, wxDefaultSize, 0 );

	wxID_CANCEL->SetDefault();
	bSizer4->Add( wxID_CANCEL, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1->Add( bSizer4, 0, wxALL|wxEXPAND|wxALIGN_RIGHT|wxALIGN_BOTTOM, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
}

DataDefDialog::~DataDefDialog()
{
}

InputParameterItemDialog::InputParameterItemDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 3, 2, 0, 0 );
	fgSizer1->AddGrowableCol( 1 );
	fgSizer1->AddGrowableRow( 1 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	ID_STATICTEXT1 = new wxStaticText( this, wxID_ANY, wxT("category:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT1->Wrap( 0 );
	fgSizer1->Add( ID_STATICTEXT1, 1, wxALL, 5 );

	ID_TEXTCTRL_CATEGORY = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( ID_TEXTCTRL_CATEGORY, 3, wxALL|wxEXPAND, 5 );

	ID_STATICTEXT2 = new wxStaticText( this, wxID_ANY, wxT("key:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT2->Wrap( 0 );
	fgSizer1->Add( ID_STATICTEXT2, 1, wxALL, 5 );

	ID_TEXTCTRL_KEY = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( ID_TEXTCTRL_KEY, 3, wxALL|wxEXPAND, 5 );

	ID_STATICTEXT3 = new wxStaticText( this, wxID_ANY, wxT("value:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT3->Wrap( 0 );
	fgSizer1->Add( ID_STATICTEXT3, 1, wxALL, 5 );

	ID_TEXTCTRL_VALUE = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( ID_TEXTCTRL_VALUE, 3, wxALL|wxEXPAND, 5 );


	bSizer5->Add( fgSizer1, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer(  );

	ID_STATICLINE1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxSize( 10,-1 ), wxLI_HORIZONTAL );
	bSizer6->Add( ID_STATICLINE1, 1, wxALL|wxEXPAND, 5 );


	bSizer5->Add( bSizer6, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer1OK = new wxButton( this, wxID_OK );
	m_sdbSizer1->AddButton( m_sdbSizer1OK );
	m_sdbSizer1Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer1->AddButton( m_sdbSizer1Cancel );
	m_sdbSizer1->Realize();

	bSizer7->Add( m_sdbSizer1, 0, wxALL|wxEXPAND, 5 );


	bSizer5->Add( bSizer7, 0, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer5 );
	this->Layout();
	bSizer5->Fit( this );
}

InputParameterItemDialog::~InputParameterItemDialog()
{
}

ParameterDefDialog::ParameterDefDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer(  );

	ID_PARAMETER_VIEW = new wxTreeListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTL_DEFAULT_STYLE );

	bSizer13->Add( ID_PARAMETER_VIEW, 1, wxEXPAND | wxALL, 5 );


	bSizer12->Add( bSizer13, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );

	ID_STATICLINE1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxSize( 10,-1 ), wxLI_HORIZONTAL );
	bSizer14->Add( ID_STATICLINE1, 1, wxALL, 5 );


	bSizer12->Add( bSizer14, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );

	ID_BUTTON_DELETE = new wxButton( this, wxID_ANY, wxT("Delete(&D)"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_DELETE->SetDefault();
	bSizer15->Add( ID_BUTTON_DELETE, 0, wxALL, 5 );

	ID_BUTTON_INSERT = new wxButton( this, wxID_ANY, wxT("Insert(&I)"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_INSERT->SetDefault();
	bSizer15->Add( ID_BUTTON_INSERT, 0, wxALL, 5 );

	m_sdbSizer3 = new wxStdDialogButtonSizer();
	m_sdbSizer3OK = new wxButton( this, wxID_OK );
	m_sdbSizer3->AddButton( m_sdbSizer3OK );
	m_sdbSizer3Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer3->AddButton( m_sdbSizer3Cancel );
	m_sdbSizer3->Realize();

	bSizer15->Add( m_sdbSizer3, 0, wxALL, 5 );


	bSizer12->Add( bSizer15, 0, wxALL, 5 );


	this->SetSizer( bSizer12 );
	this->Layout();
	bSizer12->Fit( this );

	this->Centre( wxBOTH );
}

ParameterDefDialog::~ParameterDefDialog()
{
}

RailwayCRMFrame::RailwayCRMFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Sans") ) );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxVERTICAL );

	ID_HTML_LOGO = new wxHtmlWindow( this, wxID_ANY, wxDefaultPosition, wxSize( 967,128 ), 0 );
	bSizer17->Add( ID_HTML_LOGO, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer(  );


	bSizer17->Add( bSizer18, 0, wxALL|wxEXPAND, 5 );


	bSizer16->Add( bSizer17, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer(  );

	wxBoxSizer* bSizer130;
	bSizer130 = new wxBoxSizer( wxVERTICAL );

	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 3, 4, 0, 0 );

	ID_BUTTON_WELCOME = new wxButton( this, wxID_ANY, wxT("Welcome Record"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_WELCOME->SetDefault();
	gSizer1->Add( ID_BUTTON_WELCOME, 2, wxALL|wxEXPAND, 5 );

	ID_BUTTON_ACCOUNT_DAY = new wxButton( this, wxID_ANY, wxT("Day Account"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_ACCOUNT_DAY->SetDefault();
	gSizer1->Add( ID_BUTTON_ACCOUNT_DAY, 2, wxALL|wxEXPAND, 5 );

	ID_BUTTON_ACCOUNT_MONTH = new wxButton( this, wxID_ANY, wxT("Month Account"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_ACCOUNT_MONTH->SetDefault();
	gSizer1->Add( ID_BUTTON_ACCOUNT_MONTH, 2, wxALL|wxEXPAND, 5 );

	ID_BUTTON_DEF_TRAIN = new wxButton( this, wxID_ANY, wxT("Trains Define"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_DEF_TRAIN->SetDefault();
	gSizer1->Add( ID_BUTTON_DEF_TRAIN, 2, wxALL|wxEXPAND, 5 );

	ID_BUTTON_DEF_OPERATOR = new wxButton( this, wxID_ANY, wxT("Operator Define"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_DEF_OPERATOR->SetDefault();
	gSizer1->Add( ID_BUTTON_DEF_OPERATOR, 2, wxALL|wxEXPAND, 5 );

	ID_BUTTON_DEF_IMAGE = new wxButton( this, wxID_ANY, wxT("Image Define"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_DEF_IMAGE->SetDefault();
	gSizer1->Add( ID_BUTTON_DEF_IMAGE, 2, wxALL|wxEXPAND, 5 );

	ID_BUTTON_DEF_GUEST = new wxButton( this, wxID_ANY, wxT("Guests Define"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_DEF_GUEST->SetDefault();
	gSizer1->Add( ID_BUTTON_DEF_GUEST, 2, wxALL|wxEXPAND, 5 );

	ID_BUTTON_DEF_RECORD = new wxButton( this, wxID_ANY, wxT("Record Modify"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_DEF_RECORD->SetDefault();
	gSizer1->Add( ID_BUTTON_DEF_RECORD, 2, wxALL|wxEXPAND, 5 );

	ID_BUTTON_DEF_PARAMETER = new wxButton( this, wxID_ANY, wxT("Parameter Define"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_DEF_PARAMETER->SetDefault();
	gSizer1->Add( ID_BUTTON_DEF_PARAMETER, 1, wxALL|wxEXPAND, 5 );

	ID_BUTTON_RELOGIN = new wxButton( this, wxID_ANY, wxT("ReLogin"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_RELOGIN->SetDefault();
	gSizer1->Add( ID_BUTTON_RELOGIN, 1, wxALL|wxEXPAND, 5 );


	bSizer130->Add( gSizer1, 1, wxALL|wxEXPAND, 10 );


	bSizer19->Add( bSizer130, 1, wxEXPAND, 5 );


	bSizer16->Add( bSizer19, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );

	ID_STATICLINE1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxSize( 10,-1 ), wxLI_HORIZONTAL );
	bSizer21->Add( ID_STATICLINE1, 1, wxALL|wxEXPAND, 5 );


	bSizer16->Add( bSizer21, 0, wxALL|wxEXPAND, 10 );

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxVERTICAL );

	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer3->AddGrowableCol( 0 );
	fgSizer3->AddGrowableCol( 1 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	ID_STATICTEXT2 = new wxStaticText( this, wxID_ANY, wxT("operator name:"), wxDefaultPosition, wxSize( 200,-1 ), 0 );
	ID_STATICTEXT2->Wrap( -1 );
	fgSizer3->Add( ID_STATICTEXT2, 1, wxALL, 5 );

	ID_OPERATOR_NAME = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	ID_OPERATOR_NAME->Wrap( -1 );
	fgSizer3->Add( ID_OPERATOR_NAME, 1, wxALL, 5 );

	ID_STATICTEXT4 = new wxStaticText( this, wxID_ANY, wxT("statistics date:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT4->Wrap( -1 );
	fgSizer3->Add( ID_STATICTEXT4, 1, wxALIGN_LEFT|wxALL, 5 );

	ID_STATISTICS_DATE = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	ID_STATISTICS_DATE->Wrap( -1 );
	fgSizer3->Add( ID_STATISTICS_DATE, 1, wxALIGN_LEFT|wxALL, 5 );


	bSizer22->Add( fgSizer3, 0, wxALL, 5 );

	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer(  );

	ID_STATICLINE2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxSize( 10,-1 ), wxLI_HORIZONTAL );
	bSizer23->Add( ID_STATICLINE2, 1, wxALL|wxEXPAND, 5 );


	bSizer22->Add( bSizer23, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxVERTICAL );

	ID_STATICTEXT1 = new wxStaticText( this, wxID_ANY, wxT("F2 - welcome record   F3 - day account   F4 - relogin   F7 - welcome list   F8 - change password  TAB - change focus"), wxDefaultPosition, wxSize( -1,-1 ), wxST_NO_AUTORESIZE );
	ID_STATICTEXT1->Wrap( -1 );
	bSizer25->Add( ID_STATICTEXT1, 1, wxALL|wxEXPAND, 5 );


	bSizer24->Add( bSizer25, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer(  );

	ID_DATETIME_NOW = new wxStaticText( this, wxID_ANY, wxT("2017年1月27日 10:30:00"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_DATETIME_NOW->Wrap( -1 );
	bSizer26->Add( ID_DATETIME_NOW, 1, wxALL, 5 );


	bSizer24->Add( bSizer26, 0, wxALIGN_RIGHT, 5 );


	bSizer22->Add( bSizer24, 0, wxALL|wxEXPAND, 5 );


	bSizer16->Add( bSizer22, 1, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer16 );
	this->Layout();
	m_menubar1 = new wxMenuBar( 0 );
	m_menu1 = new wxMenu();
	wxMenuItem* ID_MENU_WELCOME;
	ID_MENU_WELCOME = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("welcome record") ) + wxT('\t') + wxT("F2"), wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( ID_MENU_WELCOME );

	wxMenuItem* ID_MENU_ACCOUNT_DAY;
	ID_MENU_ACCOUNT_DAY = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("day account") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( ID_MENU_ACCOUNT_DAY );

	wxMenuItem* ID_MENU_SHOW_WELCOME;
	ID_MENU_SHOW_WELCOME = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("show welcome") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( ID_MENU_SHOW_WELCOME );

	m_menu1->AppendSeparator();

	wxMenuItem* ID_MENU_RELOGIN;
	ID_MENU_RELOGIN = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("Relogin") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( ID_MENU_RELOGIN );

	wxMenuItem* ID_MENU_CHANGE_PASSWORD;
	ID_MENU_CHANGE_PASSWORD = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("change password") ) , wxT("change current operator password."), wxITEM_NORMAL );
	m_menu1->Append( ID_MENU_CHANGE_PASSWORD );

	wxMenuItem* ID_MENU_FULLSCREEN;
	ID_MENU_FULLSCREEN = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("Full Screen") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( ID_MENU_FULLSCREEN );

	m_menu1->AppendSeparator();

	wxMenuItem* ID_MENU_QUIT;
	ID_MENU_QUIT = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("Quit") ) , wxT("Quit the application"), wxITEM_NORMAL );
	m_menu1->Append( ID_MENU_QUIT );

	m_menubar1->Append( m_menu1, wxT("&File") );

	m_menu2 = new wxMenu();
	wxMenuItem* ID_MENU_ABOUT;
	ID_MENU_ABOUT = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("About") ) , wxT("Show info about this application"), wxITEM_NORMAL );
	m_menu2->Append( ID_MENU_ABOUT );

	wxMenuItem* ID_MENU_TEST;
	ID_MENU_TEST = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("test") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( ID_MENU_TEST );

	m_menubar1->Append( m_menu2, wxT("Help") );

	this->SetMenuBar( m_menubar1 );

}

RailwayCRMFrame::~RailwayCRMFrame()
{
}

crmChangePasswordDialog::crmChangePasswordDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxVERTICAL );

	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer4->AddGrowableCol( 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	ID_STATICTEXT1 = new wxStaticText( this, wxID_ANY, wxT("old password:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT1->Wrap( -1 );
	fgSizer4->Add( ID_STATICTEXT1, 1, wxALL, 5 );

	ID_OLD_PASSWORD = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 278,27 ), wxTE_PASSWORD );
	fgSizer4->Add( ID_OLD_PASSWORD, 1, wxALL|wxEXPAND, 5 );

	ID_STATICTEXT2 = new wxStaticText( this, wxID_ANY, wxT("new password:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT2->Wrap( -1 );
	fgSizer4->Add( ID_STATICTEXT2, 1, wxALL, 5 );

	ID_NEW_PASSWORD = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	fgSizer4->Add( ID_NEW_PASSWORD, 1, wxALL|wxEXPAND, 5 );

	ID_STATICTEXT3 = new wxStaticText( this, wxID_ANY, wxT("confirm password:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT3->Wrap( -1 );
	fgSizer4->Add( ID_STATICTEXT3, 1, wxALL, 5 );

	ID_CONFIRM_PASSWORD = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	fgSizer4->Add( ID_CONFIRM_PASSWORD, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer27->Add( fgSizer4, 1, wxALL, 5 );

	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer(  );

	ID_STATICLINE1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxSize( 10,-1 ), wxLI_HORIZONTAL );
	bSizer28->Add( ID_STATICLINE1, 1, wxALL, 5 );


	bSizer27->Add( bSizer28, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer(  );

	m_sdbSizer4 = new wxStdDialogButtonSizer();
	m_sdbSizer4OK = new wxButton( this, wxID_OK );
	m_sdbSizer4->AddButton( m_sdbSizer4OK );
	m_sdbSizer4Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer4->AddButton( m_sdbSizer4Cancel );
	m_sdbSizer4->Realize();

	bSizer29->Add( m_sdbSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer27->Add( bSizer29, 0, wxLEFT|wxRIGHT, 5 );


	this->SetSizer( bSizer27 );
	this->Layout();
	bSizer27->Fit( this );

	this->Centre( wxBOTH );
}

crmChangePasswordDialog::~crmChangePasswordDialog()
{
}

crmDayAccountDialog::crmDayAccountDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer(  );

	ID_STATICTEXT2 = new wxStaticText( this, wxID_ANY, wxT("statistics date:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT2->Wrap( -1 );
	bSizer35->Add( ID_STATICTEXT2, 0, wxALL, 5 );

	ID_DATEPICKERCTRL_STATISTICS = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxSize( 178,35 ), wxDP_DEFAULT|wxDP_DROPDOWN|wxDP_SHOWCENTURY );
	bSizer35->Add( ID_DATEPICKERCTRL_STATISTICS, 1, wxALL, 5 );


	bSizer34->Add( bSizer35, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer(  );

	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("account category") ),  );

	ID_CHECK_ALL = new wxCheckBox( sbSizer1->GetStaticBox(), wxID_ANY, wxT("all"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_CHECK_ALL->SetValue(true);
	sbSizer1->Add( ID_CHECK_ALL, 0, wxALL, 5 );

	ID_CHECK_DETAIL = new wxCheckBox( sbSizer1->GetStaticBox(), wxID_ANY, wxT("detail"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_CHECK_DETAIL->SetValue(true);
	sbSizer1->Add( ID_CHECK_DETAIL, 0, wxALL, 5 );

	ID_CHECK_GROUP = new wxCheckBox( sbSizer1->GetStaticBox(), wxID_ANY, wxT("by group"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_CHECK_GROUP->SetValue(true);
	sbSizer1->Add( ID_CHECK_GROUP, 0, wxALL, 5 );

	ID_CHECK_USER = new wxCheckBox( sbSizer1->GetStaticBox(), wxID_ANY, wxT("by user"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_CHECK_USER->SetValue(true);
	sbSizer1->Add( ID_CHECK_USER, 0, wxALL, 5 );

	ID_CHECK_CARD = new wxCheckBox( sbSizer1->GetStaticBox(), wxID_ANY, wxT("by card"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_CHECK_CARD->SetValue(true);
	sbSizer1->Add( ID_CHECK_CARD, 0, wxALL, 5 );

	ID_CHECK_TRAIN = new wxCheckBox( sbSizer1->GetStaticBox(), wxID_ANY, wxT("by train"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_CHECK_TRAIN->SetValue(true);
	sbSizer1->Add( ID_CHECK_TRAIN, 0, wxALL, 5 );


	bSizer36->Add( sbSizer1, 1, wxALL, 5 );


	bSizer34->Add( bSizer36, 0, wxALL, 5 );

	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer(  );


	bSizer37->Add( 88, 56, 1, wxALL|wxEXPAND, 5 );

	ID_BUTTON_ACCOUNT = new wxButton( this, wxID_ANY, wxT("Account(&A)"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_ACCOUNT->SetDefault();
	bSizer37->Add( ID_BUTTON_ACCOUNT, 0, wxALL, 5 );

	ID_BUTTON_PRINT = new wxButton( this, wxID_ANY, wxT("Print(&P)"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_PRINT->SetDefault();
	bSizer37->Add( ID_BUTTON_PRINT, 0, wxALL, 5 );

	wxID_CANCEL = new wxButton( this, wxID_ANY, wxT("Return(&Q)"), wxDefaultPosition, wxDefaultSize, 0 );

	wxID_CANCEL->SetDefault();
	bSizer37->Add( wxID_CANCEL, 0, wxALL, 5 );


	bSizer34->Add( bSizer37, 0, wxALL|wxEXPAND, 5 );


	bSizer33->Add( bSizer34, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer(  );

	ID_STATICLINE1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxSize( 10,-1 ), wxLI_HORIZONTAL );
	bSizer38->Add( ID_STATICLINE1, 1, wxALL, 5 );


	bSizer33->Add( bSizer38, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer(  );

	ID_HTML_REPORT = new wxHtmlWindow( this, wxID_ANY, wxDefaultPosition, wxSize( 1133,409 ), wxHW_SCROLLBAR_AUTO );
	bSizer39->Add( ID_HTML_REPORT, 1, wxALL|wxEXPAND, 5 );


	bSizer33->Add( bSizer39, 1, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer33 );
	this->Layout();
	bSizer33->Fit( this );

	this->Centre( wxBOTH );
}

crmDayAccountDialog::~crmDayAccountDialog()
{
}

crmGuestDefDialog::crmGuestDefDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxVERTICAL );

	wxFlexGridSizer* fgSizer5;
	fgSizer5 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer5->SetFlexibleDirection( wxBOTH );
	fgSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer(  );

	ID_STATICTEXT1 = new wxStaticText( this, wxID_ANY, wxT("id:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT1->Wrap( 0 );
	bSizer41->Add( ID_STATICTEXT1, 1, wxALL, 5 );

	ID_TEXTCTRL_ID = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	ID_TEXTCTRL_ID->Enable( false );

	bSizer41->Add( ID_TEXTCTRL_ID, 2, wxALL, 5 );


	fgSizer5->Add( bSizer41, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer(  );

	ID_STATICTEXT2 = new wxStaticText( this, wxID_ANY, wxT("group name:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT2->Wrap( 0 );
	bSizer42->Add( ID_STATICTEXT2, 1, wxALL, 5 );

	ID_COMBOBOX_GROUP = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer42->Add( ID_COMBOBOX_GROUP, 2, wxALL, 5 );


	fgSizer5->Add( bSizer42, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer(  );

	ID_STATICTEXT3 = new wxStaticText( this, wxID_ANY, wxT("user name:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT3->Wrap( 0 );
	bSizer43->Add( ID_STATICTEXT3, 1, wxALL, 5 );

	ID_COMBOBOX_USER = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer43->Add( ID_COMBOBOX_USER, 2, wxALL, 5 );


	fgSizer5->Add( bSizer43, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer44;
	bSizer44 = new wxBoxSizer(  );

	ID_STATICTEXT4 = new wxStaticText( this, wxID_ANY, wxT("card name:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT4->Wrap( 0 );
	bSizer44->Add( ID_STATICTEXT4, 1, wxALL, 5 );

	ID_TEXTCTRL_CARD = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer44->Add( ID_TEXTCTRL_CARD, 2, wxALL, 5 );


	fgSizer5->Add( bSizer44, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer45;
	bSizer45 = new wxBoxSizer(  );

	ID_STATICTEXT5 = new wxStaticText( this, wxID_ANY, wxT("people limit:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT5->Wrap( 0 );
	bSizer45->Add( ID_STATICTEXT5, 1, wxALL, 5 );

	ID_SPINCTRL_PEOPLE = new wxSpinCtrl( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1000, 0 );
	bSizer45->Add( ID_SPINCTRL_PEOPLE, 2, wxALL, 5 );


	fgSizer5->Add( bSizer45, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer46;
	bSizer46 = new wxBoxSizer(  );

	ID_STATICTEXT6 = new wxStaticText( this, wxID_ANY, wxT("default price:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT6->Wrap( 0 );
	bSizer46->Add( ID_STATICTEXT6, 1, wxALL, 5 );

	ID_TEXTCTRL_PRICE = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer46->Add( ID_TEXTCTRL_PRICE, 2, wxALL, 5 );


	fgSizer5->Add( bSizer46, 1, wxALL|wxEXPAND, 5 );


	bSizer40->Add( fgSizer5, 0, wxALL, 5 );

	wxBoxSizer* bSizer47;
	bSizer47 = new wxBoxSizer(  );

	ID_STATICLINE1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxSize( 10,-1 ), wxLI_HORIZONTAL );
	bSizer47->Add( ID_STATICLINE1, 1, wxALL, 5 );


	bSizer40->Add( bSizer47, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer48;
	bSizer48 = new wxBoxSizer(  );

	wxBoxSizer* bSizer49;
	bSizer49 = new wxBoxSizer( wxVERTICAL );

	ID_STATICTEXT8 = new wxStaticText( this, wxID_ANY, wxT("logo(small):"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT8->Wrap( 0 );
	bSizer49->Add( ID_STATICTEXT8, 1, wxALL, 5 );

	ID_STATICBITMAP1 = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE );
	bSizer49->Add( ID_STATICBITMAP1, 0, wxALL, 5 );

	ID_BUTTON_LOAD_SMALL = new wxButton( this, wxID_ANY, wxT("change ..."), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_LOAD_SMALL->SetDefault();
	bSizer49->Add( ID_BUTTON_LOAD_SMALL, 0, wxALL, 5 );


	bSizer48->Add( bSizer49, 1, wxALL, 5 );

	wxBoxSizer* bSizer50;
	bSizer50 = new wxBoxSizer(  );

	ID_STATICLINE3 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxSize( 2,-1 ), wxLI_VERTICAL );
	bSizer50->Add( ID_STATICLINE3, 0, wxALL|wxEXPAND, 5 );


	bSizer48->Add( bSizer50, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxVERTICAL );

	ID_STATICTEXT9 = new wxStaticText( this, wxID_ANY, wxT("logo(large):"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT9->Wrap( 0 );
	bSizer51->Add( ID_STATICTEXT9, 1, wxALL, 5 );

	ID_STATICBITMAP2 = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE );
	bSizer51->Add( ID_STATICBITMAP2, 0, wxALL, 5 );

	ID_BUTTON_LOAD_LARGE = new wxButton( this, wxID_ANY, wxT("change ..."), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_LOAD_LARGE->SetDefault();
	bSizer51->Add( ID_BUTTON_LOAD_LARGE, 0, wxALL, 5 );


	bSizer48->Add( bSizer51, 1, wxALL, 5 );


	bSizer40->Add( bSizer48, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer52;
	bSizer52 = new wxBoxSizer(  );

	ID_STATICLINE2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxSize( 10,-1 ), wxLI_HORIZONTAL );
	bSizer52->Add( ID_STATICLINE2, 1, wxALL|wxEXPAND, 5 );


	bSizer40->Add( bSizer52, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer53;
	bSizer53 = new wxBoxSizer(  );


	bSizer53->Add( 59, 24, 1, wxALL|wxEXPAND, 5 );

	m_sdbSizer5 = new wxStdDialogButtonSizer();
	m_sdbSizer5OK = new wxButton( this, wxID_OK );
	m_sdbSizer5->AddButton( m_sdbSizer5OK );
	m_sdbSizer5Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer5->AddButton( m_sdbSizer5Cancel );
	m_sdbSizer5->Realize();

	bSizer53->Add( m_sdbSizer5, 0, wxALL, 5 );

	ID_BUTTON_RESET = new wxButton( this, wxID_ANY, wxT("Reset(&R)"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_RESET->SetDefault();
	bSizer53->Add( ID_BUTTON_RESET, 0, wxALL, 5 );


	bSizer40->Add( bSizer53, 0, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer40 );
	this->Layout();
	bSizer40->Fit( this );

	this->Centre( wxBOTH );
}

crmGuestDefDialog::~crmGuestDefDialog()
{
}

crmGuestFilterDialog::crmGuestFilterDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer( wxVERTICAL );

	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer6->AddGrowableCol( 1 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	ID_STATICTEXT1 = new wxStaticText( this, wxID_ANY, wxT("group name:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT1->Wrap( -1 );
	fgSizer6->Add( ID_STATICTEXT1, 1, wxALL, 5 );

	ID_COMBOBOX_GROUP = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	fgSizer6->Add( ID_COMBOBOX_GROUP, 1, wxALL|wxEXPAND, 5 );

	ID_STATICTEXT2 = new wxStaticText( this, wxID_ANY, wxT("user name:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT2->Wrap( -1 );
	fgSizer6->Add( ID_STATICTEXT2, 1, wxALL, 5 );

	ID_COMBOBOX_USER = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	fgSizer6->Add( ID_COMBOBOX_USER, 1, wxALL|wxEXPAND, 5 );

	ID_STATICTEXT3 = new wxStaticText( this, wxID_ANY, wxT("card name:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT3->Wrap( -1 );
	fgSizer6->Add( ID_STATICTEXT3, 1, wxALL, 5 );

	ID_COMBOBOX_CARD = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	fgSizer6->Add( ID_COMBOBOX_CARD, 1, wxALL|wxEXPAND, 5 );


	bSizer54->Add( fgSizer6, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer(  );

	ID_STATICLINE1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxSize( 10,-1 ), wxLI_HORIZONTAL );
	bSizer55->Add( ID_STATICLINE1, 1, wxALL, 5 );


	bSizer54->Add( bSizer55, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer56;
	bSizer56 = new wxBoxSizer(  );

	m_sdbSizer6 = new wxStdDialogButtonSizer();
	m_sdbSizer6OK = new wxButton( this, wxID_OK );
	m_sdbSizer6->AddButton( m_sdbSizer6OK );
	m_sdbSizer6Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer6->AddButton( m_sdbSizer6Cancel );
	m_sdbSizer6->Realize();

	bSizer56->Add( m_sdbSizer6, 1, wxALL, 5 );

	ID_BUTTON_RESET = new wxButton( this, wxID_ANY, wxT("Reset(&R)"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_RESET->SetDefault();
	bSizer56->Add( ID_BUTTON_RESET, 0, wxALL, 5 );


	bSizer54->Add( bSizer56, 0, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer54 );
	this->Layout();
	bSizer54->Fit( this );

	this->Centre( wxBOTH );
}

crmGuestFilterDialog::~crmGuestFilterDialog()
{
}

crmImageDefDialog::crmImageDefDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer57;
	bSizer57 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer58;
	bSizer58 = new wxBoxSizer(  );

	wxBoxSizer* bSizer59;
	bSizer59 = new wxBoxSizer( wxVERTICAL );

	ID_STATICTEXT1 = new wxStaticText( this, wxID_ANY, wxT("id:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT1->Wrap( -1 );
	bSizer59->Add( ID_STATICTEXT1, 1, wxALL, 5 );

	ID_TEXTCTRL_ID = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	ID_TEXTCTRL_ID->Enable( false );

	bSizer59->Add( ID_TEXTCTRL_ID, 1, wxALL|wxEXPAND, 5 );


	bSizer58->Add( bSizer59, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer60;
	bSizer60 = new wxBoxSizer( wxVERTICAL );

	ID_STATICTEXT2 = new wxStaticText( this, wxID_ANY, wxT("image size:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT2->Wrap( -1 );
	bSizer60->Add( ID_STATICTEXT2, 1, wxALL, 5 );

	ID_TEXTCTRL_SIZE = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	ID_TEXTCTRL_SIZE->Enable( false );

	bSizer60->Add( ID_TEXTCTRL_SIZE, 1, wxALL|wxEXPAND, 5 );


	bSizer58->Add( bSizer60, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxVERTICAL );

	ID_STATICTEXT3 = new wxStaticText( this, wxID_ANY, wxT("image name:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT3->Wrap( -1 );
	bSizer61->Add( ID_STATICTEXT3, 1, wxALL, 5 );

	ID_TEXTCTRL_NAME = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer61->Add( ID_TEXTCTRL_NAME, 1, wxALL|wxEXPAND, 5 );


	bSizer58->Add( bSizer61, 2, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer62;
	bSizer62 = new wxBoxSizer( wxVERTICAL );

	ID_STATICTEXT4 = new wxStaticText( this, wxID_ANY, wxT("image type:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT4->Wrap( -1 );
	bSizer62->Add( ID_STATICTEXT4, 1, wxALL, 5 );

	ID_TEXTCTRL_TYPE = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ID_TEXTCTRL_TYPE->Enable( false );

	bSizer62->Add( ID_TEXTCTRL_TYPE, 1, wxALL|wxEXPAND, 5 );


	bSizer58->Add( bSizer62, 1, wxALL|wxEXPAND, 5 );


	bSizer57->Add( bSizer58, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer63;
	bSizer63 = new wxBoxSizer(  );

	ID_STATICBITMAP1 = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer63->Add( ID_STATICBITMAP1, 1, wxALL, 5 );


	bSizer57->Add( bSizer63, 1, wxALL, 5 );

	wxBoxSizer* bSizer64;
	bSizer64 = new wxBoxSizer(  );

	ID_STATICLINE1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxSize( 10,-1 ), wxLI_HORIZONTAL );
	bSizer64->Add( ID_STATICLINE1, 1, wxALL|wxEXPAND, 5 );


	bSizer57->Add( bSizer64, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer65;
	bSizer65 = new wxBoxSizer(  );

	m_sdbSizer7 = new wxStdDialogButtonSizer();
	m_sdbSizer7OK = new wxButton( this, wxID_OK );
	m_sdbSizer7->AddButton( m_sdbSizer7OK );
	m_sdbSizer7Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer7->AddButton( m_sdbSizer7Cancel );
	m_sdbSizer7->Realize();

	bSizer65->Add( m_sdbSizer7, 1, wxALL, 5 );

	ID_BUTTON_LOAD = new wxButton( this, wxID_ANY, wxT("(&L)Load From ..."), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_LOAD->SetDefault();
	bSizer65->Add( ID_BUTTON_LOAD, 0, wxALL, 5 );

	ID_BUTTON_SAVE = new wxButton( this, wxID_ANY, wxT("(&S)Save To ..."), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_SAVE->SetDefault();
	bSizer65->Add( ID_BUTTON_SAVE, 0, wxALL, 5 );

	ID_BUTTON_RESET = new wxButton( this, wxID_ANY, wxT("Reset(&R)"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_RESET->SetDefault();
	bSizer65->Add( ID_BUTTON_RESET, 0, wxALL, 5 );


	bSizer57->Add( bSizer65, 0, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer57 );
	this->Layout();
	bSizer57->Fit( this );

	this->Centre( wxBOTH );
}

crmImageDefDialog::~crmImageDefDialog()
{
}

crmMessageBox::crmMessageBox( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer66;
	bSizer66 = new wxBoxSizer( wxVERTICAL );

	wxFlexGridSizer* fgSizer7;
	fgSizer7 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer7->AddGrowableCol( 1 );
	fgSizer7->SetFlexibleDirection( wxBOTH );
	fgSizer7->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	ID_STATICTEXT1 = new wxStaticText( this, wxID_ANY, wxT("Name:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT1->Wrap( -1 );
	ID_STATICTEXT1->SetForegroundColour( wxColour( 0, 0, 255 ) );

	fgSizer7->Add( ID_STATICTEXT1, 1, wxALL, 5 );

	ID_LABEL_NAME = new wxStaticText( this, wxID_ANY, wxT("Label"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_LABEL_NAME->Wrap( 0 );
	ID_LABEL_NAME->SetFont( wxFont( 15, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Sans") ) );
	ID_LABEL_NAME->SetForegroundColour( wxColour( 0, 0, 0 ) );

	fgSizer7->Add( ID_LABEL_NAME, 1, wxALL, 5 );

	ID_STATICTEXT3 = new wxStaticText( this, wxID_ANY, wxT("Version:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT3->Wrap( -1 );
	ID_STATICTEXT3->SetForegroundColour( wxColour( 0, 0, 255 ) );

	fgSizer7->Add( ID_STATICTEXT3, 1, wxALL, 5 );

	ID_LABEL_VERSION = new wxStaticText( this, wxID_ANY, wxT("Label"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_LABEL_VERSION->Wrap( -1 );
	ID_LABEL_VERSION->SetFont( wxFont( 8, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Sans") ) );

	fgSizer7->Add( ID_LABEL_VERSION, 1, wxALL, 5 );

	ID_STATICTEXT5 = new wxStaticText( this, wxID_ANY, wxT("Author:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT5->Wrap( -1 );
	ID_STATICTEXT5->SetForegroundColour( wxColour( 0, 0, 255 ) );

	fgSizer7->Add( ID_STATICTEXT5, 1, wxALL, 5 );

	ID_LABEL_AUTHOR = new wxStaticText( this, wxID_ANY, wxT("Label"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_LABEL_AUTHOR->Wrap( -1 );
	ID_LABEL_AUTHOR->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Sans") ) );
	ID_LABEL_AUTHOR->SetForegroundColour( wxColour( 255, 0, 0 ) );

	fgSizer7->Add( ID_LABEL_AUTHOR, 1, wxALL, 5 );

	ID_STATICTEXT7 = new wxStaticText( this, wxID_ANY, wxT("E-mail:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT7->Wrap( -1 );
	ID_STATICTEXT7->SetForegroundColour( wxColour( 0, 0, 255 ) );

	fgSizer7->Add( ID_STATICTEXT7, 1, wxALL, 5 );

	ID_LABEL_EMAIL = new wxStaticText( this, wxID_ANY, wxT("Label"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_LABEL_EMAIL->Wrap( -1 );
	ID_LABEL_EMAIL->SetFont( wxFont( 8, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Sans") ) );

	fgSizer7->Add( ID_LABEL_EMAIL, 1, wxALL, 5 );

	ID_STATICTEXT9 = new wxStaticText( this, wxID_ANY, wxT("Telephone:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT9->Wrap( -1 );
	ID_STATICTEXT9->SetForegroundColour( wxColour( 0, 0, 255 ) );

	fgSizer7->Add( ID_STATICTEXT9, 1, wxALL, 5 );

	ID_LABEL_PHONE = new wxStaticText( this, wxID_ANY, wxT("Label"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_LABEL_PHONE->Wrap( -1 );
	ID_LABEL_PHONE->SetFont( wxFont( 8, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Sans") ) );

	fgSizer7->Add( ID_LABEL_PHONE, 1, wxALL, 5 );

	ID_STATICTEXT11 = new wxStaticText( this, wxID_ANY, wxT("Build-Info:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT11->Wrap( -1 );
	ID_STATICTEXT11->SetForegroundColour( wxColour( 0, 0, 255 ) );

	fgSizer7->Add( ID_STATICTEXT11, 1, wxALL, 5 );

	ID_LABEL_BUILDINFO = new wxStaticText( this, wxID_ANY, wxT("Label"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_LABEL_BUILDINFO->Wrap( -1 );
	ID_LABEL_BUILDINFO->SetFont( wxFont( 8, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_NORMAL, false, wxT("Sans") ) );

	fgSizer7->Add( ID_LABEL_BUILDINFO, 1, wxALL, 5 );


	bSizer66->Add( fgSizer7, 1, wxALL|wxEXPAND, 5 );

	ID_STATICLINE1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxSize( 10,-1 ), wxLI_HORIZONTAL );
	bSizer66->Add( ID_STATICLINE1, 0, wxALL|wxEXPAND, 5 );

	m_sdbSizer8 = new wxStdDialogButtonSizer();
	m_sdbSizer8OK = new wxButton( this, wxID_OK );
	m_sdbSizer8->AddButton( m_sdbSizer8OK );
	m_sdbSizer8->Realize();

	bSizer66->Add( m_sdbSizer8, 0, wxALL, 5 );


	this->SetSizer( bSizer66 );
	this->Layout();
	bSizer66->Fit( this );

	this->Centre( wxBOTH );
}

crmMessageBox::~crmMessageBox()
{
}

crmOperatorDefDialog::crmOperatorDefDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer67;
	bSizer67 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer68;
	bSizer68 = new wxBoxSizer(  );

	wxBoxSizer* bSizer69;
	bSizer69 = new wxBoxSizer( wxVERTICAL );

	ID_STATICTEXT1 = new wxStaticText( this, wxID_ANY, wxT("id:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT1->Wrap( -1 );
	bSizer69->Add( ID_STATICTEXT1, 0, wxALL, 5 );

	ID_TEXTCTRL_ID = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ID_TEXTCTRL_ID->Enable( false );

	bSizer69->Add( ID_TEXTCTRL_ID, 0, wxALL, 5 );


	bSizer68->Add( bSizer69, 0, wxALL, 5 );

	wxBoxSizer* bSizer70;
	bSizer70 = new wxBoxSizer( wxVERTICAL );

	ID_STATICTEXT2 = new wxStaticText( this, wxID_ANY, wxT("Operator Name:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT2->Wrap( -1 );
	bSizer70->Add( ID_STATICTEXT2, 0, wxALL, 5 );

	ID_TEXTCTRL_NAME = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer70->Add( ID_TEXTCTRL_NAME, 0, wxALL|wxEXPAND, 5 );


	bSizer68->Add( bSizer70, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer71;
	bSizer71 = new wxBoxSizer( wxVERTICAL );

	ID_STATICTEXT3 = new wxStaticText( this, wxID_ANY, wxT("Password:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT3->Wrap( -1 );
	bSizer71->Add( ID_STATICTEXT3, 0, wxALL, 5 );

	ID_TEXTCTRL_PASSWORD = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer71->Add( ID_TEXTCTRL_PASSWORD, 0, wxALL|wxEXPAND, 5 );


	bSizer68->Add( bSizer71, 1, wxALL|wxEXPAND, 5 );


	bSizer67->Add( bSizer68, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer72;
	bSizer72 = new wxBoxSizer(  );

	wxArrayString ID_CHECKLISTBOX_RIGHTSChoices;
	ID_CHECKLISTBOX_RIGHTS = new wxCheckListBox( this, wxID_ANY, wxDefaultPosition, wxSize( 362,292 ), ID_CHECKLISTBOX_RIGHTSChoices, 0 );
	bSizer72->Add( ID_CHECKLISTBOX_RIGHTS, 1, wxALL, 5 );


	bSizer67->Add( bSizer72, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer73;
	bSizer73 = new wxBoxSizer(  );

	ID_STATICLINE1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxSize( 10,-1 ), wxLI_HORIZONTAL );
	bSizer73->Add( ID_STATICLINE1, 1, wxALL|wxEXPAND, 5 );


	bSizer67->Add( bSizer73, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer74;
	bSizer74 = new wxBoxSizer(  );

	m_sdbSizer9 = new wxStdDialogButtonSizer();
	m_sdbSizer9OK = new wxButton( this, wxID_OK );
	m_sdbSizer9->AddButton( m_sdbSizer9OK );
	m_sdbSizer9Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer9->AddButton( m_sdbSizer9Cancel );
	m_sdbSizer9->Realize();

	bSizer74->Add( m_sdbSizer9, 0, wxALL, 5 );

	ID_BUTTON_RESET = new wxButton( this, wxID_ANY, wxT("Reset(&R)"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_RESET->SetDefault();
	bSizer74->Add( ID_BUTTON_RESET, 0, wxALL, 5 );


	bSizer67->Add( bSizer74, 0, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer67 );
	this->Layout();
	bSizer67->Fit( this );

	this->Centre( wxBOTH );
}

crmOperatorDefDialog::~crmOperatorDefDialog()
{
}

crmRecordFilterDialog::crmRecordFilterDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer75;
	bSizer75 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer(  );

	ID_STATICTEXT1 = new wxStaticText( this, wxID_ANY, wxT("statistics date between:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT1->Wrap( -1 );
	bSizer76->Add( ID_STATICTEXT1, 0, wxALL, 5 );

	ID_DATEPICKERCTRL1 = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxSize( 156,29 ), wxDP_DEFAULT|wxDP_DROPDOWN|wxDP_SHOWCENTURY );
	bSizer76->Add( ID_DATEPICKERCTRL1, 1, wxALL|wxEXPAND, 5 );

	ID_STATICTEXT2 = new wxStaticText( this, wxID_ANY, wxT("and"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT2->Wrap( -1 );
	bSizer76->Add( ID_STATICTEXT2, 0, wxALL, 5 );

	ID_DATEPICKERCTRL2 = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_DROPDOWN|wxDP_SHOWCENTURY );
	bSizer76->Add( ID_DATEPICKERCTRL2, 1, wxALL|wxEXPAND, 5 );


	bSizer76->Add( 86, 29, 0, wxALL|wxEXPAND, 5 );

	ID_STATICTEXT3 = new wxStaticText( this, wxID_ANY, wxT("operator name:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT3->Wrap( -1 );
	bSizer76->Add( ID_STATICTEXT3, 0, wxALIGN_RIGHT|wxALL, 5 );

	ID_COMBOBOX_OPERATOR = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer76->Add( ID_COMBOBOX_OPERATOR, 1, wxALL|wxEXPAND, 5 );


	bSizer75->Add( bSizer76, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer77;
	bSizer77 = new wxBoxSizer(  );

	ID_STATICTEXT4 = new wxStaticText( this, wxID_ANY, wxT("group name:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT4->Wrap( -1 );
	bSizer77->Add( ID_STATICTEXT4, 0, wxALL, 5 );

	ID_COMBOBOX_GROUP = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer77->Add( ID_COMBOBOX_GROUP, 1, wxALL, 5 );

	ID_STATICTEXT5 = new wxStaticText( this, wxID_ANY, wxT("user name:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT5->Wrap( -1 );
	bSizer77->Add( ID_STATICTEXT5, 0, wxALL, 5 );

	ID_COMBOBOX_USER = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer77->Add( ID_COMBOBOX_USER, 1, wxALL, 5 );

	ID_STATICTEXT6 = new wxStaticText( this, wxID_ANY, wxT("card name:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT6->Wrap( -1 );
	bSizer77->Add( ID_STATICTEXT6, 0, wxALL, 5 );

	ID_COMBOBOX_CARD = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer77->Add( ID_COMBOBOX_CARD, 1, wxALL, 5 );


	bSizer75->Add( bSizer77, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer(  );

	ID_STATICLINE1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxSize( 10,-1 ), wxLI_HORIZONTAL );
	bSizer78->Add( ID_STATICLINE1, 1, wxALL|wxEXPAND, 5 );


	bSizer75->Add( bSizer78, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer79;
	bSizer79 = new wxBoxSizer(  );

	m_sdbSizer10 = new wxStdDialogButtonSizer();
	m_sdbSizer10OK = new wxButton( this, wxID_OK );
	m_sdbSizer10->AddButton( m_sdbSizer10OK );
	m_sdbSizer10Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer10->AddButton( m_sdbSizer10Cancel );
	m_sdbSizer10->Realize();

	bSizer79->Add( m_sdbSizer10, 0, wxALL, 5 );

	ID_BUTTON_RESET = new wxButton( this, wxID_ANY, wxT("Reset(&R)"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_RESET->SetDefault();
	bSizer79->Add( ID_BUTTON_RESET, 0, wxALL, 5 );


	bSizer75->Add( bSizer79, 0, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer75 );
	this->Layout();
	bSizer75->Fit( this );

	this->Centre( wxBOTH );
}

crmRecordFilterDialog::~crmRecordFilterDialog()
{
}

hkRecordFilterDialog::hkRecordFilterDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer75;
	bSizer75 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer(  );

	ID_STATICTEXT1 = new wxStaticText( this, wxID_ANY, wxT("statistics date between:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT1->Wrap( -1 );
	bSizer76->Add( ID_STATICTEXT1, 0, wxALL, 5 );

	ID_DATEPICKERCTRL1 = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxSize( 156,29 ), wxDP_DEFAULT|wxDP_DROPDOWN|wxDP_SHOWCENTURY );
	bSizer76->Add( ID_DATEPICKERCTRL1, 1, wxALL|wxEXPAND, 5 );

	ID_STATICTEXT2 = new wxStaticText( this, wxID_ANY, wxT("and"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT2->Wrap( -1 );
	bSizer76->Add( ID_STATICTEXT2, 0, wxALL, 5 );

	ID_DATEPICKERCTRL2 = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_DROPDOWN|wxDP_SHOWCENTURY );
	bSizer76->Add( ID_DATEPICKERCTRL2, 1, wxALL|wxEXPAND, 5 );


	bSizer76->Add( 86, 29, 0, wxALL|wxEXPAND, 5 );


	bSizer75->Add( bSizer76, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer77;
	bSizer77 = new wxBoxSizer(  );


	bSizer75->Add( bSizer77, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer(  );

	ID_STATICLINE1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxSize( 10,-1 ), wxLI_HORIZONTAL );
	bSizer78->Add( ID_STATICLINE1, 1, wxALL|wxEXPAND, 5 );


	bSizer75->Add( bSizer78, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer79;
	bSizer79 = new wxBoxSizer(  );

	m_sdbSizer10 = new wxStdDialogButtonSizer();
	m_sdbSizer10OK = new wxButton( this, wxID_OK );
	m_sdbSizer10->AddButton( m_sdbSizer10OK );
	m_sdbSizer10Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer10->AddButton( m_sdbSizer10Cancel );
	m_sdbSizer10->Realize();

	bSizer79->Add( m_sdbSizer10, 0, wxALL, 5 );

	ID_BUTTON_RESET = new wxButton( this, wxID_ANY, wxT("Reset(&R)"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_RESET->SetDefault();
	bSizer79->Add( ID_BUTTON_RESET, 0, wxALL, 5 );


	bSizer75->Add( bSizer79, 0, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer75 );
	this->Layout();
	bSizer75->Fit( this );

	this->Centre( wxBOTH );
}

hkRecordFilterDialog::~hkRecordFilterDialog()
{
}

crmRecordModifyDialog::crmRecordModifyDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer80;
	bSizer80 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxVERTICAL );

	wxFlexGridSizer* fgSizer8;
	fgSizer8 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer8->SetFlexibleDirection( wxBOTH );
	fgSizer8->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxBoxSizer* bSizer82;
	bSizer82 = new wxBoxSizer(  );

	ID_STATICTEXT1 = new wxStaticText( this, wxID_ANY, wxT("operator name:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT1->Wrap( -1 );
	bSizer82->Add( ID_STATICTEXT1, 1, wxALL, 5 );

	ID_TEXTCTRL_OPERATORNAME = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( ID_TEXTCTRL_OPERATORNAME, 2, wxALL, 5 );


	fgSizer8->Add( bSizer82, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer83;
	bSizer83 = new wxBoxSizer(  );

	ID_STATICTEXT2 = new wxStaticText( this, wxID_ANY, wxT("statistics date:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT2->Wrap( -1 );
	bSizer83->Add( ID_STATICTEXT2, 1, wxALL, 5 );

	ID_TEXTCTRL_STATISTICS = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer83->Add( ID_TEXTCTRL_STATISTICS, 2, wxALL, 5 );


	fgSizer8->Add( bSizer83, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer84;
	bSizer84 = new wxBoxSizer(  );

	ID_STATICTEXT3 = new wxStaticText( this, wxID_ANY, wxT("record time:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT3->Wrap( -1 );
	bSizer84->Add( ID_STATICTEXT3, 1, wxALL, 5 );

	ID_TEXTCTRL_RTIME = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer84->Add( ID_TEXTCTRL_RTIME, 2, wxALL, 5 );


	fgSizer8->Add( bSizer84, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer85;
	bSizer85 = new wxBoxSizer(  );

	ID_STATICTEXT4 = new wxStaticText( this, wxID_ANY, wxT("group name:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT4->Wrap( -1 );
	bSizer85->Add( ID_STATICTEXT4, 1, wxALL, 5 );

	ID_COMBOBOX_GROUP = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer85->Add( ID_COMBOBOX_GROUP, 2, wxALL, 5 );


	fgSizer8->Add( bSizer85, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5 );

	wxBoxSizer* bSizer86;
	bSizer86 = new wxBoxSizer(  );

	ID_STATICTEXT5 = new wxStaticText( this, wxID_ANY, wxT("user name:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT5->Wrap( -1 );
	bSizer86->Add( ID_STATICTEXT5, 1, wxALL, 5 );

	ID_COMBOBOX_USER = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer86->Add( ID_COMBOBOX_USER, 2, wxALL, 5 );


	fgSizer8->Add( bSizer86, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer87;
	bSizer87 = new wxBoxSizer(  );

	ID_STATICTEXT6 = new wxStaticText( this, wxID_ANY, wxT("card name:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT6->Wrap( -1 );
	bSizer87->Add( ID_STATICTEXT6, 1, wxALL, 5 );

	ID_COMBOBOX_CARD = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer87->Add( ID_COMBOBOX_CARD, 2, wxALL, 5 );


	fgSizer8->Add( bSizer87, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer88;
	bSizer88 = new wxBoxSizer(  );

	ID_STATICTEXT7 = new wxStaticText( this, wxID_ANY, wxT("card id:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT7->Wrap( -1 );
	bSizer88->Add( ID_STATICTEXT7, 1, wxALL, 5 );

	ID_TEXTCTRL_CARDID = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer88->Add( ID_TEXTCTRL_CARDID, 2, wxALL, 5 );


	fgSizer8->Add( bSizer88, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer89;
	bSizer89 = new wxBoxSizer(  );

	ID_STATICTEXT8 = new wxStaticText( this, wxID_ANY, wxT("presence name:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT8->Wrap( -1 );
	bSizer89->Add( ID_STATICTEXT8, 1, wxALL, 5 );

	ID_TEXTCTRL_PRESENCE = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer89->Add( ID_TEXTCTRL_PRESENCE, 2, wxALL, 5 );


	fgSizer8->Add( bSizer89, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer90;
	bSizer90 = new wxBoxSizer(  );

	ID_STATICTEXT13 = new wxStaticText( this, wxID_ANY, wxT("people count:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT13->Wrap( -1 );
	bSizer90->Add( ID_STATICTEXT13, 1, wxALL, 5 );

	ID_TEXTCTRL_PEOPLE = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer90->Add( ID_TEXTCTRL_PEOPLE, 2, wxALL, 5 );


	fgSizer8->Add( bSizer90, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer91;
	bSizer91 = new wxBoxSizer(  );

	ID_STATICTEXT9 = new wxStaticText( this, wxID_ANY, wxT("train date:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT9->Wrap( -1 );
	bSizer91->Add( ID_STATICTEXT9, 1, wxALL, 5 );

	ID_TEXTCTRL_TDATE = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer91->Add( ID_TEXTCTRL_TDATE, 2, wxALL, 5 );


	fgSizer8->Add( bSizer91, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer92;
	bSizer92 = new wxBoxSizer(  );

	ID_STATICTEXT10 = new wxStaticText( this, wxID_ANY, wxT("train code:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT10->Wrap( -1 );
	bSizer92->Add( ID_STATICTEXT10, 1, wxALL, 5 );

	ID_TEXTCTRL_TRAIN = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer92->Add( ID_TEXTCTRL_TRAIN, 2, wxALL, 5 );


	fgSizer8->Add( bSizer92, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer93;
	bSizer93 = new wxBoxSizer(  );

	ID_STATICTEXT11 = new wxStaticText( this, wxID_ANY, wxT("price:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT11->Wrap( -1 );
	bSizer93->Add( ID_STATICTEXT11, 1, wxALL, 5 );

	ID_TEXTCTRL_PRICE = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer93->Add( ID_TEXTCTRL_PRICE, 2, wxALL, 5 );


	fgSizer8->Add( bSizer93, 1, wxALL|wxEXPAND, 5 );


	bSizer81->Add( fgSizer8, 1, wxALL, 5 );

	wxBoxSizer* bSizer94;
	bSizer94 = new wxBoxSizer( wxVERTICAL );

	ID_STATICTEXT12 = new wxStaticText( this, wxID_ANY, wxT("comment:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT12->Wrap( -1 );
	bSizer94->Add( ID_STATICTEXT12, 0, wxALL, 5 );

	ID_TEXTCTRL_COMMENT = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,150 ), wxTE_MULTILINE|wxTE_PROCESS_ENTER|wxTE_WORDWRAP );
	bSizer94->Add( ID_TEXTCTRL_COMMENT, 1, wxALL|wxEXPAND, 15 );


	bSizer81->Add( bSizer94, 0, wxALL|wxEXPAND, 10 );


	bSizer80->Add( bSizer81, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer95;
	bSizer95 = new wxBoxSizer(  );

	ID_STATICLINE1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxSize( 10,-1 ), wxLI_HORIZONTAL );
	bSizer95->Add( ID_STATICLINE1, 1, wxALL|wxEXPAND, 5 );


	bSizer80->Add( bSizer95, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer96;
	bSizer96 = new wxBoxSizer(  );

	m_sdbSizer11 = new wxStdDialogButtonSizer();
	m_sdbSizer11OK = new wxButton( this, wxID_OK );
	m_sdbSizer11->AddButton( m_sdbSizer11OK );
	m_sdbSizer11Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer11->AddButton( m_sdbSizer11Cancel );
	m_sdbSizer11->Realize();

	bSizer96->Add( m_sdbSizer11, 0, wxALL, 5 );

	ID_BUTTON_RESET = new wxButton( this, wxID_ANY, wxT("Reset(&R)"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_RESET->SetDefault();
	bSizer96->Add( ID_BUTTON_RESET, 0, wxALL, 5 );


	bSizer80->Add( bSizer96, 0, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer80 );
	this->Layout();
	bSizer80->Fit( this );

	this->Centre( wxBOTH );
}

crmRecordModifyDialog::~crmRecordModifyDialog()
{
}

crmRightDefDialog::crmRightDefDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer105;
	bSizer105 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer106;
	bSizer106 = new wxBoxSizer(  );

	wxGridSizer* gSizer2;
	gSizer2 = new wxGridSizer( 3, 2, 0, 0 );

	ID_STATICTEXT1 = new wxStaticText( this, wxID_ANY, wxT("module id:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT1->Wrap( -1 );
	gSizer2->Add( ID_STATICTEXT1, 1, wxALL|wxEXPAND, 5 );

	ID_TEXTCTRL_RIGHTID = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	ID_TEXTCTRL_RIGHTID->Enable( false );

	gSizer2->Add( ID_TEXTCTRL_RIGHTID, 2, wxALL|wxEXPAND, 5 );

	ID_STATICTEXT2 = new wxStaticText( this, wxID_ANY, wxT("module name:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT2->Wrap( -1 );
	gSizer2->Add( ID_STATICTEXT2, 1, wxALL|wxEXPAND, 5 );

	ID_TEXTCTRL_RIGHTNAME = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( ID_TEXTCTRL_RIGHTNAME, 2, wxALL|wxEXPAND, 5 );

	ID_STATICTEXT3 = new wxStaticText( this, wxID_ANY, wxT("right mask:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT3->Wrap( -1 );
	gSizer2->Add( ID_STATICTEXT3, 1, wxALL|wxEXPAND, 5 );

	ID_TEXTCTRL_RIGHTMASK = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( ID_TEXTCTRL_RIGHTMASK, 2, wxALL|wxEXPAND, 5 );


	bSizer106->Add( gSizer2, 1, wxALL|wxEXPAND, 5 );


	bSizer105->Add( bSizer106, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer107;
	bSizer107 = new wxBoxSizer(  );

	ID_STATICLINE1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxSize( 10,-1 ), wxLI_HORIZONTAL );
	bSizer107->Add( ID_STATICLINE1, 1, wxALL|wxEXPAND, 5 );


	bSizer105->Add( bSizer107, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer108;
	bSizer108 = new wxBoxSizer(  );

	m_sdbSizer12 = new wxStdDialogButtonSizer();
	m_sdbSizer12OK = new wxButton( this, wxID_OK );
	m_sdbSizer12->AddButton( m_sdbSizer12OK );
	m_sdbSizer12Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer12->AddButton( m_sdbSizer12Cancel );
	m_sdbSizer12->Realize();

	bSizer108->Add( m_sdbSizer12, 0, wxALL, 5 );

	ID_BUTTON3 = new wxButton( this, wxID_ANY, wxT("Reset(&R)"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON3->SetDefault();
	bSizer108->Add( ID_BUTTON3, 0, wxALL, 5 );


	bSizer105->Add( bSizer108, 0, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer105 );
	this->Layout();
	bSizer105->Fit( this );
}

crmRightDefDialog::~crmRightDefDialog()
{
}

crmTrainDefDialog::crmTrainDefDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer109;
	bSizer109 = new wxBoxSizer( wxVERTICAL );

	wxFlexGridSizer* fgSizer9;
	fgSizer9 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer9->AddGrowableCol( 1 );
	fgSizer9->SetFlexibleDirection( wxBOTH );
	fgSizer9->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	ID_STATICTEXT1 = new wxStaticText( this, wxID_ANY, wxT("train code:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT1->Wrap( -1 );
	fgSizer9->Add( ID_STATICTEXT1, 1, wxALL, 5 );

	ID_TEXTCTRL_TRAIN = new wxTextCtrl( this, wxID_ANY, wxT("Text"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( ID_TEXTCTRL_TRAIN, 1, wxALL|wxEXPAND, 5 );

	ID_STATICTEXT2 = new wxStaticText( this, wxID_ANY, wxT("start station name:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT2->Wrap( -1 );
	fgSizer9->Add( ID_STATICTEXT2, 1, wxALL, 5 );

	ID_TEXTCTRL_STARTSTATION = new wxTextCtrl( this, wxID_ANY, wxT("Text"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( ID_TEXTCTRL_STARTSTATION, 1, wxALL|wxEXPAND, 5 );

	ID_STATICTEXT3 = new wxStaticText( this, wxID_ANY, wxT("end station name:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT3->Wrap( -1 );
	fgSizer9->Add( ID_STATICTEXT3, 1, wxALL, 5 );

	ID_TEXTCTRL_ENDSTATION = new wxTextCtrl( this, wxID_ANY, wxT("Text"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( ID_TEXTCTRL_ENDSTATION, 1, wxALL|wxEXPAND, 5 );

	ID_STATICTEXT4 = new wxStaticText( this, wxID_ANY, wxT("start time:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT4->Wrap( -1 );
	fgSizer9->Add( ID_STATICTEXT4, 1, wxALL, 5 );

	ID_TEXTCTRL_TIME = new wxTextCtrl( this, wxID_ANY, wxT("Text"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( ID_TEXTCTRL_TIME, 1, wxALL|wxEXPAND, 5 );


	bSizer109->Add( fgSizer9, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer110;
	bSizer110 = new wxBoxSizer(  );

	ID_STATICLINE1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxSize( 10,-1 ), wxLI_HORIZONTAL );
	bSizer110->Add( ID_STATICLINE1, 1, wxALL|wxEXPAND, 5 );


	bSizer109->Add( bSizer110, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer111;
	bSizer111 = new wxBoxSizer(  );

	m_sdbSizer13 = new wxStdDialogButtonSizer();
	m_sdbSizer13OK = new wxButton( this, wxID_OK );
	m_sdbSizer13->AddButton( m_sdbSizer13OK );
	m_sdbSizer13Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer13->AddButton( m_sdbSizer13Cancel );
	m_sdbSizer13->Realize();

	bSizer111->Add( m_sdbSizer13, 0, wxALL, 5 );

	ID_BUTTON_RESET = new wxButton( this, wxID_ANY, wxT("Reset(&R)"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_RESET->SetDefault();
	bSizer111->Add( ID_BUTTON_RESET, 0, wxALL, 5 );


	bSizer109->Add( bSizer111, 0, wxALL, 5 );


	this->SetSizer( bSizer109 );
	this->Layout();
	bSizer109->Fit( this );

	this->Centre( wxBOTH );
}

crmTrainDefDialog::~crmTrainDefDialog()
{
}

crmWelcomePeopleDialog::crmWelcomePeopleDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxColour( 0, 0, 0 ) );

	wxBoxSizer* bSizer112;
	bSizer112 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer113;
	bSizer113 = new wxBoxSizer(  );

	ID_GRID_WELCOME = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxSize( 218,380 ), 0 );

	// Grid
	ID_GRID_WELCOME->CreateGrid( 5, 5 );
	ID_GRID_WELCOME->EnableEditing( true );
	ID_GRID_WELCOME->EnableGridLines( true );
	ID_GRID_WELCOME->EnableDragGridSize( false );
	ID_GRID_WELCOME->SetMargins( 0, 0 );

	// Columns
	ID_GRID_WELCOME->EnableDragColMove( false );
	ID_GRID_WELCOME->EnableDragColSize( true );
	ID_GRID_WELCOME->SetColLabelSize( 30 );
	ID_GRID_WELCOME->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	ID_GRID_WELCOME->EnableDragRowSize( true );
	ID_GRID_WELCOME->SetRowLabelSize( 80 );
	ID_GRID_WELCOME->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	ID_GRID_WELCOME->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer113->Add( ID_GRID_WELCOME, 1, wxALL|wxEXPAND, 5 );


	bSizer112->Add( bSizer113, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer114;
	bSizer114 = new wxBoxSizer(  );

	ID_STATICLINE1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxSize( 10,-1 ), wxLI_HORIZONTAL );
	bSizer114->Add( ID_STATICLINE1, 1, wxALL|wxEXPAND, 5 );


	bSizer112->Add( bSizer114, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer115;
	bSizer115 = new wxBoxSizer(  );

	ID_CHECKBOX_LOCKED = new wxCheckBox( this, wxID_ANY, wxT("still on top"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_CHECKBOX_LOCKED->SetValue(true);
	bSizer115->Add( ID_CHECKBOX_LOCKED, 0, wxALL, 5 );

	wxBoxSizer* bSizer116;
	bSizer116 = new wxBoxSizer( wxVERTICAL );

	ID_BUTTON_HIDE = new wxButton( this, wxID_ANY, wxT("hide(&H)"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_HIDE->SetDefault();
	bSizer116->Add( ID_BUTTON_HIDE, 0, wxALL, 5 );

	ID_BUTTON_RETRIEVE = new wxButton( this, wxID_ANY, wxT("retrieve(&R)"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_RETRIEVE->SetDefault();
	bSizer116->Add( ID_BUTTON_RETRIEVE, 0, wxALL, 5 );


	bSizer115->Add( bSizer116, 0, wxALL, 5 );


	bSizer112->Add( bSizer115, 0, wxALL, 5 );


	this->SetSizer( bSizer112 );
	this->Layout();
	bSizer112->Fit( this );
}

crmWelcomePeopleDialog::~crmWelcomePeopleDialog()
{
}

crmWelcomeRecordDialog::crmWelcomeRecordDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer117;
	bSizer117 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer118;
	bSizer118 = new wxBoxSizer(  );

	wxFlexGridSizer* fgSizer10;
	fgSizer10 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer10->SetFlexibleDirection( wxBOTH );
	fgSizer10->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	ID_STATICTEXT1 = new wxStaticText( this, wxID_ANY, wxT("group name:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT1->Wrap( -1 );
	fgSizer10->Add( ID_STATICTEXT1, 1, wxALL, 5 );

	ID_TEXTCTRL_GROUP = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 187,27 ), wxTE_READONLY );
	ID_TEXTCTRL_GROUP->Enable( false );

	fgSizer10->Add( ID_TEXTCTRL_GROUP, 1, wxALL|wxEXPAND, 5 );

	ID_STATICTEXT2 = new wxStaticText( this, wxID_ANY, wxT("user name:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT2->Wrap( -1 );
	fgSizer10->Add( ID_STATICTEXT2, 1, wxALL, 5 );

	ID_TEXTCTRL_USER = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	ID_TEXTCTRL_USER->Enable( false );

	fgSizer10->Add( ID_TEXTCTRL_USER, 1, wxALL|wxEXPAND, 5 );

	ID_STATICTEXT3 = new wxStaticText( this, wxID_ANY, wxT("card name:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT3->Wrap( -1 );
	fgSizer10->Add( ID_STATICTEXT3, 1, wxALL, 5 );

	ID_TEXTCTRL_CARD = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	ID_TEXTCTRL_CARD->Enable( false );

	fgSizer10->Add( ID_TEXTCTRL_CARD, 1, wxALL|wxEXPAND, 5 );


	bSizer118->Add( fgSizer10, 1, wxBOTTOM|wxRIGHT|wxTOP, 5 );

	wxBoxSizer* bSizer119;
	bSizer119 = new wxBoxSizer(  );

	ID_STATICBITMAP1 = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer119->Add( ID_STATICBITMAP1, 1, wxALL, 5 );


	bSizer118->Add( bSizer119, 0, wxALL, 5 );


	bSizer117->Add( bSizer118, 1, wxALL, 5 );

	wxFlexGridSizer* fgSizer11;
	fgSizer11 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer11->AddGrowableCol( 1 );
	fgSizer11->AddGrowableRow( 5 );
	fgSizer11->SetFlexibleDirection( wxBOTH );
	fgSizer11->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	ID_STATICTEXT4 = new wxStaticText( this, wxID_ANY, wxT("card id:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT4->Wrap( -1 );
	fgSizer11->Add( ID_STATICTEXT4, 1, wxALL, 5 );

	ID_TEXTCTRL_CARDID = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	fgSizer11->Add( ID_TEXTCTRL_CARDID, 1, wxALL|wxEXPAND, 5 );

	ID_STATICTEXT5 = new wxStaticText( this, wxID_ANY, wxT("presence name:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT5->Wrap( -1 );
	fgSizer11->Add( ID_STATICTEXT5, 1, wxALL, 5 );

	ID_TEXTCTRL_PRESENCE = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	fgSizer11->Add( ID_TEXTCTRL_PRESENCE, 1, wxALL|wxEXPAND, 5 );

	ID_STATICTEXT6 = new wxStaticText( this, wxID_ANY, wxT("train info:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT6->Wrap( -1 );
	fgSizer11->Add( ID_STATICTEXT6, 1, wxALL, 5 );

	ID_COMBOBOX_TRAIN = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_DROPDOWN|wxTE_PROCESS_ENTER );
	fgSizer11->Add( ID_COMBOBOX_TRAIN, 1, wxALL|wxEXPAND, 5 );

	ID_STATICTEXT7 = new wxStaticText( this, wxID_ANY, wxT("people count:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT7->Wrap( -1 );
	fgSizer11->Add( ID_STATICTEXT7, 1, wxALL, 5 );

	ID_SPINCTRL_PEOPLECOUNT = new wxSpinCtrl( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 0, 0 );
	fgSizer11->Add( ID_SPINCTRL_PEOPLECOUNT, 1, wxALL|wxEXPAND, 5 );

	ID_STATICTEXT8 = new wxStaticText( this, wxID_ANY, wxT("price:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT8->Wrap( -1 );
	fgSizer11->Add( ID_STATICTEXT8, 1, wxALL, 5 );

	ID_TEXTCTRL_PRICE = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	fgSizer11->Add( ID_TEXTCTRL_PRICE, 1, wxALL|wxEXPAND, 5 );

	ID_STATICTEXT9 = new wxStaticText( this, wxID_ANY, wxT("comment:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT9->Wrap( -1 );
	fgSizer11->Add( ID_STATICTEXT9, 1, wxALL, 5 );

	ID_TEXTCTRL_COMMENT = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 300,62 ), wxTE_PROCESS_ENTER|wxHSCROLL|wxALWAYS_SHOW_SB );
	fgSizer11->Add( ID_TEXTCTRL_COMMENT, 1, wxALL|wxEXPAND, 5 );


	bSizer117->Add( fgSizer11, 2, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer120;
	bSizer120 = new wxBoxSizer(  );

	ID_STATICLINE1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxLI_HORIZONTAL );
	bSizer120->Add( ID_STATICLINE1, 1, wxALL|wxEXPAND, 5 );


	bSizer117->Add( bSizer120, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer121;
	bSizer121 = new wxBoxSizer(  );

	m_sdbSizer14 = new wxStdDialogButtonSizer();
	m_sdbSizer14OK = new wxButton( this, wxID_OK );
	m_sdbSizer14->AddButton( m_sdbSizer14OK );
	m_sdbSizer14Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer14->AddButton( m_sdbSizer14Cancel );
	m_sdbSizer14->Realize();

	bSizer121->Add( m_sdbSizer14, 1, wxALL, 5 );

	ID_BUTTON_RESET = new wxButton( this, wxID_ANY, wxT("Reset(&R)"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_RESET->SetDefault();
	bSizer121->Add( ID_BUTTON_RESET, 0, wxALL, 5 );


	bSizer117->Add( bSizer121, 0, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer117 );
	this->Layout();
	bSizer117->Fit( this );

	this->Centre( wxBOTH );
}

crmWelcomeRecordDialog::~crmWelcomeRecordDialog()
{
}

testDialog::testDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer122;
	bSizer122 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer123;
	bSizer123 = new wxBoxSizer(  );

	ID_COMBOBOX1 = new wxBitmapComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_DROPDOWN );
	bSizer123->Add( ID_COMBOBOX1, 1, wxALL, 5 );


	bSizer122->Add( bSizer123, 1, wxALL|wxEXPAND, 5 );

	ID_STATICLINE1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxSize( 10,-1 ), wxLI_HORIZONTAL );
	bSizer122->Add( ID_STATICLINE1, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer124;
	bSizer124 = new wxBoxSizer(  );

	wxID_OK = new wxButton( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );

	wxID_OK->SetDefault();
	bSizer124->Add( wxID_OK, 1, wxALL, 5 );

	ID_BUTTON2 = new wxButton( this, wxID_ANY, wxT("test"), wxDefaultPosition, wxDefaultSize, 0|wxBORDER_NONE );

	ID_BUTTON2->SetDefault();
	bSizer124->Add( ID_BUTTON2, 1, wxALL, 5 );


	bSizer122->Add( bSizer124, 0, wxALL, 5 );


	this->SetSizer( bSizer122 );
	this->Layout();
	bSizer122->Fit( this );

	this->Centre( wxBOTH );
}

testDialog::~testDialog()
{
}

LoginDialog::LoginDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer126;
	bSizer126 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer127;
	bSizer127 = new wxBoxSizer(  );

	ID_STATICBITMAP1 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("gui/res/images/login.bmp"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer127->Add( ID_STATICBITMAP1, 1, wxALIGN_CENTER, 5 );


	bSizer126->Add( bSizer127, 0, wxEXPAND, 5 );

	wxFlexGridSizer* fgSizer12;
	fgSizer12 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer12->AddGrowableCol( 1 );
	fgSizer12->SetFlexibleDirection( wxBOTH );
	fgSizer12->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	ID_STATICTEXT1 = new wxStaticText( this, wxID_ANY, wxT("operator name:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT1->Wrap( -1 );
	fgSizer12->Add( ID_STATICTEXT1, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	ID_CHOICE_OPERATOR = new wxBitmapComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,35 ), 0, NULL, wxCB_READONLY|wxTE_PROCESS_ENTER );
	fgSizer12->Add( ID_CHOICE_OPERATOR, 0, wxALL|wxEXPAND, 5 );

	ID_STATICTEXT2 = new wxStaticText( this, wxID_ANY, wxT("password:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT2->Wrap( -1 );
	fgSizer12->Add( ID_STATICTEXT2, 1, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT, 5 );

	ID_TEXTCTRL_PASSWORD = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxPoint( -1,35 ), wxSize( -1,35 ), wxTE_PROCESS_ENTER|wxTE_PASSWORD );
	fgSizer12->Add( ID_TEXTCTRL_PASSWORD, 0, wxALL|wxEXPAND, 5 );


	bSizer126->Add( fgSizer12, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer128;
	bSizer128 = new wxBoxSizer(  );

	ID_STATICLINE1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxSize( 10,0 ), wxLI_HORIZONTAL );
	bSizer128->Add( ID_STATICLINE1, 1, wxEXPAND, 5 );


	bSizer126->Add( bSizer128, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer129;
	bSizer129 = new wxBoxSizer( wxHORIZONTAL );

	m_sdbSizer15 = new wxStdDialogButtonSizer();
	m_sdbSizer15OK = new wxButton( this, wxID_OK );
	m_sdbSizer15->AddButton( m_sdbSizer15OK );
	m_sdbSizer15No = new wxButton( this, wxID_NO );
	m_sdbSizer15->AddButton( m_sdbSizer15No );
	m_sdbSizer15Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer15->AddButton( m_sdbSizer15Cancel );
	m_sdbSizer15->Realize();

	bSizer129->Add( m_sdbSizer15, 1, wxALL|wxEXPAND, 5 );


	bSizer126->Add( bSizer129, 0, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer126 );
	this->Layout();
	bSizer126->Fit( this );

	this->Centre( wxBOTH );
}

LoginDialog::~LoginDialog()
{
}

crmTrainFilterDialog::crmTrainFilterDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer114;
	bSizer114 = new wxBoxSizer( wxVERTICAL );

	wxFlexGridSizer* fgSizer12;
	fgSizer12 = new wxFlexGridSizer( 3, 2, 0, 0 );
	fgSizer12->AddGrowableCol( 1 );
	fgSizer12->SetFlexibleDirection( wxBOTH );
	fgSizer12->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	ID_STATICTEXT1 = new wxStaticText( this, wxID_ANY, wxT("start station name:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT1->Wrap( -1 );
	fgSizer12->Add( ID_STATICTEXT1, 0, wxALL, 5 );

	ID_TEXTCTRL_STARTSTATIONNAME = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer12->Add( ID_TEXTCTRL_STARTSTATIONNAME, 2, wxALL|wxEXPAND, 5 );

	ID_STATICTEXT2 = new wxStaticText( this, wxID_ANY, wxT("end station name:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT2->Wrap( -1 );
	fgSizer12->Add( ID_STATICTEXT2, 0, wxALL, 5 );

	ID_TEXTCTRL_ENDSTATIONNAME = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer12->Add( ID_TEXTCTRL_ENDSTATIONNAME, 2, wxALL|wxEXPAND, 5 );

	ID_STATICTEXT3 = new wxStaticText( this, wxID_ANY, wxT("train code:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT3->Wrap( -1 );
	fgSizer12->Add( ID_STATICTEXT3, 0, wxALL, 5 );

	ID_TEXTCTRL_TRAINCODE = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer12->Add( ID_TEXTCTRL_TRAINCODE, 2, wxALL|wxEXPAND, 5 );


	bSizer114->Add( fgSizer12, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer115;
	bSizer115 = new wxBoxSizer(  );

	ID_STATICLINE1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxSize( 10,-1 ), wxLI_HORIZONTAL );
	bSizer115->Add( ID_STATICLINE1, 1, wxALL|wxEXPAND, 5 );


	bSizer114->Add( bSizer115, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer116;
	bSizer116 = new wxBoxSizer(  );


	bSizer116->Add( 84, 20, 1, wxALL, 5 );

	m_sdbSizer15 = new wxStdDialogButtonSizer();
	m_sdbSizer15OK = new wxButton( this, wxID_OK );
	m_sdbSizer15->AddButton( m_sdbSizer15OK );
	m_sdbSizer15Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer15->AddButton( m_sdbSizer15Cancel );
	m_sdbSizer15->Realize();

	bSizer116->Add( m_sdbSizer15, 1, wxALL, 5 );

	ID_BUTTON_RESET = new wxButton( this, wxID_ANY, wxT("Reset(&R)"), wxDefaultPosition, wxDefaultSize, 0 );

	ID_BUTTON_RESET->SetDefault();
	bSizer116->Add( ID_BUTTON_RESET, 0, wxALL, 5 );


	bSizer114->Add( bSizer116, 0, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer114 );
	this->Layout();
	bSizer114->Fit( this );

	this->Centre( wxBOTH );
}

crmTrainFilterDialog::~crmTrainFilterDialog()
{
}
