#ifndef CHAR_CREATOR_H
#define CHAR_CREATOR_H

#include <wx/wx.h>
#include <memory>
#include <filesystem>
#include <vector>

#include "load_template.h"
#include "ui_template.h"
#include "save_template.h"
#include "../Character.h"
#include "../handy_stuff.h"

#define SKILL_OFFSET 9 // How much you need to add to Attributes_And_Skills to get to the skills
#define SAVE_LOCATION find_file("saves", fs::current_path())
#define ITEM_DATA_LOCATION find_file("items.pd", fs::current_path())
#define CHAR_CREATION_DATA_LOCATION find_file("character.pd", fs::current_path())

using std::to_string;
using std::vector;
namespace fs = std::filesystem;

class Char_Creator final : public wxApp {
public:
    bool OnInit() override;
};

class UI final : public window {
public:
    struct Attributes {
        // References the objects associated with each attribute
        wxStaticText *value;
        wxStaticText *modifier;
        wxBitmapButton *up_button;
        wxBitmapButton *down_button;
        wxCheckBox *trained_check;
    };

    struct Skills {
        wxStaticText *modifier;
        wxCheckBox *trained_check;
        wxCheckBox *mastered_check;
    };

    UI() : window(nullptr) {
    }

private:
    void save(wxCommandEvent &event) override;

    void load(wxCommandEvent &event) override;

    void save_as(wxCommandEvent &event) override;

    void new_char(wxCommandEvent &event) override;

    // Calls to this should be kept to a minimum. Before calling this, make sure to save the character name if
    // you need to
    void update_visuals();

    // Attribute changes
    void change_attribute(int increment, Attributes_And_Skills chosen_attribute);

    static void update_attribute(const Attributes &attribute_info, const Character::Stat &chosen_attribute);

    void increase_int(wxCommandEvent &event) override { change_attribute(1, INTELLIGENCE); }
    void decrease_int(wxCommandEvent &event) override { change_attribute(-1, INTELLIGENCE); }
    void increase_wis(wxCommandEvent &event) override { change_attribute(1, WISDOM); }
    void decrease_wis(wxCommandEvent &event) override { change_attribute(-1, WISDOM); }
    void increase_per(wxCommandEvent &event) override { change_attribute(1, PERCEPTION); }
    void decrease_per(wxCommandEvent &event) override { change_attribute(-1, PERCEPTION); }
    void increase_str(wxCommandEvent &event) override { change_attribute(1, STRENGTH); }
    void decrease_str(wxCommandEvent &event) override { change_attribute(-1, STRENGTH); }
    void increase_pre(wxCommandEvent &event) override { change_attribute(1, PRESENCE); }
    void decrease_pre(wxCommandEvent &event) override { change_attribute(-1, PRESENCE); }
    void increase_for(wxCommandEvent &event) override { change_attribute(1, FORTITUDE); }
    void decrease_for(wxCommandEvent &event) override { change_attribute(-1, FORTITUDE); }
    void increase_agi(wxCommandEvent &event) override { change_attribute(1, AGILITY); }
    void decrease_agi(wxCommandEvent &event) override { change_attribute(-1, AGILITY); }
    void increase_dex(wxCommandEvent &event) override { change_attribute(1, DEXTERITY); }
    void decrease_dex(wxCommandEvent &event) override { change_attribute(-1, DEXTERITY); }

    void handle_training(bool handle_attributes = true, bool handle_skills = true);

    static void update_skill(const Skills &skill_info, const Character::Stat &chosen_skill);

    string save_location;
    vector<Attributes> attributes = {
        {intV, intM, int_up, int_down, int_training}, {wisV, wisM, wis_up, wis_down, wis_training},
        {perV, perM, per_up, per_down, per_training}, {strV, strM, str_up, str_down, str_training},
        {preV, preM, pre_up, pre_down, pre_training}, {forV, forM, for_up, for_down, for_training},
        {agiV, agiM, agi_up, agi_down, agi_training}, {dexV, dexM, dex_up, dex_down, dex_training}
    };
    vector<Skills> skills = { // There has got to be a better way to do this lol
        {teachingM, teaching_training, teaching_mastery}, {doctoringM, doctoring_training, doctoring_mastery},
        {intimidationM, intimidation_training, intimidation_mastery},
        {performanceM, performance_training, performance_mastery},
        {acrobaticsM, acrobatics_trained, acrobatics_mastered},
        {supernaturalismM, supernaturalism_training, supernaturalism_mastery},
        {survivalM, survival_training, survival_mastery}, {historyM, history_training, history_mastery},
        {negotiationM, negotiation_training, negotiation_mastery}, {athleticsM, athletics_training, athletics_mastery},
        {investigationM, investigation_training, investigation_mastery}, {stealthM, stealth_training, stealth_mastery},
        {SoHM, SoH_training, SoH_mastery}, {mechanicalM, mechanical_training, mechanical_mastery},
        {intuitionM, intuition_training, intuition_mastery}
    };
    std::unique_ptr<Character> data = std::make_unique<Character>();
};

class Save_Window final : public save_dialog {
    void saved(wxCommandEvent &event) override;

    void canceled(wxCommandEvent &event) override;

public:
    explicit Save_Window(wxWindow *parent) : save_dialog(parent) {
    }

    [[nodiscard]] string get_file_name() const { return static_cast<string>(file_name->GetValue()); }
};

class Load_Window final : public load_dialog {
    // Puts all the files of the correct time that are in the saves folder into the selection wheel. Made with
    // help from AI
    void get_files();

    void update_error(const string &new_error);

    void canceled(wxCommandEvent &event) override;

    void loaded(wxCommandEvent &event) override;

    string error;
    string selected_file;
    vector<string> file_paths;

public:
    explicit Load_Window(wxWindow *parent) : load_dialog(parent) {
        get_files();
    }

    [[nodiscard]] string get_selected_file() const;
};

#endif //CHAR_CREATOR_H
