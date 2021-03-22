#include "units.hpp"
#include "stdafx.h"


Phoenix::Phoenix() {
  this->clock_move.restart();
  this->movementSpeed = 10.f;
  this->num_texture = 0;
  this->texture_rect_moving.resize(6);
  this->texture_rect_moving[0] = {402, 143, 117, 69};
  this->texture_rect_moving[1] = {604, 151, 117, 117};
  this->texture_rect_moving[2] = {805, 162, 119, 95};
  this->texture_rect_moving[3] = {1005, 165, 119, 95};
  this->texture_rect_moving[4] = {1205, 170, 119, 72};
  this->texture_rect_moving[5] = {1404, 135, 129, 98};
  this->initTexture("../strategy_game/Textures/phoenix_texture.png");
  this->initSprite(250, 300, 2, 2);
}
