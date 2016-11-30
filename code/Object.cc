#include "Object.h"


void Object::move(sf::Vector2f direction, Map* map)
{
    sprite.move(direction);
    if (false) {map->print();}
    if (!checkCollisions(direction, map))
    {
        sprite.move(-direction);
    }
}


bool Object::checkCollisions(sf::Vector2f direction, Map* map)
{
    xIndexMap = round((sprite.getPosition().x+25*direction.x)/50.0);
    yIndexMap = round((sprite.getPosition().y+25*direction.y)/50.0);
    if (map->getCoord(xIndexMap, yIndexMap) == 1) // && sprite.getGlobalBounds().intersects(map->getBoundings(xIndexMap, yIndexMap)))
    {
        return false;
    }
    else {return true;}
}
