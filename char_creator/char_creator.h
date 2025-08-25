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
    string save_location;

public:
    UI() : window(nullptr) {}

    void save(wxCommandEvent &event) override;

    void load(wxCommandEvent &event) override;

    void save_as(wxCommandEvent &event) override;

    void new_char(wxCommandEvent &event) override;

    // Should only be used for a full refresh, each individual update should update its own changes
    void update_visuals();

    Character data = Character();
};

#endif //CHAR_CREATOR_H
