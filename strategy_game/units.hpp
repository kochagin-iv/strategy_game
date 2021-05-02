#pragma once

#include "stdafx.h"

class Unit {
protected:
  
  std::vector<std::vector<int> > texture_rect_moving, 
  texture_rect_die, texture_rect_attack;
  sf::Sprite sprite;
  sf::Texture texture;
  bool in_team;  
  void initTexture(std::string file_path);
  void initSprite(int posX, int posY, float scaleX, float scaleY);
  int unit_type;
  int health;
  int attack;
  int attack_radius;
  float movementSpeed;
  
  float posX, posY;
  int num_texture;
  int num_texture_attack;
  int num_texture_die;
  bool can_move;
  bool already_has_target;
  
  bool enemy = false;
  int gold_cost;
  int silver_cost;
  sf::Clock clock_move;
  
public:

  Unit();
  ~Unit();
  void improve_attack(int new_level);
  
  void improve_health(int new_level);
  
  void improve_speed(int new_level);
  
  void move(float dirX, float dirY);
  void make_attack();
  void die();
  
  void update();
  
  void render(sf::RenderTarget& target);
  void adapter_to_enemy();
  //sf::Sprite& get_sprite();
  auto& get_health() {
    return health;
  }
  auto& get_num_texture_die() {
    return num_texture_die;
  }
  auto& get_sprite() {
    return sprite;
  }
  auto& get_unit_type() {
    return unit_type;
  }
  auto& get_enemy() {
    return enemy;
  }
  auto& get_attack_radius() {
    return attack_radius;
  }
  auto& get_attack() {
    return attack;
  }
  auto& get_in_team() {
    return in_team;
  }
  auto& get_silver_cost() {
    return silver_cost;
  }
  auto& get_clock_move() {
    return clock_move;
  }
  auto& get_can_move() {
    return can_move;
  }
  void set_can_move(bool pos) {
    can_move = pos;
  }
  void set_health(int hlth) {
    health = hlth;
  }
  void set_in_team(bool flag) {
    in_team = flag;
  }
};


// Knight class

class Knight: public Unit {
private:
  
public:
  Knight();
  ~Knight();
};

class SwordsMan: public Knight {
private:
  
  
public:
  SwordsMan();
  ~SwordsMan();
  
  void initSwordsMan(std::vector<Unit*>& units);

};

// Paladin class

class Paladin: public Knight {
  
public:
  Paladin();
  ~Paladin();
  
  void initPaladin();

};

// Archers class

class Archers: public Unit {
private:
  
public:

};

class ArcherMan: public Archers {
private:
  
  
public:
  ArcherMan();
  ~ArcherMan();
  
  void initArcerMan(std::vector<Unit*>& units);

};

class Phoenix: public Unit {
private:
  
public:
  Phoenix();
  ~Phoenix();
  
  void initPhoenix(std::vector<Unit*>& units);
};


class Team{
private:

public:
  int summ_silver_cost;
  int summ_health;
  int summ_attack;
  std::vector<Unit*> team;
  Team();
  // Team(int, Unit*);
  // Team(std::vector<Unit*>&);
  ~Team();
  void die();
};
