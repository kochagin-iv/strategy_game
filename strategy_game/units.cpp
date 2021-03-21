#include "units.hpp"
#include "stdafx.h"

Unit::Unit() {
//  this->clock_move.restart();
//  this->movementSpeed = 5.f;
//  this->num_texture = 0;
//  this->texture_rect_moving.resize(10);
//  this->texture_rect_moving[0] = {27, 525, 63, 91};
//  this->texture_rect_moving[1] = {104, 525, 63, 91};
//  this->texture_rect_moving[2] = {180, 525, 69, 91};
//  this->texture_rect_moving[3] = {263, 525, 69, 91};
//  this->texture_rect_moving[4] = {346, 525, 61, 91};
//  this->texture_rect_moving[5] = {427, 525, 61, 91};
//  this->texture_rect_moving[6] = {502, 525, 61, 91};
//  this->texture_rect_moving[7] = {571, 525, 61, 91};
//  this->texture_rect_moving[8] = {642, 525, 61, 91};
//  this->texture_rect_moving[9] = {724, 525, 72, 91};
//  // this->texture_rect_moving[10] = {811, 525, 70, 91};
//  // this->texture_rect_moving[11] = {901, 525, 59, 91};
//  this->initTexture();
//  this->initSprite();
}

Unit::~Unit() {
  texture_rect_moving.clear();
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

sf::Sprite& Unit::get_sprite() {
  return sprite;
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
