
#include "GameMusic.h"

GameMusic::GameMusic()
{
    if (!explosionBuffer.loadFromFile("Audio/explosion.flac"))
    {
        std::cerr << "Couldn't load explosion audio" << std::endl;
    }
    if (!pickUpBuffer.loadFromFile("Audio/pickup.wav"))
    {
        std::cerr << "Couldn't load pickup audio" << std::endl;
    }
    if (!deathBuffer.loadFromFile("Audio/deathsound.ogg"))
    {
        std::cerr << "Couldn't load death audio" << std::endl;
    }
}

void GameMusic::playMenuMusic()
{
    std::cerr << "Nothing here yet" << std::endl;
}

void GameMusic::playGameMusic()
{
    if (!gameMusic.openFromFile("Audio/gamemusic.ogg"))
    {
        std::cerr << "Couldn't load music" << std::endl;
    }
    gameMusic.setVolume(20);
    gameMusic.setLoop(true);

    gameMusic.play();
}

void GameMusic::explosionSound()
{
    explosion.setBuffer(explosionBuffer);
    explosion.play();
}

void GameMusic::pickUpSound()
{
    pickUp.setBuffer(pickUpBuffer);
    pickUp.play();
}

void GameMusic::deathSound()
{
    death.setBuffer(deathBuffer);
    death.play();
}
