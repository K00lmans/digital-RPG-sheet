/*
 *A collection of handy code snippets
 */

#ifndef RPG_SHEET_HANDY_FUNCTIONS_H
#define RPG_SHEET_HANDY_FUNCTIONS_H

#include <string>
#include <chrono>

enum Armor_Class {
    NONE,
    LIGHT,
    MEDIUM,
    HEAVY
};

enum Training_Level {
    UNTRAINED,
    TRAINED,
    EXPERT
};

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
template<typename NUMBER>
static void sleep(const NUMBER sleep_time) {
    static unsigned short f1 = 0, f2 = 1; // I like to do Fibonacci to pass the time
    const auto start_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<NUMBER> elapsed_time{};
    do {
        f2 += f1;
        f1 = f2 - f1;
        elapsed_time = std::chrono::high_resolution_clock::now() - start_time;
    } while (elapsed_time.count() <= sleep_time);
}

// Separates a string into a bunch of strings by a seperator. Result does not include the seperator
static std::vector<std::string> tokenize_string(const std::string &seperator, const std::string &input) {
    std::vector<std::string> tokens;
    std::string current_working_string = input;
    while (true) {
        const auto pos_of_next_seperator = current_working_string.find(seperator);
        if (pos_of_next_seperator == std::string::npos) {
            tokens.push_back(current_working_string);
            break;
        }
        tokens.push_back(current_working_string.substr(0, pos_of_next_seperator));
        current_working_string = current_working_string.substr(pos_of_next_seperator + seperator.length());
    }
    return tokens;
}

// Rounding in my system rounds down at .5 so this handles it
template<typename NUMBER, typename RESULT_NUMBER>
RESULT_NUMBER system_round(NUMBER num, int trailing_digits = 0) {
    if (static_cast<int>(num * pow(10, trailing_digits + 1)) % 10 == 5) {
        return floor(num * pow(10, trailing_digits)) / trailing_digits;
    }
    return round(num * pow(10, trailing_digits)) / trailing_digits;
}

// From the interwebs, returns 1 for positive, -1 for negative, and 0 for zero
template <typename NUM> int get_sign(NUM val) {
    return (NUM(0) < val) - (val < NUM(0));
}

#endif //RPG_SHEET_HANDY_FUNCTIONS_H