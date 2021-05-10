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
  std::vector<Button*> initButtons();
};

class CreationWarriors: public AbstractCreationFactory {
  SwordsManFriend* initSwordsMan() override;
  ArcherManFriend* initArcherMan() override;
  PaladinFriend* initPaladin() override;
  PhoenixFriend* initPhoenix() override;
};

class CreationEnemyWarriors: public AbstractCreationFactory {
  SwordsManEnemy* initSwordsMan() override;
  ArcherManEnemy* initArcherMan() override;
  PaladinEnemy* initPaladin() override;
  PhoenixEnemy* initPhoenix() override;
};