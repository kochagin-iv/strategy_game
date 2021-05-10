#include "factory.hpp"
#include "units.hpp"


SwordsManFriend* CreationWarriors::initSwordsMan() {
    return new SwordsManFriend();
    //this->units.push_back();
}

ArcherManFriend* CreationWarriors::initArcherMan() {
    return new ArcherManFriend();
  //this->units.push_back(new ArcherMan);
}

PaladinFriend* CreationWarriors::initPaladin() {
  return new PaladinFriend();
}

PhoenixFriend* CreationWarriors::initPhoenix() {
  return new PhoenixFriend();
}

SwordsManEnemy* CreationEnemyWarriors::initSwordsMan() {
  return new SwordsManEnemy();
  //this->units.push_back(swordsman);
}

ArcherManEnemy* CreationEnemyWarriors::initArcherMan() {
  return new ArcherManEnemy();
  //this->units.push_back(archerman);
}

PaladinEnemy* CreationEnemyWarriors::initPaladin() {
  return new PaladinEnemy();
  //this->units.push_back(paladin);
}

PhoenixEnemy* CreationEnemyWarriors::initPhoenix() {
  return new PhoenixEnemy();
  //this->units.push_back(phoenix);
}

std::vector<Button*> AbstractCreationFactory::initButtons() {
    std::vector<Button*> new_butt;
    new_butt.push_back(new SwordsManButton);
    new_butt.push_back(new ArcherManButton);
    new_butt.push_back(new PhoenixButton);
    new_butt.push_back(new PaladinButton);
    new_butt.push_back(new TeamButton);
    new_butt.push_back(new DangerButton);
    return new_butt;
}