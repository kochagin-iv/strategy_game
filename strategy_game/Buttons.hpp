#include "stdafx.h"

class Button
{
private:
    /* data */
public:
    sf::Sprite sprite;
    sf::Texture texture;
    bool is_onClick;
  
    Button();
    ~Button();
    bool check_if_click(sf::Event, sf::RenderWindow*);
    void onClick();
    std::string name;
    void render(sf::RenderTarget& target);
    void update();
    void initTexture(std::string file_path);
    void initSprite(int posX, int posY, float scaleX, float scaleY);
};

class UnitButton: public Button {

};

class SwordsManButton: public UnitButton {
public: 
    SwordsManButton();
    ~SwordsManButton();
  
  void onClick();
  // void initSwordsManButton(std::vector<Button*>& buttons);
};

class ArcherManButton: public UnitButton {
public: 
    ArcherManButton();
    ~ArcherManButton();
  
  void onClick();
  // void initArcherManButton(std::vector<Button*>& buttons);
};

class PhoenixButton: public UnitButton {
public: 
    PhoenixButton();
    ~PhoenixButton();
  
  void onClick();
  // void initArcherManButton(std::vector<Button*>& buttons);
};

class PaladinButton: public UnitButton {
public: 
    PaladinButton();
    ~PaladinButton();
  
  void onClick();
  // void initArcherManButton(std::vector<Button*>& buttons);
};

class TeamButton: public UnitButton {
public:
    TeamButton();
    ~TeamButton();
    void onClick();
};