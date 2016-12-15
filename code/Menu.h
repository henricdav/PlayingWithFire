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
 * BESKRIVNING:  Inkluderingsfil för klassen Menu.
 */

#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
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

    // Huvudloopen i menyn. Skickar spelaren vidare till game, highscore eller
    // avslutar spelet genom att lyssna på events.
    int run();

private:
    // Ritar ut alternativen i startmenyn
    void drawMenuText();

    // Ritar ut spritesen i startmenyn
    void drawMenuSprites();

    // Sköter stegningen med piltangenterna i uppåtgående riktning genom att
    // stega item_index upp
    void moveUp();

    // Sköter stegningen med piltangenterna i nedåtgående riktning genom att
    // stega item_index ner
    void moveDown();

    int selectedItem();

    // Submeny där spelarna kan skriva in namn på karaktärerna
    int configBeforeRun(sf::Event);

    // String vector som fylls på med spelarnas namn
    std::vector<std::string> playerNames;
    std::vector<int> playerColors;

    // SFML classes that takes care of window, font, text sprites and textures
    sf::RenderWindow window;
    sf::Font font;
    sf::Text menu[NUMBER_OF_TEXT_FIELDS];
    sf::Sprite start_page_sprite[NUMBER_OF_SPRITES];
    sf::Texture start_page_tex[NUMBER_OF_SPRITES];

    int item_index{};
    int count1{};
    int count2{};

};

#endif
