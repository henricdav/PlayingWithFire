/*
 * FILNAMN:       playingwithfire.cc
 * PROJEKT:       TDDC76-Projekt
 * PROGRAMMERARE: Johan Almgren, johal611
 *                Fredrik Björklund, frebj191
 *                Henric Davidsson, henda274
 *                Nils Larsén, nilla000
 *
 * DATUM:         2016-12-15
 *
 * BESKRIVNING:   Huvudprogram för spelet
 */
 
#include "Menu.h"
#include <iostream>
#include <exception>

int main()
{
    Menu menu{};
    try
    {
        menu.run();
    }
    catch (std::exception& e)
    {
        std::cout << "Ett okänt fel har inträffat: " << e.what() << std::endl;
    }

    return 0;
}
