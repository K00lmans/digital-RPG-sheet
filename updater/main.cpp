#include <string>
#include <filesystem>
#include <iostream>
#include <nlohmann/json.hpp>
#include <memory>
#include "Curl_Handler.h"

namespace fs = std::filesystem;
using std::cout;
using std::endl;
using nlohmann::json;
using CH = Curl_Handler;

std::string VERSION = "test"; // An internal version number to help it know when to update

int main() {
    curl_global_init(CURL_GLOBAL_DEFAULT);

    auto github_connector = std::make_unique<CH>("https://api.github.com/repos/K00lmans/digital-RPG-sheet/releases/latest");
    github_connector->custom_setting_change(CURLOPT_USERAGENT, "updater");
    json github_data;
    if (!github_connector->make_request()) {
        cout << github_connector->get_last_result() << endl;
    } else {
        github_data = json::parse(github_connector->data);
        github_connector.reset();
    }

    if (!fs::exists(fs::status("old_updater.exe"))) { // If this exists, then an update was just done
        bool update = false;
        cout << "Checking for data folder..." << endl;
        if (!fs::exists(fs::status("data"))) {
            cout << "Data folder not found, performing full install..." << endl;
            update = true;
            fs::create_directory("data");
        } else {
            cout << "Data folder found, checking for updates..." << endl;
            if (github_data.find("name").value() != VERSION) {
                update = true;
                cout << "Update is available. Starting update..." << endl;
            }
        }
        if (update) {
            cout << "Update installed." << endl;
            return 0;
        }
    } else {
        fs::remove(fs::path("old_updater.exe")); // Removes the outdated version
    }
    cout << "Launching character creator..." << endl;
    // system("start data/char_creator.exe");

    curl_global_cleanup();
    return 0;
}