/*
Klassen Object
*/
#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Map.h"

class Object
{
public:
    Object() = default;
    virtual ~Object() = default;

    void move(sf::Vector2f, std::shared_ptr<Map>);
    bool collision(sf::Vector2f, std::shared_ptr<Map>);
    void animate_sprite(sf::Vector2f);
    MapCoords tileCoordinates(){return mapCoords;};
    sf::Sprite sprite{};


protected:
    sf::IntRect rect{};
    MapCoords mapCoords;
    int counter_rendering{};
    void updateMapIndex();
    bool bombMover{};
private:
    const int moveThreshold{15};
};

#endif
