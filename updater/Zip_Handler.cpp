#include "Zip_Handler.h"

Zip_Handler::Zip_Handler(const string& zip_location) {
    int *temp = nullptr;
    zipped_file = zip_open(zip_location.c_str(), NO_FLAGS, temp);
    if (zipped_file == nullptr) {
        throw_error(1, "Can't open zip file");
    }
    number_of_files = zip_get_num_entries(zipped_file, NO_FLAGS);
}

Zip_Handler::~Zip_Handler() {
    zip_close(zipped_file);
}

void Zip_Handler::throw_error(const int error_num, const string& description) {
    string message = "Error ";
    message += std::to_string(error_num);
    message += ": ";
    message += description;
    throw std::runtime_error(message);
}
