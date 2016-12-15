/*
* FILNAMN:       GameMusic.h
* PROJEKT:       TDDC76-Projekt
* PROGRAMMERARE: Johan Almgren, johal611
*                Fredrik Björklund, frebj191
*                Henric Davidsson, henda274
*                Nils Larsén, nilla000
*
* DATUM:         2016-12-15
*
* BESKRIVNING:   Inkluderingsfil för klassen GameMusic.
*/

#ifndef GAMEMUSIC_H
#define GAMEMUSIC_H

#include <SFML/Audio.hpp>
#include <iostream>

class GameMusic
{
public:
    GameMusic();
    ~GameMusic() = default;

    // Funktioner för att spela ljud
    void playMenuMusic();
    void playGameMusic();
    void explosionSound();
    void pickUpSound();
    void deathSound();

private:
    // Datamedlemmar för att hålla de olika ljuden
    sf::Music menuMusic{};
    sf::Music gameMusic{};
    sf::Sound explosion{};
    sf::Sound pickUp{};
    sf::Sound death{};
    sf::SoundBuffer explosionBuffer{};
    sf::SoundBuffer pickUpBuffer{};
    sf::SoundBuffer deathBuffer{};

};

#endif
