#include "char_creator.h"

wxIMPLEMENT_APP(Char_Creator);

bool Char_Creator::OnInit() {
    auto ui_info = new UI();
    ui_info->Show(TRUE);
    SetTopWindow(ui_info);
    return true;
}
