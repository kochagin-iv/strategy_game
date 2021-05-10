#include "stdafx.h"

class ConfigPaladin {
public:
    std::vector<std::vector<int> > paladin_texture_rect_moving = {
        {0, 107, 56, 89},
        {126, 107, 56, 89},
        {246, 107, 56, 89},
        {369, 107, 56, 89},
        {499, 107, 56, 89},
        {624, 107, 64, 91},
        {748, 107, 61, 84},
        {875, 107, 61, 91}
    };

    std::vector<std::vector<int> > paladin_texture_rect_attack = {
        {593, 202, 66, 99},
        {701, 202, 66, 99},
        {830, 202, 84, 99}
    };

    std::vector<std::vector<int> > paladin_texture_rect_die = {
        {353, 327, 92, 72},
        {472, 327, 92, 72},
        {595, 327, 98, 72},
        {710, 327, 98, 72},
        {819, 327, 98, 72}
    };  


    float paladin_speed = 3.f;
    std::string address_for_texture = "../strategy_game/Textures/Paladin_texture.png";
    int sprite_x = 250, sprite_y = 780, scale_x = 2, scale_y = 2;

    int silver_cost = 20;
    int gold_cost = 0;
    int attack_radius = 150;
    int attack = 40;
    int unit_type = 1;
    int health = 3000;
};