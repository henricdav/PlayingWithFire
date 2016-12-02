#include "Bomb.h"

Bomb::Bomb(Character & player,Map & map)
: texture{},
bombRadius{player.getBombRadius()},
timer{},
mapPtr{&map},
detonated{false},
exploded{false}
{
    sprite.setPosition(player.tileCoordinates().x,player.tileCoordinates().y);
    texture.loadFromFile("Texture/bomb-small.png");
    sprite.setTexture(texture);
    timer.restart();
    xIndexMap = player.tileCoordinates().x;
    yIndexMap = player.tileCoordinates().y;
}

void Bomb::update()
{
    int elapsedTime{timer.getElapsedTime().asMilliseconds()};
    if (elapsedTime > 1000 && !exploded) // Begin explosion
    {
        std::vector<bool> validDirections{true,true,true,true};
        for (int i{1}; i <= bombRadius; ++i)
        {
            if (!(mapPtr->getCoord(xIndexMap,yIndexMap-i) == wall) && validDirections.at(0))
            {
                mapPtr->setCoord(xIndexMap,yIndexMap-i,wall);
            }
            else
            {
                validDirections.at(0) = false;
            }
            if (!(mapPtr->getCoord(xIndexMap,yIndexMap+i) == wall) && validDirections.at(1))
            {
                mapPtr->setCoord(xIndexMap,yIndexMap+i,wall);
            }
            else
            {
                validDirections.at(1) = false;
            }
            if (!(mapPtr->getCoord(xIndexMap-i,yIndexMap) == wall) && validDirections.at(2))
            {
                mapPtr->setCoord(xIndexMap-i,yIndexMap,wall);
            }
            else
            {
                validDirections.at(2) = false;
            }
            if (!(mapPtr->getCoord(xIndexMap+i,yIndexMap) == wall) && validDirections.at(3))
            {
                mapPtr->setCoord(xIndexMap+i,yIndexMap,wall);
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
        mapPtr->setCoord(xIndexMap,yIndexMap-1,empty);
        mapPtr->setCoord(xIndexMap,yIndexMap+1,empty);
        mapPtr->setCoord(xIndexMap+1,yIndexMap,empty);
        mapPtr->setCoord(xIndexMap-1,yIndexMap,empty);
        detonated = true;
    }
}
