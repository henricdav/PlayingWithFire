

#include "Menu.h"


Menu::Menu()
    :   playerNames{"Henric"}, playerColors{1},
        window(sf::VideoMode(750,750), "Lek inte med elden II"),
        game{}
{
    window.setFramerateLimit(60);
}

int Menu::run()
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
            game.run(&playerNames, &playerColors, &window);
        }

        window.display();
        sf::sleep(sf::milliseconds(10));
    }
    return 0;
}
