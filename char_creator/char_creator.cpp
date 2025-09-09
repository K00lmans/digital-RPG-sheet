#include "char_creator.h"

wxIMPLEMENT_APP(Char_Creator);

bool Char_Creator::OnInit() {
    auto ui_info = new UI();
    ui_info->Show(TRUE);
    return true;
}

void UI::save(wxCommandEvent &event) {
    data->name = char_name->GetValue(); // Instead of getting the name with every keypress get it only when needed
    if (save_location.empty()) {
        save_as(event);
    }
    data->save_character(save_location);
}

void UI::load(wxCommandEvent &event) {
    if (Load_Window dialog(this); dialog.ShowModal() == wxID_OK) {
        save_location = dialog.get_selected_file();
        if (!save_location.empty()) { // If nothing is loaded, do nothing
            data = std::make_unique<Character>(save_location);
            update_visuals();
        }
    }
}

void UI::new_char(wxCommandEvent &event) {
    save_location.clear();
    data = std::make_unique<Character>();
    update_visuals();
}

void UI::save_as(wxCommandEvent &event) {
    if (Save_Window dialog(this); dialog.ShowModal() == wxID_OK) {
        save_location = SAVE_LOCATION.value().string() + "/" + dialog.get_file_name() + ".cha";
        save(event);
    }
}

void UI::update_visuals() {
    char_name->SetValue(data->name);
    int data_attribute = 0;
    for (const auto &ui_attribute: attributes) {
        update_attribute(ui_attribute, data->get_stat(static_cast<Attributes_And_Skills>(data_attribute)));
        data_attribute++;
    }
    remaining_points->SetLabel(to_string(data->calculate_remaining_points()));
    health->SetLabel(to_string(data->get_health()) + "/" + to_string(data->get_max_health()));
    speed->SetLabel(remove_trailing_zeros(to_string(data->calculate_speed())) + "ft");
    protection_score->SetLabel(to_string(data->calculate_protection_score()));
    int data_skill = SKILL_OFFSET;
    for (const auto &ui_skill: skills) {
        update_skill(ui_skill, data->get_stat(static_cast<Attributes_And_Skills>(data_skill)));
        data_skill++;
    }
    handle_training();
}

void Save_Window::saved(wxCommandEvent &event) {
    EndModal(wxID_OK);
}

void Save_Window::canceled(wxCommandEvent &event) {
    EndModal(wxID_CANCEL);
}

void Load_Window::update_error(const string &new_error) {
    error = new_error;
    error_text->SetLabel(error.c_str());
    if (!error_text->IsShownOnScreen()) {
        error_text->Show();
    }
}

void Load_Window::get_files() {
    // Setup to save selection data
    const auto selection = file_selection->GetStringSelection();

    file_selection->Clear();
    for (const auto &file: fs::directory_iterator(SAVE_LOCATION.value())) {
        if (file.path().extension().string() == ".char" || file.path().extension().string() == ".cha") {
            file_paths.push_back(fs::relative(file.path(), fs::current_path()).string());
            file_selection->Append(fs::relative(file.path(), SAVE_LOCATION.value()).stem().string());
        }
    }

    // Restore the selected item
    if (!selection.IsEmpty()) {
        if (const int selected_file_value = file_selection->FindString(selection); selected_file_value != wxNOT_FOUND) {
            file_selection->SetSelection(selected_file_value);
        }
    }
    // Default value of the first entry
    if (file_selection->GetSelection() == wxNOT_FOUND && file_selection->GetCount() > 0) {
        file_selection->SetSelection(0);
    }
}

void Load_Window::canceled(wxCommandEvent &event) {
    EndModal(wxID_CANCEL);
}

void Load_Window::loaded(wxCommandEvent &event) {
    const auto currently_selected_file = get_selected_file();
    get_files(); // Refresh the files to make sure the selected file is still valid
    if (currently_selected_file == get_selected_file()) {
        selected_file = currently_selected_file;
        EndModal(wxID_OK);
    } else {
        update_error("File Read Error: Files in save folder have been modified. Please try again");
    }
}

string Load_Window::get_selected_file() const {
    if (!selected_file.empty()) {
        return selected_file;
    }
    const int selection = file_selection->GetSelection();
    if (selection == wxNOT_FOUND) {
        return {};
    }
    return file_paths[selection];
}

void UI::change_attribute(const int increment, const Attributes_And_Skills chosen_attribute) {
    data->name = char_name->GetValue();
    data->change_attributes(chosen_attribute, increment, Character::ADD_TO);
    data->update_skills();
    update_visuals(); // As changing an attribute has a massive knock-on effect, just call this
}

void UI::update_attribute(const Attributes &attribute_info, const Character::Stat &chosen_attribute) {
    attribute_info.value->SetLabel(to_string(chosen_attribute.value.value()));
    attribute_info.modifier->SetLabel(
        (get_sign(chosen_attribute.modifier) == -1 ? "" : "+") + to_string(chosen_attribute.modifier));
    attribute_info.trained_check->SetValue(chosen_attribute.training_info.training_level);
}

void UI::handle_training(const bool handle_attributes, const bool handle_skills) {
    if (handle_attributes) {
        if (data->lineage.empty()) {
            // Disable all attribute training checks
        } else {
            // Enable or disable based on lineage
        }
    }
    if (handle_skills) {
        if (data->background.empty()) {
            // Disable all skill training checks
        } else {
            // Enable or disable based on background
        }
    }
}

void UI::update_skill(const Skills &skill_info, const Character::Stat &chosen_skill) {
    // Gets just the bit before the actual value
    string modifier_string{skill_info.modifier->GetLabel().substr(0, skill_info.modifier->GetLabel().find(": ") + 2)};
    modifier_string += get_sign(chosen_skill.modifier) == -1 ? "" : "+"; // Adds sign
    modifier_string += to_string(chosen_skill.modifier); // And finally adds the number
    skill_info.modifier->SetLabel(modifier_string);
    skill_info.trained_check->SetValue(chosen_skill.training_info.training_level);
    skill_info.mastered_check->SetValue(chosen_skill.training_info.training_level == EXPERT);
}
