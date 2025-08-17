#include <filesystem>
#include <print>
#include <nlohmann/json.hpp>
#include <vector>
#include "Curl_Handler.h"
#include "../handy_stuff.h"

namespace fs = std::filesystem;
using std::println;
using nlohmann::json;
using CH = Curl_Handler;

static std::vector<string> file_names = {"updater", "char_creator"};

int main() {
    CH github_connector("updater", "https://api.github.com/repos/K00lmans/digital-RPG-sheet/releases/latest");
    if (!github_connector.make_request()) {
        println("{}: {}", static_cast<int>(github_connector.get_error().error_code),
                github_connector.get_error().buffer);
        return 1;
    }
    json github_data = json::parse(github_connector.data);

    if (!fs::exists(fs::status("old_updater.exe"))) {
        // If this exists, then an update was just done
        bool update = false;
        println("Checking for data folder...");
        if (!fs::exists(fs::status("data"))) {
            println("Data folder not found, performing full install...");
            update = true;
            fs::create_directory("data");
            fs::create_directory("saves");
        } else {
            println("Data folder found, checking for updates...");
            if (github_data.find("name").value() != VERSION) {
                update = true;
                println("Update is available. Starting update...");
            } else {
                println("No update found, you are using the latest version, {}", VERSION);
            }
        }
        if (update) {
            fs::rename("updater.exe", "old_updater.exe");
            json files = github_data["assets"];
            github_connector.reset_settings("updater");
            for (auto file : files) {
                if (auto file_name = static_cast<string>(file.find("name").value());
                    contains(file_name.substr(0, file_name.size() - 4), file_names)) {
                    github_connector.change_URL(file.find("browser_download_url").value());
                    github_connector.make_request();
                }
            }
            println("Update installed. Restarting...");
            // system("start updater.exe");
            return 0;
        }
    } else {
        fs::remove(fs::path("old_updater.exe")); // Removes the outdated version
        println("Successfully restarted after updating to {}", VERSION);
    }
    println("Launching character creator...");
    system("start data/char_creator.exe");
    return 0;
}
