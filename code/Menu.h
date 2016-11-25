/*
Klassen Menu
*/
#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameEngine.h"

class Menu
{
public:
    Menu();
    ~Menu() {};

    void run();
private:
    std::vector<std::string> playerNames;
    std::vector<int> playerColors;
    sf::RenderWindow window;

    GameEngine game;
};

#endif
