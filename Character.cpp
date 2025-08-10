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
