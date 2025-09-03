add_executable(char_creator WIN32
        ui_template.cpp
        ui_template.h
        char_creator.cpp
        char_creator.h
        ../Character.cpp
        ../Character.h
        ../handy_stuff.h
)

find_package(wxWidgets CONFIG REQUIRED)
target_link_libraries(char_creator PRIVATE wx::core wx::base)
find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(updater PRIVATE nlohmann_json::nlohmann_json)
