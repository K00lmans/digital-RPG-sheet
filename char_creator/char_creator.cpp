#include "char_creator.h"

#include <memory>

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
        data = std::make_unique<Character>(save_location);
        update_visuals();
    }
}

void UI::new_char(wxCommandEvent &event) {
    data = std::make_unique<Character>();
    update_visuals();
}

void UI::save_as(wxCommandEvent &event) {
    if (Save_Window dialog(this); dialog.ShowModal() == wxID_OK) {
        save_location = SAVE_LOCATION + dialog.get_file_name() + ".char";
        save(event);
    }
}

void UI::update_visuals() const {
    char_name->SetValue(data->name);
    int data_attribute = 0;
    for (const auto &ui_attribute: attributes) {
        // What a mess lol
        ui_attribute.value->SetLabel(
            std::to_string(data->get_stat(static_cast<Character::Attributes_And_Skills>(data_attribute)).value.value()));
        ui_attribute.modifier->SetLabel(
            std::to_string(data->get_stat(static_cast<Character::Attributes_And_Skills>(data_attribute)).modifier));
        ui_attribute.trained_check->SetValue(
            data->get_stat(static_cast<Character::Attributes_And_Skills>(data_attribute)).training_info.training_level);
        if (data->lineage.empty()) {
            ui_attribute.trained_check->Disable();
        } else {
            // Enable or disable based on lineage
        }
        data_attribute++;
    }
    // Same thing for stats
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

void Load_Window::get_files() const {
    // Setup to save selection data
    const auto selection = file_selection->GetStringSelection();

    file_selection->Clear();
    for (const auto &file : std::filesystem::directory_iterator(SAVE_LOCATION)) {
        if (file.path().extension().string() == ".char") {
            file_selection->Append(file.path().string());
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
    return static_cast<string>(file_selection->GetString(selection));
}
