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
#include <wx/textctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/bmpbuttn.h>
#include <wx/stattext.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class window
///////////////////////////////////////////////////////////////////////////////
class window : public wxFrame
{
	private:

	protected:
		wxTextCtrl* char_name;
		wxButton* save_button;
		wxButton* load_button;
		wxBitmapButton* int_up;
		wxStaticText* m_staticText361;
		wxBitmapButton* int_down;
		wxStaticText* m_staticText1411;
		wxCheckBox* int_training;
		wxBitmapButton* wis_up;
		wxStaticText* m_staticText362;
		wxBitmapButton* wis_down;
		wxStaticText* wisM;
		wxCheckBox* wis_training;
		wxBitmapButton* per_up;
		wxStaticText* m_staticText363;
		wxBitmapButton* per_down;
		wxStaticText* m_staticText1413;
		wxCheckBox* per_training;
		wxBitmapButton* str_up;
		wxStaticText* strV;
		wxBitmapButton* str_down;
		wxStaticText* strM;
		wxCheckBox* str_training;
		wxBitmapButton* pre_up;
		wxStaticText* preV;
		wxBitmapButton* pre_down;
		wxStaticText* preM;
		wxCheckBox* pre_training;
		wxBitmapButton* for_up;
		wxStaticText* forV;
		wxBitmapButton* for_down;
		wxStaticText* forM;
		wxCheckBox* for_training;
		wxBitmapButton* agi_up;
		wxStaticText* agiV;
		wxBitmapButton* agi_down;
		wxStaticText* agiM;
		wxCheckBox* agi_training;
		wxBitmapButton* dex_up;
		wxStaticText* dexV;
		wxBitmapButton* dex_down;
		wxStaticText* dexM;
		wxCheckBox* dex_training;
		wxStaticText* remaining_points;
		wxStaticText* health;
		wxStaticText* speed;
		wxStaticText* protection_score;
		wxChoice* lineages;
		wxStaticText* lineage_description;
		wxStaticText* teachingM;
		wxCheckBox* teaching_training;
		wxCheckBox* teaching_mastery;
		wxStaticText* m_staticText1061;
		wxCheckBox* doctoring_training;
		wxCheckBox* doctoring_mastery;
		wxStaticText* intimidationM;
		wxCheckBox* intimidation_training;
		wxCheckBox* intimidation_mastery;
		wxStaticText* performanceM;
		wxCheckBox* performance_training;
		wxCheckBox* performance_mastery;
		wxStaticText* acrobaticsM;
		wxCheckBox* acrobatics_trained;
		wxCheckBox* acrobatics_mastered;
		wxStaticText* supernatralismM;
		wxCheckBox* supernatralism_training;
		wxCheckBox* supernatralism_mastery;
		wxStaticText* survivalM;
		wxCheckBox* survival_training;
		wxCheckBox* survival_mastery;
		wxStaticText* historyM;
		wxCheckBox* history_training;
		wxCheckBox* history_mastery;
		wxStaticText* negotiationM;
		wxCheckBox* negotiation_training;
		wxCheckBox* negotiation_mastery;
		wxStaticText* athleticsM;
		wxCheckBox* athletics_training;
		wxCheckBox* athletics_mastery;
		wxStaticText* investigationM;
		wxCheckBox* investigation_training;
		wxCheckBox* investigation_mastery;
		wxStaticText* stealthM;
		wxCheckBox* stealth_training;
		wxCheckBox* stealth_mastery;
		wxStaticText* SoHM;
		wxCheckBox* SoH_training;
		wxCheckBox* SoH_mastery;
		wxStaticText* mechanicalM;
		wxCheckBox* mechanical_training;
		wxCheckBox* mechanical_mastery;
		wxStaticText* insightM;
		wxCheckBox* insight_training;
		wxCheckBox* insight_mastery;
		wxStaticText* m_staticText95;
		wxChoice* weapon;
		wxCheckBox* weapon_training;
		wxChoice* armor;
		wxCheckBox* armor_training;
		wxChoice* backgrounds;
		wxStaticText* background_description;

		// Virtual event handlers, override them in your derived class
		virtual void save( wxCommandEvent& event ) { event.Skip(); }
		virtual void load( wxCommandEvent& event ) { event.Skip(); }
		virtual void increase_int( wxCommandEvent& event ) { event.Skip(); }
		virtual void decrease_int( wxCommandEvent& event ) { event.Skip(); }
		virtual void train_int( wxCommandEvent& event ) { event.Skip(); }
		virtual void increase_wis( wxCommandEvent& event ) { event.Skip(); }
		virtual void decrease_wis( wxCommandEvent& event ) { event.Skip(); }
		virtual void wis_trained( wxCommandEvent& event ) { event.Skip(); }
		virtual void increase_per( wxCommandEvent& event ) { event.Skip(); }
		virtual void trained_per( wxCommandEvent& event ) { event.Skip(); }
		virtual void increase_str( wxCommandEvent& event ) { event.Skip(); }
		virtual void decrease_str( wxCommandEvent& event ) { event.Skip(); }
		virtual void trained_str( wxCommandEvent& event ) { event.Skip(); }
		virtual void increase_pre( wxCommandEvent& event ) { event.Skip(); }
		virtual void decrease_pre( wxCommandEvent& event ) { event.Skip(); }
		virtual void trained_pre( wxCommandEvent& event ) { event.Skip(); }
		virtual void increase_for( wxCommandEvent& event ) { event.Skip(); }
		virtual void decrease_for( wxCommandEvent& event ) { event.Skip(); }
		virtual void trained_for( wxCommandEvent& event ) { event.Skip(); }
		virtual void increase_agi( wxCommandEvent& event ) { event.Skip(); }
		virtual void decrease_agi( wxCommandEvent& event ) { event.Skip(); }
		virtual void trained_agi( wxCommandEvent& event ) { event.Skip(); }
		virtual void increase_dec( wxCommandEvent& event ) { event.Skip(); }
		virtual void decrease_dex( wxCommandEvent& event ) { event.Skip(); }
		virtual void trained_dex( wxCommandEvent& event ) { event.Skip(); }
		virtual void lineage_selected( wxCommandEvent& event ) { event.Skip(); }
		virtual void trained_teaching( wxCommandEvent& event ) { event.Skip(); }
		virtual void mastered_teaching( wxCommandEvent& event ) { event.Skip(); }
		virtual void trained_doctoring( wxCommandEvent& event ) { event.Skip(); }
		virtual void mastered_doctoring( wxCommandEvent& event ) { event.Skip(); }
		virtual void trained_intimidation( wxCommandEvent& event ) { event.Skip(); }
		virtual void mastered_intimidation( wxCommandEvent& event ) { event.Skip(); }
		virtual void trained_performance( wxCommandEvent& event ) { event.Skip(); }
		virtual void mastered_performance( wxCommandEvent& event ) { event.Skip(); }
		virtual void trained_acrobatics( wxCommandEvent& event ) { event.Skip(); }
		virtual void mastered_acrobatics( wxCommandEvent& event ) { event.Skip(); }
		virtual void trained_supernatralism( wxCommandEvent& event ) { event.Skip(); }
		virtual void mastered_supernatralism( wxCommandEvent& event ) { event.Skip(); }
		virtual void trained_survival( wxCommandEvent& event ) { event.Skip(); }
		virtual void mastered_survival( wxCommandEvent& event ) { event.Skip(); }
		virtual void trained_history( wxCommandEvent& event ) { event.Skip(); }
		virtual void mastered_history( wxCommandEvent& event ) { event.Skip(); }
		virtual void trained_negotiation( wxCommandEvent& event ) { event.Skip(); }
		virtual void mastered_negotiation( wxCommandEvent& event ) { event.Skip(); }
		virtual void trained_athletics( wxCommandEvent& event ) { event.Skip(); }
		virtual void mastered_athletics( wxCommandEvent& event ) { event.Skip(); }
		virtual void trained_investigation( wxCommandEvent& event ) { event.Skip(); }
		virtual void mastered_investigation( wxCommandEvent& event ) { event.Skip(); }
		virtual void trained_stealth( wxCommandEvent& event ) { event.Skip(); }
		virtual void mastered_stealth( wxCommandEvent& event ) { event.Skip(); }
		virtual void trained_SoH( wxCommandEvent& event ) { event.Skip(); }
		virtual void mastered_SoH( wxCommandEvent& event ) { event.Skip(); }
		virtual void trained_mechanical( wxCommandEvent& event ) { event.Skip(); }
		virtual void mastered_mechanical( wxCommandEvent& event ) { event.Skip(); }
		virtual void trained_insight( wxCommandEvent& event ) { event.Skip(); }
		virtual void mastered_insight( wxCommandEvent& event ) { event.Skip(); }
		virtual void weapon_chosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void trained_weapon( wxCommandEvent& event ) { event.Skip(); }
		virtual void armor_chosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void trained_armor( wxCommandEvent& event ) { event.Skip(); }
		virtual void background_selected( wxCommandEvent& event ) { event.Skip(); }


	public:

		window( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("UTTRPG Character Creator"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~window();

};

