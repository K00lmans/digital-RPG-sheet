///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "save_template.h"

///////////////////////////////////////////////////////////////////////////

save_dialog::save_dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	text_plate = new wxStaticText( this, wxID_ANY, _("File Name"), wxDefaultPosition, wxDefaultSize, 0 );
	text_plate->Wrap( -1 );
	bSizer7->Add( text_plate, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	file_name = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !file_name->HasFlag( wxTE_MULTILINE ) )
	{
	file_name->SetMaxLength( 24 );
	}
	#else
	file_name->SetMaxLength( 24 );
	#endif
	file_name->SetMinSize( wxSize( 160,-1 ) );

	bSizer7->Add( file_name, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	save_button = new wxButton( this, wxID_ANY, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( save_button, 0, wxALL, 5 );

	cancel_button = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( cancel_button, 0, wxALL, 5 );


	bSizer7->Add( bSizer8, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer7 );
	this->Layout();
	bSizer7->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	save_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( save_dialog::saved ), NULL, this );
	cancel_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( save_dialog::canceled ), NULL, this );
}

save_dialog::~save_dialog()
{
}
