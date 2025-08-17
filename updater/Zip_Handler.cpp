#include "Zip_Handler.h"

Zip_Handler::Zip_Handler(const string& zip_location) {
    zipped_file = zip_open(zip_location.c_str(), 0, &error_num);
    update_error();
}

string Zip_Handler::get_error_message() const {
    string return_message = "Error ";
    return_message += error_num;
    return_message += ": ";
    return_message += error.buffer;
    return return_message;
}

void Zip_Handler::update_error() {
    zip_error_init_with_code(&error.error_code, error_num);
    error.buffer = zip_error_strerror(&error.error_code);
}

Zip_Handler::~Zip_Handler() {
    zip_close(zipped_file);
}
