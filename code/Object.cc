#include "Object.h"


void Object::move(sf::Vector2f direction, std::shared_ptr<Map> map)
{
    sprite.move(direction);
    if (false) {map->print();}
    if (!checkCollisions(direction, map))
    {
        sprite.move(-direction);
    }
    updateMapIndex();
    //std::cout << xIndexMap << " " << yIndexMap << std::endl;
    animate_sprite(direction);
}


bool Object::checkCollisions(sf::Vector2f direction, std::shared_ptr<Map> map)
{
    if (direction.x != 0) {direction.x = direction.x/std::abs(direction.x);} //0, -1 or +1
    if (direction.y != 0) {direction.y = direction.y/std::abs(direction.y);} //0, -1 or +1
    xIndexMap = round((sprite.getPosition().x)/TILE_WIDTH+direction.x);
    yIndexMap = round((sprite.getPosition().y)/TILE_HEIGHT+direction.y);

    //if (map->getCoord(xIndexMap + direction.x, yIndexMap + direction.y) == 1)
    if (sprite.getGlobalBounds().intersects(map->getBoundings(xIndexMap,yIndexMap).getGlobalBounds())
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

void Object::animate_sprite(sf::Vector2f direction)
{
    if (direction.x != 0) {direction.x = direction.x/std::abs(direction.x);} //0, -1 or +1
    if (direction.y != 0) {direction.y = direction.y/std::abs(direction.y);} //0, -1 or +1
    if (rect.left == 350){
         counter_rendering = 0;
         if (direction.x != 0){rect = sf::IntRect(0, 0, direction.x*50, 50);}
         else {rect = sf::IntRect(0, 0, 50, 50);}
    }
    else if (direction.x !=0){rect = sf::IntRect(50*counter_rendering, 0, direction.x*50, 50);
        if (counter_rendering <= 6){counter_rendering++;}}
    else {rect = sf::IntRect(0, 0, 50, 50);}

     sprite.setTextureRect(rect);
}

void Object::updateMapIndex()
{
    xIndexMap = round(sprite.getPosition().x/TILE_WIDTH);
    yIndexMap = round(sprite.getPosition().y/TILE_HEIGHT);
}
