/*
 *A personal object to handle libcurl because I don't wanna have to remember to manage C shenanigans I don't understand
 *and I did not understand how the existing ones worked, so here is my own crappy one.
 *
 *Due to the presence of curl_global_init(CURL_GLOBAL_DEFAULT) and curl_global_cleanup() in the constructor and
 *deconstructor of this object, it is recommended to only ever have one at a time
 */

#ifndef RPG_SHEET_CURL_HANDLER_H
#define RPG_SHEET_CURL_HANDLER_H

#include <curl/curl.h>
#include <string>

using std::string;

// I don't know how any of this works, but the internet is a wonderful thing
static size_t return_data(const char* data, const size_t data_size, const size_t amount_of_data, string data_storage) {
    data_storage.append(data, data_size * amount_of_data);
    return data_size * amount_of_data;
}

struct Error {
    CURLcode curl_result;
    string error_message;
};

class Curl_Handler {
    CURL* handle;

public:
    explicit Curl_Handler(const string& agent_name, const string &URL = "");

    ~Curl_Handler();

    bool make_request();

    void change_URL(const string &new_URL) const;

    void custom_setting_change(CURLoption setting, const string &value) const;

    void reset_settings(const string &agent_name, const string& new_URL = "") const;

    string data;
    Error last_error;
};


#endif //RPG_SHEET_CURL_HANDLER_H