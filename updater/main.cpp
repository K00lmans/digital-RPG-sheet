#include <pybind11/embed.h>
#include <string>
#include <print>
#include <filesystem>

namespace py = pybind11;
namespace fs = std::filesystem;
using std::print;

std::string VERSION = "test"; // An internal version number to help it know when to update

int main() {
    if (!fs::exists(fs::status("old_updater.exe"))) { // If this exists, then an update was just done
        bool update = false;
        print("Checking for data folder...\n");
        if (!fs::exists(fs::status("data"))) {
            print("Data folder not found, performing full install...\n");
            update = true;
            fs::create_directory("data");
        } else {
            print("Data folder found, checking for updates...\n");
            // python stuff
        }
        if (update) {
            // update code
            print("Update installed. ");
        }
    } else {
        fs::remove(fs::path("old_updater.exe")); // Removes the outdated version
    }
    print("Launching character creator...\n");
    return 0;
}