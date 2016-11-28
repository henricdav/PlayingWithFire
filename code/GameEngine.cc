

#include "GameEngine.h"

int GameEngine::run(std::vector<std::string>* playerNamesPtr, std::vector<int>* playerColorsPtr, sf::RenderWindow* windowPtr)
{
    windowPtr->clear(sf::Color::Green);

    std::cout << "NAME: " << playerNamesPtr->at(0) <<
    " - COLOR: " << playerColorsPtr->at(0) << std::endl;

    std::cout << "NAME: " << playerNamesPtr->at(1) <<
    " - COLOR: " << playerColorsPtr->at(1) << std::endl;

    windowPtr->display();

    return 0;
}
