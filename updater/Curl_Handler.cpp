#include "Curl_Handler.h"

Curl_Handler::~Curl_Handler() {
    curl_easy_cleanup(curl);
}

Curl_Handler::Curl_Handler(const string &URL, const bool format_as_json) {
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, return_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
    if (format_as_json) {
        headers = curl_slist_append(headers, "Accept: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    }
}

void Curl_Handler::change_URL(const string &new_URL) const {
    curl_easy_setopt(curl, CURLOPT_URL, new_URL.c_str());
}

bool Curl_Handler::make_request() {
    curl_result = curl_easy_perform(curl);
    return curl_result == CURLE_OK;
}

void Curl_Handler::custom_setting_change(const CURLoption setting, const string &value) const {
    curl_easy_setopt(curl, setting, value.c_str());
}
