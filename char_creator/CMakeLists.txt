add_executable(char_creator WIN32
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

find_package(wxWidgets CONFIG REQUIRED)
target_link_libraries(char_creator PRIVATE wx::core wx::base)
find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(char_creator PRIVATE nlohmann_json::nlohmann_json)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Set this to where you have created the saves folder
    add_compile_definitions(char_creator.cpp PRIVATE SAVE_LOCATION="../../saves/")
else ()
    add_compile_definitions(char_creator.cpp PRIVATE SAVE_LOCATION="../saves/")
endif ()
