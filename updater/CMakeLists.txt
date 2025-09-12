add_executable(updater main.cpp
        Curl_Handler.cpp
        Curl_Handler.h
        ../handy_stuff.h
        Zip_Handler.cpp
        Zip_Handler.h)
# Makes sure it runs in a terminal
set_target_properties(updater PROPERTIES OUTPUT_NAME "updater_linux.sh")

find_package(CURL REQUIRED)
target_link_libraries(updater PRIVATE CURL::libcurl)
find_package(libzip CONFIG REQUIRED)
target_link_libraries(updater PRIVATE libzip::zip)

# An internal version number to help it know when to update
add_compile_definitions(updater PRIVATE VERSION="0.2.2")
