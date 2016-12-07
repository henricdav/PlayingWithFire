#include "Object.h"


void Object::move(sf::Vector2f direction, std::shared_ptr<Map> map)
{
    sprite.move(direction);
    if (false) {map->print();}
    if (!checkCollisions(direction, map))
    {
        sprite.move(-direction);
    }
    else
    {
        animate_sprite(direction);
    }
    updateMapIndex();
}


bool Object::checkCollisions(sf::Vector2f direction, std::shared_ptr<Map> map)
{
    if (direction.x != 0) {direction.x = direction.x/std::abs(direction.x);} //0, -1 or +1
    if (direction.y != 0) {direction.y = direction.y/std::abs(direction.y);} //0, -1 or +1
    //xIndexMap = round((sprite.getPosition().x)/TILE_WIDTH+direction.x);
    //yIndexMap = round((sprite.getPosition().y)/TILE_HEIGHT+direction.y);
    MapCoords mapIndex{static_cast<int>(round((sprite.getPosition().x)/TILE_WIDTH+direction.x)),
                       static_cast<int>(round((sprite.getPosition().y)/TILE_HEIGHT+direction.y))};
    //if (map->getCoord(xIndexMap + direction.x, yIndexMap + direction.y) == 1)
    if (sprite.getGlobalBounds().intersects(map->getBoundings(mapIndex).getGlobalBounds())
        || sprite.getGlobalBounds().intersects(map->getBoundings(mapIndex + MapCoords(direction.y,direction.x)).getGlobalBounds())
        || sprite.getGlobalBounds().intersects(map->getBoundings(mapIndex + MapCoords(-direction.y,-direction.x)).getGlobalBounds()))
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Object::animate_sprite(sf::Vector2f direction)
{
    counter_rendering++;
    if (direction.x < 0)
    {
        rect = sf::IntRect(50, 50*counter_rendering, 50, 50);
    }
    else if (direction.x > 0)
    {
        rect = sf::IntRect(150, 50*counter_rendering, 50, 50);
    }
    else if (direction.y < 0)
    {
        rect = sf::IntRect(100, 50*counter_rendering, 50, 50);
    }
    else if (direction.y > 0)
    {
        rect = sf::IntRect(0, 50*counter_rendering, 50, 50);
    }
    else
    {
        rect = sf::IntRect(0, 0, 50, 50);
    }
    if (counter_rendering == 3) //Reset counter_rendering
        counter_rendering = 0;
    }


    sprite.setTextureRect(rect);
}

void Object::updateMapIndex()
{
    mapCoords = MapCoords(static_cast<int>(round(sprite.getPosition().x/TILE_WIDTH)), static_cast<int>(round(sprite.getPosition().y/TILE_HEIGHT)));
    //xIndexMap = round(sprite.getPosition().x/TILE_WIDTH);
    //yIndexMap = round(sprite.getPosition().y/TILE_HEIGHT);
}
