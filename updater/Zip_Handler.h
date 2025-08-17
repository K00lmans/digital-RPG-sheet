#ifndef RPG_SHEET_ZIP_HANDLER_H
#define RPG_SHEET_ZIP_HANDLER_H

#include <zip.h>
#include <string>
#include "../handy_stuff.h"

using std::string;

// A wrapper class for libzip
class Zip_Handler {
    void update_error();

    zip_t *zipped_file;
    int error_num = 0;
    Error<zip_error_t, string> error;

public:
    explicit Zip_Handler(const string& zip_location);

    string get_error_message() const;

    ~Zip_Handler();
};

#endif //RPG_SHEET_ZIP_HANDLER_H