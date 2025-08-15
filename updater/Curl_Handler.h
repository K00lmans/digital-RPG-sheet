#ifndef RPG_SHEET_CURL_HANDLER_H
#define RPG_SHEET_CURL_HANDLER_H

#include <curl/curl.h>
#include <string>

using std::string;

// I don't know how any of this works, but the internet is a wonderful thing
static size_t return_data(const char *data, const size_t data_size, const size_t amount_of_data, string &data_storage) {
    data_storage.append(data, data_size * amount_of_data);
    return data_size * amount_of_data;
}

// A one-stop variable to store all the info if something goes wrong.
struct Error {
    CURLcode curl_result = CURLE_OK;
    char error_message[CURL_ERROR_SIZE] = ""; // If it's a string, it causes so many issues
};

/*
A personal object to handle libcurl because I don't wanna have to remember to manage C shenanigans I don't
understand and I did not understand how the existing ones worked, so here is my own crappy one.

You must call the startup and shutdown functions at program start and end. Defaults to writing to string
 */
class Curl_Handler {
    CURL *handle = nullptr;
    Error last_error;

public:
    explicit Curl_Handler(const string &agent_name, const string &URL = "");

    ~Curl_Handler();

    bool make_request();

    void change_URL(const string &new_URL) const;

    void custom_setting_change(CURLoption setting, const string &value) const;

    void custom_setting_change(CURLoption setting, long value) const;

    void reset_settings(const string &agent_name, const string &new_URL = "") const;

    [[nodiscard]] Error get_error() const;

    string data;
};

#endif //RPG_SHEET_CURL_HANDLER_H
