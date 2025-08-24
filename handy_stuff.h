/*
 *A collection of handy code snippets
 */

#ifndef RPG_SHEET_HANDY_FUNCTIONS_H
#define RPG_SHEET_HANDY_FUNCTIONS_H

#include <string>
#include <chrono>

template<class ITEM, class SEARCHABLE>
static bool contains(ITEM item, SEARCHABLE searchable) {
    for (auto searchable_item : searchable) {
        if (item == searchable_item) {
            return true;
        }
    }
    return false;
}

template<class ERROR_CODE, class BUFFER>
struct Error {
    ERROR_CODE error_code;
    BUFFER buffer;
};

template<typename NUMBER>
static int count_digits(NUMBER num) {
    std::abs(num); // Prevents the negative sign
    const std::string str_num = std::to_string(num);
    // The second half removes the decimal from the count in case of a float
    return static_cast<int>(str_num.length()) - contains('.', str_num);
}

static int replace_substring(std::string &string, const std::string &substring, const std::string &new_string) {
    int substrings_replaced = 0;
    size_t position = 0;
    const size_t substring_length = new_string.length();
    while (true) {
        position = string.find(substring, position);
        if (position == std::string::npos) {
            return substrings_replaced;
        }
        string.replace(position, substring_length, new_string);
        substrings_replaced++;
        position += substring_length;
    }
}

// I find most C++ sleep functions kinda sucky, so I like to make my own instead
static void sleep(const long double sleep_time) {
    static unsigned short f1 = 0, f2 = 1; // I like to do Fibonacci to pass the time
    const auto start_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<long double> elapsed_time;
    do {
        f2 += f1;
        f1 = f2 - f1;
        elapsed_time = std::chrono::high_resolution_clock::now() - start_time;
    } while (elapsed_time.count() <= sleep_time);
}

#endif //RPG_SHEET_HANDY_FUNCTIONS_H