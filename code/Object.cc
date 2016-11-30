#include "Object.h"


void Object::move(sf::Vector2f direction, Map* map)
{
    sprite.move(direction);
    if (false) {map->print();}
    // if (!checkCollisions(map))
    // {
    //   sprite.move(-direction)
    // }
}
