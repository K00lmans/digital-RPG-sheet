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
}

void Character::save_character(const string &path) const {
    std::ofstream output_file(path);
    output_file << name << endl << *attributes << *skills << health_info << extra_attribute_points << ";" << speed <<
            ";" << armor_class << ";" << lineage << ";" << background;
    output_file.close();
}

Character::Character(std::ifstream char_file) {
    std::getline(char_file, name);
    char_file >> *attributes >> *skills >> health_info;
    string data;
    std::getline(char_file, data);
    const auto data_tokens = tokenize_string(";", data);
    extra_attribute_points = std::stoi(data_tokens[0]);
    speed = std::stof(data_tokens[1]);
    armor_class = static_cast<Armor_Class>(std::stoi(data_tokens[2]));
    lineage = data_tokens[3];
    background = data_tokens[4];
}

ostream &operator<<(ostream &stream, const Character::Stat &stat) {
    stream << stat.modifier << ";" << stat.training_level << ";" << stat.training_points << ";";
    if (stat.value.has_value()) {
        stream << stat.value.value() << endl;
    } else {
        stream << endl;
    }
    return stream;
}

istream &operator>>(istream &stream, Character::Stat &stat) {
    string data;
    std::getline(stream, data);
    const auto data_tokens = tokenize_string(";", data);
    stat.modifier = std::stoi(data_tokens[0]);
    stat.training_level = static_cast<Training_Level>(std::stoi(data_tokens[1]));
    stat.training_points = std::stoi(data_tokens[2]);
    if (data.back() == ';') {
        stat.value = std::nullopt;
    } else {
        stat.value = std::stoi(data_tokens[3]);
    }
    return stream;
}

ostream &operator<<(ostream &stream, const Character::Attributes &attributes) {
    stream << attributes.agility << attributes.dexterity << attributes.fortitude << attributes.intelligence <<
            attributes.perception << attributes.presence << attributes.strength << attributes.wisdom;
    return stream;
}

istream &operator>>(istream &stream, Character::Attributes &attributes) {
    stream >> attributes.agility >> attributes.dexterity >> attributes.fortitude >> attributes.intelligence >>
            attributes.perception >> attributes.presence >> attributes.strength >> attributes.wisdom;
    return stream;
}

ostream &operator<<(ostream &stream, const Character::Skills &skills) {
    stream << skills.acrobatics << skills.athletics << skills.doctoring << skills.history << skills.insight << skills.
            intimidation << skills.investigation << skills.mechanical << skills.negotiation << skills.performance <<
            skills.sleight_of_hand << skills.stealth << skills.supernaturalism << skills.survival << skills.teaching;
    return stream;
}

istream &operator>>(istream &stream, Character::Skills &skills) {
    stream >> skills.acrobatics >> skills.athletics >> skills.doctoring >> skills.history >> skills.insight >> skills.
            intimidation >> skills.investigation >> skills.mechanical >> skills.negotiation >> skills.performance >>
            skills.sleight_of_hand >> skills.stealth >> skills.supernaturalism >> skills.survival >> skills.teaching;
    return stream;
}

Character::Character(const string &file_path) {
    std::ifstream input_file(file_path);
    *this = Character(std::move(input_file));
    input_file.close();
}

ostream &operator<<(ostream &stream, const Character::Health &health) {
    stream << health.current_health << ";" << health.max_health << ";" << health.temp_health << endl;
    return stream;
}

istream &operator>>(istream &stream, Character::Health &health) {
    string data;
    std::getline(stream, data);
    const auto data_tokens = tokenize_string(";", data);
    health.current_health = std::stoi(data_tokens[0]);
    health.max_health = std::stoi(data_tokens[1]);
    health.temp_health = std::stoi(data_tokens[2]);
    return stream;
}

void Character::change_attributes(const Attributes_And_Skills attribute_to_change, int modification_value, const Flag flag) const {
    const auto selected_attribute = attributes->attribute_selection_map[attribute_to_change];
    if (flag == CHANGE_TO) {
        selected_attribute->value = modification_value;
    } else if (flag == ADD_TO) {
        selected_attribute->value.value() += modification_value;
    }
    attribute_update(selected_attribute);
}

void Character::train(const Attributes_And_Skills thing_to_train, int new_level, const Flag setting) {
    Stat *selection;
    if (thing_to_train < END_OF_ATTRIBUTES) {
        selection = attributes->attribute_selection_map[thing_to_train];
    } else {
        selection = skills->skill_selection_map[thing_to_train];
    }
    if (setting == CHANGE_TO) {
        selection->training_level = static_cast<Training_Level>(new_level);
    } else if (setting == ADD_TO) {
        selection->training_level = static_cast<Training_Level>(
            (selection->training_level + new_level) % (2 + selection->value.has_value()));
    } else {
        return;
    }
    update_single_stat(thing_to_train);
}

void Character::attribute_update(Stat *attribute) {
    attribute->modifier = attribute->value.value() / 2 - 5 + 5 * attribute->training_level;
}

int Character::handle_training_for_skills(int modifier, const Training_Level training) {
    if (modifier > 0 && training == UNTRAINED) {
        return system_round<double, int>(modifier / 2.0);
    }
    if (modifier < 0 && training >= TRAINED) {
        modifier = system_round<double, int>(modifier / 2.0);
    }
    if (training == EXPERT) {
        modifier += 5;
    }
    return modifier;
}

void Character::update_single_stat(const Attributes_And_Skills thing_to_update) {
    if (thing_to_update < END_OF_ATTRIBUTES) {
        attribute_update(attributes->attribute_selection_map[thing_to_update]);
    } else {
        const auto selected_skill = skills->skill_selection_map[thing_to_update];
        selected_skill->modifier = handle_training_for_skills(selected_skill->modifier, selected_skill->training_level);
    }
}

Character::Health::Damage_Result Character::deal_damage(unsigned int damage_dealt) {
    if (damage_dealt >= health_info.current_health) {
        health_info.current_health = 0;
        if (damage_dealt >= health_info.max_health / 4) {
            if (health_info.temp_health != 0) {
                health_info.temp_health = 0;
                return Health::BAD_TIME;
            }
            return Health::HEALTH_AND_ATTRITION;
        }
        if (health_info.temp_health != 0) {
            health_info.temp_health = 0;
            return Health::TEMP_AND_HEALTH;
        }
        return Health::HEALTH_DEPLETED;
    }
    health_info.current_health -= damage_dealt;
    if (damage_dealt >= health_info.temp_health) {
        damage_dealt -= health_info.temp_health;
        health_info.temp_health = 0;
        if (damage_dealt >= health_info.max_health / 4) {
            return Health::TEMP_AND_ATTRITION;
        }
        return Health::TEMP_HEALTH_DEPLETED;
    }
    health_info.temp_health -= damage_dealt;
    return Health::NONE;
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
            break; // Need to make item training system first
        case MEDIUM : {
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
    Stat stat_to_return;
    if (thing_to_get < END_OF_ATTRIBUTES) {
        stat_to_return = *attributes->attribute_selection_map[thing_to_get];
    } else {
        stat_to_return = *skills->skill_selection_map[thing_to_get];
    }
    return stat_to_return;
}

void Character::update_skills() {
    for (int skill = END_OF_ATTRIBUTES + 1; skill < END_OF_SKILLS; skill++) {
        update_single_stat(static_cast<Attributes_And_Skills>(skill));
    }
}
