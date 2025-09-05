#ifndef CHAR_CREATOR_H
#define CHAR_CREATOR_H

#include <wx/wx.h>
#include <memory>
#include <filesystem>

#include "load_template.h"
#include "ui_template.h"
#include "save_template.h"
#include "../Character.h"

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

private:
    string save_location;
    vector<Attributes> attributes = {{intV, intM, int_up, int_down, int_training}};

public:
    UI() : window(nullptr) {
    }

    void save(wxCommandEvent &event) override;

    void load(wxCommandEvent &event) override;

    void save_as(wxCommandEvent &event) override;

    void new_char(wxCommandEvent &event) override;

    // Should only be used for a full refresh, each individual update should update its own changes
    void update_visuals() const;

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
    void get_files() const;

    void update_error(const string &new_error);

    void canceled(wxCommandEvent &event) override;

    void loaded(wxCommandEvent &event) override;

    string error;
    string selected_file;

public:
    explicit Load_Window(wxWindow *parent) : load_dialog(parent) {
        get_files();
    }

    [[nodiscard]] string get_selected_file() const;
};

#endif //CHAR_CREATOR_H
