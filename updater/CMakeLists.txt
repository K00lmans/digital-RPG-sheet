add_executable(updater main.cpp
        Curl_Handler.cpp
        Curl_Handler.h
        ../handy_stuff.h
        Zip_Handler.cpp
        Zip_Handler.h)

find_package(CURL REQUIRED)
target_link_libraries(updater PRIVATE CURL::libcurl)
find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(updater PRIVATE nlohmann_json::nlohmann_json)
find_package(libzip CONFIG REQUIRED)
target_link_libraries(updater PRIVATE libzip::zip)

# An internal version number to help it know when to update
add_compile_definitions(updater PRIVATE VERSION="0.1.2")
