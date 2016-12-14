#include "Object.h"

sf::Vector2f sign(sf::Vector2f); // Declaration
int absInt(sf::Vector2f);

void Object::move(sf::Vector2f direction, std::shared_ptr<Map> map)
{
    int speed{absInt(direction)};
    for (int i{1}; i <= speed; i++)
    {
        sprite.move(sign(direction));

        if (!checkCollisions(direction, map))
        {
            float dx{static_cast<float>(direction.x != 0 ? 0 : TILE_SIZE*round(sprite.getPosition().x/TILE_SIZE)-sprite.getPosition().x)};
            float dy{static_cast<float>(direction.y != 0 ? 0 : TILE_SIZE*round(sprite.getPosition().y/TILE_SIZE)-sprite.getPosition().y)};
            sf::Vector2f dVec{dx, dy};
            if (absInt(dVec) <= moveThreshold && absInt(dVec) != 0)
            {
                sprite.move(dVec);
                if (checkCollisions(direction, map))
                {
                    sprite.move(sign(dVec) - dVec);
                    animate_sprite(dVec);
                }
                else
                {
                    sprite.move(-dVec);
                }
            }
            if (!checkCollisions(direction, map))
            {
                sprite.move(-sign(direction));
                break;
            }
        }
        else if (abs(direction.x) == i || abs(direction.y) == i)
        {
            animate_sprite(direction);
        }
        updateMapIndex();
    }
}

bool Object::checkCollisions(sf::Vector2f direction, std::shared_ptr<Map> map)
{
    direction = sign(direction);

    MapCoords mapIndex{static_cast<int>(round((sprite.getPosition().x)/TILE_WIDTH+direction.x)),
        static_cast<int>(round((sprite.getPosition().y)/TILE_HEIGHT+direction.y))};

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
        int direction_x = ((direction.x!=0) ? (direction.x/abs(direction.x)) : -1);
        int direction_y = ((direction.y!=0) ? (direction.y/abs(direction.y)) : 0);
        rect = sf::IntRect(50 + (1 + direction_x)*50 - direction_y*50, 50*counter_rendering, 50, 50);
        counter_rendering++;
        counter_rendering = ((counter_rendering >= 3) ? 0 : counter_rendering);
        sprite.setTextureRect(rect);
    }

    void Object::updateMapIndex()
    {
        mapCoords = MapCoords(static_cast<int>(round(sprite.getPosition().x/TILE_WIDTH)), static_cast<int>(round(sprite.getPosition().y/TILE_HEIGHT)));
        //xIndexMap = round(sprite.getPosition().x/TILE_WIDTH);
        //yIndexMap = round(sprite.getPosition().y/TILE_HEIGHT);
    }

    sf::Vector2f sign(sf::Vector2f vec)
    {
        return sf::Vector2f(((vec.x > 0) ? 1 : ((vec.x < 0) ? -1 : 0)),
        ((vec.y > 0) ? 1 : ((vec.y < 0) ? -1 : 0)));
    }

    int absInt(sf::Vector2f vec)
    {
        return sqrt(vec.x*vec.x + vec.y*vec.y);
    }
