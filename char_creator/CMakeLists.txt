add_executable(char_creator
        ui_template.cpp
        ui_template.h
        char_creator.cpp
        char_creator.h
        ../Character.cpp
        ../Character.h
        ../handy_stuff.h
        save_template.cpp
        save_template.h
        load_template.cpp
        load_template.h
)
# Makes it so it can be grabbed nice and easy by updater
set_target_properties(char_creator PROPERTIES OUTPUT_NAME "char_creator_linux")

find_package(wxWidgets CONFIG REQUIRED)
target_link_libraries(char_creator PRIVATE wx::core wx::base)
