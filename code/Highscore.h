/*
Klassen Highscore
*/
#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "globaldefines.h"

class Highscore
{
public:
    Highscore();
    ~Highscore() = default;

    void getHighscore();
    void setHighscore(int &);
    unsigned int getSize();
    //void showHighscore();
private:
    std::vector<std::string> highscore{};
};

bool operator>(std::string const & input, Highscore & list);

#endif
