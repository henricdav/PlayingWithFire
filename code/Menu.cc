

#include "Menu.h"


Menu::Menu()
    :   playerNames{}, playerColors{}, window(sf::VideoMode(750,750), "Lek inte med elden II")
{
    window.setFramerateLimit(60);
}

void Menu::run()
{
    while (window.isOpen())
    {
        window.clear(sf::Color::White);

        // Check window events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {

            game.run(window);
        }

        window.display();
    }
}
