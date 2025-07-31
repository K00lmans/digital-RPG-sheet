///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "ui_template.h"

///////////////////////////////////////////////////////////////////////////

main_frame::main_frame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxGridSizer* stats;
	stats = new wxGridSizer( 1, 8, 0, 0 );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );

	m_button10 = new wxButton( this, wxID_ANY, _("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_button10, 0, wxALL, 5 );

	m_staticText1 = new wxStaticText( this, wxID_ANY, _("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer14->Add( m_staticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_button11 = new wxButton( this, wxID_ANY, _("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_button11, 0, wxALL, 5 );


	stats->Add( bSizer14, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );

	m_button12 = new wxButton( this, wxID_ANY, _("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_button12, 0, wxALL, 5 );

	m_staticText2 = new wxStaticText( this, wxID_ANY, _("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer15->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_button13 = new wxButton( this, wxID_ANY, _("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_button13, 0, wxALL, 5 );


	stats->Add( bSizer15, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );

	m_button14 = new wxButton( this, wxID_ANY, _("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_button14, 0, wxALL, 5 );

	m_staticText3 = new wxStaticText( this, wxID_ANY, _("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer16->Add( m_staticText3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_button15 = new wxButton( this, wxID_ANY, _("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_button15, 0, wxALL, 5 );


	stats->Add( bSizer16, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxVERTICAL );

	m_button16 = new wxButton( this, wxID_ANY, _("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_button16, 0, wxALL, 5 );

	m_staticText4 = new wxStaticText( this, wxID_ANY, _("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer17->Add( m_staticText4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_button17 = new wxButton( this, wxID_ANY, _("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_button17, 0, wxALL, 5 );


	stats->Add( bSizer17, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxVERTICAL );

	m_button18 = new wxButton( this, wxID_ANY, _("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( m_button18, 0, wxALL, 5 );

	m_staticText5 = new wxStaticText( this, wxID_ANY, _("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer18->Add( m_staticText5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_button19 = new wxButton( this, wxID_ANY, _("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( m_button19, 0, wxALL, 5 );


	stats->Add( bSizer18, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxVERTICAL );

	m_button20 = new wxButton( this, wxID_ANY, _("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer19->Add( m_button20, 0, wxALL, 5 );

	m_staticText6 = new wxStaticText( this, wxID_ANY, _("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer19->Add( m_staticText6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_button21 = new wxButton( this, wxID_ANY, _("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer19->Add( m_button21, 0, wxALL, 5 );


	stats->Add( bSizer19, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxVERTICAL );

	m_button22 = new wxButton( this, wxID_ANY, _("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_button22, 0, wxALL, 5 );

	m_staticText7 = new wxStaticText( this, wxID_ANY, _("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer20->Add( m_staticText7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_button23 = new wxButton( this, wxID_ANY, _("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_button23, 0, wxALL, 5 );


	stats->Add( bSizer20, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );

	m_button24 = new wxButton( this, wxID_ANY, _("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer21->Add( m_button24, 0, wxALL, 5 );

	m_staticText8 = new wxStaticText( this, wxID_ANY, _("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer21->Add( m_staticText8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_button25 = new wxButton( this, wxID_ANY, _("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer21->Add( m_button25, 0, wxALL, 5 );


	stats->Add( bSizer21, 1, wxEXPAND, 5 );


	this->SetSizer( stats );
	this->Layout();
	stats->Fit( this );

	this->Centre( wxBOTH );
}

main_frame::~main_frame()
{
}
