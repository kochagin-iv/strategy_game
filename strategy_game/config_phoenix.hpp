#include "stdafx.h"

class ConfigPhoenix {
public:
    std::vector<std::vector<int> > phoenix_texture_rect_moving = {
        {402, 135, 117, 117},
        {604, 135, 117, 117},
        {805, 135, 119, 117},
        {1005, 135, 119, 117},
        {1205, 135, 119, 117},
        {1404, 135, 129, 117}
    };

    std::vector<std::vector<int> > phoenix_texture_rect_attack = {
        {8, 473, 166, 97},
        {214, 500, 136, 97},
        {414, 490, 136, 97}
    };

    std::vector<std::vector<int> > phoenix_texture_rect_die = {
        {14, 942, 102, 173},
        {209, 942, 102, 173},
        {408, 942, 102, 173},
        {606, 942, 102, 173},
        {808, 942, 102, 173},
        {1007, 942, 102, 173},
        {1212, 942, 102, 173},
        {1414, 942, 102, 173},
        {14, 1137, 102, 173},
        {209, 1137, 102, 173},
        {408, 1137, 102, 173},
        {606, 1137, 102, 173},
        {808, 1137, 102, 173}
    };  


    float phoenix_speed = 10.f;
    std::string address_for_texture = "../strategy_game/Textures/phoenix_texture.png";
    int sprite_x = 250, sprite_y = 250, scale_x = 2, scale_y = 2;

    int silver_cost = 50;
    int gold_cost = 0;
    int attack_radius = 600;
    int attack = 20;
    int unit_type = 3;
    int health = 500;
};