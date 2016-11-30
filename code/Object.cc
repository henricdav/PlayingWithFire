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
    if (direction.x != 0) {direction.x = direction.x/std::abs(direction.x);} //0, -1 or +1
    if (direction.y != 0) {direction.y = direction.y/std::abs(direction.y);} //0, -1 or +1
    xIndexMap = round((sprite.getPosition().x)/50.0+direction.x);
    yIndexMap = round((sprite.getPosition().y)/50.0+direction.y);

    //if (map->getCoord(xIndexMap + direction.x, yIndexMap + direction.y) == 1)
    if (sprite.getGlobalBounds().intersects(map->getBoundings(xIndexMap, yIndexMap).getGlobalBounds())
        || sprite.getGlobalBounds().intersects(map->getBoundings(xIndexMap+direction.y, yIndexMap+direction.x).getGlobalBounds())
        || sprite.getGlobalBounds().intersects(map->getBoundings(xIndexMap-direction.y, yIndexMap-direction.x).getGlobalBounds()))
    {
        return false;
    }
    else
    {
        return true;
    }
}
