#include "Bomb.h"

Bomb::Bomb(Character & player,Map & map)
: texture{},
bombRadius{player.getBombRadius()},
timer{},
mapPtr{&map},
detonated{false},
exploded{false}
{
    sprite.setPosition(TILE_WIDTH*player.tileCoordinates().x,TILE_HEIGHT*player.tileCoordinates().y);
    texture.loadFromFile("Texture/bomb-small.png");
    sprite.setTexture(texture);
    timer.restart();
    mapCoords = player.tileCoordinates();

    //xIndexMap = player.tileCoordinates().x;
    //yIndexMap = player.tileCoordinates().y;
}

void Bomb::update()
{
    int elapsedTime{timer.getElapsedTime().asMilliseconds()};
    std::vector<MapCoords> directions{{0,-1},{0,1},{-1,0},{1,0}};
    if (elapsedTime > 1000 && !exploded) // Begin explosion
    {
        std::vector<bool> validDirections{true,true,true,true};

        for (int i{1}; i <= bombRadius; ++i)
        {
            if (!(mapPtr->getCoord(mapCoords + directions[0]*i) == wall) && validDirections.at(0))
            {
                mapPtr->setCoord(mapCoords + directions[0]*i,wall);
            }
            else
            {
                validDirections.at(0) = false;
            }
            if (!(mapPtr->getCoord(mapCoords + directions[1]*i) == wall) && validDirections.at(1))
            {
                mapPtr->setCoord(mapCoords + directions[1]*i,wall);
            }
            else
            {
                validDirections.at(1) = false;
            }
            if (!(mapPtr->getCoord(mapCoords + directions[2]*i) == wall) && validDirections.at(2))
            {
                mapPtr->setCoord(mapCoords + directions[2]*i,wall);
            }
            else
            {
                validDirections.at(2) = false;
            }
            if (!(mapPtr->getCoord(mapCoords + directions[3]*i) == wall) && validDirections.at(3))
            {
                mapPtr->setCoord(mapCoords + directions[3]*i,wall);
            }
            else
            {
                validDirections.at(3) = false;
            }
        }
        exploded = true;
    }

    if (elapsedTime > 2000) // End explosion
    {
        mapPtr->setCoord(mapCoords + directions[0],empty);
        mapPtr->setCoord(mapCoords + directions[1],empty);
        mapPtr->setCoord(mapCoords + directions[2],empty);
        mapPtr->setCoord(mapCoords + directions[3],empty);
        detonated = true;
    }
}
