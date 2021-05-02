#pragma once
#include "stdafx.h"
#include "units.hpp"
#include "Buttons.hpp"


class AbstractCreationFactory {
private:

public:
  virtual SwordsMan* initSwordsMan() {};
  virtual ArcherMan* initArcherMan() {};
  virtual Paladin* initPaladin() {};
  virtual Phoenix* initPhoenix() {};
  virtual SwordsMan* initSwordsManEnemy() {};
  virtual ArcherMan* initArcherManEnemy() {};
  virtual Paladin* initPaladinEnemy() {};
  virtual Phoenix* initPhoenixEnemy() {};
  virtual Team* initTeam() {};
  virtual std::vector<Button*> initButtons() {};
};

class CreationWarriors: public AbstractCreationFactory {
  virtual SwordsMan* initSwordsMan();
  virtual ArcherMan* initArcherMan();
  virtual Paladin* initPaladin();
  virtual Phoenix* initPhoenix();
  virtual Team* initTeam();

};

class CreationEnemyWarriors: public AbstractCreationFactory {
  virtual SwordsMan* initSwordsManEnemy();
  virtual ArcherMan* initArcherManEnemy();
  virtual Paladin* initPaladinEnemy();
  virtual Phoenix* initPhoenixEnemy();
};

class CreationButtons: public AbstractCreationFactory {
  virtual std::vector<Button*> initButtons();
};