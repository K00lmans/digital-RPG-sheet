/*
 *This object stores all the data relating to a character sheet
 */

#ifndef RPG_SHEET_CHARACTER_H
#define RPG_SHEET_CHARACTER_H

#include <optional>
#include <memory>
#include <string>

using std::optional;
using std::string;

class Character {
public:
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

    // Attributes and skills have several elements inside of them, this struct contains all those values
    struct Stat {
        int modifier;
        Training_Level training_level;
        int training_points;
        optional<int> value; // Skills do not have a value
    };

    struct Attributes {
        Stat intelligence;
        Stat wisdom;
        Stat perception;
        Stat strength;
        Stat presence;
        Stat fortitude;
        Stat agility;
        Stat dexterity;
    };

    struct Skills {
        Stat teaching;
        Stat doctoring;
        Stat intimidation;
        Stat performance;
        Stat acrobatics;
        Stat supernaturalism;
        Stat survival;
        Stat history;
        Stat negotiation;
        Stat athletics;
        Stat investigation;
        Stat stealth;
        Stat sleight_of_hand;
        Stat mechanical;
        Stat insight;
    };

    struct Health {
        int current_health;
        int max_health;
        int temp_health;
    };

    Character(); // Assumes default values

private:
    std::string name;
    std::shared_ptr<Attributes> attributes = std::make_shared<Attributes>();
    std::shared_ptr<Skills> skills = std::make_shared<Skills>();
    int extra_attribute_points;
    Health health_info;
    double speed;
    Armor_Class armor_class;
    string lineage;
    string background;
};

#endif //RPG_SHEET_CHARACTER_H