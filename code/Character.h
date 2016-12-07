/*
Klassen Character
*/
#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include <string>
#include <iostream>
#include "Object.h"

class Character : public Object
{
public:
    Character(); //{sprite.setPosition(sf::Vector2f(50, 50));};
    ~Character() = default;
    void initCharacter(std::string, int);
    std::string getName(){return name;};
    void eraseLife(){if(lives >= 1){lives = lives -1;}};
    bool dropBomb();
    int getSpeed(){return speed;};
    int getBombRadius() {return bombRadius;};
    void resetBombTimer();

private:
    sf::Texture player_texture{};
    std::string name{};
    int bombRadius{3};
    bool bombMover{};
    int speed{};
    int lives{};
    int color{};
    int bombTime{3000};
    sf::Clock respawnTimer{};
    sf::Clock timeToNextBomb{};
};

#endif
