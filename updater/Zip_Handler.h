#ifndef RPG_SHEET_ZIP_HANDLER_H
#define RPG_SHEET_ZIP_HANDLER_H

#include <zip.h>
#include <string>
#include <stdexcept>
#include <vector>
#include "../handy_stuff.h"

#define NO_FLAGS 0 // Makes it more clear when passing no flag into libzip functions

using std::string;
using std::vector;

// A wrapper class for libzip
class Zip_Handler {
public:
    struct File_Data {
        zip_uint64_t file_size;
        string file_binary;
        zip_stat_t file_info;

    };

private:
    void read_files(); // Puts all the files in the files vector for easier referencing. Should only be called once

    zip_t *zipped_file;
    zip_int64_t number_of_files;
    vector<File_Data> files;

public:
    explicit Zip_Handler(const string& zip_location);

    ~Zip_Handler();

    // The way this library does errors suck, so I'm just doing my own way
    static void throw_error(double error_num, const string& description);

    [[nodiscard]] zip_int64_t get_number_of_files() const;
};

#endif //RPG_SHEET_ZIP_HANDLER_H