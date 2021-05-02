#include "stdafx.h"

class Config_archer{
public:
    std::vector<std::vector<int> > archer_texture_rect_moving = {
        {68, 785, 56, 83},
        {135, 785, 67, 83},
        {209, 785, 67, 83},
        {290, 785, 61, 83},
        {365, 785, 54, 83},
        {435, 785, 54, 83},
        {507, 785, 60, 83},
        {573, 785, 60, 83}
    };

    std::vector<std::vector<int> > archer_texture_rect_attack = {
        {9, 255, 48, 109},
        {78, 255, 48, 109},
        {151, 255, 50, 109},
        {222, 255, 50, 109},
        {290, 255, 64, 109},
        {383, 255, 67, 109},
        {478, 255, 67, 109},
        {572, 255, 64, 109}
    };

    std::vector<std::vector<int> > archer_texture_rect_die = {
        {471, 884, 95, 92},
        {570, 884, 95, 92},
        {674, 884, 67, 92},
        {742, 884, 67, 92},
        {810, 884, 67, 92}
    };

    float archer_speed = 10.f;
    std::string address_for_texture = "../strategy_game/Textures/archerman_texture.png";
    int sprite_x = 250, sprite_y = 780, scale_x = 2, scale_y = 2;

    int silver_cost = 15;
    int gold_cost = 0;
    int attack_radius = 800;
    int attack = 40;
    int unit_type = 2;
    int health = 100;
};
