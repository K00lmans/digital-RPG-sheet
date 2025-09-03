#include "Character.h"

Character::Character() {
    constexpr Stat default_ability = {0, UNTRAINED, 0, 10}, default_skill = {0, UNTRAINED, 0};
    *attributes = {
        default_ability, default_ability, default_ability, default_ability, default_ability, default_ability,
        default_ability, default_ability
    };
    *skills = {
        default_skill, default_skill, default_skill, default_skill, default_skill, default_skill, default_skill,
        default_skill, default_skill, default_skill, default_skill, default_skill, default_skill, default_skill,
        default_skill
    };

    extra_attribute_points = 10;
    health_info = {0, 0, 0};
    speed = 15;
    armor_class = NONE;
    armor_training = {UNTRAINED, 0, UNTRAINED, 0, UNTRAINED, 0};
    weapon_training = {UNTRAINED, 0, UNTRAINED, 0};
}

void Character::save_character(const string &path) const {
    json save_data;
    save_data["name"] = name;
    save_data["speed"] = speed;
    save_data["armor_class"] = armor_class;
    save_data["lineage"] = lineage;
    save_data["background"] = background;
    save_data["attributes"] = *attributes;
    save_data["skills"] = *skills;
    save_data["health_info"] = health_info;
    save_data["armor_training"] = armor_training;
    save_data["weapon_training"] = weapon_training;
    std::ofstream output_file(path);
    output_file << save_data;
    output_file.close();
}

Character::Character(std::ifstream &char_file) {
    json save_data;
    char_file >> save_data;
    name = save_data["name"];
    speed = save_data["speed"];
    armor_class = save_data["armor_class"];
    lineage = save_data["lineage"];
    background = save_data["background"];
    *attributes = save_data["attributes"];
    *skills = save_data["skills"];
    health_info = save_data["health_info"];
    armor_training = save_data["armor_training"];
    weapon_training = save_data["weapon_training"];
    int attribute_points = 90;
    for (int attributes_i = 0; attributes_i < END_OF_ATTRIBUTES; attributes_i++) {
        attribute_points -= attributes->attribute_selection_map[static_cast<Attributes_And_Skills>(attributes_i)]->
                value.value();
    }
    extra_attribute_points = attribute_points;
}

Character::Character(const string &file_path) {
    std::ifstream save_file(file_path);
    *this = Character(save_file);
    save_file.close();
}

void Character::change_attributes(const Attributes_And_Skills attribute_to_change, int modification_value,
                                  const Flag flag) const {
    const auto selected_attribute = attributes->attribute_selection_map[attribute_to_change];
    if (flag == CHANGE_TO) {
        selected_attribute->value = modification_value;
    } else if (flag == ADD_TO) {
        selected_attribute->value.value() += modification_value;
    }
    attribute_update(selected_attribute);
}

void Character::train(const Attributes_And_Skills thing_to_train, int new_level, const Flag setting) const {
    Stat *selection;
    thing_to_train < END_OF_ATTRIBUTES
        ? selection = attributes->attribute_selection_map[thing_to_train]
        : selection = skills->skill_selection_map[thing_to_train];
    if (setting == CHANGE_TO) {
        selection->training_info.training_level = static_cast<Training_Level>(new_level);
    } else if (setting == ADD_TO) {
        selection->training_info.training_level = static_cast<Training_Level>(
            (selection->training_info.training_level + new_level) % (2 + selection->value.has_value()));
    } else {
        return;
    }
    update_single_stat(thing_to_train);
}

void Character::attribute_update(Stat *attribute) {
    attribute->modifier = attribute->value.value() / 2 - 5 + 5 * attribute->training_info.training_level;
}

int Character::handle_training_for_skills(int modifier, const Training_Level training, const Flag type) {
    if (type == AVERAGE) {
        // Training works different for skills that select from the highest
        if (modifier > 0 && training == UNTRAINED) {
            return system_round<double, int>(modifier / 2.0);
        }
        if (modifier < 0 && training >= TRAINED) {
            modifier = system_round<double, int>(modifier / 2.0);
        }
    }
    if (training == EXPERT) {
        modifier += 5;
    }
    return modifier;
}

void Character::update_single_stat(const Attributes_And_Skills thing_to_update) const {
    if (thing_to_update < END_OF_ATTRIBUTES) {
        attribute_update(attributes->attribute_selection_map[thing_to_update]);
    } else {
        const auto selected_skill = skills->skill_selection_map[thing_to_update];
        Flag type = AVERAGE;
        switch (thing_to_update) {
            case TEACHING: // This brings me joy, you never get to use this lol
            case HISTORY:
                skill_with_just_averages(selected_skill, {attributes->wisdom});
                break;
            case MECHANICAL:
            case SLEIGHT_OF_HAND:
            case DOCTORING:
                skill_with_just_averages(selected_skill, {attributes->dexterity, attributes->wisdom});
                break;
            case INTIMIDATION:
                type = HIGHEST;
                skill_with_just_averages(selected_skill, {
                                             *get_highest<vector<Stat *> >(
                                                 {&attributes->strength, &attributes->presence},
                                                 selected_skill->training_info.training_level),
                                             attributes->wisdom
                                         });
                break;
            case PERFORMANCE:
                skill_with_just_averages(selected_skill, {attributes->wisdom, attributes->presence});
                break;
            case ACROBATICS:
                skill_with_just_averages(selected_skill, {attributes->dexterity, attributes->agility});
                break;
            case SUPERNATURALISM:
                type = HIGHEST;
                selected_skill->modifier = get_highest<vector<Stat *> >(
                    {&attributes->wisdom, std::make_shared<Stat>(-attributes->wisdom).get()},
                    selected_skill->training_info.training_level)->modifier;
                break;
            case SURVIVAL:
                skill_with_just_averages(selected_skill, {attributes->wisdom, attributes->fortitude});
                break;
            case NEGOTIATION: {
                type = HIGHEST;
                auto possible_attributes = list{&attributes->presence, &attributes->intelligence, &attributes->wisdom};
                auto highest_attribute = get_highest(possible_attributes, selected_skill->training_info.training_level);
                possible_attributes.remove(highest_attribute);
                auto second_highest_attribute = get_highest(possible_attributes,
                                                            selected_skill->training_info.training_level);
                skill_with_just_averages(selected_skill, {highest_attribute, second_highest_attribute});
                break;
            }
            case ATHLETICS:
                type = HIGHEST;
                skill_with_just_averages(selected_skill, {
                                             attributes->wisdom,
                                             *get_highest<vector<Stat *> >(
                                                 {&attributes->strength, &attributes->agility},
                                                 selected_skill->training_info.training_level)
                                         });
                break;
            case INTUITION:
            case INVESTIGATION:
                skill_with_just_averages(selected_skill, {attributes->intelligence, attributes->perception});
                break;
            case STEALTH: {
                type = HIGHEST;
                Stat averaged_stat = {(attributes->dexterity.modifier + (-attributes->presence).modifier / 2)};
                skill_with_just_averages(selected_skill, {
                                             attributes->wisdom,
                                             *get_highest<vector<Stat *> >(
                                                 {&attributes->dexterity, &attributes->presence, &averaged_stat},
                                                 selected_skill->training_info.training_level)
                                         });
                break;
            }
            default: break; // Should never be hit
        }
        selected_skill->modifier = handle_training_for_skills(selected_skill->modifier,
                                                              selected_skill->training_info.training_level,
                                                              type);
    }
}

Character::Health::Damage_Result Character::deal_damage(unsigned int damage_dealt) {
    int damage_result = 0;
    if (damage_dealt >= health_info.temp_health) {
        damage_result += Health::TEMP_HEALTH_DEPLETED;
        damage_dealt -= health_info.temp_health;
        health_info.temp_health = 0;
        if (damage_dealt >= health_info.max_health / 4) {
            damage_result += Health::ATTRITION_LIMIT;
        }
        if (damage_dealt >= health_info.current_health) {
            damage_result += Health::HEALTH_DEPLETED;
            health_info.current_health = 0;
        } else {
            health_info.current_health -= damage_dealt;
        }
    } else {
        health_info.temp_health -= damage_dealt;
    }
    return static_cast<Health::Damage_Result>(damage_result);
}

void Character::heal(unsigned int amount, const Flag type) {
    if (type == NORMAL) {
        if (const auto missing_health = health_info.max_health - (health_info.current_health - health_info.temp_health);
            missing_health <= amount) {
            amount = missing_health;
        }
        health_info.current_health += amount;
    } else if (type == TEMP) {
        health_info.temp_health += amount;
        health_info.current_health += amount;
    }
}

void Character::set_max_health(const int amount, const Flag flag) {
    if (flag == CHANGE_TO) {
        health_info.max_health = amount;
    } else if (flag == ADD_TO) {
        health_info.max_health += amount;
    }
}

int Character::calculate_protection_score() const {
    int protection_score = 1;
    protection_score += attributes->fortitude.modifier;
    switch (armor_class) {
        case NONE:
            protection_score += attributes->agility.modifier;
            break;
        case LIGHT:
            protection_score += 5 + attributes->agility.modifier / (1 + armor_training.light_armor.training_level);
            break;
        case MEDIUM: {
            int agility_component = attributes->agility.modifier;
            if (abs(agility_component) > 5) {
                agility_component = 5 * get_sign(agility_component);
            }
            protection_score += 10 + agility_component;
            break;
        }
        case HEAVY:
            protection_score += 15;
            break;
    }
    if (protection_score < 1) {
        protection_score = 1;
    }
    return protection_score;
}

unsigned int Character::get_health() const {
    return health_info.current_health;
}

unsigned int Character::get_max_health() const {
    return health_info.max_health;
}

unsigned int Character::get_temp_health() const {
    return health_info.temp_health;
}

Character::Stat Character::get_stat(const Attributes_And_Skills thing_to_get) const {
    return thing_to_get < END_OF_ATTRIBUTES
               ? *attributes->attribute_selection_map[thing_to_get]
               : *skills->skill_selection_map[thing_to_get];
}

void Character::update_skills() const {
    for (int skill = END_OF_ATTRIBUTES + 1; skill < END_OF_SKILLS; skill++) {
        update_single_stat(static_cast<Attributes_And_Skills>(skill));
    }
}

void Character::skill_with_just_averages(Stat *skill, const vector<Stat> &attributes_to_average) {
    int new_modifier = 0;
    for (const auto &attribute: attributes_to_average) {
        new_modifier += attribute.modifier;
    }
    new_modifier /= attributes_to_average.size();
    skill->modifier = new_modifier;
}

Character::Stat Character::Stat::operator-() const {
    auto return_thing = *this;
    return_thing.modifier = -return_thing.modifier;
    return return_thing;
}

void to_json(json &j, const Character::Stat &stat) {
    j = {{"modifier", stat.modifier}, {"training_info", stat.training_info}, {"value", stat.value}};
}

void from_json(const json &j, Character::Stat &stat) {
    stat.modifier = j["modifier"];
    stat.training_info = j["training_info"];
    stat.value = j["value"];
}
