cmake_minimum_required(VERSION 3.31)

add_executable(updater main.cpp)

set_target_properties(updater PROPERTIES
        CXX_VERSION 26
        CXX_EXTENSIONS OFF
)