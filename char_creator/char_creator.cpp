#include "char_creator.h"

wxIMPLEMENT_APP(Char_Creator);

bool Char_Creator::OnInit() {
    auto ui_info = new UI();
    ui_info->Show(TRUE);
    SetTopWindow(ui_info);
    return true;
}

void UI::save(wxCommandEvent &event) {
    OPENFILENAME file;
    string file_name;
    data.save_character(file_name);
}

void UI::load(wxCommandEvent &event) {
    OPENFILENAME file;
    string file_name;
    data = Character(std::ifstream(file_name));
}