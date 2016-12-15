/*
* FILNAMN:       Map.h
* PROJEKT:       TDDC76-Projekt
* PROGRAMMERARE: Johan Almgren, johal611
*                Fredrik Björklund, frebj191
*                Henric Davidsson, henda274
*                Nils Larsén, nilla000
*
* DATUM:         2016-12-15
*
* BESKRIVNING:   Inkluderingsfil för klassen Map.
*/

#ifndef MAP_H
#define MAP_H

#include <vector>
#include <fstream>
#include <iostream> //For testing
#include <string>
#include <cmath>
#include <stdexcept>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "globaldefines.h"

// enum för att hålla reda på tile-types
enum tile{empty = 0, wall = 1, bomb, flames, emptybox = 4, shoebox, extrabombbox, bombradiusbox, lifebox, bombmoverbox, shoes, extrabomb, bombradius, life, bombmover};

// vector med strängar för att randomisera karta
const std::vector<std::string> randomMap{"level1.map", "level2.map", "level3.map", "level4.map", "level5.map", "level6.map", "level7.map", "level8.map", "level9.map", "level10.map"};

class MapCoords
{
public:
    MapCoords() {};
    ~MapCoords() = default;
    MapCoords(int xcoord, int ycoord) : x{xcoord}, y{ycoord} {};

    // Operatorer
    MapCoords operator+(const MapCoords & rhs) {return MapCoords(this->x+rhs.x,this->y+rhs.y);};
    MapCoords operator*(const int & i) {return MapCoords(this->x*i,this->y*i);};
    bool operator==(const MapCoords & rhs) {return this->x == rhs.x && this->y == rhs.y;};

    int x;
    int y;
};

class Map
{
public:
    Map();
    ~Map() = default;

    // Sätter koordinattyper i mapArray
    void setCoord(MapCoords, int type);

    // Hämtar koordinattyper i mapArray
    int getCoord(MapCoords) const;

    // returnerar en Sprite på rätt position utifrån mapArray
    sf::Sprite getBoundings(MapCoords, bool bombMover) const;

    //For testing
    void print();

private:
    // Map-matrisen
    std::vector<int> mapArray{};

    // Kollar tillåtna index
    bool validIndices(MapCoords) const;
};










#endif
