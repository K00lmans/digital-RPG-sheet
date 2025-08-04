///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "ui_template.h"

///////////////////////////////////////////////////////////////////////////

window::window( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxStaticBoxSizer* sbSizer13;
	sbSizer13 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Name") ), wxVERTICAL );

	sbSizer13->SetMinSize( wxSize( 200,-1 ) );
	char_name = new wxTextCtrl( sbSizer13->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer13->Add( char_name, 1, wxALL|wxEXPAND, 5 );


	fgSizer2->Add( sbSizer13, 1, wxALIGN_CENTER_VERTICAL, 5 );

	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxVERTICAL );

	save_button = new wxButton( this, wxID_ANY, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer25->Add( save_button, 0, wxALL|wxALIGN_RIGHT, 5 );

	load_button = new wxButton( this, wxID_ANY, _("Load"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer25->Add( load_button, 0, wxALL|wxALIGN_RIGHT, 5 );


	fgSizer2->Add( bSizer25, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticBoxSizer* sbSizer1411;
	sbSizer1411 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Int") ), wxVERTICAL );

	m_bpButton1711 = new wxBitmapButton( sbSizer1411->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton1711->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_UP), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer1411->Add( m_bpButton1711, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );

	m_staticText361 = new wxStaticText( sbSizer1411->GetStaticBox(), wxID_ANY, _("10"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText361->Wrap( -1 );
	sbSizer1411->Add( m_staticText361, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );

	m_bpButton1811 = new wxBitmapButton( sbSizer1411->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton1811->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_DOWN), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer1411->Add( m_bpButton1811, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );

	m_staticText1411 = new wxStaticText( sbSizer1411->GetStaticBox(), wxID_ANY, _("+0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1411->Wrap( -1 );
	sbSizer1411->Add( m_staticText1411, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_checkBox911 = new wxCheckBox( sbSizer1411->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox911->Enable( false );

	sbSizer1411->Add( m_checkBox911, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer12->Add( sbSizer1411, 1, 0, 5 );

	wxStaticBoxSizer* sbSizer1412;
	sbSizer1412 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Wis") ), wxVERTICAL );

	m_bpButton1712 = new wxBitmapButton( sbSizer1412->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton1712->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_UP), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer1412->Add( m_bpButton1712, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );

	m_staticText362 = new wxStaticText( sbSizer1412->GetStaticBox(), wxID_ANY, _("10"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText362->Wrap( -1 );
	sbSizer1412->Add( m_staticText362, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );

	m_bpButton18111 = new wxBitmapButton( sbSizer1412->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton18111->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_DOWN), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer1412->Add( m_bpButton18111, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );

	m_staticText1412 = new wxStaticText( sbSizer1412->GetStaticBox(), wxID_ANY, _("+0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1412->Wrap( -1 );
	sbSizer1412->Add( m_staticText1412, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_checkBox912 = new wxCheckBox( sbSizer1412->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox912->Enable( false );

	sbSizer1412->Add( m_checkBox912, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer12->Add( sbSizer1412, 1, 0, 5 );

	wxStaticBoxSizer* sbSizer1413;
	sbSizer1413 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Per") ), wxVERTICAL );

	m_bpButton17121 = new wxBitmapButton( sbSizer1413->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton17121->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_UP), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer1413->Add( m_bpButton17121, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );

	m_staticText363 = new wxStaticText( sbSizer1413->GetStaticBox(), wxID_ANY, _("10"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText363->Wrap( -1 );
	sbSizer1413->Add( m_staticText363, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );

	m_bpButton18112 = new wxBitmapButton( sbSizer1413->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton18112->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_DOWN), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer1413->Add( m_bpButton18112, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );

	m_staticText1413 = new wxStaticText( sbSizer1413->GetStaticBox(), wxID_ANY, _("+0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1413->Wrap( -1 );
	sbSizer1413->Add( m_staticText1413, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_checkBox913 = new wxCheckBox( sbSizer1413->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox913->Enable( false );

	sbSizer1413->Add( m_checkBox913, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer12->Add( sbSizer1413, 1, 0, 5 );

	wxStaticBoxSizer* sbSizer1415;
	sbSizer1415 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Str") ), wxVERTICAL );

	m_bpButton17122 = new wxBitmapButton( sbSizer1415->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton17122->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_UP), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer1415->Add( m_bpButton17122, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );

	m_staticText365 = new wxStaticText( sbSizer1415->GetStaticBox(), wxID_ANY, _("10"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText365->Wrap( -1 );
	sbSizer1415->Add( m_staticText365, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );

	m_bpButton18113 = new wxBitmapButton( sbSizer1415->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton18113->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_DOWN), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer1415->Add( m_bpButton18113, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );

	m_staticText1415 = new wxStaticText( sbSizer1415->GetStaticBox(), wxID_ANY, _("+0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1415->Wrap( -1 );
	sbSizer1415->Add( m_staticText1415, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_checkBox915 = new wxCheckBox( sbSizer1415->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox915->Enable( false );

	sbSizer1415->Add( m_checkBox915, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer12->Add( sbSizer1415, 1, 0, 5 );

	wxStaticBoxSizer* sbSizer1416;
	sbSizer1416 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Pre") ), wxVERTICAL );

	m_bpButton171221 = new wxBitmapButton( sbSizer1416->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton171221->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_UP), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer1416->Add( m_bpButton171221, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );

	m_staticText366 = new wxStaticText( sbSizer1416->GetStaticBox(), wxID_ANY, _("10"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText366->Wrap( -1 );
	sbSizer1416->Add( m_staticText366, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );

	m_bpButton18114 = new wxBitmapButton( sbSizer1416->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton18114->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_DOWN), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer1416->Add( m_bpButton18114, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );

	m_staticText1416 = new wxStaticText( sbSizer1416->GetStaticBox(), wxID_ANY, _("+0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1416->Wrap( -1 );
	sbSizer1416->Add( m_staticText1416, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_checkBox916 = new wxCheckBox( sbSizer1416->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox916->Enable( false );

	sbSizer1416->Add( m_checkBox916, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer12->Add( sbSizer1416, 1, 0, 5 );

	wxStaticBoxSizer* sbSizer1417;
	sbSizer1417 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("For") ), wxVERTICAL );

	m_bpButton171222 = new wxBitmapButton( sbSizer1417->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton171222->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_UP), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer1417->Add( m_bpButton171222, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );

	m_staticText367 = new wxStaticText( sbSizer1417->GetStaticBox(), wxID_ANY, _("10"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText367->Wrap( -1 );
	sbSizer1417->Add( m_staticText367, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );

	m_bpButton18115 = new wxBitmapButton( sbSizer1417->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton18115->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_DOWN), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer1417->Add( m_bpButton18115, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );

	m_staticText1417 = new wxStaticText( sbSizer1417->GetStaticBox(), wxID_ANY, _("+0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1417->Wrap( -1 );
	sbSizer1417->Add( m_staticText1417, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_checkBox917 = new wxCheckBox( sbSizer1417->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox917->Enable( false );

	sbSizer1417->Add( m_checkBox917, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer12->Add( sbSizer1417, 1, 0, 5 );

	wxStaticBoxSizer* sbSizer141;
	sbSizer141 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Agi") ), wxVERTICAL );

	m_bpButton171223 = new wxBitmapButton( sbSizer141->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton171223->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_UP), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer141->Add( m_bpButton171223, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );

	m_staticText36 = new wxStaticText( sbSizer141->GetStaticBox(), wxID_ANY, _("10"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText36->Wrap( -1 );
	sbSizer141->Add( m_staticText36, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );

	m_bpButton18116 = new wxBitmapButton( sbSizer141->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton18116->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_DOWN), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer141->Add( m_bpButton18116, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );

	m_staticText141 = new wxStaticText( sbSizer141->GetStaticBox(), wxID_ANY, _("+0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText141->Wrap( -1 );
	sbSizer141->Add( m_staticText141, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_checkBox91 = new wxCheckBox( sbSizer141->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox91->Enable( false );

	sbSizer141->Add( m_checkBox91, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer12->Add( sbSizer141, 1, 0, 5 );

	wxStaticBoxSizer* sbSizer1414;
	sbSizer1414 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Dex") ), wxVERTICAL );

	m_bpButton171224 = new wxBitmapButton( sbSizer1414->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton171224->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_UP), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer1414->Add( m_bpButton171224, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );

	m_staticText364 = new wxStaticText( sbSizer1414->GetStaticBox(), wxID_ANY, _("10"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText364->Wrap( -1 );
	sbSizer1414->Add( m_staticText364, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );

	m_bpButton18117 = new wxBitmapButton( sbSizer1414->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton18117->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_DOWN), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer1414->Add( m_bpButton18117, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );

	m_staticText1414 = new wxStaticText( sbSizer1414->GetStaticBox(), wxID_ANY, _("+0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1414->Wrap( -1 );
	sbSizer1414->Add( m_staticText1414, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_checkBox914 = new wxCheckBox( sbSizer1414->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox914->Enable( false );

	sbSizer1414->Add( m_checkBox914, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer12->Add( sbSizer1414, 1, 0, 5 );


	fgSizer2->Add( bSizer12, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxVERTICAL );


	bSizer24->Add( 0, 0, 1, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer33;
	sbSizer33 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Remaining Points") ), wxVERTICAL );

	m_staticText34 = new wxStaticText( sbSizer33->GetStaticBox(), wxID_ANY, _("10"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText34->Wrap( -1 );
	sbSizer33->Add( m_staticText34, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer24->Add( sbSizer33, 1, 0, 5 );


	bSizer24->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer13->Add( bSizer24, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer58;
	sbSizer58 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Health") ), wxVERTICAL );

	m_staticText58 = new wxStaticText( sbSizer58->GetStaticBox(), wxID_ANY, _("0/0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText58->Wrap( -1 );
	sbSizer58->Add( m_staticText58, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer26->Add( sbSizer58, 1, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer59;
	sbSizer59 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Speed") ), wxVERTICAL );

	m_staticText59 = new wxStaticText( sbSizer59->GetStaticBox(), wxID_ANY, _("15"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText59->Wrap( -1 );
	sbSizer59->Add( m_staticText59, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer26->Add( sbSizer59, 1, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer60;
	sbSizer60 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Protection Score") ), wxVERTICAL );

	m_staticText60 = new wxStaticText( sbSizer60->GetStaticBox(), wxID_ANY, _("1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText60->Wrap( -1 );
	sbSizer60->Add( m_staticText60, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer26->Add( sbSizer60, 1, wxEXPAND, 5 );


	bSizer13->Add( bSizer26, 1, wxEXPAND, 5 );


	fgSizer2->Add( bSizer13, 1, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer57;
	sbSizer57 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Lineages") ), wxVERTICAL );

	wxArrayString m_choice3Choices;
	m_choice3 = new wxChoice( sbSizer57->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice3Choices, 0 );
	m_choice3->SetSelection( 0 );
	sbSizer57->Add( m_choice3, 1, wxALL|wxEXPAND, 5 );


	fgSizer2->Add( sbSizer57, 1, wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer56;
	sbSizer56 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Description") ), wxVERTICAL );

	m_staticText57 = new wxStaticText( sbSizer56->GetStaticBox(), wxID_ANY, _("Please Select a Lineage"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText57->Wrap( 200 );
	m_staticText57->SetMinSize( wxSize( 200,-1 ) );
	m_staticText57->SetMaxSize( wxSize( 200,-1 ) );

	sbSizer56->Add( m_staticText57, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	fgSizer2->Add( sbSizer56, 1, wxEXPAND, 5 );

	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* fgSizer17;
	fgSizer17 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer17->SetFlexibleDirection( wxBOTH );
	fgSizer17->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* fgSizer18;
	fgSizer18 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer18->SetFlexibleDirection( wxBOTH );
	fgSizer18->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText106 = new wxStaticText( this, wxID_ANY, _("Teaching: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText106->Wrap( -1 );
	fgSizer18->Add( m_staticText106, 0, wxALL, 5 );

	m_checkBox113 = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox113->Enable( false );

	fgSizer18->Add( m_checkBox113, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_checkBox114 = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox114->Enable( false );

	fgSizer18->Add( m_checkBox114, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer17->Add( fgSizer18, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxFlexGridSizer* fgSizer181;
	fgSizer181 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer181->SetFlexibleDirection( wxBOTH );
	fgSizer181->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText1061 = new wxStaticText( this, wxID_ANY, _("Doctoring: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1061->Wrap( -1 );
	fgSizer181->Add( m_staticText1061, 0, wxALL, 5 );

	m_checkBox1131 = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox1131->Enable( false );

	fgSizer181->Add( m_checkBox1131, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_checkBox1141 = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox1141->Enable( false );

	fgSizer181->Add( m_checkBox1141, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer17->Add( fgSizer181, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxFlexGridSizer* fgSizer182;
	fgSizer182 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer182->SetFlexibleDirection( wxBOTH );
	fgSizer182->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText1062 = new wxStaticText( this, wxID_ANY, _("Intimidation: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1062->Wrap( -1 );
	fgSizer182->Add( m_staticText1062, 0, wxALL, 5 );

	m_checkBox1132 = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox1132->Enable( false );

	fgSizer182->Add( m_checkBox1132, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_checkBox1142 = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox1142->Enable( false );

	fgSizer182->Add( m_checkBox1142, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer17->Add( fgSizer182, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxFlexGridSizer* fgSizer183;
	fgSizer183 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer183->SetFlexibleDirection( wxBOTH );
	fgSizer183->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText1063 = new wxStaticText( this, wxID_ANY, _("Performance: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1063->Wrap( -1 );
	fgSizer183->Add( m_staticText1063, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_checkBox1133 = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox1133->Enable( false );

	fgSizer183->Add( m_checkBox1133, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_checkBox1143 = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox1143->Enable( false );

	fgSizer183->Add( m_checkBox1143, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer17->Add( fgSizer183, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxFlexGridSizer* fgSizer184;
	fgSizer184 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer184->SetFlexibleDirection( wxBOTH );
	fgSizer184->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText1064 = new wxStaticText( this, wxID_ANY, _("Acrobatics: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1064->Wrap( -1 );
	fgSizer184->Add( m_staticText1064, 0, wxALL, 5 );

	m_checkBox1134 = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox1134->Enable( false );

	fgSizer184->Add( m_checkBox1134, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_checkBox1144 = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox1144->Enable( false );

	fgSizer184->Add( m_checkBox1144, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer17->Add( fgSizer184, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxFlexGridSizer* fgSizer185;
	fgSizer185 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer185->SetFlexibleDirection( wxBOTH );
	fgSizer185->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText1065 = new wxStaticText( this, wxID_ANY, _("Supernatralism: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1065->Wrap( -1 );
	fgSizer185->Add( m_staticText1065, 0, wxALL, 5 );

	m_checkBox1135 = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox1135->Enable( false );

	fgSizer185->Add( m_checkBox1135, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_checkBox1145 = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox1145->Enable( false );

	fgSizer185->Add( m_checkBox1145, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer17->Add( fgSizer185, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxFlexGridSizer* fgSizer186;
	fgSizer186 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer186->SetFlexibleDirection( wxBOTH );
	fgSizer186->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText1066 = new wxStaticText( this, wxID_ANY, _("Suvival: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1066->Wrap( -1 );
	fgSizer186->Add( m_staticText1066, 0, wxALL, 5 );

	m_checkBox1136 = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox1136->Enable( false );

	fgSizer186->Add( m_checkBox1136, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_checkBox1146 = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox1146->Enable( false );

	fgSizer186->Add( m_checkBox1146, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer17->Add( fgSizer186, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxFlexGridSizer* fgSizer187;
	fgSizer187 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer187->SetFlexibleDirection( wxBOTH );
	fgSizer187->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText1067 = new wxStaticText( this, wxID_ANY, _("History: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1067->Wrap( -1 );
	fgSizer187->Add( m_staticText1067, 0, wxALL, 5 );

	m_checkBox1137 = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox1137->Enable( false );

	fgSizer187->Add( m_checkBox1137, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_checkBox1147 = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox1147->Enable( false );

	fgSizer187->Add( m_checkBox1147, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer17->Add( fgSizer187, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxFlexGridSizer* fgSizer188;
	fgSizer188 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer188->SetFlexibleDirection( wxBOTH );
	fgSizer188->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText1068 = new wxStaticText( this, wxID_ANY, _("Negotiation: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1068->Wrap( -1 );
	fgSizer188->Add( m_staticText1068, 0, wxALL, 5 );

	m_checkBox1138 = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox1138->Enable( false );

	fgSizer188->Add( m_checkBox1138, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_checkBox1148 = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox1148->Enable( false );

	fgSizer188->Add( m_checkBox1148, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer17->Add( fgSizer188, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxFlexGridSizer* fgSizer189;
	fgSizer189 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer189->SetFlexibleDirection( wxBOTH );
	fgSizer189->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText1069 = new wxStaticText( this, wxID_ANY, _("Athletics: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1069->Wrap( -1 );
	fgSizer189->Add( m_staticText1069, 0, wxALL, 5 );

	m_checkBox1139 = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox1139->Enable( false );

	fgSizer189->Add( m_checkBox1139, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_checkBox1149 = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox1149->Enable( false );

	fgSizer189->Add( m_checkBox1149, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer17->Add( fgSizer189, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxFlexGridSizer* fgSizer1810;
	fgSizer1810 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer1810->SetFlexibleDirection( wxBOTH );
	fgSizer1810->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText10610 = new wxStaticText( this, wxID_ANY, _("Investigation: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10610->Wrap( -1 );
	fgSizer1810->Add( m_staticText10610, 0, wxALL, 5 );

	m_checkBox11310 = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox11310->Enable( false );

	fgSizer1810->Add( m_checkBox11310, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_checkBox11410 = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox11410->Enable( false );

	fgSizer1810->Add( m_checkBox11410, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer17->Add( fgSizer1810, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxFlexGridSizer* fgSizer1811;
	fgSizer1811 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer1811->SetFlexibleDirection( wxBOTH );
	fgSizer1811->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText10611 = new wxStaticText( this, wxID_ANY, _("Stealth: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10611->Wrap( -1 );
	fgSizer1811->Add( m_staticText10611, 0, wxALL, 5 );

	m_checkBox11311 = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox11311->Enable( false );

	fgSizer1811->Add( m_checkBox11311, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_checkBox11411 = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox11411->Enable( false );

	fgSizer1811->Add( m_checkBox11411, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer17->Add( fgSizer1811, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxFlexGridSizer* fgSizer1812;
	fgSizer1812 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer1812->SetFlexibleDirection( wxBOTH );
	fgSizer1812->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText10612 = new wxStaticText( this, wxID_ANY, _("Sleight of Hand: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10612->Wrap( -1 );
	fgSizer1812->Add( m_staticText10612, 0, wxALL, 5 );

	m_checkBox11312 = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox11312->Enable( false );

	fgSizer1812->Add( m_checkBox11312, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_checkBox11412 = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox11412->Enable( false );

	fgSizer1812->Add( m_checkBox11412, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer17->Add( fgSizer1812, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxFlexGridSizer* fgSizer1813;
	fgSizer1813 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer1813->SetFlexibleDirection( wxBOTH );
	fgSizer1813->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText10613 = new wxStaticText( this, wxID_ANY, _("Mechanical: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10613->Wrap( -1 );
	fgSizer1813->Add( m_staticText10613, 0, wxALL, 5 );

	m_checkBox11313 = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox11313->Enable( false );

	fgSizer1813->Add( m_checkBox11313, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_checkBox11413 = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox11413->Enable( false );

	fgSizer1813->Add( m_checkBox11413, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer17->Add( fgSizer1813, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	fgSizer3->Add( fgSizer17, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText70 = new wxStaticText( this, wxID_ANY, _("Insight: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText70->Wrap( -1 );
	bSizer40->Add( m_staticText70, 0, wxALL, 5 );

	m_checkBox43 = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox43->Enable( false );

	bSizer40->Add( m_checkBox43, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_checkBox44 = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox44->Enable( false );

	bSizer40->Add( m_checkBox44, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer3->Add( bSizer40, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	fgSizer2->Add( fgSizer3, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer87;
	bSizer87 = new wxBoxSizer( wxVERTICAL );

	m_staticText95 = new wxStaticText( this, wxID_ANY, _("Starting Weapon and Armor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText95->Wrap( -1 );
	bSizer87->Add( m_staticText95, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxArrayString m_choice6Choices;
	m_choice6 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice6Choices, 0 );
	m_choice6->SetSelection( 0 );
	fgSizer4->Add( m_choice6, 0, wxALL, 5 );

	m_checkBox95 = new wxCheckBox( this, wxID_ANY, _("Trained"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox95->Enable( false );

	fgSizer4->Add( m_checkBox95, 0, wxALL, 5 );

	wxArrayString m_choice7Choices;
	m_choice7 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice7Choices, 0 );
	m_choice7->SetSelection( 0 );
	fgSizer4->Add( m_choice7, 0, wxALL, 5 );

	m_checkBox96 = new wxCheckBox( this, wxID_ANY, _("Trained"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox96->Enable( false );

	fgSizer4->Add( m_checkBox96, 0, wxALL, 5 );


	bSizer87->Add( fgSizer4, 1, wxEXPAND, 5 );


	fgSizer2->Add( bSizer87, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );

	wxStaticBoxSizer* sbSizer571;
	sbSizer571 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Backgrounds") ), wxVERTICAL );

	wxArrayString m_choice31Choices;
	m_choice31 = new wxChoice( sbSizer571->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice31Choices, 0 );
	m_choice31->SetSelection( 0 );
	sbSizer571->Add( m_choice31, 1, wxALL|wxEXPAND, 5 );


	fgSizer2->Add( sbSizer571, 1, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer561;
	sbSizer561 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Description") ), wxVERTICAL );

	m_staticText571 = new wxStaticText( sbSizer561->GetStaticBox(), wxID_ANY, _("Please Select a Background"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText571->Wrap( 200 );
	m_staticText571->SetMinSize( wxSize( 200,-1 ) );
	m_staticText571->SetMaxSize( wxSize( 200,-1 ) );

	sbSizer561->Add( m_staticText571, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	fgSizer2->Add( sbSizer561, 1, wxEXPAND, 5 );


	this->SetSizer( fgSizer2 );
	this->Layout();
	fgSizer2->Fit( this );

	this->Centre( wxBOTH );
}

window::~window()
{
}
