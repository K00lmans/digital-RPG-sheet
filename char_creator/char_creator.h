#ifndef CHAR_CREATOR_H
#define CHAR_CREATOR_H

#include <wx/wx.h>

#include "ui_template.h"

class Char_Creator final : public wxApp {
public:
    bool OnInit() override;
};

class UI final : public window {
public:
    UI() : window(nullptr) {}
};

#endif //CHAR_CREATOR_H
