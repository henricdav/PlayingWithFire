/*
Klassen Highscore
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

    void setHighscore(std::string, int);
    void showHighscore(sf::RenderWindow &);

private:
    void getHighscore();
    void splitVectorIntoPair();
    void sortHighscore();
    void drawHighscore(sf::RenderWindow &);
    void prepareEverythingToDraw();

    std::vector<std::string> stringFromFileVector{};
    std::vector<std::pair<int, std::string>> highscore{};

    sf::Font font;
    sf::Text text[NUMBER_OF_TEXTFIELDS];
    sf::Text highscoreNames[NR_OF_HIGHSCORES];
    sf::Text highscorePoints[NR_OF_HIGHSCORES];
};

//bool operator>(std::string const & input, Highscore & list);

#endif
