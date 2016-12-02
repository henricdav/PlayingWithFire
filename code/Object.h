/*
Klassen Object
*/
#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Map.h"

class Object
{
public:
  Object() = default;
  virtual ~Object() = default;

  void move(sf::Vector2f, std::shared_ptr<Map>);
  bool checkCollisions(sf::Vector2f, std::shared_ptr<Map>);
  void animate_sprite(sf::Vector2f);
  sf::Vector2i tileCoordinates(){return sf::Vector2i{xIndexMap, yIndexMap};};
  sf::Sprite sprite{};


protected:
  sf::IntRect rect{};
  int xIndexMap;
  int yIndexMap;
  int counter_rendering{};
  void updateMapIndex();
};

#endif
