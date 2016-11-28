

#include "GameEngine.h"

int GameEngine::run(std::vector<std::string>* playerNamesPtr, std::vector<int>* playerColorsPtr, sf::RenderWindow* windowPtr)
{
    std::cout << "hej" << std::endl;
    windowPtr->clear(sf::Color::Green);
    std::cout << playerNamesPtr->at(0) << std::endl;
    std::cout << playerColorsPtr->at(0) << std::endl;

    return 0;
}
