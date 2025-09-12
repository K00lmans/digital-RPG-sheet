///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-111-g5faebfea)
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
	sbSizer13 = new wxStaticBoxSizer( wxVERTICAL, this, _("Name") );

	sbSizer13->SetMinSize( wxSize( 200,-1 ) );
	char_name = new wxTextCtrl( sbSizer13->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer13->Add( char_name, 1, wxALL|wxEXPAND, 5 );


	fgSizer2->Add( sbSizer13, 1, wxALIGN_CENTER_VERTICAL, 5 );

	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 0, 2, 0, 0 );

	save_button = new wxButton( this, wxID_ANY, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( save_button, 0, wxALL|wxALIGN_RIGHT, 5 );

	new_button = new wxButton( this, wxID_ANY, _("New"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( new_button, 0, wxALL, 5 );

	save_as_button = new wxButton( this, wxID_ANY, _("Save As"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( save_as_button, 0, wxALL, 5 );

	load_button = new wxButton( this, wxID_ANY, _("Load"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( load_button, 0, wxALL|wxALIGN_RIGHT, 5 );


	fgSizer2->Add( gSizer1, 1, wxEXPAND|wxALIGN_RIGHT, 5 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticBoxSizer* sbSizer1411;
	sbSizer1411 = new wxStaticBoxSizer( wxVERTICAL, this, _("Int") );

	int_up = new wxBitmapButton( sbSizer1411->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	int_up->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_UP), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer1411->Add( int_up, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );

	intV = new wxStaticText( sbSizer1411->GetStaticBox(), wxID_ANY, _("10"), wxDefaultPosition, wxDefaultSize, 0 );
	intV->Wrap( -1 );
	sbSizer1411->Add( intV, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );

	int_down = new wxBitmapButton( sbSizer1411->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	int_down->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_DOWN), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer1411->Add( int_down, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );

	intM = new wxStaticText( sbSizer1411->GetStaticBox(), wxID_ANY, _("+0"), wxDefaultPosition, wxDefaultSize, 0 );
	intM->Wrap( -1 );
	sbSizer1411->Add( intM, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	int_training = new wxCheckBox( sbSizer1411->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	int_training->Enable( false );

	sbSizer1411->Add( int_training, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer12->Add( sbSizer1411, 1, 0, 5 );

	wxStaticBoxSizer* sbSizer1412;
	sbSizer1412 = new wxStaticBoxSizer( wxVERTICAL, this, _("Wis") );

	wis_up = new wxBitmapButton( sbSizer1412->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	wis_up->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_UP), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer1412->Add( wis_up, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );

	wisV = new wxStaticText( sbSizer1412->GetStaticBox(), wxID_ANY, _("10"), wxDefaultPosition, wxDefaultSize, 0 );
	wisV->Wrap( -1 );
	sbSizer1412->Add( wisV, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );

	wis_down = new wxBitmapButton( sbSizer1412->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	wis_down->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_DOWN), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer1412->Add( wis_down, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );

	wisM = new wxStaticText( sbSizer1412->GetStaticBox(), wxID_ANY, _("+0"), wxDefaultPosition, wxDefaultSize, 0 );
	wisM->Wrap( -1 );
	sbSizer1412->Add( wisM, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wis_training = new wxCheckBox( sbSizer1412->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	wis_training->Enable( false );

	sbSizer1412->Add( wis_training, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer12->Add( sbSizer1412, 1, 0, 5 );

	wxStaticBoxSizer* sbSizer1413;
	sbSizer1413 = new wxStaticBoxSizer( wxVERTICAL, this, _("Per") );

	per_up = new wxBitmapButton( sbSizer1413->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	per_up->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_UP), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer1413->Add( per_up, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );

	perV = new wxStaticText( sbSizer1413->GetStaticBox(), wxID_ANY, _("10"), wxDefaultPosition, wxDefaultSize, 0 );
	perV->Wrap( -1 );
	sbSizer1413->Add( perV, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );

	per_down = new wxBitmapButton( sbSizer1413->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	per_down->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_DOWN), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer1413->Add( per_down, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );

	perM = new wxStaticText( sbSizer1413->GetStaticBox(), wxID_ANY, _("+0"), wxDefaultPosition, wxDefaultSize, 0 );
	perM->Wrap( -1 );
	sbSizer1413->Add( perM, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	per_training = new wxCheckBox( sbSizer1413->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	per_training->Enable( false );

	sbSizer1413->Add( per_training, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer12->Add( sbSizer1413, 1, 0, 5 );

	wxStaticBoxSizer* sbSizer1415;
	sbSizer1415 = new wxStaticBoxSizer( wxVERTICAL, this, _("Str") );

	str_up = new wxBitmapButton( sbSizer1415->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	str_up->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_UP), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer1415->Add( str_up, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );

	strV = new wxStaticText( sbSizer1415->GetStaticBox(), wxID_ANY, _("10"), wxDefaultPosition, wxDefaultSize, 0 );
	strV->Wrap( -1 );
	sbSizer1415->Add( strV, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );

	str_down = new wxBitmapButton( sbSizer1415->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	str_down->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_DOWN), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer1415->Add( str_down, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );

	strM = new wxStaticText( sbSizer1415->GetStaticBox(), wxID_ANY, _("+0"), wxDefaultPosition, wxDefaultSize, 0 );
	strM->Wrap( -1 );
	sbSizer1415->Add( strM, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	str_training = new wxCheckBox( sbSizer1415->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	str_training->Enable( false );

	sbSizer1415->Add( str_training, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer12->Add( sbSizer1415, 1, 0, 5 );

	wxStaticBoxSizer* sbSizer1416;
	sbSizer1416 = new wxStaticBoxSizer( wxVERTICAL, this, _("Pre") );

	pre_up = new wxBitmapButton( sbSizer1416->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	pre_up->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_UP), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer1416->Add( pre_up, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );

	preV = new wxStaticText( sbSizer1416->GetStaticBox(), wxID_ANY, _("10"), wxDefaultPosition, wxDefaultSize, 0 );
	preV->Wrap( -1 );
	sbSizer1416->Add( preV, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );

	pre_down = new wxBitmapButton( sbSizer1416->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	pre_down->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_DOWN), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer1416->Add( pre_down, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );

	preM = new wxStaticText( sbSizer1416->GetStaticBox(), wxID_ANY, _("+0"), wxDefaultPosition, wxDefaultSize, 0 );
	preM->Wrap( -1 );
	sbSizer1416->Add( preM, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	pre_training = new wxCheckBox( sbSizer1416->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	pre_training->Enable( false );

	sbSizer1416->Add( pre_training, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer12->Add( sbSizer1416, 1, 0, 5 );

	wxStaticBoxSizer* sbSizer1417;
	sbSizer1417 = new wxStaticBoxSizer( wxVERTICAL, this, _("For") );

	for_up = new wxBitmapButton( sbSizer1417->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	for_up->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_UP), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer1417->Add( for_up, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );

	forV = new wxStaticText( sbSizer1417->GetStaticBox(), wxID_ANY, _("10"), wxDefaultPosition, wxDefaultSize, 0 );
	forV->Wrap( -1 );
	sbSizer1417->Add( forV, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );

	for_down = new wxBitmapButton( sbSizer1417->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	for_down->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_DOWN), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer1417->Add( for_down, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );

	forM = new wxStaticText( sbSizer1417->GetStaticBox(), wxID_ANY, _("+0"), wxDefaultPosition, wxDefaultSize, 0 );
	forM->Wrap( -1 );
	sbSizer1417->Add( forM, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	for_training = new wxCheckBox( sbSizer1417->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	for_training->Enable( false );

	sbSizer1417->Add( for_training, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer12->Add( sbSizer1417, 1, 0, 5 );

	wxStaticBoxSizer* sbSizer141;
	sbSizer141 = new wxStaticBoxSizer( wxVERTICAL, this, _("Agi") );

	agi_up = new wxBitmapButton( sbSizer141->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	agi_up->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_UP), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer141->Add( agi_up, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );

	agiV = new wxStaticText( sbSizer141->GetStaticBox(), wxID_ANY, _("10"), wxDefaultPosition, wxDefaultSize, 0 );
	agiV->Wrap( -1 );
	sbSizer141->Add( agiV, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );

	agi_down = new wxBitmapButton( sbSizer141->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	agi_down->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_DOWN), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer141->Add( agi_down, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );

	agiM = new wxStaticText( sbSizer141->GetStaticBox(), wxID_ANY, _("+0"), wxDefaultPosition, wxDefaultSize, 0 );
	agiM->Wrap( -1 );
	sbSizer141->Add( agiM, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	agi_training = new wxCheckBox( sbSizer141->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	agi_training->Enable( false );

	sbSizer141->Add( agi_training, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer12->Add( sbSizer141, 1, 0, 5 );

	wxStaticBoxSizer* sbSizer1414;
	sbSizer1414 = new wxStaticBoxSizer( wxVERTICAL, this, _("Dex") );

	dex_up = new wxBitmapButton( sbSizer1414->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	dex_up->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_UP), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer1414->Add( dex_up, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );

	dexV = new wxStaticText( sbSizer1414->GetStaticBox(), wxID_ANY, _("10"), wxDefaultPosition, wxDefaultSize, 0 );
	dexV->Wrap( -1 );
	sbSizer1414->Add( dexV, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );

	dex_down = new wxBitmapButton( sbSizer1414->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	dex_down->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_DOWN), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer1414->Add( dex_down, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );

	dexM = new wxStaticText( sbSizer1414->GetStaticBox(), wxID_ANY, _("+0"), wxDefaultPosition, wxDefaultSize, 0 );
	dexM->Wrap( -1 );
	sbSizer1414->Add( dexM, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	dex_training = new wxCheckBox( sbSizer1414->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	dex_training->Enable( false );

	sbSizer1414->Add( dex_training, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer12->Add( sbSizer1414, 1, 0, 5 );


	fgSizer2->Add( bSizer12, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxVERTICAL );


	bSizer24->Add( 0, 0, 1, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer33;
	sbSizer33 = new wxStaticBoxSizer( wxVERTICAL, this, _("Remaining Points") );

	remaining_points = new wxStaticText( sbSizer33->GetStaticBox(), wxID_ANY, _("10"), wxDefaultPosition, wxDefaultSize, 0 );
	remaining_points->Wrap( -1 );
	sbSizer33->Add( remaining_points, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer24->Add( sbSizer33, 1, wxEXPAND, 5 );


	bSizer24->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer13->Add( bSizer24, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer58;
	sbSizer58 = new wxStaticBoxSizer( wxVERTICAL, this, _("Health") );

	health = new wxStaticText( sbSizer58->GetStaticBox(), wxID_ANY, _("0/0"), wxDefaultPosition, wxDefaultSize, 0 );
	health->Wrap( -1 );
	sbSizer58->Add( health, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer26->Add( sbSizer58, 1, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer59;
	sbSizer59 = new wxStaticBoxSizer( wxVERTICAL, this, _("Speed") );

	speed = new wxStaticText( sbSizer59->GetStaticBox(), wxID_ANY, _("15ft"), wxDefaultPosition, wxDefaultSize, 0 );
	speed->Wrap( -1 );
	sbSizer59->Add( speed, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer26->Add( sbSizer59, 1, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer60;
	sbSizer60 = new wxStaticBoxSizer( wxVERTICAL, this, _("Protection Score") );

	protection_score = new wxStaticText( sbSizer60->GetStaticBox(), wxID_ANY, _("1"), wxDefaultPosition, wxDefaultSize, 0 );
	protection_score->Wrap( -1 );
	sbSizer60->Add( protection_score, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer26->Add( sbSizer60, 1, wxEXPAND, 5 );


	bSizer13->Add( bSizer26, 1, wxEXPAND, 5 );


	fgSizer2->Add( bSizer13, 1, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer57;
	sbSizer57 = new wxStaticBoxSizer( wxVERTICAL, this, _("Lineages") );

	wxArrayString lineagesChoices;
	lineages = new wxChoice( sbSizer57->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, lineagesChoices, 0 );
	lineages->SetSelection( 0 );
	sbSizer57->Add( lineages, 1, wxALL|wxEXPAND, 5 );


	fgSizer2->Add( sbSizer57, 1, wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer56;
	sbSizer56 = new wxStaticBoxSizer( wxVERTICAL, this, _("Description") );

	lineage_description = new wxStaticText( sbSizer56->GetStaticBox(), wxID_ANY, _("Please Select a Lineage"), wxDefaultPosition, wxDefaultSize, 0 );
	lineage_description->Wrap( 200 );
	lineage_description->SetMinSize( wxSize( 200,-1 ) );
	lineage_description->SetMaxSize( wxSize( 200,-1 ) );

	sbSizer56->Add( lineage_description, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


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

	teachingM = new wxStaticText( this, wxID_ANY, _("Teaching: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	teachingM->Wrap( -1 );
	fgSizer18->Add( teachingM, 0, wxALL, 5 );

	teaching_training = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	teaching_training->Enable( false );

	fgSizer18->Add( teaching_training, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	teaching_mastery = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	teaching_mastery->Enable( false );

	fgSizer18->Add( teaching_mastery, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer17->Add( fgSizer18, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxFlexGridSizer* fgSizer181;
	fgSizer181 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer181->SetFlexibleDirection( wxBOTH );
	fgSizer181->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	doctoringM = new wxStaticText( this, wxID_ANY, _("Doctoring: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	doctoringM->Wrap( -1 );
	fgSizer181->Add( doctoringM, 0, wxALL, 5 );

	doctoring_training = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	doctoring_training->Enable( false );

	fgSizer181->Add( doctoring_training, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	doctoring_mastery = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	doctoring_mastery->Enable( false );

	fgSizer181->Add( doctoring_mastery, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer17->Add( fgSizer181, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxFlexGridSizer* fgSizer182;
	fgSizer182 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer182->SetFlexibleDirection( wxBOTH );
	fgSizer182->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	intimidationM = new wxStaticText( this, wxID_ANY, _("Intimidation: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	intimidationM->Wrap( -1 );
	fgSizer182->Add( intimidationM, 0, wxALL, 5 );

	intimidation_training = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	intimidation_training->Enable( false );

	fgSizer182->Add( intimidation_training, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	intimidation_mastery = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	intimidation_mastery->Enable( false );

	fgSizer182->Add( intimidation_mastery, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer17->Add( fgSizer182, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxFlexGridSizer* fgSizer183;
	fgSizer183 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer183->SetFlexibleDirection( wxBOTH );
	fgSizer183->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	performanceM = new wxStaticText( this, wxID_ANY, _("Performance: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	performanceM->Wrap( -1 );
	fgSizer183->Add( performanceM, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	performance_training = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	performance_training->Enable( false );

	fgSizer183->Add( performance_training, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	performance_mastery = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	performance_mastery->Enable( false );

	fgSizer183->Add( performance_mastery, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer17->Add( fgSizer183, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxFlexGridSizer* fgSizer184;
	fgSizer184 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer184->SetFlexibleDirection( wxBOTH );
	fgSizer184->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	acrobaticsM = new wxStaticText( this, wxID_ANY, _("Acrobatics: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	acrobaticsM->Wrap( -1 );
	fgSizer184->Add( acrobaticsM, 0, wxALL, 5 );

	acrobatics_trained = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	acrobatics_trained->Enable( false );

	fgSizer184->Add( acrobatics_trained, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	acrobatics_mastered = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	acrobatics_mastered->Enable( false );

	fgSizer184->Add( acrobatics_mastered, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer17->Add( fgSizer184, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxFlexGridSizer* fgSizer185;
	fgSizer185 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer185->SetFlexibleDirection( wxBOTH );
	fgSizer185->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	supernaturalismM = new wxStaticText( this, wxID_ANY, _("Supernaturalism: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	supernaturalismM->Wrap( -1 );
	fgSizer185->Add( supernaturalismM, 0, wxALL, 5 );

	supernaturalism_training = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	supernaturalism_training->Enable( false );

	fgSizer185->Add( supernaturalism_training, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	supernaturalism_mastery = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	supernaturalism_mastery->Enable( false );

	fgSizer185->Add( supernaturalism_mastery, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer17->Add( fgSizer185, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxFlexGridSizer* fgSizer186;
	fgSizer186 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer186->SetFlexibleDirection( wxBOTH );
	fgSizer186->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	survivalM = new wxStaticText( this, wxID_ANY, _("Suvival: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	survivalM->Wrap( -1 );
	fgSizer186->Add( survivalM, 0, wxALL, 5 );

	survival_training = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	survival_training->Enable( false );

	fgSizer186->Add( survival_training, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	survival_mastery = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	survival_mastery->Enable( false );

	fgSizer186->Add( survival_mastery, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer17->Add( fgSizer186, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxFlexGridSizer* fgSizer187;
	fgSizer187 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer187->SetFlexibleDirection( wxBOTH );
	fgSizer187->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	historyM = new wxStaticText( this, wxID_ANY, _("History: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	historyM->Wrap( -1 );
	fgSizer187->Add( historyM, 0, wxALL, 5 );

	history_training = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	history_training->Enable( false );

	fgSizer187->Add( history_training, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	history_mastery = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	history_mastery->Enable( false );

	fgSizer187->Add( history_mastery, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer17->Add( fgSizer187, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxFlexGridSizer* fgSizer188;
	fgSizer188 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer188->SetFlexibleDirection( wxBOTH );
	fgSizer188->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	negotiationM = new wxStaticText( this, wxID_ANY, _("Negotiation: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	negotiationM->Wrap( -1 );
	fgSizer188->Add( negotiationM, 0, wxALL, 5 );

	negotiation_training = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	negotiation_training->Enable( false );

	fgSizer188->Add( negotiation_training, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	negotiation_mastery = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	negotiation_mastery->Enable( false );

	fgSizer188->Add( negotiation_mastery, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer17->Add( fgSizer188, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxFlexGridSizer* fgSizer189;
	fgSizer189 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer189->SetFlexibleDirection( wxBOTH );
	fgSizer189->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	athleticsM = new wxStaticText( this, wxID_ANY, _("Athletics: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	athleticsM->Wrap( -1 );
	fgSizer189->Add( athleticsM, 0, wxALL, 5 );

	athletics_training = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	athletics_training->Enable( false );

	fgSizer189->Add( athletics_training, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	athletics_mastery = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	athletics_mastery->Enable( false );

	fgSizer189->Add( athletics_mastery, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer17->Add( fgSizer189, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxFlexGridSizer* fgSizer1810;
	fgSizer1810 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer1810->SetFlexibleDirection( wxBOTH );
	fgSizer1810->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	investigationM = new wxStaticText( this, wxID_ANY, _("Investigation: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	investigationM->Wrap( -1 );
	fgSizer1810->Add( investigationM, 0, wxALL, 5 );

	investigation_training = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	investigation_training->Enable( false );

	fgSizer1810->Add( investigation_training, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	investigation_mastery = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	investigation_mastery->Enable( false );

	fgSizer1810->Add( investigation_mastery, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer17->Add( fgSizer1810, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxFlexGridSizer* fgSizer1811;
	fgSizer1811 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer1811->SetFlexibleDirection( wxBOTH );
	fgSizer1811->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	stealthM = new wxStaticText( this, wxID_ANY, _("Stealth: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	stealthM->Wrap( -1 );
	fgSizer1811->Add( stealthM, 0, wxALL, 5 );

	stealth_training = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	stealth_training->Enable( false );

	fgSizer1811->Add( stealth_training, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	stealth_mastery = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	stealth_mastery->Enable( false );

	fgSizer1811->Add( stealth_mastery, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer17->Add( fgSizer1811, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxFlexGridSizer* fgSizer1812;
	fgSizer1812 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer1812->SetFlexibleDirection( wxBOTH );
	fgSizer1812->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	SoHM = new wxStaticText( this, wxID_ANY, _("Sleight of Hand: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	SoHM->Wrap( -1 );
	fgSizer1812->Add( SoHM, 0, wxALL, 5 );

	SoH_training = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	SoH_training->Enable( false );

	fgSizer1812->Add( SoH_training, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	SoH_mastery = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	SoH_mastery->Enable( false );

	fgSizer1812->Add( SoH_mastery, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer17->Add( fgSizer1812, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxFlexGridSizer* fgSizer1813;
	fgSizer1813 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer1813->SetFlexibleDirection( wxBOTH );
	fgSizer1813->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	mechanicalM = new wxStaticText( this, wxID_ANY, _("Mechanical: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	mechanicalM->Wrap( -1 );
	fgSizer1813->Add( mechanicalM, 0, wxALL, 5 );

	mechanical_training = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	mechanical_training->Enable( false );

	fgSizer1813->Add( mechanical_training, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	mechanical_mastery = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	mechanical_mastery->Enable( false );

	fgSizer1813->Add( mechanical_mastery, 0, wxTOP|wxBOTTOM, 5 );


	fgSizer17->Add( fgSizer1813, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	fgSizer3->Add( fgSizer17, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxHORIZONTAL );

	intuitionM = new wxStaticText( this, wxID_ANY, _("Intuition: +0"), wxDefaultPosition, wxDefaultSize, 0 );
	intuitionM->Wrap( -1 );
	bSizer40->Add( intuitionM, 0, wxALL, 5 );

	intuition_training = new wxCheckBox( this, wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	intuition_training->Enable( false );

	bSizer40->Add( intuition_training, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	intuition_mastery = new wxCheckBox( this, wxID_ANY, _("E"), wxDefaultPosition, wxDefaultSize, 0 );
	intuition_mastery->Enable( false );

	bSizer40->Add( intuition_mastery, 0, wxTOP|wxBOTTOM, 5 );


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

	wxArrayString weaponChoices;
	weapon = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, weaponChoices, 0 );
	weapon->SetSelection( 0 );
	fgSizer4->Add( weapon, 0, wxALL, 5 );

	weapon_training = new wxCheckBox( this, wxID_ANY, _("Trained"), wxDefaultPosition, wxDefaultSize, 0 );
	weapon_training->Enable( false );

	fgSizer4->Add( weapon_training, 0, wxALL, 5 );

	wxArrayString armorChoices;
	armor = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, armorChoices, 0 );
	armor->SetSelection( 0 );
	fgSizer4->Add( armor, 0, wxALL, 5 );

	armor_training = new wxCheckBox( this, wxID_ANY, _("Trained"), wxDefaultPosition, wxDefaultSize, 0 );
	armor_training->Enable( false );

	fgSizer4->Add( armor_training, 0, wxALL, 5 );


	bSizer87->Add( fgSizer4, 1, wxEXPAND, 5 );


	fgSizer2->Add( bSizer87, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );

	wxStaticBoxSizer* sbSizer571;
	sbSizer571 = new wxStaticBoxSizer( wxVERTICAL, this, _("Backgrounds") );

	wxArrayString backgroundsChoices;
	backgrounds = new wxChoice( sbSizer571->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, backgroundsChoices, 0 );
	backgrounds->SetSelection( 0 );
	sbSizer571->Add( backgrounds, 1, wxALL|wxEXPAND, 5 );


	fgSizer2->Add( sbSizer571, 1, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer561;
	sbSizer561 = new wxStaticBoxSizer( wxVERTICAL, this, _("Description") );

	background_description = new wxStaticText( sbSizer561->GetStaticBox(), wxID_ANY, _("Please Select a Background"), wxDefaultPosition, wxDefaultSize, 0 );
	background_description->Wrap( 200 );
	background_description->SetMinSize( wxSize( 200,-1 ) );
	background_description->SetMaxSize( wxSize( 200,-1 ) );

	sbSizer561->Add( background_description, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	fgSizer2->Add( sbSizer561, 1, wxEXPAND, 5 );


	this->SetSizer( fgSizer2 );
	this->Layout();
	fgSizer2->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	save_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( window::save ), NULL, this );
	new_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( window::new_char ), NULL, this );
	save_as_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( window::save_as ), NULL, this );
	load_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( window::load ), NULL, this );
	int_up->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( window::increase_int ), NULL, this );
	int_down->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( window::decrease_int ), NULL, this );
	int_training->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::train_int ), NULL, this );
	wis_up->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( window::increase_wis ), NULL, this );
	wis_down->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( window::decrease_wis ), NULL, this );
	wis_training->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::wis_trained ), NULL, this );
	per_up->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( window::increase_per ), NULL, this );
	per_down->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( window::decrease_per ), NULL, this );
	per_training->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::trained_per ), NULL, this );
	str_up->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( window::increase_str ), NULL, this );
	str_down->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( window::decrease_str ), NULL, this );
	str_training->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::trained_str ), NULL, this );
	pre_up->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( window::increase_pre ), NULL, this );
	pre_down->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( window::decrease_pre ), NULL, this );
	pre_training->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::trained_pre ), NULL, this );
	for_up->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( window::increase_for ), NULL, this );
	for_down->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( window::decrease_for ), NULL, this );
	for_training->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::trained_for ), NULL, this );
	agi_up->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( window::increase_agi ), NULL, this );
	agi_down->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( window::decrease_agi ), NULL, this );
	agi_training->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::trained_agi ), NULL, this );
	dex_up->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( window::increase_dex ), NULL, this );
	dex_down->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( window::decrease_dex ), NULL, this );
	dex_training->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::trained_dex ), NULL, this );
	lineages->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( window::lineage_selected ), NULL, this );
	teaching_training->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::trained_teaching ), NULL, this );
	teaching_mastery->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::mastered_teaching ), NULL, this );
	doctoring_training->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::trained_doctoring ), NULL, this );
	doctoring_mastery->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::mastered_doctoring ), NULL, this );
	intimidation_training->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::trained_intimidation ), NULL, this );
	intimidation_mastery->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::mastered_intimidation ), NULL, this );
	performance_training->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::trained_performance ), NULL, this );
	performance_mastery->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::mastered_performance ), NULL, this );
	acrobatics_trained->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::trained_acrobatics ), NULL, this );
	acrobatics_mastered->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::mastered_acrobatics ), NULL, this );
	supernaturalism_training->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::trained_supernaturalism ), NULL, this );
	supernaturalism_mastery->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::mastered_supernaturalism ), NULL, this );
	survival_training->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::trained_survival ), NULL, this );
	survival_mastery->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::mastered_survival ), NULL, this );
	history_training->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::trained_history ), NULL, this );
	history_mastery->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::mastered_history ), NULL, this );
	negotiation_training->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::trained_negotiation ), NULL, this );
	negotiation_mastery->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::mastered_negotiation ), NULL, this );
	athletics_training->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::trained_athletics ), NULL, this );
	athletics_mastery->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::mastered_athletics ), NULL, this );
	investigation_training->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::trained_investigation ), NULL, this );
	investigation_mastery->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::mastered_investigation ), NULL, this );
	stealth_training->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::trained_stealth ), NULL, this );
	stealth_mastery->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::mastered_stealth ), NULL, this );
	SoH_training->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::trained_SoH ), NULL, this );
	SoH_mastery->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::mastered_SoH ), NULL, this );
	mechanical_training->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::trained_mechanical ), NULL, this );
	mechanical_mastery->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::mastered_mechanical ), NULL, this );
	intuition_training->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::trained_intuition ), NULL, this );
	intuition_mastery->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::mastered_intuition ), NULL, this );
	weapon->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( window::weapon_chosen ), NULL, this );
	weapon_training->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::trained_weapon ), NULL, this );
	armor->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( window::armor_chosen ), NULL, this );
	armor_training->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( window::trained_armor ), NULL, this );
	backgrounds->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( window::background_selected ), NULL, this );
}

window::~window()
{
}
