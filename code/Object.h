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
  virtual ~Object() = default;
  void move(int Speed, std::vector<bool> direction);
  sf::Sprite sprite{};


private:
  sf::IntRect rect{};
  int mapCoord{};
};

#endif
