/*
Klassen GameMusic
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

    void playMenuMusic();
    void playGameMusic();
    void explosionSound();
    void pickUpSound();
    void deathSound();

private:
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
