cmake_minimum_required(VERSION 3.31)

add_executable(updater main.cpp)

find_package(Boost CONFIG REQUIRED COMPONENTS python)
target_link_libraries(updater PRIVATE Boost::python)

set_target_properties(updater PROPERTIES
        CXX_VERSION 26
        CXX_EXTENSIONS OFF
)