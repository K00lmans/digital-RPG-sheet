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
#include <vector>
#include "handy_stuff.h"

using std::optional;
using std::string;
using std::endl;
using std::ostream;
using std::istream;
using std::vector;

#define um std::unordered_map

class Character {
public:
    enum Flag {
        // A set of flags to be used with this class

        // For use when changing values
        CHANGE_TO, // Sets the value being changed
        ADD_TO, // Adds to the value being changed

        // For use as an identifier in general purpose functions
        ATTRIBUTE,
        SKILL,

        // For use with health
        NORMAL, // Non-temp heath
        TEMP // Temp health
    };

    enum Attributes_And_Skills {
        INTELLIGENCE,
        WISDOM,
        PERCEPTION,
        STRENGTH,
        PRESENCE,
        FORTITUDE,
        AGILITY,
        DEXTERITY,
        END_OF_ATTRIBUTES, // Along with END_OF_SKILLS acts as a divider
        TEACHING,
        DOCTORING,
        INTIMIDATION,
        PERFORMANCE,
        ACROBATICS,
        SUPERNATURALISM,
        SURVIVAL,
        HISTORY,
        NEGOTIATION,
        ATHLETICS,
        INVESTIGATION,
        STEALTH,
        SLEIGHT_OF_HAND,
        MECHANICAL,
        INSIGHT,
        END_OF_SKILLS
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
        um<Attributes_And_Skills, Stat *> attribute_selection_map = {
            {INTELLIGENCE, &intelligence}, {WISDOM, &wisdom}, {PERCEPTION, &perception}, {STRENGTH, &strength},
            {PRESENCE, &presence}, {FORTITUDE, &fortitude}, {AGILITY, &agility}, {DEXTERITY, &dexterity}
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
        um<Attributes_And_Skills, Stat *> skill_selection_map = {
            {TEACHING, &teaching}, {DOCTORING, &doctoring}, {INTIMIDATION, &intimidation},
            {PERFORMANCE, &performance}, {ACROBATICS, &acrobatics}, {SUPERNATURALISM, &supernaturalism},
            {SURVIVAL, &survival}, {HISTORY, &history}, {NEGOTIATION, &negotiation}, {ATHLETICS, &athletics},
            {INVESTIGATION, &investigation}, {STEALTH, &stealth}, {SLEIGHT_OF_HAND, &sleight_of_hand},
            {MECHANICAL, &mechanical}, {INSIGHT, &insight}
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
    void change_attributes(Attributes_And_Skills attribute_to_change, int modification_value,
                           Flag flag = CHANGE_TO) const;

    void train(Attributes_And_Skills thing_to_train, Flag type, int new_level, Flag setting = CHANGE_TO);

    // Returns true if damage dealt adds a level of attrition
    Health::Damage_Result deal_damage(unsigned int damage_dealt);

    void heal(unsigned int amount, Flag type);

    void set_max_health(int amount, Flag flag = CHANGE_TO);

    [[nodiscard]] int calculate_protection_score() const;

    [[nodiscard]] unsigned int get_health() const;

    [[nodiscard]] unsigned int get_max_health() const;

    [[nodiscard]] unsigned int get_temp_health() const;

    void update_skills();

    // Returns a deep copy of a stat to prevent editing
    [[nodiscard]] std::shared_ptr<Stat> get_stat(Attributes_And_Skills thing_to_get, Flag type) const;

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

    void update_single_stat(Flag type, Attributes_And_Skills thing_to_update);

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
