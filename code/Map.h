
#ifndef MAP_H
#define MAP_H

#include <vector>
#include <fstream>
#include <iostream> //For testing
#include <string>
#include <cmath>
#include <stdexcept>
#include <SFML/Graphics.hpp>
#include "globaldefines.h"

enum tile{empty = 0, wall = 1, emptybox, shoebox};

class MapCoords
{
public:
    MapCoords() {};
    ~MapCoords() = default;
    MapCoords(int xcoord, int ycoord) : x{xcoord}, y{ycoord} {};
    int x;
    int y;
};

class Map
{
public:
  Map(); //(std::string & fileName);
  ~Map() = default;
  void setCoord(int xCoord, int yCoord, int type);
  int getCoord(int xCoord, int yCoord) const;
  sf::Sprite getBoundings(int xCoord, int yCoord) const;

  //For testing
  void print();

private:
  std::vector<int> mapArray{};
  bool validIndices(int, int) const;
  //sf::Sprite tempStaticSprite{};
};










#endif
