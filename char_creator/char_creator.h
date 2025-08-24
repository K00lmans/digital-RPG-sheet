#ifndef CHAR_CREATOR_H
#define CHAR_CREATOR_H

#include <wx/wx.h>
#include <windows.h>
#include <commdlg.h>

#include "ui_template.h"
#include "../Character.h"

class Char_Creator final : public wxApp {
public:
    bool OnInit() override;
};

class UI final : public window {
public:
    UI() : window(nullptr) {}

    void save(wxCommandEvent &event) override;

    void load(wxCommandEvent &event) override;

    Character data = Character();
};

#endif //CHAR_CREATOR_H
