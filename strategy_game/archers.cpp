#include "units.hpp"
#include "stdafx.h"

ArcherMan::ArcherMan() {
  this->clock_move.restart();
  this->movementSpeed = 10.f;
  this->num_texture = 0;
  this->texture_rect_moving.resize(8);
  this->texture_rect_attack.resize(8);
  this->texture_rect_die.resize(5);
  this->texture_rect_moving[0] = {68, 785, 56, 83};
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
  this->texture_rect_attack[0] = {9, 255, 48, 109};
  this->texture_rect_attack[1] = {78, 255, 48, 109};
  this->texture_rect_attack[2] = {151, 255, 50, 109};
  this->texture_rect_attack[3] = {222, 255, 50, 109};
  this->texture_rect_attack[4] = {290, 255, 64, 109};
  this->texture_rect_attack[5] = {383, 255, 67, 109};
  this->texture_rect_attack[6] = {478, 255, 67, 109};
  this->texture_rect_attack[7] = {572, 255, 64, 109};

  this->texture_rect_die[0] = {471, 884, 95, 92};
  this->texture_rect_die[1] = {570, 884, 95, 92};
  this->texture_rect_die[2] = {674, 884, 67, 92};
  this->texture_rect_die[3] = {742, 884, 67, 92};
  this->texture_rect_die[4] = {810, 884, 67, 92};
  
  this->initTexture("../strategy_game/Textures/archerman_texture.png");
  this->initSprite(250, 780, 2, 2);
  this->silver_cost = 15;
  this->gold_cost = 0;
  this->attack_radius = 800;
  this->attack = 40;
  this->unit_type = 2;
  this->health = 100;

}

ArcherMan::~ArcherMan() {
  this->texture_rect_moving.clear();
  this->texture_rect_attack.clear();
}
