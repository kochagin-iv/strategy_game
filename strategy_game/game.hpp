#include "stdafx.h"
#include "units.hpp"
#include "Buttons.hpp"

class Game {
private:
  sf::RenderWindow* window;
  
  sf::Sprite spriteFon;
  sf::Texture textureFon;
  
  sf::Sprite spriteCastle;
  sf::Texture textureCastle;
  
  std::vector<Unit*> units;
  std::vector<Team*> teams;
  
  std::vector<Button*> buttons;

  int current_silver;
  int current_gold;
  
  
  void initWindow();
public:
  sf::Clock clock_create;
  Game();
  virtual ~Game();
  // Functions
  // void initUnit();
  
  // Init units
  void initSwordsMan();
  void initArcherMan();
  void initPaladin();
  void initPhoenix();
  void initTeam();

  // Init enemy
  void initSwordsManEnemy();
  void initArcherManEnemy();
  void initPaladinEnemy();
  void initPhoenixEnemy();

  void initButtons();
  void clearButtons();
  
  void delete_invisible_units();
  void update();
  void render();
  void run();
  void render(sf::RenderTarget& target);
  const sf::RenderWindow& getWindow() const;
};

