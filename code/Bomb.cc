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
}

void Bomb::update()
{
    int elapsedTime{timer.getElapsedTime().asMilliseconds()};
    if (elapsedTime > 2000)
    {
        detonated = true;
    }
}
