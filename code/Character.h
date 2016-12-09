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
    Character();
    ~Character() = default;
    void resetBombTimer();
    void initCharacter(std::string, int);
    bool dropBomb();
    std::string getName() const;
    int getSpeed() const;
    int getBombRadius() const;
    int getLife() const;
    void eraseLife();
    void setLife();
    void setSpeed();
    void setBombRadius();
    void setBombTime();
    void setBombMover();
    void setRespawnTimer();
    sf::Clock getRespawnTimer();

private:
    sf::Texture player_texture{};
    std::string name{};
    int bombRadius{};
    bool bombMover{};
    int speed{};
    int lives{};
    int color{};
    int bombTime{};
    sf::Clock respawnTimer{};
    sf::Clock timeToNextBomb{};
};

#endif
