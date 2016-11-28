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

#define NUMBER_OF_ITEMS 1

class Menu
{
public:
    Menu();
    ~Menu() {};

    int run();

private:
    std::vector<std::string> playerNames;
    std::vector<int> playerColors;
    sf::RenderWindow window;
    sf::Font font;
    sf::Text menu[NUMBER_OF_ITEMS];

    void draw();

    GameEngine game;
};

#endif
