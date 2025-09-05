///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "load_template.h"

///////////////////////////////////////////////////////////////////////////

load_dialog::load_dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	text_plate = new wxStaticText( this, wxID_ANY, _("File to Load"), wxDefaultPosition, wxDefaultSize, 0 );
	text_plate->Wrap( -1 );
	bSizer3->Add( text_plate, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	error_text = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	error_text->Wrap( -1 );
	error_text->SetForegroundColour( wxColour( 255, 0, 0 ) );
	error_text->Hide();

	bSizer3->Add( error_text, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	wxArrayString file_selectionChoices;
	file_selection = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, file_selectionChoices, 0 );
	file_selection->SetSelection( 0 );
	file_selection->SetMinSize( wxSize( 160,-1 ) );

	bSizer3->Add( file_selection, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	load_button = new wxButton( this, wxID_ANY, _("Load"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( load_button, 0, wxALL, 5 );

	cancel_button = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( cancel_button, 0, wxALL, 5 );


	bSizer3->Add( bSizer4, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer3 );
	this->Layout();
	bSizer3->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	file_selection->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( load_dialog::file_selected ), NULL, this );
	load_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( load_dialog::loaded ), NULL, this );
	cancel_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( load_dialog::canceled ), NULL, this );
}

load_dialog::~load_dialog()
{
}
