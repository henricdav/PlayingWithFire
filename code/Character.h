/*
Klassen Character
*/
#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include <string>
#include <iostream>
#include "Object.h"

class Character : public Object
{
public:
  Character() = default;
  ~Character() = default;
  void setAttribute(int attribute);
  std::string getName(){return "hej";};
  void eraseLife();
  void dropBomb();

private:
  std::string name;
  int bombRadius;
  bool bomMover;
  int speed;
  int lives;
  int color;
  sf::Clock respawnTimer;
  sf::Clock timeToNextBomb;
};

#endif
