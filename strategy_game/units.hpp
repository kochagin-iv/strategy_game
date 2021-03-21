#pragma once
#include "stdafx.h"

class Unit {
protected:
  int health;
  int attack;
  float movementSpeed;
  int gold_cost;
  int silver_cost;
  float posX, posY;
  int num_texture;
  //------bool enemy;
  std::vector<std::vector<int> > texture_rect_moving;
  sf::Sprite sprite;
  sf::Texture texture;
  
  void initTexture(std::string file_path);
  void initSprite(int posX, int posY, float scaleX, float scaleY);
  
public:
  sf::Clock clock_move;
  
  Unit();
  ~Unit();
  void improve_attack(int new_level);
  
  void improve_health(int new_level);
  
  void improve_speed(int new_level);
  
  void move(float dirX, float dirY);
  
  void update();
  
  void render(sf::RenderTarget& target);
  
  sf::Sprite& get_sprite();
};


// Knight class

class Knight: public Unit {
private:
  
public:

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
