#include "Character.h"


Character::Character()
{
    speed = 4;
    bombRadius = 1;
    lives = 3;
    bombTime = 3000;
}

void Character::resetBombTimer()
{
    timeToNextBomb.restart();
}

void Character::initCharacter(std::string name, int attribute)
{
    color = attribute;
    if (color == 1)
    {
        player_texture.loadFromFile("Figures/adaRed.png");
        sprite.setPosition(sf::Vector2f(TILE_SIZE+X_OFFSET, TILE_SIZE+Y_OFFSET));
        sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
    }
    if (color == 2)
    {
        player_texture.loadFromFile("Figures/danteBlue.png");
        sprite.setPosition(sf::Vector2f((TILES_X*TILE_SIZE-2*TILE_SIZE)+X_OFFSET,
                                        (TILES_Y*TILE_SIZE-2*TILE_SIZE)+Y_OFFSET));
        sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));

    }
    sprite.setTexture(player_texture);
    updateMapIndex();

    name = name;
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

std::string Character::getName() const
{
    return name;
}

int Character::getSpeed() const
{
    return speed;
}

int Character::getBombRadius() const
{
    return bombRadius;
}

void Character::eraseLife()
{
    if (lives >= 1)
    {
        lives -= 1;
    }
}

void Character::setLife()
{
    lives += 1;
}

void Character::setSpeed()
{
    speed += 2;
}

void Character::setBombRadius()
{
    bombRadius += 1;
}

void Character::setBombTime()
{
    bombTime /= 2;
}

void Character::setBombMover()
{
    bombMover = true;
}
