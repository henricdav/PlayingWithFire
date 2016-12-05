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

    if (elapsedTime > 1000 && !exploded) // Begin explosion
    {


        for (int i{1}; i <= bombRadius; ++i)
        {

            for (int j{0}; j <= 3; ++j)
            {
                if (explodeRange[j] == bombRadius)
                {
                if (mapPtr->getCoord(mapCoords + directions[j]*i) == wall)
                {
                    explodeRange[j] = i - 1;
                }
                else if (mapPtr->getCoord(mapCoords + directions[j]*i) > wall)
                {
                    mapPtr->setCoord(mapCoords + directions[j]*i, flames);
                }
            }
            }
        }
        texture.loadFromFile("Texture/explosion.png");
        sprite.setTexture(texture);

        std::cout << explodeRange[0] << explodeRange[1] << explodeRange[2] << explodeRange[3] << std::endl;
        exploded = true;
    }

    if (elapsedTime > 2000) // End explosion
    {

        for (int j{0}; j <= 3; ++j)
        {
            for (int i{0}; i <= explodeRange[j]; ++i)
            {
                if (i == explodeRange)
                    mapPtr->setCoord(mapCoords + directions[j]*i, contents[j]);
                else
                    mapPtr->setCoord(mapCoords + directions[j]*i, empty);
            }
        }
        detonated = true;
    }
}
