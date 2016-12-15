/*
 * FILNAMN:       Object.h
 * PROJEKT:       TDDC76-Projekt
 * PROGRAMMERARE: Johan Almgren, johal611
 *                Fredrik Björklund, frebj191
 *                Henric Davidsson, henda274
 *                Nils Larsén, nilla000
 *
 * DATUM:         2016-12-15
 *
 * BESKRIVNING:   Inkluderingsfil för klassen Object.
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

    // Flyttar ett Object's sf::Sprite
    void move(sf::Vector2f, std::shared_ptr<Map>);
    bool collision(sf::Vector2f, std::shared_ptr<Map>);
    void animate_sprite(sf::Vector2f);
    MapCoords tileCoordinates(){return mapCoords;};
    sf::Sprite sprite{};
    void updateMapIndex();

protected:
    sf::IntRect rect{};
    MapCoords mapCoords;
    int counter_rendering{};

    bool bombMover{};
private:
    const int moveThreshold{15};
};

#endif
