/*
 *A collection of handy code snippets
 */

#ifndef RPG_SHEET_HANDY_FUNCTIONS_H
#define RPG_SHEET_HANDY_FUNCTIONS_H

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

#endif //RPG_SHEET_HANDY_FUNCTIONS_H