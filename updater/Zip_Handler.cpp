#include "Zip_Handler.h"

Zip_Handler::Zip_Handler(const string &zip_location) {
    int *temp = nullptr;
    zipped_file = zip_open(zip_location.c_str(), NO_FLAGS, temp);
    if (zipped_file == nullptr) {
        throw_error(1, "Can't open zip file");
    }
    number_of_files = zip_get_num_entries(zipped_file, NO_FLAGS);
    read_files();
}

Zip_Handler::~Zip_Handler() {
    zip_close(zipped_file);
}

void Zip_Handler::throw_error(const double error_num, const string &description) {
    string message = "Error ";
    message += std::to_string(error_num);
    message += ": ";
    message += description;
    throw std::runtime_error(message);
}

/*
 *Errors:
 *1: zip_open fails and file can not be opened
 *2: Uses an index greater than the number of files
 *3: zip_stat fails and file data can not be retrieved
 *4: zip_fopen fails and file can not be opened
 *5: Data read from file via zip_fread is not equal to total size of file indicating only partial read
 *
 *All error numbers a doubles, with the decimal giving info on the file index that caused the error
 */

zip_int64_t Zip_Handler::get_number_of_files() const {
    return number_of_files;
}

void Zip_Handler::read_files() {
    // Would I like this to be an iterator loop? Yes. But I don't know that much about how to interface C and C++, or
    // iterators for that matter
    for (int file = 0; file < number_of_files; file++) {
        File_Data file_data;
        // Get file info
        if (zip_stat_index(zipped_file, file, NO_FLAGS, &file_data.file_info) == -1) {
            throw_error(3 + static_cast<double>(file) / (10 * count_digits(number_of_files - 1)),
                        "Can't get file info");
        }
        // The last character being a slash indicates a directory, and therefore we skip reading it since it has no data
        if (file_data.file_info.name[strlen(file_data.file_info.name) - 1] == '/') {
            has_subfolders = true;
            continue; // First time ever using this, so that's neat
        }
        file_data.file_size = file_data.file_info.size;
        // Load file
        zip_file_t *zipped_up_file = zip_fopen_index(zipped_file, file, NO_FLAGS);
        if (zipped_file == nullptr) {
            throw_error(4 + static_cast<double>(file) / (10 * count_digits(number_of_files - 1)), "Can't open file");
        }
        // Get file binary
        vector<char> buffer(file_data.file_size);
        if (file_data.file_size != zip_fread(zipped_up_file, buffer.data(), file_data.file_size)) {
            throw_error(5 + static_cast<double>(file) / (10 * count_digits(number_of_files - 1)), "Full file not read");
        }
        file_data.file_binary = string(buffer.data(), buffer.size());
        zip_fclose(zipped_up_file);
        files.emplace_back(file_data);
    }
}

Zip_Handler::File_Data Zip_Handler::operator[](const int file) {
    if (file >= number_of_files) {
        throw_error(2, "Index greater then file count");
    }
    return files[file];
}

Zip_Handler::File_Data Zip_Handler::get_file(const int file) {
    if (file >= number_of_files) {
        throw_error(2, "Index greater then file count");
    }
    return files[file];
}

std::optional<Zip_Handler::File_Data> Zip_Handler::get_file(const string &file_name) const {
    for (const auto &file : files) {
        if (file.file_info.name == file_name) {
            return file;
        }
    }
    return std::nullopt;
}

// Makes a deep copy of the files data to allow deletion of this object
vector<Zip_Handler::Return_File_Data> Zip_Handler::get_copy_of_file_data() const {
    vector<Return_File_Data> copy_of_files;
    for (const auto &file : files) {
        Return_File_Data file_data;
        file_data.file_size = file.file_info.size;
        file_data.file_binary = file.file_binary;
        file_data.file_name = string(file.file_info.name);
        copy_of_files.emplace_back(file_data);
    }
    return copy_of_files;
}

bool Zip_Handler::check_for_subfolders() const {
    return has_subfolders;
}
