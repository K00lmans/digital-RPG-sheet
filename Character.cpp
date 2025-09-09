#include "Character.h"

Character::Character() {
    // All other values are covered by the initialization defaults
    attributes.agility->value = 10;
    attributes.dexterity->value = 10;
    attributes.fortitude->value = 10;
    attributes.intelligence->value = 10;
    attributes.perception->value = 10;
    attributes.presence->value = 10;
    attributes.strength->value = 10;
    attributes.wisdom->value = 10;
}

void Character::save_character(const string &path) {
    json save_data;
    save_data["name"] = name;
    save_data["armor_class"] = armor_class;
    save_data["lineage"] = lineage;
    save_data["background"] = background;
    save_data["attributes"] = attributes;
    save_data["skills"] = skills;
    save_data["health_info"] = health_info;
    save_data["armor_training"] = armor_training;
    save_data["weapon_training"] = weapon_training;
    std::ofstream output_file(static_cast<std::filesystem::path>(path));
    output_file << save_data;
    output_file.close();
}

Character::Character(std::ifstream char_file) {
    json save_data;
    char_file >> save_data;
    name = save_data["name"];
    armor_class = save_data["armor_class"];
    lineage = save_data["lineage"];
    background = save_data["background"];
    attributes = save_data["attributes"];
    skills = save_data["skills"];
    health_info = save_data["health_info"];
    armor_training = save_data["armor_training"];
    weapon_training = save_data["weapon_training"];
}

void Character::change_attributes(const Attributes_And_Skills attribute_to_change, int modification_value,
                                  const Flag flag) const {
    const auto selected_attribute = attributes[attribute_to_change];
    if (flag == CHANGE_TO) {
        if (modification_value >= 20) {
            selected_attribute->value = 20;
        } else if (modification_value <= 1) {
            selected_attribute->value = 1;
        } else {
            selected_attribute->value = modification_value;
        }
    } else if (flag == ADD_TO) {
        selected_attribute->value.value() += modification_value;
        if (selected_attribute->value.value() > 20) {
            selected_attribute->value = 20;
        } else if (selected_attribute->value.value() < 1) {
            selected_attribute->value = 1;
        }
    }
    attribute_update(selected_attribute);
}

void Character::train(const Attributes_And_Skills thing_to_train, int new_level, const Flag setting) {
    shared_ptr<Stat> selection;
    thing_to_train < END_OF_ATTRIBUTES
        ? selection = attributes[thing_to_train]
        : selection = skills[thing_to_train];
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

void Character::attribute_update(const shared_ptr<Stat> &attribute) {
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

void Character::update_single_stat(const Attributes_And_Skills thing_to_update) {
    if (thing_to_update < END_OF_ATTRIBUTES) {
        attribute_update(attributes[thing_to_update]);
    } else {
        const auto selected_skill = skills[thing_to_update];
        Flag type = AVERAGE;
        switch (thing_to_update) {
            case TEACHING: // This brings me joy, you never get to use this lol
            case HISTORY:
                skill_with_just_averages(selected_skill, {attributes.wisdom});
                break;
            case MECHANICAL:
            case SLEIGHT_OF_HAND:
            case DOCTORING:
                skill_with_just_averages(selected_skill, {attributes.dexterity, attributes.wisdom});
                break;
            case INTIMIDATION:
                type = HIGHEST;
                skill_with_just_averages(selected_skill, {
                                             get_highest<vector<shared_ptr<Stat> > >(
                                                 {attributes.presence, attributes.strength},
                                                 selected_skill->training_info.training_level),
                                             attributes.wisdom
                                         });
                break;
            case PERFORMANCE:
                skill_with_just_averages(selected_skill, {attributes.wisdom, attributes.presence});
                break;
            case ACROBATICS:
                skill_with_just_averages(selected_skill, {attributes.dexterity, attributes.agility});
                break;
            case SUPERNATURALISM:
                type = HIGHEST;
                selected_skill->modifier = get_highest<vector<Stat> >({*attributes.wisdom, (-*attributes.wisdom)},
                                                                      selected_skill->training_info.training_level)->
                        modifier;
                break;
            case SURVIVAL:
                skill_with_just_averages(selected_skill, {attributes.wisdom, attributes.fortitude});
                break;
            case NEGOTIATION: {
                type = HIGHEST;
                auto possible_attributes = list{attributes.presence, attributes.intelligence, attributes.wisdom};
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
                                             attributes.wisdom,
                                             get_highest<vector<shared_ptr<Stat> > >(
                                                 {attributes.strength, attributes.agility},
                                                 selected_skill->training_info.training_level)
                                         });
                break;
            case INTUITION:
            case INVESTIGATION:
                skill_with_just_averages(selected_skill, {attributes.intelligence, attributes.perception});
                break;
            case STEALTH: {
                type = HIGHEST;
                auto averaged_stat = make_shared<Stat>(
                    attributes.dexterity->modifier + (-*attributes.presence).modifier / 2);
                skill_with_just_averages(selected_skill, {
                                             attributes.wisdom,
                                             get_highest<vector<shared_ptr<Stat> > >(
                                                 {attributes.dexterity, attributes.presence, averaged_stat},
                                                 selected_skill->training_info.training_level)
                                         });
                break;
            }
            default: break; // Should never be hit
        }
        selected_skill->modifier = handle_training_for_skills(selected_skill->modifier,
                                                              selected_skill->training_info.training_level, type);
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
    protection_score += attributes.fortitude->modifier;
    switch (armor_class) {
        case NONE:
            protection_score += attributes.agility->modifier;
            break;
        case LIGHT:
            protection_score += 5 + attributes.agility->modifier / (1 + armor_training.light_armor.training_level);
            break;
        case MEDIUM: {
            int agility_component = attributes.agility->modifier;
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
    Stat copy_of_stat;
    // Make it not a pointer to allow for the splitting
    const auto [modifier, training_info, value] = thing_to_get < END_OF_ATTRIBUTES
                                                      ? *attributes[thing_to_get]
                                                      : *skills[thing_to_get];
    copy_of_stat.modifier = modifier;
    copy_of_stat.training_info.training_level = training_info.training_level;
    copy_of_stat.training_info.training_points = training_info.training_points;
    if (value.has_value()) {
        copy_of_stat.value = value.value();
    } else {
        copy_of_stat.value = std::nullopt;
    }
    return copy_of_stat;
}

void Character::update_skills() {
    for (int skill = END_OF_ATTRIBUTES + 1; skill < END_OF_SKILLS; skill++) {
        update_single_stat(static_cast<Attributes_And_Skills>(skill));
    }
}

void Character::skill_with_just_averages(const shared_ptr<Stat> &skill,
                                         const vector<shared_ptr<Stat> > &attributes_to_average) {
    int new_modifier = 0;
    for (const auto &attribute: attributes_to_average) {
        new_modifier += attribute->modifier;
    }
    new_modifier /= attributes_to_average.size();
    skill->modifier = new_modifier;
}

Character::Stat Character::Stat::operator-() const {
    const auto return_thing = *this;
    return_thing.modifier = -return_thing.modifier;
    return return_thing;
}

void to_json(json &j, const shared_ptr<Character::Stat> &stat) {
    j = {{"modifier", stat->modifier}, {"training_info", stat->training_info}, {"value", stat->value}};
}

void from_json(const json &j, shared_ptr<Character::Stat> &stat) {
    stat->modifier = j["modifier"];
    stat->training_info = j["training_info"];
    if (j["value"].is_number_unsigned()) {
        stat->value = j["value"];
    } else {
        stat->value = std::nullopt;
    }
}

int Character::calculate_remaining_points() const {
    int remaining_points = 90;
    for (int attribute = 0; attribute < END_OF_ATTRIBUTES; attribute++) {
        remaining_points -= attributes[attribute]->value.value();
    }
    return remaining_points;
}
