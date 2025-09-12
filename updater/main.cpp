#include "../handy_stuff.h"
#include "Curl_Handler.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <vector>

namespace fs = std::filesystem;
using nlohmann::json;
using std::cout;
using std::endl;
using CH = Curl_Handler;
using std::ofstream;

static std::vector<string> file_names = {
    "updater_linux.sh",
    "char_creator_linux"
};

int main() {
    CH github_connector("updater-linux", "https://api.github.com/repos/K00lmans/"
                        "digital-RPG-sheet/releases/latest");
    if (!github_connector.make_request()) {
        cout << github_connector.get_error().error_code << ": "
            << github_connector.get_error().buffer << endl;
        return 1;
    }
    json github_data = json::parse(github_connector.get_data());

    if (!fs::exists(fs::status("old_updater.sh"))) {
        // If this exists, then an update was just done
        bool update = false;
        cout << "Checking for data folder..." << endl;
        if (!fs::exists(fs::status("data"))) {
            cout << "Data folder not found, performing full install..." << endl;
            update = true;
            fs::create_directory("data");
            fs::create_directory("saves");
            sleep(1.0);
        }
        else {
            cout << "Data folder found, checking for updates..." << endl;
            if (github_data.find("name").value() != VERSION) {
                update = true;
                cout << "Update is available. Starting update..." << endl;
            }
            else {
                cout << "No update found, you are using the latest version, " << VERSION
                    << endl;
                sleep(1.0);
            }
        }

        if (update) {
            fs::rename("updater.sh", "old_updater.sh");
            json files = github_data["assets"];
            github_connector.reset_settings("updater-linux");
            github_connector.custom_setting_change(CURLOPT_FOLLOWLOCATION, 1l);
            for (const auto& file : files) {
                if (auto file_name = static_cast<string>(file.find("name").value());
                    contains(file_name, file_names)) {
                    github_connector.change_URL(
                        file.find("browser_download_url").value());
                    if (!github_connector.make_request()) {
                        cout << github_connector.get_error().error_code << ": "
                            << github_connector.get_error().buffer << endl;
                    }
                    ofstream zip_file(file_name, std::ios::binary);
                    zip_file.write(github_connector.get_data().c_str(),
                                   github_connector.get_data().size());
                    zip_file.close();
                    if (file_name != "updater_linux.sh") {
                        // Moves to the data folder if not part of the updater
                        fs::rename(file_name, "data/" + file_name);
                    }
                    cout << file_name << " has been downloaded..." << endl;
                }
            }
            cout << "Update installed. Restarting..." << endl;
            sleep(1.0);
            execve(fs::path("updater.sh").c_str(),
                   reinterpret_cast<char*const *>(string("updater.sh").c_str()),
                   nullptr);
            return 0;
        }
    }
    else {
        fs::remove(fs::path("old_updater.sh")); // Removes the outdated version
        cout << "Successfully updated to version " << VERSION << endl;
        sleep(1.0);
    }
    cout << "Launching character creator..." << endl;
    sleep(1.0);
    execve(fs::path("data/char_creator").c_str(),
           reinterpret_cast<char*const *>(string("char_creator").c_str()),
           nullptr);
    return 0;
}
