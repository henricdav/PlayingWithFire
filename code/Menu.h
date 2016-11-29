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

#define NUMBER_OF_ITEMS 4
#define NUMBER_OF_SPRITES 3

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
    int count1;
    int count2;
    bool game_running;
    sf::Sprite start_page_sprite[NUMBER_OF_SPRITES];
    sf::Texture start_page_tex[NUMBER_OF_SPRITES];

    void drawText();
    void drawSprites();
    void moveUp();
    void moveDown();
    int selectedItem();
    int configBeforeRun(sf::Event);

};

#endif
