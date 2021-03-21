#include "stdafx.h"
#include "units.hpp"

class Game {
private:
  sf::RenderWindow* window;
  
  sf::Sprite spriteFon;
  sf::Texture textureFon;
  
  sf::Sprite spriteCastle;
  sf::Texture textureCastle;
  
  std::vector<Unit*> units;
  
  
  
  
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
  
  void delete_invisible_units();
  void update();
  void render();
  void run();
  void render(sf::RenderTarget& target);
  const sf::RenderWindow& getWindow() const;
};

