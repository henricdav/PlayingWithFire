/*
 * FILNAMN:       Bomb.cc
 * Projekt:       TDDC76-Projekt
 * PROGRAMMERARE: Johan Almgren, johal 611
 *                Fredrik Björklund, frebj191
 *                Henric Davidsson, henda274'
 *                Nils Larsén, nilla000
 *
 * DATUM:         2016-12-15
 *
 * BESKRIVNING:   Implementeringsfil som håller koll på bomber
 */

#include "Bomb.h"

Bomb::Bomb(Character & player, Map & map)
: texture{},
bombRadius{player.getBombRadius()},
timer{},
mapPtr{&map},
detonated{false},
exploded{false},
explodeRange{bombRadius,bombRadius,bombRadius,bombRadius},
directions{{0,-1},{0,1},{-1,0},{1,0}},
boxContents{0,0,0,0},
playerPtr{&player},
playerInTile{true}

{
    sprite.setPosition(TILE_WIDTH*player.tileCoordinates().x,
                       TILE_HEIGHT*player.tileCoordinates().y);
    texture.loadFromFile("Figures/bomb.png");
    sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
    sprite.setTexture(texture);
    timer.restart();
    mapCoords = player.tileCoordinates();
    oldMapCoords = mapCoords;
    mapPtr->setCoord(mapCoords, bomb);
}

void Bomb::update()
{
    int elapsedTime{timer.getElapsedTime().asMilliseconds()};

    if (!(oldMapCoords == mapCoords))
    {
        mapPtr->setCoord(oldMapCoords, empty);
        mapPtr->setCoord(mapCoords, bomb);
    }
    oldMapCoords = mapCoords;
    if (exploded)
    {
        moveDirection = MapCoords(0,0);
    }
    if (!exploded && elapsedTime > 3000) // Begin explosion
    {
        mapPtr->setCoord(mapCoords, flames);
        music.explosionSound();
        bool validDirection{};
        for (int j{0}; j <= 3; ++j)
        {
            validDirection = true;
            for (int i{1}; i <= bombRadius; ++i)
            {
                if (validDirection == true &&
                    mapPtr->getCoord(mapCoords + directions[j]*i) == wall)
                {
                    explodeRange[j] = i - 1;
                    validDirection = false;
                }
                else if (validDirection == true &&
                    mapPtr->getCoord(mapCoords + directions[j]*i) > emptybox &&
                    mapPtr->getCoord(mapCoords + directions[j]*i) < shoes)
                {
                    boxContents[j] = mapPtr->getCoord(mapCoords + directions[j]*i) + 5;
                    validDirection = false;
                    mapPtr->setCoord(mapCoords + directions[j]*i, flames);
                    explodeRange[j] = i;
                    playerPtr->setPoints(100);
                }
                else if (validDirection == true &&
                    mapPtr->getCoord(mapCoords + directions[j]*i) == emptybox)
                {
                    mapPtr->setCoord(mapCoords + directions[j]*i, flames);
                    explodeRange[j] = i;
                    validDirection = false;
                    playerPtr->setPoints(100);
                }
                else if (validDirection == true)
                {
                    mapPtr->setCoord(mapCoords + directions[j]*i, flames);
                }
            }
        }
        texture.loadFromFile("Texture/explosion.png");
        sprite.setTexture(texture);
        exploded = true;
        moveDirection = MapCoords(0,0);
    }

    if (elapsedTime > 4000) // End explosion
    {
        for (int j{0}; j <= 3; ++j)
        {
            for (int i{0}; i <= explodeRange[j]; ++i)
            {
                if (i == explodeRange[j])
                {
                    mapPtr->setCoord(mapCoords + directions[j]*i,
                        boxContents[j]);
                }
                else
                {
                    mapPtr->setCoord(mapCoords + directions[j]*i, empty);
                }
            }
        }
        mapPtr->setCoord(mapCoords, empty);
        detonated = true;
    }
}
