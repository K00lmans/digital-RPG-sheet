/*
 *A personal object to handle libcurl because I don't wanna have to remeber to manage C shenanigins I don't understand
 *and I did not understand how the exsisting ones worked, so here is my own crappy one.
 *
 *This object expects you to call curl_global_init and curl_global_cleanup on your own in your main file. This object
 *must be deleted before calling of curl_global_cleanup, and as such must be a pointer
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

class Curl_Handler {
    CURL* curl;
    CURLcode curl_result = CURLE_OK;
    curl_slist* headers = nullptr;

public:
    explicit Curl_Handler(const string &URL, bool format_as_json = false);

    ~Curl_Handler();

    bool make_request();

    void change_URL(const string &new_URL) const;

    CURLcode get_last_result() const { return curl_result; }

    void custom_setting_change(CURLoption setting, const string &value) const;

    string data;
};


#endif //RPG_SHEET_CURL_HANDLER_H