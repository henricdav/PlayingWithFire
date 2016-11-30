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

  void move(sf::Vector2f, Map*);
  bool checkCollisions(sf::Vector2f, Map*);
  void animate_sprite(sf::Vector2f);
  sf::Sprite sprite{};


private:
  sf::IntRect rect{};
  int xIndexMap{};
  int yIndexMap{};
  int counter_rendering{};
};

#endif
