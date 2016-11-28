/*
Klassen Object
*/
#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

class Object
{
public:
  Object() = default;
  virtual ~Object();
  void move(int Speed, std::vector<bool> direction);

private:
  sf::Sprite sprite;
  sf::IntRect rect;
  int mapCoord;
};

#endif
