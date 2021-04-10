#include "units.hpp"
#include "stdafx.h"

Knight::Knight() {
  unit_type = 1;
}

Knight::~Knight() {

}

SwordsMan::SwordsMan() {
  this->clock_move.restart();
  this->movementSpeed = 5.f;
  this->num_texture = 0;
  this->texture_rect_moving.resize(10);
  this->texture_rect_attack.resize(3);
  this->texture_rect_die.resize(6);

  this->texture_rect_moving[0] = {27, 525, 63, 91};
  this->texture_rect_moving[1] = {104, 525, 63, 91};
  this->texture_rect_moving[2] = {180, 525, 69, 91};
  this->texture_rect_moving[3] = {263, 525, 69, 91};
  this->texture_rect_moving[4] = {346, 525, 61, 91};
  this->texture_rect_moving[5] = {427, 525, 61, 91};
  this->texture_rect_moving[6] = {502, 525, 61, 91};
  this->texture_rect_moving[7] = {571, 525, 61, 91};
  this->texture_rect_moving[8] = {642, 525, 61, 91};
  this->texture_rect_moving[9] = {724, 525, 72, 91};
  // this->texture_rect_moving[10] = {811, 525, 70, 91};
  // this->texture_rect_moving[11] = {901, 525, 59, 91};

  this->texture_rect_attack[0] = {182, 252, 70, 100};
  this->texture_rect_attack[1] = {269, 252, 99, 100};
  this->texture_rect_attack[2] = {386, 252, 82, 100};

  this->texture_rect_die[0] = {11, 789, 66, 105};
  this->texture_rect_die[1] = {102, 789, 70, 105};
  this->texture_rect_die[2] = {192, 789, 76, 105};
  this->texture_rect_die[3] = {275, 789, 76, 105};
  this->texture_rect_die[4] = {348, 789, 76, 105};
  this->texture_rect_die[5] = {420, 789, 76, 105};

  this->initTexture("../strategy_game/Textures/swordsman_texture.png");
  this->initSprite(250, 780, 2, 2);
  this->silver_cost = 10;
  this->gold_cost = 0;
  this->attack_radius = 100;
  this->attack = 30;
  this->health = 2000;
}

SwordsMan::~SwordsMan() {
}


Paladin::Paladin() {
  this->clock_move.restart();
  this->movementSpeed = 3.f;
  this->num_texture = 0;
  this->texture_rect_moving.resize(8);
  this->texture_rect_attack.resize(3);
  this->texture_rect_die.resize(5);

  this->texture_rect_moving[0] = {0, 107, 56, 89};
  this->texture_rect_moving[1] = {126, 107, 56, 89};
  this->texture_rect_moving[2] = {246, 107, 56, 89};
  this->texture_rect_moving[3] = {369, 107, 56, 89};
  this->texture_rect_moving[4] = {499, 107, 56, 89};
  this->texture_rect_moving[5] = {624, 107, 64, 91};
  this->texture_rect_moving[6] = {748, 107, 61, 84};
  this->texture_rect_moving[7] = {875, 107, 61, 91};

  this->texture_rect_attack[0] = {593, 202, 66, 99};
  this->texture_rect_attack[1] = {701, 202, 66, 99};
  this->texture_rect_attack[2] = {830, 202, 84, 99};

  this->texture_rect_die[0] = {353, 327, 92, 72};
  this->texture_rect_die[1] = {472, 327, 92, 72};
  this->texture_rect_die[2] = {595, 327, 98, 72};
  this->texture_rect_die[3] = {710, 327, 98, 72};
  this->texture_rect_die[4] = {819, 327, 98, 72};

  this->initTexture("../strategy_game/Textures/Paladin_texture.png");
  this->initSprite(250, 780, 2, 2);
  this->silver_cost = 20;
  this->gold_cost = 0;
  this->attack_radius = 150;
  this->attack = 40;
  this->health = 3000;
}

Paladin::~Paladin() {
}
