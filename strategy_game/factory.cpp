#include "factory.hpp"
#include "units.hpp"


SwordsMan* CreationWarriors::initSwordsMan() {
    return new SwordsMan;
    //this->units.push_back();
}

ArcherMan* CreationWarriors::initArcherMan() {
    return new ArcherMan;
  //this->units.push_back(new ArcherMan);
}

Paladin* CreationWarriors::initPaladin() {
  return new Paladin;
}

Phoenix* CreationWarriors::initPhoenix() {
  return new Phoenix;
}

SwordsMan* CreationEnemyWarriors::initSwordsMan() {
  SwordsMan* swordsman = new SwordsMan;
  swordsman->adapter_to_enemy();
  return swordsman;
  //this->units.push_back(swordsman);
}

ArcherMan* CreationEnemyWarriors::initArcherMan() {
  ArcherMan* archerman = new ArcherMan;
  archerman->adapter_to_enemy();
  return archerman;
  //this->units.push_back(archerman);
}

Paladin* CreationEnemyWarriors::initPaladin() {
  Paladin* paladin = new Paladin;
  paladin->adapter_to_enemy();
  return paladin;
  //this->units.push_back(paladin);
}

Phoenix* CreationEnemyWarriors::initPhoenix() {
  Phoenix* phoenix = new Phoenix;
  phoenix->adapter_to_enemy();
  return phoenix;
  //this->units.push_back(phoenix);
}

Team* AbstractCreationFactory::initTeam() {
  Team* team = new Team();
  for (auto unit: team->team) {
    team->team.push_back(unit);
  }
  return team;
  //teams.push_back(team);
}

std::vector<Button*> AbstractCreationFactory::initButtons() {
    std::vector<Button*> new_butt;
    new_butt.push_back(new SwordsManButton);
    new_butt.push_back(new ArcherManButton);
    new_butt.push_back(new PhoenixButton);
    new_butt.push_back(new PaladinButton);
    new_butt.push_back(new TeamButton);
    return new_butt;
}