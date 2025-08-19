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

void Zip_Handler::throw_error(const double error_num, const string& description) {
    string message = "Error ";
    message += std::to_string(error_num);
    message += ": ";
    message += description;
    throw std::runtime_error(message);
}

zip_int64_t Zip_Handler::get_number_of_files() const {
    return number_of_files;
}

Zip_Handler::File_Data Zip_Handler::operator[](const int index) const {
    File_Data file_data;
    if (index >= number_of_files) {
        // This is error 2, however the decimal indicates the index for easier debugging
        throw_error(2.0 + index/(10 * count_digits(number_of_files - 1)), "File index out of range");
    }
    zip_stat_t *zip_file_info;
    if (zip_stat_index(zipped_file, index, NO_FLAGS, zip_file_info) == -1) {
        throw_error(3.0 + index/(10 * count_digits(number_of_files - 1)), "Can't get file info");
    }
    zip_file_t *zip_file = zip_fopen_index(zipped_file, index, NO_FLAGS);
    if (zip_file == nullptr) {
        throw_error(4.0 + index/(10 * count_digits(number_of_files - 1)), "Can't open file");
    }
    file_data.file_size = zip_fread(zip_file, &file_data.file_binary, zip_file_info->size);
    if (file_data.file_size != zip_file_info->size) {
        throw_error(5.0 + index/(10 * count_digits(number_of_files - 1)), "Full file not read");
    }
    zip_fclose(zip_file);
    return file_data;
}
