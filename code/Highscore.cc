#include "Highscore.h"

Highscore::Highscore()
    : highscore{}
{}

void Highscore::getHighscore()
{
    //std::cout << "getHighscore" << std::endl;
    std::string highscoreName = "Highscore.list";
    std::ifstream inputFile;
    inputFile.open(highscoreName);
    std::string listInput;
    while(getline(inputFile, listInput))
    {
        std::cout << listInput << std::endl;
        highscore.push_back(listInput);
    }
    inputFile.close();
}

void Highscore::setHighscore(int & value)
{
    std::cout << "setHighscore" << value << std::endl;
    std::string highscoreName = "Highscore.list";
    std::ifstream highscoreFile;
    highscoreFile.open(highscoreName);
    std::string list;
    while(getline(highscoreFile, list))
    {
        
    }
    highscoreFile.close();
}

unsigned int Highscore::getSize()
{
    unsigned int highscoreSize{};
    std::string highscoreName = "Highscore.list";
    std::ifstream inputFile;
    inputFile.open(highscoreName);
    std::string listInput;
    while(getline(inputFile, listInput))
    {
        ++highscoreSize;
    }
    inputFile.close();
    return highscoreSize;
}

bool operator>(std::string const & input, Highscore & list)
{
    std::cout << input << std::endl;
    for(unsigned int i=0;i<list.getSize();++i)
    {
        std::cout << "hej" << std::endl;
    }
    return true;
}
/*
void Highscore::showHighscore()
{
    std::string line{};
    while(std::getline(highscore, line))
    {
        std::cout << line << std::endl;
    }
}
*/
