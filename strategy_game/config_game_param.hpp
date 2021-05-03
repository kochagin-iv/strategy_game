#include "stdafx.h"

struct ConfigGameParam {
    int current_gold = 100;
    int current_silver = 100;
    int window_size_x = 1920;
    int window_size_y = 1067;
};

// --------CONFIG BUTTONS---------- //

struct ConfigButtonParam {
    int setTextureRect_x = 600;
    int setTextureRect_y = 600;

};

struct SwordsManButtonConf {
    std::string address_for_texture = "../strategy_game/Textures/Buttons/SwordsManButton.png";
    int initSprite_x = 500;
    int initSprite_y = 920;
    float scale_x = 0.25;
    float scale_y = 0.25;
    std::string name = "SwordsManButton";
};

struct ArcherManButtonConf {
    std::string address_for_texture = "../strategy_game/Textures/Buttons/ArcherManButton.png";
    int initSprite_x = 700;
    int initSprite_y = 920;
    float scale_x = 0.25;
    float scale_y = 0.25;
    std::string name = "ArcherManButton";
};

struct PhoenixButtonConf {
    std::string address_for_texture = "../strategy_game/Textures/Buttons/PhoenixButton.png";
    int initSprite_x = 900;
    int initSprite_y = 920;
    float scale_x = 0.25;
    float scale_y = 0.25;
    std::string name = "PhoenixButton";
};

struct PaladinButtonConf {
    std::string address_for_texture = "../strategy_game/Textures/Buttons/PaladinButton.png";
    int initSprite_x = 300;
    int initSprite_y = 920;
    float scale_x = 0.25;
    float scale_y = 0.25;
    std::string name = "PaladinButton";
};

struct TeamButtonConf {
    std::string address_for_texture = "../strategy_game/Textures/Buttons/TeamButton.png";
    int initSprite_x = 100;
    int initSprite_y = 920;
    float scale_x = 0.25;
    float scale_y = 0.25;
    std::string name = "TeamButton";
};