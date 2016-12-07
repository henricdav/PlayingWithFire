#include "Bomb.h"

Bomb::Bomb(Character & player,Map & map)
: texture{},
bombRadius{player.getBombRadius()},
timer{},
mapPtr{&map},
detonated{false},
exploded{false},
explodeRange{bombRadius,bombRadius,bombRadius,bombRadius},
directions{{0,-1},{0,1},{-1,0},{1,0}},
boxContents{0,0,0,0}
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

    if (!exploded && elapsedTime > 1000) // Begin explosion
    {
        bool validDirection{};
        for (int j{0}; j <= 3; ++j)
        {
            validDirection = true;
            for (int i{1}; i <= bombRadius; ++i)
            {
                if (validDirection == true && mapPtr->getCoord(mapCoords + directions[j]*i) == wall)
                {
                    explodeRange[j] = i - 1;
                    validDirection = false;
                }
                else if (validDirection == true && mapPtr->getCoord(mapCoords + directions[j]*i) == blownemptybox)
                {
                    explodeRange[j] = i;
                    validDirection = false;
                }
                else if (validDirection == true && mapPtr->getCoord(mapCoords + directions[j]*i) > blownemptybox && mapPtr->getCoord(mapCoords + directions[j]*i) < shoes)
                {
                    boxContents[j] = mapPtr->getCoord(mapCoords + directions[j]*i) + 6;
                    explodeRange[j] = i;
                    validDirection = false;
                }
                else if (validDirection == true && mapPtr->getCoord(mapCoords + directions[j]*i) > emptybox && mapPtr->getCoord(mapCoords + directions[j]*i) < blownemptybox)
                {
                    boxContents[j] = mapPtr->getCoord(mapCoords + directions[j]*i) + 6;
                    validDirection = false;
                    mapPtr->setCoord(mapCoords + directions[j]*i, boxContents[j]);
                    explodeRange[j] = i;
                }
                else if (validDirection == true && mapPtr->getCoord(mapCoords + directions[j]*i) == emptybox)
                {
                    mapPtr->setCoord(mapCoords + directions[j]*i, blownemptybox);
                    explodeRange[j] = i;
                    validDirection = false;
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
    }

    if (elapsedTime > 2000) // End explosion
    {

        for (int j{0}; j <= 3; ++j)
        {
            for (int i{0}; i <= explodeRange[j]; ++i)
            {
                if (i == explodeRange[j])
                {
                    mapPtr->setCoord(mapCoords + directions[j]*i, boxContents[j]);
                }
                else
                {
                    mapPtr->setCoord(mapCoords + directions[j]*i, empty);
                }
            }
        }
        detonated = true;
    }
}
