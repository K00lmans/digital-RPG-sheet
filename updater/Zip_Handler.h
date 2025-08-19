#ifndef RPG_SHEET_ZIP_HANDLER_H
#define RPG_SHEET_ZIP_HANDLER_H

#include <zip.h>
#include <string>
#include <stdexcept>

#define NO_FLAGS 0 // Makes it more clear when passing no flag into libzip functions

using std::string;

// A wrapper class for libzip. Does not contain anything for creating or editing a zip file, because all I
// need it to do is open one
class Zip_Handler {
    zip_t *zipped_file;
    zip_int64_t number_of_files;

public:
    explicit Zip_Handler(const string& zip_location);

    ~Zip_Handler();

    // The way this library does errors suck, so I'm just doing my own way
    static void throw_error(int error_num, const string& description);
};

#endif //RPG_SHEET_ZIP_HANDLER_H