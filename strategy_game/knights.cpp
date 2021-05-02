#include "units.hpp"
#include "stdafx.h"
#include "config_swordsman.hpp"
#include "config_paladin.hpp"

Knight::Knight() {
  unit_type = 1;
}

Knight::~Knight() {

}

SwordsMan::SwordsMan() {
  Config_swordsman config_swordsman;
  this->clock_move.restart();
  this->movementSpeed = config_swordsman.swordsman_speed;
  this->num_texture = 0;
  this->texture_rect_moving = config_swordsman.swordsman_texture_rect_moving;
  this->texture_rect_attack = config_swordsman.swordsman_texture_rect_attack;
  this->texture_rect_die = config_swordsman.swordsman_texture_rect_die;

  

  this->initTexture(config_swordsman.address_for_texture);
  this->initSprite(config_swordsman.sprite_x, config_swordsman.sprite_y, config_swordsman.scale_x, config_swordsman.scale_y);
  this->silver_cost = config_swordsman.silver_cost;
  this->gold_cost = config_swordsman.gold_cost;
  this->attack_radius = config_swordsman.attack_radius;
  this->attack = config_swordsman.attack;
  this->health = config_swordsman.health;
}

SwordsMan::~SwordsMan() {
}


Paladin::Paladin() {
  Config_paladin config_paladin;
  this->clock_move.restart();
  this->movementSpeed = config_paladin.paladin_speed;
  this->num_texture = 0;
  this->texture_rect_moving = config_paladin.paladin_texture_rect_moving;
  this->texture_rect_attack = config_paladin.paladin_texture_rect_attack;
  this->texture_rect_die = config_paladin.paladin_texture_rect_die;


  this->initTexture(config_paladin.address_for_texture);
  this->initSprite(config_paladin.sprite_x, config_paladin.sprite_y, config_paladin.scale_x, config_paladin.scale_y);
  this->silver_cost = config_paladin.silver_cost;
  this->gold_cost = config_paladin.gold_cost;
  this->attack_radius = config_paladin.attack_radius;
  this->attack = config_paladin.attack;
  this->health = config_paladin.health;
}

Paladin::~Paladin() {
}
