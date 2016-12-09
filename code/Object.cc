#include "Object.h"


void Object::move(sf::Vector2f direction, std::shared_ptr<Map> map)
{
    if (direction.x != 0)
    {
        for (int i{1}; i <=abs(direction.x); i++)
        {
            sprite.move(direction.x/abs(direction.x), 0);

            if (!checkCollisions(sf::Vector2f(direction.x, 0), map))
            {
                int dy = 50*round(sprite.getPosition().y/50.0)-sprite.getPosition().y;
                if (abs(dy) <= 15 && dy != 0)
                {
                    sprite.move(0, dy);
                    if (checkCollisions(sf::Vector2f(direction.x, 0), map))
                    {
                        sprite.move(0, -dy + dy/abs(dy));
                    }
                    else
                    {
                        sprite.move(0, -dy);
                    }
                    animate_sprite(sf::Vector2f(0, dy));

                }
                if (!checkCollisions(sf::Vector2f(direction.x, 0), map))
                {
                    sprite.move(-direction.x/abs(direction.x), 0);
                    i = 100;
                }
            }
            else
            {
                animate_sprite(direction);
            }
            updateMapIndex();
        }
    }

    else if (direction.y != 0)
    {
        for (int j{1}; j <=abs(direction.y); j++)
        {
            sprite.move(0, direction.y/abs(direction.y));

            if (!checkCollisions(sf::Vector2f(0, direction.y), map))
            {
                int dx = 50*round(sprite.getPosition().x/50.0)-sprite.getPosition().x;
                if (abs(dx) <= 15 && dx != 0 && checkCollisions(sf::Vector2f(dx, 0), map))
                {
                   sprite.move(dx/abs(dx), 0);
                   animate_sprite(sf::Vector2f(dx, 0));
                }
                if (!checkCollisions(sf::Vector2f(0, direction.y), map))
                {
                    sprite.move(0, -direction.y/abs(direction.y));
                    j = 100;
                }
            }
            else
            {
                animate_sprite(direction);
            }
            updateMapIndex();
        }
    }



    // sprite.move(direction);
    // if (false) {map->print();}
    // if (!checkCollisions(direction, map))
    // {
    //     sprite.move(-direction);
    // }
    // else
    // {
    //animate_sprite(direction);
    // }
    //updateMapIndex();
}


bool Object::checkCollisions(sf::Vector2f direction, std::shared_ptr<Map> map)
{
    if (direction.x != 0)
    {
        direction.x = direction.x/abs(direction.x);  //0, -1 or +1
    }
    if (direction.y != 0)
    {
        direction.y = direction.y/abs(direction.y); //0, -1 or +1
    }
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
    {
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
