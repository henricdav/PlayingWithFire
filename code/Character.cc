#include "Character.h"


Character::Character()
{
    sprite.setPosition(sf::Vector2f(50, 50));
    player_texture.loadFromFile("Figures/BLUELADY.png");
    sprite.setTexture(player_texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
    speed = 2;
    updateMapIndex();
}

void Character::resetBombTimer()
{
    timeToNextBomb.restart();
}

void Character::setAttribute(int attribute)
{
    color = attribute;

    sprite.setColor(sf::Color::Black);
}


bool Character::dropBomb()
{
    int timeElapsed{timeToNextBomb.getElapsedTime().asMilliseconds()};

    if (timeElapsed > bombTime)
    {
        return true;
    }
    else
    {
        return false;
    }
}
