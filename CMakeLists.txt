cmake_minimum_required(VERSION 3.31)
project(RPG_SHEET)

set(CMAKE_CXX_STANDARD 26)

add_subdirectory(updater)
add_subdirectory(char_creator)

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(updater PRIVATE nlohmann_json::nlohmann_json)
