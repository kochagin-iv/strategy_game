#include "units.hpp"
#include "stdafx.h"
#include "config_archer.hpp"


ArcherMan::ArcherMan() {
  ConfigArcher config_archer;
  this->clock_move.restart();
  this->movementSpeed = config_archer.archer_speed;
  this->num_texture = 0;
  this->texture_rect_moving = config_archer.archer_texture_rect_moving;
  this->texture_rect_attack = config_archer.archer_texture_rect_attack;
  this->texture_rect_die = config_archer.archer_texture_rect_die;
  
  this->initTexture(config_archer.address_for_texture);
  this->initSprite(config_archer.sprite_x, config_archer.sprite_y, config_archer.scale_x, config_archer.scale_y);
  this->silver_cost = config_archer.silver_cost;
  this->gold_cost = config_archer.gold_cost;
  this->attack_radius = config_archer.attack_radius;
  this->attack = config_archer.attack;
  this->unit_type = config_archer.unit_type;
  this->health = config_archer.health;

}

ArcherMan::~ArcherMan() {
  this->texture_rect_moving.clear();
  this->texture_rect_attack.clear();
}

ArcherManEnemy::ArcherManEnemy() {
  this->adapter_to_enemy();
}