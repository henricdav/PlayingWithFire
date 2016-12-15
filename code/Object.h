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
 * BESKRIVNING:   Inkluderingsfil för klassen Object. Basklass för Character
 *                och Bomb
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

    // Kollar kollision med objekt i en Map. Används av move()
    bool collision(sf::Vector2f, std::shared_ptr<Map>);

    // Animerar figurerna
    void animate_sprite(sf::Vector2f);

    // Returnerar ett Object's  koordinater i en Map
    MapCoords tileCoordinates() const {return mapCoords;};

    // Uppdaterar koordinaterna för ett Object
    void updateMapIndex();

    // Själva grafikobjektet
    sf::Sprite sprite{};

protected:
    // Ruta att rita i.
    sf::IntRect rect{};
    // Koordinaterna i Map:en
    MapCoords mapCoords;
    // För animering
    int counter_rendering{};
    // Kan objektet flytta bomber?
    bool bombMover{};

private:
    // Gräns för att "glida" åt sidan
    const int moveThreshold{15};
};

#endif
