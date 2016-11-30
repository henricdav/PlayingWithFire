#include "Character.h"


Character::Character()
{
    sprite.setPosition(sf::Vector2f(50, 50));
    player_texture.loadFromFile("Texture/dragons2.png");
    sprite.setTexture(player_texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
    speed = 1;
}



void Character::setAttribute(int attribute)
{
    color = attribute;

    sprite.setColor(sf::Color::Black);
}
