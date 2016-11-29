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

#define NUMBER_OF_ITEMS 3

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

    GameEngine game;
    int item_index;
    bool game_running;
    sf::RectangleShape rect;

    void draw();
    void moveUp();
    void moveDown();
    int selectedItem();
    int configBeforeRun(sf::Event);

};

#endif
