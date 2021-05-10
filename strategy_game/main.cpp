#include "stdafx.h"
#include "game.hpp"

// #include "ResourcePath.hpp"

int main(int, char const**)
{
    //sf::Image icon;
    //if (!icon.loadFromFile(resourcePath() + "i.jpeg")) {
    //    return EXIT_FAILURE;
    //}
  srand(time(0));
  Game game;
  game.run();
  return EXIT_SUCCESS;
}
