/*
Klassen Bomb
*/
#ifndef BOMB_H
#define BOMB_H

#include "Object.h"

class Bomb : public Object
{
public:
  Bomb() = default;
  ~Bomb() = default;

private:
  int bombRadius;
  sf::Clock timer;
};

#endif
