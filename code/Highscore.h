/*
 * FILNAMN:       Highscore.h
 * PROJEKT:       TDDC76-Projekt
 * PROGRAMMERARE: Johan Almgren, johal611
 *                Fredrik Björklund, frebj191
 *                Henric Davidsson, henda274
 *                Nils Larsén, nilla000
 *
 * DATUM:         2016-12-15
 *
 * BESKRIVNING:   Inkluderingsfil för klassen Highscore.
 */
#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <functional>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "globaldefines.h"

#define NUMBER_OF_TEXTFIELDS 3


class Highscore
{
public:
    Highscore();
    ~Highscore() = default;
    //skriver resultat längst ner till fil
    void setHighscore(std::string, int);
    //skriver ut highscore på skärmen, avslutas med Q
    void showHighscore(sf::RenderWindow &);

private:
    //läser in highscore från fil
    void getHighscore();
    //delar in highscorelistan i poäng och namnn
    void splitVectorIntoPair();
    //sorterar highscorelistan i fallande ordning
    void sortHighscore();
    //renderar och visar ett förbestämt antal highscoreresultat
    void drawHighscore(sf::RenderWindow &);
    //laddar in typsnitt, sätter färger och skrier ut
    void prepareEverythingToDraw();

    //sting som lagrar highscoren vid inläsning i getHighscore()
    std::vector<std::string> stringFromFileVector{};
    std::vector<std::pair<int, std::string>> highscore{};

    sf::Font font;
    sf::Text text[NUMBER_OF_TEXTFIELDS];
    sf::Text highscoreNames[NR_OF_HIGHSCORES];
    sf::Text highscorePoints[NR_OF_HIGHSCORES];
};

//bool operator>(std::string const & input, Highscore & list);

#endif
