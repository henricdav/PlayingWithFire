/*
 * FILNAMN:       Menu.h
 * PROJEKT:       TDDC76-Projekt
 * PROGRAMMERARE: Johan Almgren, johal611
 *                Fredrik Björklund, frebj191
 *                Henric Davidsson, henda274
 *                Nils Larsén, nilla000
 *
 * DATUM:         2016-12-15
 *
 * BESKRIVNING:   Inkluderingsfil för klassen Object. Basklass för Character
 *                och Bomb
 */

#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "GameEngine.h"
#include "globaldefines.h"
#include "Highscore.h"

#define NUMBER_OF_TEXT_FIELDS 3
#define NUMBER_OF_SPRITES 3
#define NUMBER_OF_PLAYERS 2

class Menu
{
public:
    Menu();
    ~Menu() {};

    int run();

private:
    void drawMenuText();
    void drawMenuSprites();
    void moveUp();
    void moveDown();
    int selectedItem();
    int configBeforeRun(sf::Event);

    std::vector<std::string> playerNames;
    std::vector<int> playerColors;

    sf::RenderWindow window;
    sf::Font font;
    sf::Text menu[NUMBER_OF_TEXT_FIELDS];
    sf::Sprite start_page_sprite[NUMBER_OF_SPRITES];
    sf::Texture start_page_tex[NUMBER_OF_SPRITES];

    int item_index;
    int count1 = 0;
    int count2 = 0;

};

#endif
