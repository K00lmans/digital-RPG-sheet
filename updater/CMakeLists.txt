add_executable(updater main.cpp)

find_package(pybind11 REQUIRED)
target_link_libraries(updater PRIVATE pybind11::embed)
