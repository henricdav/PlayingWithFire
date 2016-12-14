
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

enum tile{empty = 0, wall = 1, bomb, flames, emptybox, shoebox, extrabombbox, bombradiusbox, lifebox, bombmoverbox, shoes, extrabomb, bombradius, life, bombmover};

class MapCoords
{
public:
    MapCoords() {};
    ~MapCoords() = default;
    MapCoords(int xcoord, int ycoord) : x{xcoord}, y{ycoord} {};

    MapCoords operator+(const MapCoords & rhs) {return MapCoords(this->x+rhs.x,this->y+rhs.y);};
    MapCoords operator*(const int & i) {return MapCoords(this->x*i,this->y*i);};

    int x;
    int y;
};

class Map
{
public:
  Map(); //(std::string & fileName);
  ~Map() = default;
  void setCoord(MapCoords, int type);
  int getCoord(MapCoords) const;
  sf::Sprite getBoundings(MapCoords) const;

  //For testing
  void print();

private:
  std::vector<int> mapArray{};
  bool validIndices(MapCoords) const;
};










#endif
