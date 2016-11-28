

#include "GameEngine.h"

void GameEngine::getCommands()
{
    commands[0] = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A);
    commands[1] = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);
    commands[2] = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
    commands[3] = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S);
    commands[4] = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::B);
    commands[5] = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
    commands[6] = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
    commands[7] = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
    commands[8] = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
    commands[9] = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad0);
}

int GameEngine::run(std::vector<std::string>* playerNamesPtr, std::vector<int>* playerColorsPtr, sf::RenderWindow* windowPtr)
{
    while (true)
    {
        getCommands();

        if (commands[9] == true)
        {
            std::cout << "Numpad0 pressed!" << std::endl;
        }

        if(false)
        {
            std::cout << playerColorsPtr->at(0) << playerNamesPtr->at(0);
        }

        windowPtr->clear(sf::Color::Green);
        windowPtr->display();
        sf::sleep(sf::milliseconds(10));
    }



    // std::cout << "hej" << std::endl;
    // windowPtr->clear(sf::Color::Green);
    // std::cout << playerNamesPtr->at(0) << std::endl;
    // std::cout << playerColorsPtr->at(0) << std::endl;
    return 0;
}
