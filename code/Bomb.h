/*
 * FILNAMN:       Bomb.h
 * Projekt:       TDDC76-Projekt
 * PROGRAMMERARE: Johan Almgren, johal 611
 *                Fredrik Björklund, frebj191
 *                Henric Davidsson, henda274'
 *                Nils Larsén, nilla000
 *
 * DATUM:         2016-12-15
 *
 * BESKRIVNING:   Inkluderingsfil för bombklassen
 */

#ifndef BOMB_H
#define BOMB_H

#include "Object.h"
#include "Character.h"
#include <vector>
#include <memory>
#include "GameMusic.h"

class Bomb : public Object
{
public:
    Bomb() = default;
    Bomb(Character & player,Map & map);
    ~Bomb() = default;

    //
    bool isDetonated() {return detonated;};

    // Uppdaterar bomben och hanterar sprängradien, så att tillåtna områden
    // sprängs korrekt.
    void update();

    //
    void unsetPlayerInTile() {playerInTile = false;};

    //
    bool getPlayerInTile() {return playerInTile;};

    //
    MapCoords moveDirection{0,0};

private:
    sf::Texture texture;
    int bombRadius;
    sf::Clock timer;
    Map* mapPtr;
    bool detonated;
    bool exploded;
    std::vector<int> explodeRange;
    std::vector<MapCoords> directions;
    std::vector<int> boxContents;
    Character* playerPtr{};
    GameMusic music{};
    MapCoords oldMapCoords{};
    bool playerInTile{};
};

#endif
