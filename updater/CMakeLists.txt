add_executable(updater main.cpp)

find_package(curlcpp CONFIG REQUIRED)
target_link_libraries(updater PRIVATE curlcpp::curlcpp)
find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(updater PRIVATE nlohmann_json::nlohmann_json)
