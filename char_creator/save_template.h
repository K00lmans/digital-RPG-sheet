///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/sizer.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class save_dialog
///////////////////////////////////////////////////////////////////////////////
class save_dialog : public wxDialog
{
	private:

	protected:
		wxStaticText* text_plate;
		wxTextCtrl* file_name;
		wxButton* save_button;
		wxButton* cancel_button;

		// Virtual event handlers, override them in your derived class
		virtual void saved( wxCommandEvent& event ) { event.Skip(); }
		virtual void canceled( wxCommandEvent& event ) { event.Skip(); }


	public:

		save_dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Save File"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~save_dialog();

};

