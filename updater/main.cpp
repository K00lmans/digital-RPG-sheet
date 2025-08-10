#include <string>
#include <filesystem>
#include <iostream>
#include <curlcpp/curl_easy.h>
#include <nlohmann/json.hpp>

namespace fs = std::filesystem;
using std::cout;
using std::endl;

std::string VERSION = "test"; // An internal version number to help it know when to update

int main() {
    if (!fs::exists(fs::status("old_updater.exe"))) { // If this exists, then an update was just done
        bool update = false;
        cout << "Checking for data folder..." << endl;
        if (!fs::exists(fs::status("data"))) {
            cout << "Data folder not found, performing full install..." << endl;
            update = true;
            fs::create_directory("data");
        } else {
            cout << "Data folder found, checking for updates..." << endl;
        }
        if (update) {
            cout << "Update installed. ";
        }
    } else {
        fs::remove(fs::path("old_updater.exe")); // Removes the outdated version
    }
    cout << "Launching character creator..." << endl;
    return 0;
}