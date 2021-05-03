#include "units.hpp"
#include "stdafx.h"
#include "config_team.hpp"

Unit::Unit() {
  this->num_texture_attack = 0;
  this->num_texture = 0;
  this->num_texture_die = 0;
  this->can_move = true;
  this->already_has_target = false;
  this->in_team = false;
}

Unit::~Unit() {
  this->texture_rect_moving.clear();
  this->texture_rect_die.clear();
  this->texture_rect_attack.clear();
}

void Unit::initSprite(int posX, int posY, float scaleX = 1.0f, float scaleY = 1.0f) {
  // Set a texture to the sprait
  this->sprite.setTexture(this->texture);
  
  int new_x_texture = this->texture_rect_moving[this->num_texture][0];
  int new_y_texture = this->texture_rect_moving[this->num_texture][1];
  int new_w_texture = this->texture_rect_moving[this->num_texture][2];
  int new_h_texture = this->texture_rect_moving[this->num_texture][3];
  
  this->sprite.setTextureRect(sf::IntRect(new_x_texture, new_y_texture, new_w_texture, new_h_texture));
  
  this->num_texture++;
  
  // Set a sprite position
  // this->sprite.setPosition(250, 780);
  this->sprite.setPosition(posX, posY);
  // Resize the Sprite
  // this->sprite.scale(2.0f, 2.0f);
  this->sprite.scale(scaleX, scaleY);
}

void Unit::initTexture(std::string file_path) {
  // Load a texture from file
  
  if(!this->texture.loadFromFile(file_path)) {
    std::cout << "ERROR::UNIT::INITTEXTURE::Could not load texture file!" << "\n" << file_path << "\n";
  }
}

void Unit::update() {
  
}

void Unit::render(sf::RenderTarget &target) {
  target.draw(this->sprite);
}

void Unit::improve_attack(int new_level){
  this->attack = int(float(this->attack) * (1 + float(new_level) / 10));
}

void Unit::improve_health(int new_level) {
  this->health = int(float(this->health) * (1 + float(new_level) / 10));
}

void Unit::improve_speed(int new_level) {
  this->movementSpeed = float(this->movementSpeed) * (1 + float(new_level) / 10);
}

void Unit::move(float dirX, float dirY) {
  this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
  int new_x_texture = this->texture_rect_moving[this->num_texture][0];
  int new_y_texture = this->texture_rect_moving[this->num_texture][1];
  int new_w_texture = this->texture_rect_moving[this->num_texture][2];
  int new_h_texture = this->texture_rect_moving[this->num_texture][3];
  
  this->sprite.setTextureRect(sf::IntRect(new_x_texture, new_y_texture, new_w_texture, new_h_texture));
  
  this->num_texture++;
  num_texture %= this->texture_rect_moving.size();
}

void Unit::make_attack() {
  int new_x_texture = this->texture_rect_attack[this->num_texture_attack][0];
  int new_y_texture = this->texture_rect_attack[this->num_texture_attack][1];
  int new_w_texture = this->texture_rect_attack[this->num_texture_attack][2];
  int new_h_texture = this->texture_rect_attack[this->num_texture_attack][3];
  
  this->sprite.setTextureRect(sf::IntRect(new_x_texture, new_y_texture, new_w_texture, new_h_texture));
  
  this->num_texture_attack++;
  num_texture_attack %= this->texture_rect_attack.size();
}

void Unit::die() {
  int new_x_texture = this->texture_rect_die[this->num_texture_die][0];
  int new_y_texture = this->texture_rect_die[this->num_texture_die][1];
  int new_w_texture = this->texture_rect_die[this->num_texture_die][2];
  int new_h_texture = this->texture_rect_die[this->num_texture_die][3];
  
  this->sprite.setTextureRect(sf::IntRect(new_x_texture, new_y_texture, new_w_texture, new_h_texture));
  
  this->num_texture_die++;
  num_texture_die %= this->texture_rect_die.size();
}



void Unit::adapter_to_enemy() {
  this->enemy = 1;
  this->movementSpeed *= -1;
  this->sprite.setScale(-2, 2);
  this->sprite.setPosition(1920, this->sprite.getPosition().y);
}

Team::Team() {
  SwordsMan* swordsman = new SwordsMan;
  ArcherMan* archerman = new ArcherMan;
  Paladin* paladin = new Paladin;
  Phoenix* phoenix = new Phoenix;

  ConfigTeam conf_team;
  this->team = {swordsman, archerman, paladin, phoenix};
  this->summ_silver_cost = conf_team.summ_silver_cost;
  this->summ_health = conf_team.summ_health;
  this->summ_attack = conf_team.summ_attack;
  for (auto& unit: this->team) {
    unit->set_in_team(true);
    unit->improve_attack(1);
    unit->improve_health(1);
    unit->improve_speed(1);
  }
}

/*Team::Team(int kol_units, Unit* unit) {
  this->summ_health = kol_units * unit->health;
  this->summ_attack = kol_units * unit->attack;
  this->summ_silver_cost = kol_units * unit->silver_cost;
  for (int i = 0; i < kol_units; ++i) {
    this->team.push_back(unit);
  }
}

Team::Team(std::vector<Unit*>& units) {
  this->team = units;
  this->summ_silver_cost = 0;
  this->summ_health = 0;
  for (auto unit: this->team) {
    this->summ_silver_cost += unit->silver_cost;
    this->summ_health += unit->health;
  }
}*/

Team::~Team() {
  this->team.clear();
}

void Team::die() {
  for (auto unit: this->team) {
    unit->set_health(0);
    unit->die();
  }
}