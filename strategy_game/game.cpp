#include "game.hpp"
#include "stdafx.h"

Game::Game() {
  this->initWindow();
  // this->initUnit();
  this->clock_create.restart();
}

Game::~Game() {
  delete this->window;
  for (auto unit: units) {
    delete unit;
  }
}

void Game::initWindow() {
  this->window = new sf::RenderWindow(sf::VideoMode(1920, 1067),  "Strategy game", sf::Style::Close | sf::Style::Titlebar);
  this->window->setVerticalSyncEnabled(false);
  
}

//void Game::initUnit() {
//  this->units.push_back(new Unit);
//}

void Game::initSwordsMan() {
  this->units.push_back(new SwordsMan);
}

void Game::initArcherMan() {
  this->units.push_back(new ArcherMan);
}

void Game::initPaladin() {
  this->units.push_back(new Paladin);
}

void Game::initPhoenix() {
  this->units.push_back(new Phoenix);
}

void Game::run() {
  while(this->window->isOpen()) {
    this->update();
    this->render();
  }
}

void Game::delete_invisible_units() {
  std::vector<int> iterators_for_delete;
  int iter = 0;
  for (auto unit: units) {
    if (unit->get_sprite().getPosition().x > this->window->Window::getSize().x) {
      iterators_for_delete.push_back(iter);
    }
    ++iter;
  }
  for (auto iterator: iterators_for_delete) {
    units.erase(units.begin() + iterator);
  }
}

void Game::update () {
  sf::Event e;
  while (this->window->pollEvent(e)) {
    if (e.Event::type == sf::Event::Closed) {
      this->window->close();
    }
  }
  
  
  for (auto unit: units) {
    // Move Unit
    float time_move = unit->clock_move.getElapsedTime().asMilliseconds();
    
    if (time_move > 30) {
      std::cout << "move:" << time_move << " " << units.size() << "\n";
      unit->move(1.f, 0.f);
      unit->clock_move.restart();
    }
    
    delete_invisible_units();
//    if (unit->get_sprite().getPosition().x > 1067) {
//      delete unit;
//    }
  }
  // Create Unit
  float time_create = clock_create.getElapsedTime().asMilliseconds();
  
  if (time_create > 10000) {
    std::cout << "create: " << time_create << "\n";
    this->initSwordsMan();
    this->initArcherMan();
    this->initPaladin();
    this->initPhoenix();
    this->clock_create.restart();
  }
  
  /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    this->unit->move(-1.f, 0.f);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    this->unit->move(1.f, 0.f);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    this->unit->move(0.f, -1.f);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    this->unit->move(0.f, 1.f);
  }*/
}

void Game::render(sf::RenderTarget &target) {
  if(!this->textureFon.loadFromFile("/Users/ila/Desktop/strategy_game/strategy_game/Textures/fone.png")) {
    std::cout << "ERROR::FONE::INITTEXTURE::Could not load texture file!" << "\n";
    exit(0);
  }
  this->spriteFon.setTexture(this->textureFon);
  this->window->draw(spriteFon);
  
  if(!this->textureCastle.loadFromFile("/Users/ila/Desktop/strategy_game/strategy_game/Textures/castle.png")) {
    std::cout << "ERROR::CASTLE::INITTEXTURE::Could not load texture file!" << "\n";
  }
  this->spriteCastle.setTexture(this->textureCastle);
  spriteCastle.setPosition(0, 220);
  this->window->draw(spriteFon);
  this->window->draw(spriteCastle);

}

void Game::render() {
  this->window->clear();
  
  //Draw all the stuffs
  this->render(*this->window);
  for (auto unit: units) {
    unit->render(*this->window);
  }
  
  
  this->window->display();
}
