/*
 *A collection of handy code snippets
 */

#ifndef RPG_SHEET_HANDY_FUNCTIONS_H
#define RPG_SHEET_HANDY_FUNCTIONS_H

#include <string>

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
    // The second bit removes the decimal from the count in case of a float
    return str_num.length() - contains('.', str_num);
}

#endif //RPG_SHEET_HANDY_FUNCTIONS_H