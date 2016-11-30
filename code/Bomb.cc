#include "Bomb.h"

void Bomb::update()
{
    int elapsedTime{timer.getElapsedTime().asMilliseconds()};
    if (elapsedTime > 2000)
    {
        detonated = true;
    }
}
