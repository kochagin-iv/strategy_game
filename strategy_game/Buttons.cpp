#include "Buttons.hpp"
#include "config_game_param.hpp"

Button::Button() {

}

Button::~Button() {

}

void Button::render(sf::RenderTarget &target) {
  target.draw(this->sprite);
}

void Button::initSprite(int posX, int posY, float scaleX = 1.0f, float scaleY = 1.0f) {
  // Set a texture to the sprait
  Config_button_param conf;
  this->sprite.setTexture(this->texture);
  this->sprite.setTextureRect(sf::IntRect(0, 0, conf.setTextureRect_x, conf.setTextureRect_y));
  // Set a sprite position
  this->sprite.setPosition(posX, posY);
  // Resize the Sprite
  this->sprite.scale(scaleX, scaleY);
}

void Button::initTexture(std::string file_path) {
  // Load a texture from file
  if(!this->texture.loadFromFile(file_path)) {
    std::cout << "ERROR::BUTTON::INITTEXTURE::Could not load texture file!" << "\n" << file_path << "\n";
  }
}

bool Button::check_if_click(sf::Event event, sf::RenderWindow* window) {
  sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);
  sf::Vector2f pos = window->mapPixelToCoords(pixelPos);
  if (this->sprite.getGlobalBounds().contains(pos.x, pos.y)) {
    return true;
  }
  return false;
}

void Button::onClick() {
  //this->units.push_back(new SwordsMan);
}

SwordsManButton::SwordsManButton() {
  SwordsManButton_conf conf;
  this->initTexture(conf.address_for_texture);
  this->initSprite(conf.initSprite_x, conf.initSprite_y, conf.scale_x, conf.scale_y);
  this->is_onClick = false;
  this->name = conf.name;
}


SwordsManButton::~SwordsManButton() {
}

ArcherManButton::ArcherManButton() {
  ArcherManButton_conf conf;
  this->initTexture(conf.address_for_texture);
  this->initSprite(conf.initSprite_x, conf.initSprite_y, conf.scale_x, conf.scale_y);
  this->is_onClick = false;
  this->name = conf.name;
}


ArcherManButton::~ArcherManButton() {
  
}

PhoenixButton::PhoenixButton() {
  PhoenixButton_conf conf;
  this->initTexture(conf.address_for_texture);
  this->initSprite(conf.initSprite_x, conf.initSprite_y, conf.scale_x, conf.scale_y);
  this->is_onClick = false;
  this->name = conf.name;
}


PhoenixButton::~PhoenixButton() {
}

PaladinButton::PaladinButton() {
  PaladinButton_conf conf;
  this->initTexture(conf.address_for_texture);
  this->initSprite(conf.initSprite_x, conf.initSprite_y, conf.scale_x, conf.scale_y);
  this->is_onClick = false;
  this->name = conf.name;
}


PaladinButton::~PaladinButton() {
}

TeamButton::TeamButton() {
  TeamButton_conf conf;
  this->initTexture(conf.address_for_texture);
  this->initSprite(conf.initSprite_x, conf.initSprite_y, conf.scale_x, conf.scale_y);
  this->is_onClick = false;
  this->name = conf.name;
}


TeamButton::~TeamButton() {
}