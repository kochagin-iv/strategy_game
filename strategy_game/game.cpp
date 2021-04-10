#include "game.hpp"
#include "stdafx.h"

Game::Game() {
  this->initWindow();
  // this->initUnit();
  current_silver = 100;
  current_gold = 100;
  this->clock_create.restart();
}

Game::~Game() {
  delete this->window;
  buttons.clear();
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

void Game::initSwordsManEnemy() {
  SwordsMan* swordsman = new SwordsMan;
  swordsman->adapter_to_enemy();
  this->units.push_back(swordsman);
}

void Game::initArcherManEnemy() {
  ArcherMan* archerman = new ArcherMan;
  archerman->adapter_to_enemy();
  this->units.push_back(archerman);
}

void Game::initPaladinEnemy() {
  Paladin* paladin = new Paladin;
  paladin->adapter_to_enemy();
  this->units.push_back(paladin);
}

void Game::initPhoenixEnemy() {
  Phoenix* phoenix = new Phoenix;
  phoenix->adapter_to_enemy();
  this->units.push_back(phoenix);
}

void Game::initTeam() {
  Team* team = new Team();
  for (auto unit: team->team) {
    this->units.push_back(unit);
  }
  teams.push_back(team);
}

void Game::initButtons() {
  this->buttons.push_back(new SwordsManButton);
  this->buttons.push_back(new ArcherManButton);
  this->buttons.push_back(new PhoenixButton);
  this->buttons.push_back(new PaladinButton);
  this->buttons.push_back(new TeamButton);
}

void Game::clearButtons() {
  this->buttons.clear();
}

void Game::run() {
  while(this->window->isOpen()) {
    this->window->setKeyRepeatEnabled (false);
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
    if (unit->get_sprite().getPosition().x < 0) {
      iterators_for_delete.push_back(iter);
    }
    if (unit->health <= 0 && unit->num_texture_die == 0) {
      this->current_silver += 10;
      iterators_for_delete.push_back(iter);
    }
    ++iter;
  }
  for (auto iterator: iterators_for_delete) {
    units.erase(units.begin() + iterator);
  }
  iterators_for_delete.clear();
  iter = 0;
}

void find_and_attack_enemy(Unit* hero, std::vector<Unit*>& units) {
  int min_dist_to_other_unit = INT_MAX;
  int hero_x = hero->sprite.getPosition().x;
  int hero_y = hero->sprite.getPosition().y;
  int idx_for_attack = -1;
  int i = 0;
  for (auto unit: units) {
    if (unit->health <= 0) {
      ++i;
      continue;
    }
    if (unit->unit_type == 3 && hero->unit_type == 1) {
      ++i;
      continue;
    }
    if(unit->sprite.getPosition() == hero->sprite.getPosition()) {
      ++i;
      continue;
    }
    if (unit->enemy == hero->enemy) {
      ++i;
      continue;
    }
    int unit_x = unit->sprite.getPosition().x;
    int unit_y = unit->sprite.getPosition().y;
    if (hero->enemy) {
      unit_x += unit->sprite.getTextureRect().width;
    }
    else {
      hero_x += hero->sprite.getTextureRect().width;
    }
    double dist = sqrt((unit_x - hero_x) * (unit_x - hero_x) + (unit_y - hero_y) * (unit_y - hero_y));
    //std::cout << "hero " << hero_x << "\n";
    //std::cout << "unit " << unit_x << "\n";
    if (!hero->enemy && hero_x >= unit_x) {
      ++i;
      continue;
    }
    if (hero->enemy && hero_x <= unit_x) {
      ++i;
      continue;
    }
    if (dist <= hero->attack_radius && dist <= min_dist_to_other_unit) {
      min_dist_to_other_unit = dist;
      idx_for_attack = i;
    }
    ++i;
  }
  std::cout << idx_for_attack << " " << units.size() << "\n";
  if (idx_for_attack == -1 || min_dist_to_other_unit == INT_MAX) {
    hero->can_move = true;
    return;
  }
  hero->can_move = false;
  hero->make_attack();
  units[idx_for_attack]->health -= hero->attack;
  if (!units[idx_for_attack]->in_team) {
    units[idx_for_attack]->health -= hero->attack;
    if (units[idx_for_attack]->health <= 0) {
      units[idx_for_attack]->die();
    }
  }
}

void Game::update () {
  sf::Event e;
  while (this->window->pollEvent(e)) {
    switch (e.type) {
      case sf::Event::Closed: {
        this->window->close();
        break;
      };
      case sf::Event::MouseButtonPressed: {
        // std::cout << buttons.size() << "\n";
        if (e.mouseButton.button == sf::Mouse::Left) {
          for (auto button: buttons) {
            if (button->check_if_click(e, this->window)) {
              SwordsMan a = *(new SwordsMan);
              if (this->current_silver >= a.silver_cost && 
               button->name == "SwordsManButton") {
                this->initSwordsMan();
                this->current_silver -= a.silver_cost;
              }
              ArcherMan b = *(new ArcherMan);
              if (this->current_silver >= b.silver_cost && 
               button->name == "ArcherManButton") {
                this->initArcherMan();
                this->current_silver -= b.silver_cost;
              }
              Phoenix c = *(new Phoenix);
              if (this->current_silver >= c.silver_cost && 
               button->name == "PhoenixButton") {
                this->initPhoenix();
                this->current_silver -= c.silver_cost;
              }
              Paladin d = *(new Paladin);
              if (this->current_silver >= d.silver_cost && 
               button->name == "PaladinButton") {
                this->initPaladin();
                this->current_silver -= d.silver_cost;
              }
              Team e = *(new Team);
              if (this->current_silver >= e.summ_silver_cost && 
               button->name == "TeamButton") {
                this->initTeam();
                this->current_silver -= e.summ_silver_cost;
              }
            }
          }
        }
      } break;
      default:
        break;
    };
    
    
  }
  
  for (auto unit: units) {
    if (unit->health <= 0) {
      unit->die();
      delete_invisible_units();
      continue;
    }
    // Move Unit
    float time_move = unit->clock_move.getElapsedTime().asMilliseconds();
    
    if (time_move > 30) {
      // std::cout << "move:" << time_move << " " << units.size() << "\n";
      if (unit->can_move) {
        unit->move(1.f, 0.f);
      }
      find_and_attack_enemy(unit, units);
      //unit->make_attack();
      // std::cout << unit->sprite.getPosition().x << " " <<  unit->sprite.getPosition().y << "\n";
      unit->clock_move.restart();
    }
    for (auto team: teams) {
      for (auto unit: team->team) {
        if (unit->health <= 0) {
          if (team->summ_health >= abs(unit->health) + 1) {
            team->summ_health -= (abs(unit->health) + 1);
            unit->health += abs(unit->health) + 1;
            std::cout << "unit " << unit->health << " team " << team->summ_health << "\n";
          }
          else {
            unit->die();
          }
        }
      }
    }
    int summ_health = 0;
    for (auto team: teams) {
      summ_health = team->summ_health;
      for (auto unit: team->team) {
        summ_health += unit->health;
      }
      if (summ_health <= 0) {
        team->team.clear();
      }
    }
  }
  // delete_invisible_units();

  float time_create = clock_create.getElapsedTime().asMilliseconds();
  
  if (time_create > 2000) {
    // std::cout << "create: " << time_create << "\n";
    //this->initTeam();
    int id = rand() % 4;
    if (id == 0) {
      this->initSwordsManEnemy();
    }
    if (id == 1) {
      this->initArcherManEnemy();
    }
    if (id == 2) {
      this->initPaladinEnemy();
    }
    if (id == 3) {
      this->initPhoenixEnemy();
    }
    this->clock_create.restart();
  }
}

void Game::render(sf::RenderTarget &target) {
  if(!this->textureFon.loadFromFile("../strategy_game/Textures/fone.png")) {
    std::cout << "ERROR::FONE::INITTEXTURE::Could not load texture file!" << "\n";
    exit(0);
  }
  this->spriteFon.setTexture(this->textureFon);
  this->window->draw(spriteFon);
  
  if(!this->textureCastle.loadFromFile("../strategy_game/Textures/castle.png")) {
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
  this->clearButtons();
  this->initButtons();
  for (auto button: buttons) {
    button->render(*this->window);
  }
  sf::Font font;
  font.loadFromFile("../strategy_game/Fonts/CyrilicOld.ttf");
  sf::Text text("MONEY: " + std::to_string(this->current_silver), font, 40);
  text.setColor(sf::Color::Yellow);
  text.setStyle(sf::Text::Bold | sf::Text::Underlined);
  text.setPosition(100, 100);
  this->window->draw(text);
  this->window->display();
}