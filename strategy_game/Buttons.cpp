#include "Buttons.hpp"

Button::Button() {

}

Button::~Button() {

}

void Button::render(sf::RenderTarget &target) {
  target.draw(this->sprite);
}

void Button::initSprite(int posX, int posY, float scaleX = 1.0f, float scaleY = 1.0f) {
  // Set a texture to the sprait
  this->sprite.setTexture(this->texture);
  this->sprite.setTextureRect(sf::IntRect(0, 0, 600, 600));
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
  this->initTexture("../strategy_game/Textures/Buttons/SwordsManButton.png");
  this->initSprite(500, 920, 0.25, 0.25);
  this->is_onClick = false;
  this->name = "SwordsManButton";
}


SwordsManButton::~SwordsManButton() {
}

ArcherManButton::ArcherManButton() {
  this->initTexture("../strategy_game/Textures/Buttons/ArcherManButton.png");
  this->initSprite(700, 920, 0.25, 0.25);
  this->is_onClick = false;
  this->name = "ArcherManButton";
}


ArcherManButton::~ArcherManButton() {
  
}

PhoenixButton::PhoenixButton() {
  this->initTexture("../strategy_game/Textures/Buttons/PhoenixButton.png");
  this->initSprite(900, 920, 0.25, 0.25);
  this->is_onClick = false;
  this->name = "PhoenixButton";
}


PhoenixButton::~PhoenixButton() {
}

PaladinButton::PaladinButton() {
  this->initTexture("../strategy_game/Textures/Buttons/PaladinButton.png");
  this->initSprite(300, 920, 0.25, 0.25);
  this->is_onClick = false;
  this->name = "PaladinButton";
}


PaladinButton::~PaladinButton() {
}

TeamButton::TeamButton() {
  this->initTexture("../strategy_game/Textures/Buttons/TeamButton.png");
  this->initSprite(100, 920, 0.25, 0.25);
  this->is_onClick = false;
  this->name = "TeamButton";
}


TeamButton::~TeamButton() {
}