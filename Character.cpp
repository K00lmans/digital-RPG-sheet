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
    stat.training_level = static_cast<Character::Training_Level>(std::stoi(data_tokens[1]));
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

void Character::change_attributes(const string &attribute_to_change, int modification_value, const Flag flag) {
    const auto selected_attribute = attributes->attribute_selection_map[attribute_to_change];
    if (flag == CHANGE_TO) {
        selected_attribute->value = modification_value;
    } else if (flag == ADD_TO) {
        selected_attribute->value.value() += modification_value;
    }
    recalculate_modifier(selected_attribute, ATTRIBUTE);
}

void Character::train(const string &thing_to_train, const Flag selected_thing, int new_level, const Flag setting_flag) {
    Stat *selection;
    if (selected_thing == ATTRIBUTE) {
        selection = attributes->attribute_selection_map[thing_to_train];
    } else if (selected_thing == SKILL) {
        selection = skills->skill_selection_map[thing_to_train];
    } else {
        return;
    }
    if (setting_flag == CHANGE_TO) {
        selection->training_level = static_cast<Training_Level>(new_level);
    } else if (setting_flag == ADD_TO) {
        selection->training_level = static_cast<Training_Level>(
            (selection->training_level + new_level) % (2 + selection->value.has_value()));
    } else {
        return;
    }
    recalculate_modifier(selection, selected_thing);
}
