#include "Bomb.h"

Bomb::Bomb(std::shared_ptr<Character> player,std::shared_ptr<Map> map)
    : texture{},
    bombRadius{player->getBombRadius()},
    timer{},
    mapPtr{map},
    detonated{false}
{
sprite.setPosition(player->tileCoordinates()*static_cast<float>(TILE_SIZE));
texture.loadFromFile("Texture/bomb-small.png");
sprite.setTexture(texture);
timer.restart();
xIndexMap = static_cast<int>(player->tileCoordinates().x);
yIndexMap = static_cast<int>(player->tileCoordinates().y);
}

void Bomb::update()
{
    int elapsedTime{timer.getElapsedTime().asMilliseconds()};
    if (elapsedTime > 1000) // Begin explosion
    {
        mapPtr->setCoord(xIndexMap-1,yIndexMap-1,wall);
        mapPtr->setCoord(xIndexMap-1,yIndexMap+1,wall);
        mapPtr->setCoord(xIndexMap+1,yIndexMap+1,wall);
        mapPtr->setCoord(xIndexMap+1,yIndexMap-1,wall);
    }

    if (elapsedTime > 2000) // End explosion
    {
        mapPtr->setCoord(xIndexMap-1,yIndexMap-1,empty);
        mapPtr->setCoord(xIndexMap-1,yIndexMap+1,empty);
        mapPtr->setCoord(xIndexMap+1,yIndexMap+1,empty);
        mapPtr->setCoord(xIndexMap+1,yIndexMap-1,empty);
        detonated = true;
    }
}
