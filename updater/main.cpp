#include <filesystem>
#include <print>
#include <nlohmann/json.hpp>
#include <vector>
#include <fstream>
#include <windows.h>
#include "Curl_Handler.h"
#include "Zip_Handler.h"
#include "../handy_stuff.h"

namespace fs = std::filesystem;
using std::println;
using nlohmann::json;
using CH = Curl_Handler;
using std::ofstream;

static std::vector<string> file_names = {"updater", "char_creator"};

string get_unzip_location(const string &zipped_file);

bool start_another_program(const string &file_location);

int main() {
    CH github_connector("updater", "https://api.github.com/repos/K00lmans/digital-RPG-sheet/releases/latest");
    if (!github_connector.make_request()) {
        println("{}: {}", static_cast<int>(github_connector.get_error().error_code),
                github_connector.get_error().buffer);
        return 1;
    }
    json github_data = json::parse(github_connector.get_data());

    if (!fs::exists(fs::status("old_updater.exe"))) {
        // If this exists, then an update was just done
        bool update = false;
        println("Checking for data folder...");
        if (!fs::exists(fs::status("data"))) {
            println("Data folder not found, performing full install...");
            update = true;
            fs::create_directory("data");
            fs::create_directory("saves");
            sleep(1.0);
        } else {
            println("Data folder found, checking for updates...");
            if (github_data.find("name").value() != VERSION) {
                update = true;
                println("Update is available. Starting update...");
            } else {
                println("No update found, you are using the latest version, {}", VERSION);
                sleep(1.0);
            }
        }

        if (update) {
            fs::rename("updater.exe", "old_updater.exe");
            json files = github_data["assets"];
            github_connector.reset_settings("updater");
            github_connector.custom_setting_change(CURLOPT_FOLLOWLOCATION, 1l);
            for (const auto &file: files) {
                if (auto file_name = static_cast<string>(file.find("name").value());
                    contains(file_name.substr(0, file_name.size() - 4), file_names)) {
                    github_connector.change_URL(file.find("browser_download_url").value());
                    if (!github_connector.make_request()) {
                        println("{}: {}", static_cast<int>(github_connector.get_error().error_code),
                                github_connector.get_error().buffer);
                    }
                    ofstream zip_file(file_name, std::ios::binary);
                    zip_file.write(github_connector.get_data().c_str(), github_connector.get_data().size());
                    zip_file.close();
                    println("{} has been downloaded...", file_name);

                    const auto zipped_file = new Zip_Handler(file_name);
                    // This way I don't have to deal with the object sitting around
                    auto file_data = zipped_file->get_copy_of_file_data();
                    delete zipped_file;
                    auto unzip_location = get_unzip_location(file_name);
                    for (const auto &file_in_zip : file_data) {
                        ofstream file_to_write(unzip_location + file_in_zip.file_name, std::ios::binary);
                        file_to_write.write(file_in_zip.file_binary.c_str(), file_in_zip.file_binary.size());
                        file_to_write.close();
                    }
                    fs::remove(fs::path(file_name));
                    println("{} has been unzipped...", file_name);
                }
            }
            println("Update installed. Restarting...");
            sleep(1.0);
            start_another_program("updater.exe");
            return 0;
        }
    } else {
        fs::remove(fs::path("old_updater.exe")); // Removes the outdated version
        println("Successfully restarted after updating to {}", VERSION);
        sleep(1.0);
    }
    println("Launching character creator...");
    sleep(1.0);
    start_another_program("data/char_creator.exe");
    return 0;
}

string get_unzip_location(const string &zipped_file) {
    if (zipped_file == "updater.zip") {
        return ""; // Updater files are installed in the main directory
    }
    return "data/"; // Makes sure everything else is installed in the data folder
}

// I don't know how this works but ah well
bool start_another_program(const string &file_location) {
    STARTUPINFO startup_info;
    PROCESS_INFORMATION process_info;
    ZeroMemory(&startup_info, sizeof(STARTUPINFO));
    startup_info.cb = sizeof(STARTUPINFO);
    ZeroMemory(&process_info, sizeof(PROCESS_INFORMATION));

    const bool result = CreateProcess(file_location.c_str(), nullptr, nullptr, nullptr, false, 0, nullptr, nullptr,
                                      &startup_info, &process_info);
    return result;
}
