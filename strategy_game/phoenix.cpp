#include "units.hpp"
#include "stdafx.h"
#include "config_phoenix.hpp"

Phoenix::Phoenix() {
  Config_phoenix config_phoenix;
  this->clock_move.restart();
  this->movementSpeed = config_phoenix.phoenix_speed;
  this->num_texture = 0;
  this->texture_rect_moving = config_phoenix.phoenix_texture_rect_moving;
  this->texture_rect_attack = config_phoenix.phoenix_texture_rect_attack;
  this->texture_rect_die = config_phoenix.phoenix_texture_rect_die;
  

  this->initTexture(config_phoenix.address_for_texture);
  this->initSprite(config_phoenix.sprite_x, config_phoenix.sprite_y, config_phoenix.scale_x, config_phoenix.scale_y);
  this->silver_cost = config_phoenix.silver_cost;
  this->gold_cost = config_phoenix.gold_cost;
  this->unit_type = config_phoenix.unit_type;
  this->attack_radius = config_phoenix.attack_radius;
  this->attack = config_phoenix.attack;
  this->health = config_phoenix.health;

}

Phoenix::~Phoenix() {
  this->texture_rect_attack.clear();
  this->texture_rect_moving.clear();
}