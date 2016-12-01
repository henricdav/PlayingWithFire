/*
Klassen Bomb
*/
#ifndef BOMB_H
#define BOMB_H

#include "Object.h"
#include "Character.h"

class Bomb : public Object
{
public:
    Bomb() = default;
    Bomb(Character* player, Map* map)
        : texture{},
        bombRadius{player->getBombRadius()},
        timer{},
        mapPtr{map},
        detonated{false}
    {
        sprite.setPosition(sf::Vector2f(50, 50));
        texture.loadFromFile("Texture/bomb-small.png");
        sprite.setTexture(texture);
        timer.restart();
    }

    ~Bomb() = default;
    bool isDetonated() {return detonated;};
    void update();

private:
    sf::Texture texture;
    int bombRadius;
    sf::Clock timer;
    Map* mapPtr;
    bool detonated;
};

#endif
