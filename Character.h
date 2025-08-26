/*
 *This object stores all the data relating to a character sheet
 */

#ifndef RPG_SHEET_CHARACTER_H
#define RPG_SHEET_CHARACTER_H

#include <optional>
#include <memory>
#include <string>
#include <fstream>
#include <unordered_map>
#include "handy_stuff.h"

using std::optional;
using std::string;
using std::endl;
using std::ostream;
using std::istream;

#define um std::unordered_map

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

    enum Flag {
        // A set of flags to be used with this class
        // For use in change attributes
        CHANGE_TO, // Sets the value being changed
        ADD_TO // Adds to the value being changed
    };

    // Attributes and skills have several elements inside of them, this struct contains all those values
    struct Stat {
        int modifier;
        Training_Level training_level;
        int training_points;
        optional<int> value; // Skills do not have a value

         void value_to_modifier() {
             if (value.has_value()) {
                 modifier = (value.value() - 10) / 2 + 5 * training_level;
             }
        }
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
        um<string, Stat*> attribute_selection_map = {
            {"intelligence", &intelligence}, {"wisdom", &wisdom}, {"perception", &perception}, {"strength", &strength},
            {"presence", &presence}, {"fortitude", &fortitude}, {"agility", &agility}, {"dexterity", &dexterity}
        };
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

    explicit Character(std::ifstream char_file);

    void save_character(const string &path) const;

    explicit Character(const string &file_path);

    void change_attributes(const string& attribute_to_change, int modification_value, Flag flag = CHANGE_TO) const;

    // Flips the training level, so becomes untrained if trained and trained if untrained
    void train_attribute(const string &attribute_to_train) const;

    std::string name;
    int extra_attribute_points{};
    Health health_info{};
    double speed{};
    Armor_Class armor_class;
    string lineage;
    string background;

private:
    std::shared_ptr<Attributes> attributes = std::make_shared<Attributes>();
    std::shared_ptr<Skills> skills = std::make_shared<Skills>();
};

#endif //RPG_SHEET_CHARACTER_H

ostream &operator<<(ostream &stream, const Character::Stat &stat);

istream &operator>>(istream &stream, Character::Stat &stat);

ostream &operator<<(ostream &stream, const Character::Attributes &attributes);

istream &operator>>(istream &stream, Character::Attributes &attributes);

ostream &operator<<(ostream &stream, const Character::Skills &skills);

istream &operator>>(istream &stream, Character::Skills &skills);

ostream &operator<<(ostream &stream, const Character::Health &health);

istream &operator>>(istream &stream, Character::Health &health);
