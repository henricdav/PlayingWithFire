

#include "GameEngine.h"


GameEngine::GameEngine()
: commands{std::vector<bool>(10, false)}
{
    static_texture.loadFromFile("Texture/Ground_2.jpg");
    static_object.setTexture(static_texture);
    static_object.setTextureRect(sf::IntRect(0, 0, 50, 50));
}


void GameEngine::run(std::vector<std::string>* playerNamesPtr,
    std::vector<int>* playerColorsPtr,
    sf::RenderWindow* windowPtr)
    {
        while (windowPtr->isOpen())
        {
            sf::Event event;
            while (windowPtr->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                windowPtr->close();
            }

            windowPtr->clear(sf::Color::White);
            drawWindowFromMap(windowPtr);
            getCommands();
            moveObjects();
            windowPtr->draw(player1.sprite);
            windowPtr->draw(player2.sprite);

            if (commands[9] == true)
            {
                windowPtr->draw(player1.sprite);
                std::cout << "Numpad0 pressed!" << std::endl;
            }

            if(false)
            {
                std::cout << playerColorsPtr->at(0) << playerNamesPtr->at(0);
            }

            //windowPtr->clear(sf::Color::Green);
            windowPtr->display();
            sf::sleep(sf::milliseconds(10));

        }

        // std::cout << playerNamesPtr->at(0) << std::endl;
        // std::cout << playerColorsPtr->at(0) << std::endl;
        //return 0;
    }

    void GameEngine::drawWindowFromMap(sf::RenderWindow* windowPtr)
    {
        for (int i{0}; i < TILES_X; i++)
        {
            for (int j{0}; j < TILES_Y; j++)
            {
                int A = map.getCoord(i, j);
                if (A==1){
                    static_object.setPosition(sf::Vector2f(X_OFFSET+i*50, Y_OFFSET+j*50));
                    windowPtr->draw(static_object);
                }
            }
        }
    }


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

    void GameEngine::moveObjects()
    {

        if (commands[0]) {player1.move(sf::Vector2f(-player1.getSpeed(), 0), &map);}
        if (commands[1]) {player1.move(sf::Vector2f(player1.getSpeed(), 0), &map);}
        if (commands[2]) {player1.move(sf::Vector2f(0, -player1.getSpeed()), &map);}
        if (commands[3]) {player1.move(sf::Vector2f(0, player1.getSpeed()), &map);}
        if (commands[4]) {}
        if (commands[5]) {player2.move(sf::Vector2f(-player2.getSpeed(), 0), &map);}
        if (commands[6]) {player2.move(sf::Vector2f(player2.getSpeed(), 0), &map);}
        if (commands[7]) {player2.move(sf::Vector2f(0, -player2.getSpeed()), &map);}
        if (commands[8]) {player2.move(sf::Vector2f(0, player2.getSpeed()), &map);}
        if (commands[9]) {}
    }



    void GameEngine::dropBombs(){}
