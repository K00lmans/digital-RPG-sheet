#include "Curl_Handler.h"

#include <memory>

Curl_Handler::~Curl_Handler() {
    if (handle) {
        curl_easy_cleanup(handle);
    }
    curl_global_cleanup();
}

Curl_Handler::Curl_Handler(const string &agent_name, const string &URL) {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    handle = curl_easy_init();
    reset_settings(agent_name, URL);
}

void Curl_Handler::change_URL(const string &new_URL) const {
    curl_easy_setopt(handle, CURLOPT_URL, new_URL.c_str());
}

bool Curl_Handler::make_request(const bool keep_old_data) {
    if (!data.empty() && !keep_old_data) { // Prevents the buffer from holding old data
        data.clear();
    }
    last_error->error_code = curl_easy_perform(handle);
    return !last_error->error_code; // 0 is the value of a success
}

void Curl_Handler::custom_setting_change(const CURLoption setting, const string &value) const {
    curl_easy_setopt(handle, setting, value.c_str());
}

void Curl_Handler::custom_setting_change(const CURLoption setting, const long value) const {
    curl_easy_setopt(handle, setting, value);
}

void Curl_Handler::reset_settings(const string &agent_name, const string& new_URL) {
    curl_easy_reset(handle);
    data.clear();
    last_error = std::make_unique<Error<CURLcode, char[CURL_ERROR_SIZE]>>();
    change_URL(new_URL);
    curl_easy_setopt(handle, CURLOPT_USERAGENT, agent_name.c_str());
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, return_data);
    curl_easy_setopt(handle, CURLOPT_ERRORBUFFER, last_error->buffer);
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, &data);
}

Error<CURLcode, char[CURL_ERROR_SIZE]> Curl_Handler::get_error() const {
    return *last_error;
}

string Curl_Handler::get_data() {
    return data;
}
