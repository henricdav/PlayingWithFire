/*
Klassen Bomb
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
    bool isDetonated() {return detonated;};
    void update();
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

};

#endif
