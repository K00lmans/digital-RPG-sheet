#include <filesystem>
#include <iostream>
#include <nlohmann/json.hpp>
#include <vector>
#include <fstream>
#include "Curl_Handler.h"
#include "Zip_Handler.h"
#include "../handy_stuff.h"

namespace fs = std::filesystem;
using std::cout;
using std::endl;
using nlohmann::json;
using CH = Curl_Handler;
using std::ofstream;

static std::vector<string> file_names = {"updater", "char_creator"};

string get_unzip_location(const string& zipped_file);

int main()
{
    CH github_connector("updater", "https://api.github.com/repos/K00lmans/digital-RPG-sheet/releases/latest");
    if (!github_connector.make_request())
    {
        cout << github_connector.get_error().error_code << ": " << github_connector.get_error().buffer << endl;
        return 1;
    }
    json github_data = json::parse(github_connector.get_data());

    if (!fs::exists(fs::status("old_updater.exe")))
    {
        // If this exists, then an update was just done
        bool update = false;
        cout << "Checking for data folder..." << endl;
        if (!fs::exists(fs::status("data")))
        {
            cout << "Data folder not found, performing full install..." << endl;
            update = true;
            fs::create_directory("data");
            fs::create_directory("saves");
            sleep(1.0);
        }
        else
        {
            cout << "Data folder found, checking for updates..." << endl;
            if (github_data.find("name").value() != VERSION)
            {
                update = true;
                cout << "Update is available. Starting update..." << endl;
            }
            else
            {
                cout << "No update found, you are using the latest version, " << VERSION << endl;
                sleep(1.0);
            }
        }

        if (update)
        {
            fs::rename("updater.exe", "old_updater.exe");
            json files = github_data["assets"];
            github_connector.reset_settings("updater");
            github_connector.custom_setting_change(CURLOPT_FOLLOWLOCATION, 1l);
            for (const auto& file : files)
            {
                if (auto file_name = static_cast<string>(file.find("name").value());
                    contains(file_name.substr(0, file_name.size() - 4), file_names))
                {
                    github_connector.change_URL(file.find("browser_download_url").value());
                    if (!github_connector.make_request())
                    {
                        cout << github_connector.get_error().error_code << ": " << github_connector.get_error().buffer
                            << endl;
                    }
                    ofstream zip_file(file_name, std::ios::binary);
                    zip_file.write(github_connector.get_data().c_str(), github_connector.get_data().size());
                    zip_file.close();
                    cout << file_name << " has been downloaded..." << endl;

                    const auto zipped_file = new Zip_Handler(file_name);
                    // This way I don't have to deal with the object sitting around
                    auto file_data = zipped_file->get_copy_of_file_data();
                    delete zipped_file;
                    auto unzip_location = get_unzip_location(file_name);
                    for (const auto& file_in_zip : file_data)
                    {
                        ofstream file_to_write(unzip_location + file_in_zip.file_name, std::ios::binary);
                        file_to_write.write(file_in_zip.file_binary.c_str(), file_in_zip.file_binary.size());
                        file_to_write.close();
                    }
                    fs::remove(fs::path(file_name));
                    cout << file_name << " has been unzipped..." << endl;
                }
            }
            cout << "Update installed. Restarting..." << endl;
            sleep(1.0);
            execve(fs::path("updater.exe").c_str(), reinterpret_cast<char* const*>(string("updater.exe").c_str()),
                   nullptr);
            return 0;
        }
    }
    else
    {
        fs::remove(fs::path("old_updater.exe")); // Removes the outdated version
        cout << "Successfully updated to version " << VERSION << endl;
        sleep(1.0);
    }
    cout << "Launching character creator..." << endl;
    sleep(1.0);
    execve(fs::path("data/char_creator.exe").c_str(),
           reinterpret_cast<char* const*>(string("char_creator.exe").c_str()), nullptr);
    return 0;
}

string get_unzip_location(const string& zipped_file)
{
    if (zipped_file == "updater.zip")
    {
        return ""; // Updater files are installed in the main directory
    }
    return "data/"; // Makes sure everything else is installed in the data folder
}
