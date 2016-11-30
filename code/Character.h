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
  Character(); //{sprite.setPosition(sf::Vector2f(50, 50));};
  ~Character() = default;
  void setAttribute(int attribute);
  std::string getName(){return name;};
  void eraseLife(){if(lives >= 1){lives = lives -1;}};
  void dropBomb();
  int getSpeed(){return speed;};

private:
  sf::Texture player_texture{};
  std::string name{};
  int bombRadius{};
  bool bomMover{};
  int speed{};
  int lives{};
  int color{};
  sf::Clock respawnTimer{};
  sf::Clock timeToNextBomb{};
};

#endif
