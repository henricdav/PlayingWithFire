#include "Character.h"


Character::Character()
{
    speed = 2;
    bombRadius = 1;
    lives = 3;
    bombTime = 3000;
}

void Character::resetBombTimer()
{
    timeToNextBomb.restart();
}

void Character::initCharacter(std::string new_name, int attribute)
{
    color = attribute;
    name = new_name;

    if (color == 1)
    {
        sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
        sprite.setPosition(sf::Vector2f(TILE_SIZE+X_OFFSET, TILE_SIZE+Y_OFFSET));
    }
    if (color == 2)
    {
        sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
        sprite.setPosition(sf::Vector2f((TILES_X*TILE_SIZE-2*TILE_SIZE)+X_OFFSET,
                                        (TILES_Y*TILE_SIZE-2*TILE_SIZE)+Y_OFFSET));
    }
    setSprite();
    updateMapIndex();
}

void Character::setSprite()
{
    switch(color)
    {
    case 1:
        if (getRespawnTimer().getElapsedTime().asSeconds() < 3)
        {
            player_texture.loadFromFile("Figures/adaRedRespawn.png");
        }
        else
        {
            player_texture.loadFromFile("Figures/adaRed.png");
        }
        break;
    case 2:
        if (getRespawnTimer().getElapsedTime().asSeconds() < 3)
        {
            player_texture.loadFromFile("Figures/danteBlueRespawn.png");
        }
        else
        {
            player_texture.loadFromFile("Figures/danteBlue.png");
        }
        break;
    }
    sprite.setTexture(player_texture);
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

int Character::getLife() const
{
    return lives;
}

int Character::getPoints() const
{
    return points;
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

void Character::setPoints(int value)
{
    points += value;
}

void Character::setRespawnTimer()
{
    respawnTimer.restart();
}

sf::Clock Character::getRespawnTimer()
{
    return respawnTimer;
}
