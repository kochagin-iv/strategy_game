#include "units.hpp"
#include "stdafx.h"

SwordsMan::SwordsMan() {
  this->clock_move.restart();
  this->movementSpeed = 5.f;
  this->num_texture = 0;
  this->texture_rect_moving.resize(10);
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
  this->initTexture("/Users/ila/Desktop/strategy_game/strategy_game/Textures/swordsman_texture.png");
  this->initSprite(250, 780, 2, 2);
}

SwordsMan::~SwordsMan() {
  this->texture_rect_moving.clear();
}


Paladin::Paladin() {
  this->clock_move.restart();
  this->movementSpeed = 3.f;
  this->num_texture = 0;
  this->texture_rect_moving.resize(8);
  this->texture_rect_moving[0] = {0, 107, 56, 89};
  this->texture_rect_moving[1] = {126, 107, 56, 89};
  this->texture_rect_moving[2] = {246, 107, 56, 89};
  this->texture_rect_moving[3] = {369, 107, 56, 89};
  this->texture_rect_moving[4] = {499, 107, 56, 89};
  this->texture_rect_moving[5] = {624, 107, 64, 91};
  this->texture_rect_moving[6] = {748, 107, 61, 84};
  this->texture_rect_moving[7] = {875, 107, 61, 91};
  this->initTexture("/Users/ila/Desktop/strategy_game/strategy_game/Textures/Paladin_texture.png");
  this->initSprite(250, 780, 2, 2);
}

Paladin::~Paladin() {
  this->texture_rect_moving.clear();
}
