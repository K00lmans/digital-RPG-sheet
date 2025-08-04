add_executable(char_creator WIN32
        ui_template.cpp
        ui_template.h
        char_creator.cpp
        char_creator.h
)

find_package(wxWidgets CONFIG REQUIRED)
target_link_libraries(char_creator PRIVATE wx::core wx::base)
