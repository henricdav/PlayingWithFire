/*
 * FILNAMN:       Character.h
 * PROJEKT:       TDDC76-Projekt
 * PROGRAMMERARE: Johan Almgren, johal611
 *                Fredrik Björklund, frebj191
 *                Henric Davidsson, henda274
 *                Nils Larsén, nilla000
 *
 * DATUM:         2016-12-15
 *
 * BESKRIVNING:   Inkluderingsfil för klassen Character.
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
    //återställer timern timeToNextBomb
    void resetBombTimer();
    //initierar karaktärerna vid spelstart, tilldelar namn och position
    void initCharacter(std::string, int);
    void setSprite();
    //boolean som avgör huruvida spelaren har rättighet att lägga bomb
    bool dropBomb();
    std::string getName() const;
    //returnerar karaktärens snabbhet
    int getSpeed() const;
    //returnerar karaktärens bombradie
    int getBombRadius() const;
    //returnerar huruvida karaktären har förmågan att flytta bomber eller inte
    bool isBombMover() {return bombMover;};
    //returnerar karaktärens antal kvarvarande liv
    int getLife() const;
    //returnerar karaktärens poäng
    int getPoints() const;
    //tar bort ett liv
    void eraseLife();
    //adderar ett liv
    void setLife();
    //ökar karaktärens hastighet med 1
    void setSpeed();
    //ökar karaktärens bombradie
    void setBombRadius();
    //halverar karaktärens tid mellan varje bomb
    void setBombTime();
    //ger karaktären förmågan att flytta bomber
    void setBombMover();
    //adderar ett antal poäng till karaktären
    void setPoints(int);
    //gör karaktären odödlig i 3 sekunder efter att ha klivit på en bomb
    void setRespawnTimer();
    //returnerar karaktärens respawnTimer
    sf::Clock getRespawnTimer();

private:
    std::vector<std::string> textures{};
    sf::Texture player_texture{};
    std::string name{};
    int bombRadius{};
    int speed{};
    int lives{};
    int color{};
    //tid mellan bomber
    int bombTime{};
    int points{};
    sf::Clock respawnTimer{};
    sf::Clock timeToNextBomb{};
};

#endif
