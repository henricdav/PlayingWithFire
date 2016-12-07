#include "Character.h"


Character::Character()
{
    speed = 2;
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
    std::cerr << name << std::endl;

}
