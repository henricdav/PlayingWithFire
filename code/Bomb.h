/*
Klassen Bomb
*/
#ifndef BOMB_H
#define BOMB_H

#include "Object.h"
#include "Character.h"
#include <memory>

class Bomb : public Object
{
public:
    Bomb() = default;
    Bomb(std::shared_ptr<Character> player,std::shared_ptr<Map> map);

    ~Bomb() = default;
    bool isDetonated() {return detonated;};
    void update();

private:
    sf::Texture texture;
    int bombRadius;
    sf::Clock timer;
    std::shared_ptr<Map> mapPtr;
    bool detonated;
};

#endif
