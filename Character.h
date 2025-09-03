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
#include <list>
#include <nlohmann/json.hpp>
#include <utility>
#include "handy_stuff.h"

using std::optional;
using std::string;
using std::endl;
using std::ostream;
using std::istream;
using std::vector;
using std::list;
using std::pair;
using nlohmann::json;

#define um std::unordered_map

class Character {
public:
    enum Flag {
        // A set of flags to be used with this class

        // For use when changing values
        CHANGE_TO, // Sets the value being changed
        ADD_TO, // Adds to the value being changed

        // For use with health
        NORMAL, // Non-temp heath
        TEMP, // Temp health

        // For use with skill training
        AVERAGE, // Stat is determined by averaging several stats
        HIGHEST // Stat is determined by picking from the highest and lowest, takes precedent
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
        INTUITION,
        END_OF_SKILLS
    };

    // Attributes and skills have several elements inside of them, this struct contains all those values
    struct Stat {
        int modifier;
        Training training_info;
        optional<unsigned int> value; // Skills do not have a value

        // An inversion operator
        Stat operator-() const;
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
        Stat intuition;
        um<Attributes_And_Skills, Stat *> skill_selection_map = {
            {TEACHING, &teaching}, {DOCTORING, &doctoring}, {INTIMIDATION, &intimidation},
            {PERFORMANCE, &performance}, {ACROBATICS, &acrobatics}, {SUPERNATURALISM, &supernaturalism},
            {SURVIVAL, &survival}, {HISTORY, &history}, {NEGOTIATION, &negotiation}, {ATHLETICS, &athletics},
            {INVESTIGATION, &investigation}, {STEALTH, &stealth}, {SLEIGHT_OF_HAND, &sleight_of_hand},
            {MECHANICAL, &mechanical}, {INTUITION, &intuition}
        };
    };

    struct Health {
        unsigned int current_health; // Includes temp_health
        unsigned int max_health;
        unsigned int temp_health;

        // A way to describe if there are any extra results from taking damage
        enum Damage_Result {
            NONE = 0b0, // Nothing else happens
            TEMP_HEALTH_DEPLETED = 0b001, // All of temp health was used
            ATTRITION_LIMIT = 0b010, // Enough Damage was dealt to the base health to gain a level of attrition
            HEALTH_DEPLETED = 0b100, // The damage removed all their health
            TEMP_AND_ATTRITION = 0b011, // Both ATTRITION_LIMIT and TEMP_HEALTH_DEPLETED
            TEMP_AND_HEALTH = 0b101, // Both HEALTH_DEPLETED and TEMP_HEALTH_DEPLETED
            HEALTH_AND_ATTRITION = 0b110, // Both HEALTH_DEPLETED and ATTRITION_LIMIT happen
            BAD_TIME = 0b111 // All non-combined effects
        };
    };

    struct Armor_Training {
        Training light_armor;
        Training medium_armor;
        Training heavy_armor;
    };

    struct Weapon_Training {
        Training basic_weapons;
        Training simple_weapons;
        vector<pair<string, Training> > advanced_weapons;
        vector<pair<string, Training> > complicated_weapons;
    };

    Character(); // Assumes default values

    explicit Character(std::ifstream &char_file);

    void save_character(const string &path) const;

    explicit Character(const string &file_path);

    // Skills are based on attributes and therefore this does not need to be a general function
    void change_attributes(Attributes_And_Skills attribute_to_change, int modification_value,
                           Flag flag = CHANGE_TO) const;

    void train(Attributes_And_Skills thing_to_train, int new_level, Flag setting = CHANGE_TO) const;

    // Returns true if damage dealt adds a level of attrition
    Health::Damage_Result deal_damage(unsigned int damage_dealt);

    void heal(unsigned int amount, Flag type);

    void set_max_health(int amount, Flag flag = CHANGE_TO);

    [[nodiscard]] int calculate_protection_score() const;

    [[nodiscard]] unsigned int get_health() const;

    [[nodiscard]] unsigned int get_max_health() const;

    [[nodiscard]] unsigned int get_temp_health() const;

    void update_skills() const;

    // Returns a deep copy of a stat to prevent editing
    [[nodiscard]] Stat get_stat(Attributes_And_Skills thing_to_get) const;

    std::string name;
    int extra_attribute_points;
    double speed;
    Armor_Class armor_class;
    string lineage;
    string background;

private:
    static void attribute_update(Stat *attribute);

    // Handles the effect of training on a modifier
    static int handle_training_for_skills(int modifier, Training_Level training, Flag type = AVERAGE);

    void update_single_stat(Attributes_And_Skills thing_to_update) const;

    // Updates the scores of those stats that just average several attributes
    static void skill_with_just_averages(Stat *skill, const vector<Stat> &attributes_to_average);

    // Returns lowest value of untrained, as that is how the rules are modified if untrained
    template<class SET>
    static Stat *get_highest(const SET &options, const Training_Level training_level) {
        auto first_item = options.begin();
        Stat *highest_value_stat = *first_item, *lowest_value_stat = *first_item;
        for (const auto &option: options) {
            if (option->modifier > highest_value_stat->modifier) {
                highest_value_stat = option;
            }
            if (option->modifier < lowest_value_stat->modifier) {
                lowest_value_stat = option;
            }
        }
        return training_level == UNTRAINED ? highest_value_stat : lowest_value_stat;
    }

    std::shared_ptr<Attributes> attributes = std::make_shared<Attributes>();
    std::shared_ptr<Skills> skills = std::make_shared<Skills>();
    Health health_info{};
    Armor_Training armor_training{};
    Weapon_Training weapon_training;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Training, training_level, training_points)

template<class T>
void to_json(json &j, const optional<T> &optional) {
    if (optional.has_value()) {
        j = optional->value;
    } else {
        j = nullptr;
    }
}

template<class T>
void from_json(const json &j, optional<T> &optional) {
    if (j.is_null()) {
        optional = std::nullopt;
    } else {
        optional->value = j.get<T>();
    }
}

void to_json(json &j, const Character::Stat &stat);
void from_json(const json &j, Character::Stat &stat);

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Character::Attributes, intelligence, wisdom, perception, strength, presence,
                                   fortitude, agility, dexterity)

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Character::Skills, teaching, doctoring, intimidation, performance, acrobatics,
                                   supernaturalism, survival, history, negotiation, athletics, investigation, stealth,
                                   sleight_of_hand, mechanical, intuition)

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Character::Health, current_health, max_health, temp_health)

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Character::Armor_Training, light_armor, medium_armor, heavy_armor)

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Character::Weapon_Training, basic_weapons, simple_weapons, advanced_weapons,
                                   complicated_weapons)

#endif //RPG_SHEET_CHARACTER_H
