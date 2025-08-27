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

        // For use when changing values
        CHANGE_TO, // Sets the value being changed
        ADD_TO, // Adds to the value being changed

        // For use as an identifier in general purpose functions
        ATTRIBUTE,
        SKILL
    };

    // Attributes and skills have several elements inside of them, this struct contains all those values
    struct Stat {
        int modifier;
        Training_Level training_level;
        unsigned int training_points;
        optional<unsigned int> value; // Skills do not have a value
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
        um<string, Stat *> attribute_selection_map = {
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
        um<string, Stat *> skill_selection_map = {
            {"teaching", &teaching}, {"doctoring", &doctoring}, {"intimidation", &intimidation},
            {"performance", &performance}, {"acrobatics", &acrobatics}, {"acrobatics", &acrobatics},
            {"supernaturalism", &supernaturalism}, {"survival", &survival}, {"history", &history},
            {"negotiation", &negotiation}, {"athletics", &athletics}, {"investigation", &investigation},
            {"stealth", &stealth}, {"sleight_of_hand", &sleight_of_hand}, {"mechanical", &mechanical},
            {"insight", &insight}
        };
    };

    struct Health {
        unsigned int current_health; // Includes temp_health
        unsigned int max_health;
        unsigned int temp_health;

        // A way to describe if there are any extra results from taking damage
        enum Damage_Result {
            NONE, // Nothing else happens
            TEMP_HEALTH_DEPLETED, // All of temp health was used
            ATTRITION_LIMIT, // Enough Damage was dealt to the base health to gain a level of attrition
            HEALTH_DEPLETED, // The damage removed all their health
            TEMP_AND_ATTRITION, // Both ATTRITION_LIMIT and TEMP_HEALTH_DEPLETED
            TEMP_AND_HEALTH, // Both HEALTH_DEPLETED and TEMP_HEALTH_DEPLETED
            HEALTH_AND_ATTRITION, // Both HEALTH_DEPLETED and ATTRITION_LIMIT happen
            BAD_TIME // All non-combined effects
        };
    };

    Character(); // Assumes default values

    explicit Character(std::ifstream char_file);

    void save_character(const string &path) const;

    explicit Character(const string &file_path);

    // Skills are based on attributes and therefore this does not need to be a general function
    void change_attributes(const string &attribute_to_change, int modification_value, Flag flag = CHANGE_TO) const;

    void train(const string &thing_to_train, Flag type, int new_level, Flag setting = CHANGE_TO);

    // Returns true if damage dealt adds a level of attrition
    Health::Damage_Result deal_damage(int damage_dealt);

    std::string name;
    unsigned int extra_attribute_points{};
    double speed{};
    Armor_Class armor_class;
    string lineage;
    string background;

private:
    static void attribute_update(Stat *attribute);

    // Handles the effect of training on a modifier
    static int handle_training_for_skills(int modifier, Training_Level training);

    void update_single_stat(Flag type, const string &thing_to_update);

    std::shared_ptr<Attributes> attributes = std::make_shared<Attributes>();
    std::shared_ptr<Skills> skills = std::make_shared<Skills>();
    Health health_info{};
};

ostream &operator<<(ostream &stream, const Character::Stat &stat);

istream &operator>>(istream &stream, Character::Stat &stat);

ostream &operator<<(ostream &stream, const Character::Attributes &attributes);

istream &operator>>(istream &stream, Character::Attributes &attributes);

ostream &operator<<(ostream &stream, const Character::Skills &skills);

istream &operator>>(istream &stream, Character::Skills &skills);

ostream &operator<<(ostream &stream, const Character::Health &health);

istream &operator>>(istream &stream, Character::Health &health);

#endif //RPG_SHEET_CHARACTER_H
