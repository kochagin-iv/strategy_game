#include "units.hpp"
#include "stdafx.h"


Phoenix::Phoenix() {
  this->clock_move.restart();
  this->movementSpeed = 10.f;
  this->num_texture = 0;
  this->texture_rect_moving.resize(6);
  this->texture_rect_attack.resize(3);
  this->texture_rect_die.resize(13);
  
  this->texture_rect_moving[0] = {402, 135, 117, 117};
  this->texture_rect_moving[1] = {604, 135, 117, 117};
  this->texture_rect_moving[2] = {805, 135, 119, 117};
  this->texture_rect_moving[3] = {1005, 135, 119, 117};
  this->texture_rect_moving[4] = {1205, 135, 119, 117};
  this->texture_rect_moving[5] = {1404, 135, 129, 117};

  this->texture_rect_attack[0] = {8, 473, 166, 97};
  this->texture_rect_attack[1] = {214, 500, 136, 97};
  this->texture_rect_attack[2] = {414, 490, 136, 97};

  this->texture_rect_die[0] = {14, 942, 102, 173};
  this->texture_rect_die[1] = {209, 942, 102, 173};
  this->texture_rect_die[2] = {408, 942, 102, 173};
  this->texture_rect_die[3] = {606, 942, 102, 173};
  this->texture_rect_die[4] = {808, 942, 102, 173};
  this->texture_rect_die[5] = {1007, 942, 102, 173};
  this->texture_rect_die[6] = {1212, 942, 102, 173};
  this->texture_rect_die[7] = {1414, 942, 102, 173};
  this->texture_rect_die[8] = {14, 1137, 102, 173};
  this->texture_rect_die[9] = {209, 1137, 102, 173};
  this->texture_rect_die[10] = {408, 1137, 102, 173};
  this->texture_rect_die[11] = {606, 1137, 102, 173};
  this->texture_rect_die[12] = {808, 1137, 102, 173};

  this->initTexture("../strategy_game/Textures/phoenix_texture.png");
  this->initSprite(250, 300, 2, 2);
  this->silver_cost = 50;
  this->gold_cost = 0;
  this->unit_type = 3;
  this->attack_radius = 600;
  this->attack = 20;
  this->health = 500;

}

Phoenix::~Phoenix() {
  this->texture_rect_attack.clear();
  this->texture_rect_moving.clear();
}