/*
Klassen Object
*/
#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Map.h"

class Object
{
public:
  Object() = default;
  virtual ~Object() = default;

  void move(sf::Vector2f direction, Map* mappen);
  sf::Sprite sprite{};


private:
  sf::IntRect rect{};
  int mapCoord{};
};

#endif
