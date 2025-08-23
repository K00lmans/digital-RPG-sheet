#ifndef RPG_SHEET_ZIP_HANDLER_H
#define RPG_SHEET_ZIP_HANDLER_H

#include <zip.h>
#include <string>
#include <stdexcept>
#include <vector>
#include <optional>
#include "../handy_stuff.h"

#define NO_FLAGS 0 // Makes it more clear when passing no flag into libzip functions

using std::string;
using std::vector;

// A wrapper class for libzip. Currently, does not have any way to write data to the file because I don't need
// it, and I am lazy, but may be added at a further date for completeness and usability
class Zip_Handler {
public:
    struct File_Data {
        zip_uint64_t file_size;
        string file_binary;
        zip_stat_t file_info;
    };

    struct  Return_File_Data { // A modified version of File_Data specifically for get_copy_of_file_data()
        unsigned long long file_size;
        string file_binary;
        string file_name;
    };

private:
    void read_files(); // Puts all the files in the files vector for easier referencing. Should only be called once

    zip_t *zipped_file;
    zip_int64_t number_of_files;
    vector<File_Data> files;
    bool has_subfolders = false;

public:
    explicit Zip_Handler(const string& zip_location);

    ~Zip_Handler();

    // The way this library does errors suck, so I'm just doing my own way
    static void throw_error(double error_num, const string& description);

    [[nodiscard]] zip_int64_t get_number_of_files() const;

    File_Data operator[](int file);

    File_Data get_file(int file);

    // Does not return anything if file not found
    [[nodiscard]] std::optional<File_Data> get_file(const string &file_name) const;

    [[nodiscard]] vector<Return_File_Data> get_copy_of_file_data() const;

    bool check_for_subfolders() const;
};

#endif //RPG_SHEET_ZIP_HANDLER_H