#include "char_creator.h"

wxIMPLEMENT_APP(Char_Creator);

bool Char_Creator::OnInit() {
    auto ui_info = new UI();
    ui_info->Show(TRUE);
    SetTopWindow(ui_info);
    return true;
}

void UI::save(wxCommandEvent &event) {
    data.name = char_name->GetValue(); // Instead of getting the name with every keypress get it only when needed
    if (save_location.empty()) {
        save_as(event);
    }
    data.save_character(save_location);
}

void UI::load(wxCommandEvent &event) {
    OPENFILENAME file;
    data = Character(save_location);
    update_visuals();
}

void UI::new_char(wxCommandEvent &event) {
    data = Character();
    update_visuals();
}

void UI::save_as(wxCommandEvent &event) {
    OPENFILENAME file;
}
