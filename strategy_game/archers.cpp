#include "units.hpp"
#include "stdafx.h"

ArcherMan::ArcherMan() {
  this->clock_move.restart();
  this->movementSpeed = 10.f;
  this->num_texture = 0;
  this->texture_rect_moving.resize(8);
  // this->texture_rect_moving[0] = {16, 784, 41, 83};
  this->texture_rect_moving[0] = {68, 784, 56, 83};
  this->texture_rect_moving[1] = {135, 785, 67, 83};
  this->texture_rect_moving[2] = {209, 785, 67, 83};
  this->texture_rect_moving[3] = {290, 785, 61, 83};
  this->texture_rect_moving[4] = {365, 785, 54, 83};
  this->texture_rect_moving[5] = {435, 785, 54, 83};
  this->texture_rect_moving[6] = {507, 785, 60, 83};
  this->texture_rect_moving[7] = {573, 785, 60, 83};
  // this->texture_rect_moving[9] = {645, 785, 65, 83};
  // this->texture_rect_moving[8] = {724, 785, 70, 83};
  // this->texture_rect_moving[9] = {802, 785, 55, 83};
  this->initTexture("../strategy_game/Textures/archerman_texture.png");
  this->initSprite(250, 780, 2, 2);
}

ArcherMan::~ArcherMan() {
  this->texture_rect_moving.clear();
}
