#include "stdafx.h"

class ConfigSwordsman {
public:
    std::vector<std::vector<int> > swordsman_texture_rect_moving = {
        {27, 525, 63, 91},
        {104, 525, 63, 91},
        {180, 525, 69, 91},
        {263, 525, 69, 91},
        {346, 525, 61, 91},
        {427, 525, 61, 91},
        {502, 525, 61, 91},
        {571, 525, 61, 91},
        {642, 525, 61, 91},
        {724, 525, 72, 91}
    };

    std::vector<std::vector<int> > swordsman_texture_rect_attack = {
        {182, 252, 70, 100},
        {269, 252, 99, 100},
        {386, 252, 82, 100}
    };

    std::vector<std::vector<int> > swordsman_texture_rect_die = {
        {11, 789, 66, 105},
        {102, 789, 70, 105},
        {192, 789, 76, 105},
        {275, 789, 76, 105},
        {348, 789, 76, 105},
        {420, 789, 76, 105}
    };  


    float swordsman_speed = 5.f;
    std::string address_for_texture = "../strategy_game/Textures/swordsman_texture.png";
    int sprite_x = 250, sprite_y = 780, scale_x = 2, scale_y = 2;

    int silver_cost = 10;
    int gold_cost = 0;
    int attack_radius = 100;
    int attack = 30;
    int unit_type = 1;
    int health = 2000;
};