

#include "GameEngine.h"


GameEngine::GameEngine()
: commands{std::vector<bool>(10, false)}
{
    static_texture.loadFromFile("Texture/Ground_2.jpg");
    static_object.setTexture(static_texture);
    static_object.setTextureRect(sf::IntRect(0, 0, 50, 50));
}


void GameEngine::run(std::vector<std::string> & playerNames,
    std::vector<int> & playerColors,
    sf::RenderWindow & window)
    {
        bool terminated{false};
        while (!terminated)
        {
            sf::Event event;
            while (window.pollEvent(event))
            {

                if (event.type == sf::Event::Closed)
                {
                    terminated = true;
                    std::cout << "Stänger!";
                }
            }

            window.clear(sf::Color::White);
            drawWindowFromMap(window);
            getCommands();
            moveObjects();
            dropBombs();
            updateBombs();

            drawObjects(window);

            if (commands[9] == true)
            {
                window.draw(player1.sprite);
                std::cout << "Numpad0 pressed!" << std::endl;
            }

            if(false)
            {
                std::cout << playerColors.at(0) << playerNames.at(0);
            }

            //window.clear(sf::Color::Green);
            window.display();
            sf::sleep(sf::milliseconds(20));

        }
        std::cout << "Slut!" << std::endl;
        // std::cout << playerNames.at(0) << std::endl;
        // std::cout << playerColors.at(0) << std::endl;

    }

    void GameEngine::drawWindowFromMap(sf::RenderWindow & window)
    {
        for (int i{0}; i < TILES_X; i++)
        {
            for (int j{0}; j < TILES_Y; j++)
            {
                int A = map.getCoord(i, j);
                if (A==1){
                    static_object.setPosition(sf::Vector2f(X_OFFSET+i*50, Y_OFFSET+j*50));
                    window.draw(static_object);
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

        if (commands[0]) {player1.move(sf::Vector2f(-player1.getSpeed(), 0), std::make_shared<Map>(map));}
        if (commands[1]) {player1.move(sf::Vector2f(player1.getSpeed(), 0), std::make_shared<Map>(map));}
        if (commands[2]) {player1.move(sf::Vector2f(0, -player1.getSpeed()), std::make_shared<Map>(map));}
        if (commands[3]) {player1.move(sf::Vector2f(0, player1.getSpeed()), std::make_shared<Map>(map));}
        if (commands[4]) {}
        if (commands[5]) {player2.move(sf::Vector2f(-player2.getSpeed(), 0), std::make_shared<Map>(map));}
        if (commands[6]) {player2.move(sf::Vector2f(player2.getSpeed(), 0), std::make_shared<Map>(map));}
        if (commands[7]) {player2.move(sf::Vector2f(0, -player2.getSpeed()), std::make_shared<Map>(map));}
        if (commands[8]) {player2.move(sf::Vector2f(0, player2.getSpeed()), std::make_shared<Map>(map));}
        if (commands[9]) {}
    }

    void GameEngine::dropBombs()
    {
        if (!(bombs.empty()) && (*bombs.begin())->isDetonated())
        {
            bombs.erase(bombs.begin());
        }

        if (commands[4])
        {
            bombs.push_back(std::make_shared<Bomb>(std::make_shared<Character>(player1), std::make_shared<Map>(map)));
            std::cout << "Dropping bombs!" << std::endl;
        }
    }

    void GameEngine::updateBombs()
    {
        for (unsigned int i{0}; i < bombs.size(); ++i)
        {
            bombs.at(i)->update();
        }
    }

    void GameEngine::drawObjects(sf::RenderWindow & window)
    {
        window.draw(player1.sprite);
        window.draw(player2.sprite);
        for (unsigned int i{0}; i < bombs.size(); ++i)
        {
            window.draw(bombs.at(i)->sprite);
        }
    }
