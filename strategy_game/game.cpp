#include "game.hpp"
#include "stdafx.h"
#include "factory.hpp"
#include "config_game_param.hpp"

Game::Game() {
  this->initWindow();
  // this->initUnit();
  ConfigGameParam conf;
  current_silver = conf.current_silver;
  current_gold = conf.current_gold;
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
  ConfigGameParam conf;
  this->window = new sf::RenderWindow(sf::VideoMode(conf.window_size_x, conf.window_size_y),  "Strategy game", sf::Style::Close | sf::Style::Titlebar);
  this->window->setVerticalSyncEnabled(false);
  
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
    if (unit->get_sprite().getPosition().x > this->window->Window::getSize().x + 100) {
      iterators_for_delete.push_back(iter);
    }
    if (unit->get_sprite().getPosition().x < -100) {
      iterators_for_delete.push_back(iter);
    }
    if (unit->get_health() <= 0 && unit->get_num_texture_die() == 0) {
      this->current_silver += std::min(unit->get_attack(), 10);
      iterators_for_delete.push_back(iter);
    }
    ++iter;
  }
  for (auto iterator: iterators_for_delete) {
    units.erase(units.begin() + iterator);
  }

  iterators_for_delete.clear();
  for (auto tm: teams) {
    iter = 0;
    for (auto unit: tm->team) {
      bool fl = 0;
      for (auto addr: units) {
        if (unit == addr) {
          fl = 1;
          break;
        }
      }
      if (!fl) {
        ++iter;
        continue;
      }
      if (unit->get_sprite().getPosition().x > this->window->Window::getSize().x) {
        iterators_for_delete.push_back(iter);
      }
      if (unit->get_sprite().getPosition().x < 0) {
        iterators_for_delete.push_back(iter);
      }
      if (unit->get_health() <= 0 && unit->get_num_texture_die() == 0) {
        this->current_silver += 10;
        iterators_for_delete.push_back(iter);
      }
      ++iter;
    }
    for (auto iterator: iterators_for_delete) {
      tm->team.erase(tm->team.begin() + iterator);
    }
    iterators_for_delete.clear();
  }
  
  
}

void find_and_attack_enemy(Unit* hero, std::vector<Unit*>& units) {
  int min_dist_to_other_unit = INT_MAX;
  int hero_x = hero->get_sprite().getPosition().x;
  int hero_y = hero->get_sprite().getPosition().y;
  int idx_for_attack = -1;
  int i = 0;
  for (auto unit: units) {
    if (unit->get_health() <= 0) {
      ++i;
      continue;
    }
    if (unit->get_unit_type() == 3 && hero->get_unit_type() == 1) {
      ++i;
      continue;
    }
    if(unit->get_sprite().getPosition() == hero->get_sprite().getPosition()) {
      ++i;
      continue;
    }
    if (unit->get_enemy() == hero->get_enemy()) {
      ++i;
      continue;
    }
    int unit_x = unit->get_sprite().getPosition().x;
    int unit_y = unit->get_sprite().getPosition().y;
    if (hero->get_enemy()) {
      unit_x += unit->get_sprite().getTextureRect().width;
    }
    else {
      hero_x += hero->get_sprite().getTextureRect().width;
    }
    double dist = sqrt((unit_x - hero_x) * (unit_x - hero_x) + (unit_y - hero_y) * (unit_y - hero_y));
    //std::cout << "hero " << hero_x << "\n";
    //std::cout << "unit " << unit_x << "\n";
    if (!hero->get_enemy() && hero_x >= unit_x) {
      ++i;
      continue;
    }
    if (hero->get_enemy() && hero_x <= unit_x) {
      ++i;
      continue;
    }
    if (dist <= hero->get_attack_radius() && dist <= min_dist_to_other_unit) {
      min_dist_to_other_unit = dist;
      idx_for_attack = i;
    }
    ++i;
  }
  //std::cout << idx_for_attack << " " << units.size() << "\n";
  if (idx_for_attack == -1 || min_dist_to_other_unit == INT_MAX) {
    hero->set_can_move(true);
    return;
  }
  hero->set_can_move(false);
  hero->make_attack();
  units[idx_for_attack]->set_health(units[idx_for_attack]->get_health() - hero->get_attack());
  //units[idx_for_attack]->health -= hero->attack;
  if (!units[idx_for_attack]->get_in_team()) {
    units[idx_for_attack]->set_health(units[idx_for_attack]->get_health() - hero->get_attack());
    if (units[idx_for_attack]->get_health() <= 0) {
      units[idx_for_attack]->die();
    }
  }
}

void Game::update () {
  AbstractCreationFactory* fact_war = new CreationWarriors;
  AbstractCreationFactory* fact_enemy_war = new CreationEnemyWarriors;
  
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
              if (this->current_silver >= a.get_silver_cost() && 
               button->name == "SwordsManButton") {
                this->units.push_back(fact_war->initSwordsMan());
                this->current_silver -= a.get_silver_cost();
              }
              ArcherMan b = *(new ArcherMan);
              if (this->current_silver >= b.get_silver_cost() && 
               button->name == "ArcherManButton") {
                this->units.push_back(fact_war->initArcherMan());
                this->current_silver -= b.get_silver_cost();
              }
              Phoenix c = *(new Phoenix);
              if (this->current_silver >= c.get_silver_cost() && 
               button->name == "PhoenixButton") {
                this->units.push_back(fact_war->initPhoenix());
                this->current_silver -= c.get_silver_cost();
              }
              Paladin d = *(new Paladin);
              if (this->current_silver >= d.get_silver_cost() && 
               button->name == "PaladinButton") {
                this->units.push_back(fact_war->initPaladin());
                this->current_silver -= d.get_silver_cost();
              }
              Team e = *(new Team);
              if (this->current_silver >= e.summ_silver_cost && 
               button->name == "TeamButton") {
                this->teams.push_back(fact_war->initTeam());
                for (auto uit: this->teams.back()->team) {
                  this->units.push_back(uit);
                }
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
    if (unit->get_health() <= 0) {
      unit->die();
      delete_invisible_units();
      continue;
    }
    // Move Unit
    float time_move = unit->get_clock_move().getElapsedTime().asMilliseconds();
    
    if (time_move > 30) {
      // std::cout << "move:" << time_move << " " << units.size() << "\n";
      if (unit->get_can_move()) {
        unit->move(1.f, 0.f);
      }
      find_and_attack_enemy(unit, units);
      //unit->make_attack();
      // std::cout << unit->sprite.getPosition().x << " " <<  unit->sprite.getPosition().y << "\n";
      unit->get_clock_move().restart();
    }
    for (auto team: teams) {
      for (auto unit: team->team) {
        if (unit->get_health() <= 0) {
          if (team->summ_health >= abs(unit->get_health()) + 1) {
            team->summ_health -= (abs(unit->get_health()) + 1);
            unit->set_health(unit->get_health() + abs(unit->get_health()) + 1);
            //unit->health += abs(unit->get_health()) + 1;
            //std::cout << "unit " << unit->health << " team " << team->summ_health << "\n";
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
        summ_health += unit->get_health();
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
      this->units.push_back(fact_enemy_war->initSwordsMan());
    }
    if (id == 1) {
      this->units.push_back(fact_enemy_war->initArcherMan());
    }
    if (id == 2) {
      this->units.push_back(fact_enemy_war->initPaladin());
    }
    if (id == 3) {
      this->units.push_back(fact_enemy_war->initPhoenix());
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
  AbstractCreationFactory* fact_butt = new CreationWarriors;
  for (auto button: fact_butt->initButtons()) {
    this->buttons.push_back(button);
  }
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