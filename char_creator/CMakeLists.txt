add_executable(char_creator main.cpp)

find_package(wxWidgets CONFIG REQUIRED)
target_link_libraries(char_creator PRIVATE wx::core wx::base)
