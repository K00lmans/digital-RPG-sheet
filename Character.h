/*
 *This object stores all the data relating to a character sheet
 */

#ifndef RPG_SHEET_CHARACTER_H
#define RPG_SHEET_CHARACTER_H

// This is an absurd number of things I include for like 1 thing lol. I wish I had the python thing of just including
// the bit I need
#include <optional>
#include <memory>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <nlohmann/json.hpp>
#include <utility>
#include <filesystem>
#include <array>
#include <type_traits>

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
using std::shared_ptr;
using std::make_shared;

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

    // Attributes and skills have several elements inside of them, this struct contains all those values
    struct Stat {
        mutable int modifier = 0;
        Training training_info{};
        optional<unsigned int> value = std::nullopt; // Skills do not have a value

        // An inversion operator
        Stat operator-() const;
    };

    struct Attributes {
        shared_ptr<Stat> intelligence = make_shared<Stat>();
        shared_ptr<Stat> wisdom = make_shared<Stat>();
        shared_ptr<Stat> perception = make_shared<Stat>();
        shared_ptr<Stat> strength = make_shared<Stat>();
        shared_ptr<Stat> presence = make_shared<Stat>();
        shared_ptr<Stat> fortitude = make_shared<Stat>();
        shared_ptr<Stat> agility = make_shared<Stat>();
        shared_ptr<Stat> dexterity = make_shared<Stat>();

    private:
        std::array<shared_ptr<Stat>, 8> attribute_selection_array = {
            intelligence, wisdom, perception, strength, presence, fortitude, agility, dexterity
        };

    public:
        template<typename COUNTABLE>
        shared_ptr<Stat> operator[](const COUNTABLE attribute) const {
            return attribute_selection_array[attribute];
        }
    };

    struct Skills {
        shared_ptr<Stat> teaching = make_shared<Stat>();
        shared_ptr<Stat> doctoring = make_shared<Stat>();
        shared_ptr<Stat> intimidation = make_shared<Stat>();
        shared_ptr<Stat> performance = make_shared<Stat>();
        shared_ptr<Stat> acrobatics = make_shared<Stat>();
        shared_ptr<Stat> supernaturalism = make_shared<Stat>();
        shared_ptr<Stat> survival = make_shared<Stat>();
        shared_ptr<Stat> history = make_shared<Stat>();
        shared_ptr<Stat> negotiation = make_shared<Stat>();
        shared_ptr<Stat> athletics = make_shared<Stat>();
        shared_ptr<Stat> investigation = make_shared<Stat>();
        shared_ptr<Stat> stealth = make_shared<Stat>();
        shared_ptr<Stat> sleight_of_hand = make_shared<Stat>();
        shared_ptr<Stat> mechanical = make_shared<Stat>();
        shared_ptr<Stat> intuition = make_shared<Stat>();

    private:
        std::array<shared_ptr<Stat>, 15> skill_selection_array = {
            teaching, doctoring, intimidation, performance, acrobatics, supernaturalism, survival, history, negotiation,
            athletics, investigation, stealth, sleight_of_hand, mechanical, intuition
        };

    public:
        template<typename COUNTABLE>
        shared_ptr<Stat> operator[](const COUNTABLE skill) const {
            return skill_selection_array[skill - 9];
        }
    };

    struct Health {
        unsigned int current_health = 0; // Includes temp_health
        unsigned int max_health = 0;
        unsigned int temp_health = 0;

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
        Training light_armor{};
        Training medium_armor{};
        Training heavy_armor{};
    };

    struct Weapon_Training {
        Training basic_weapons{};
        Training simple_weapons{};
        vector<pair<string, Training> > advanced_weapons{};
        vector<pair<string, Training> > complicated_weapons{};
    };

    Character(); // Assumes default values

    explicit Character(std::ifstream &char_file);

    void save_character(const string &path);

    explicit Character(const string &file_path);

    // Skills are based on attributes and therefore this does not need to be a general function
    void change_attributes(Attributes_And_Skills attribute_to_change, int modification_value,
                           Flag flag = CHANGE_TO) const;

    void train(Attributes_And_Skills thing_to_train, int new_level, Flag setting = CHANGE_TO);

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
    [[nodiscard]] Stat get_stat(Attributes_And_Skills thing_to_get) const;

    double calculate_speed() const { return 15 + 2.5 * attributes.agility->modifier; }
    int calculate_remaining_points() const;

    std::string name{};
    Armor_Class armor_class = NONE;
    string lineage{};
    string background{};

private:
    static void attribute_update(const shared_ptr<Stat> &attribute);

    // Handles the effect of training on a modifier
    static int handle_training_for_skills(int modifier, Training_Level training, Flag type = AVERAGE);

    void update_single_stat(Attributes_And_Skills thing_to_update);

    // Updates the scores of those stats that just average several attributes
    static void skill_with_just_averages(const shared_ptr<Stat> &skill,
                                         const vector<shared_ptr<Stat> > &attributes_to_average);

    // Returns lowest value of untrained, as that is how the rules are modified if untrained. Additionally, this
    // function was made with the help of AI
    template<class SET>
    static shared_ptr<Stat> get_highest(const SET &options, Training_Level training_level) {
        // This is utter witchcraft to me. Anyway this lets us use both shared_ptr and referenced values
        auto get_modifier = [](const auto value) -> int {
            if constexpr (std::is_convertible_v<typename SET::value_type, shared_ptr<Stat> >) {
                return value->modifier;
            } else {
                return value.modifier;
            }
        };

        // This is also witchcraft because iterators scare me. Anyway it just finds the highest and lowest
        auto highest_value = options.begin(), lowest_value = options.begin();
        for (auto iterator = options.begin(); iterator != options.end(); ++iterator) {
            if (get_modifier(*iterator) > get_modifier(*highest_value)) {
                highest_value = iterator;
            }
            if (get_modifier(*iterator) < get_modifier(*lowest_value)) {
                lowest_value = iterator;
            }
        }
        auto selection = training_level == UNTRAINED ? highest_value : lowest_value;

        // So much witchcraft. Anyway, just makes sure the return type is shared_ptr
        if constexpr (std::is_convertible_v<typename SET::value_type, shared_ptr<Stat> >) {
            return *selection;
        } else {
            return make_shared<Stat>(*selection);
        }
    }

    Attributes attributes{};
    Skills skills{};
    Health health_info{};
    Armor_Training armor_training{};
    Weapon_Training weapon_training{};
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Training, training_level, training_points)

void to_json(json &j, const shared_ptr<Character::Stat> &stat);

void from_json(const json &j, const shared_ptr<Character::Stat> &stat);

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
