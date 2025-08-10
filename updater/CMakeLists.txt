add_executable(updater main.cpp
        Curl_Handler.cpp
        Curl_Handler.h)

find_package(CURL REQUIRED)
target_link_libraries(updater PRIVATE CURL::libcurl)
find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(updater PRIVATE nlohmann_json::nlohmann_json)
