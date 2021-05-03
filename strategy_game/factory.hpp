#pragma once
#include "stdafx.h"
#include "units.hpp"
#include "Buttons.hpp"


class AbstractCreationFactory {
private:

public:
  virtual SwordsMan* initSwordsMan() = 0;
  virtual ArcherMan* initArcherMan() = 0;
  virtual Paladin* initPaladin() = 0;
  virtual Phoenix* initPhoenix() = 0;
  Team* initTeam();
  std::vector<Button*> initButtons();
};

class CreationWarriors: public AbstractCreationFactory {
  SwordsMan* initSwordsMan() override;
  ArcherMan* initArcherMan() override;
  Paladin* initPaladin() override;
  Phoenix* initPhoenix() override;
};

class CreationEnemyWarriors: public AbstractCreationFactory {
  SwordsMan* initSwordsMan() override;
  ArcherMan* initArcherMan() override;
  Paladin* initPaladin() override;
  Phoenix* initPhoenix() override;
};