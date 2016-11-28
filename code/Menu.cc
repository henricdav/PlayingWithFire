

#include "Menu.h"


Menu::Menu()
    :   playerNames{"Henric"}, playerColors{1},
        window(sf::VideoMode(750,750), "Lek inte med elden II"), font{},
        game{}
{
    window.setFramerateLimit(60);

    if (!font.loadFromFile("/home/johal611/TDDC76/mats-3/code/Figures/arial.ttf"))
        std::cout << "fontfail" << std::endl;
        //return EXIT_FAILURE

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(750/2, 200));

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
            {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            //std::cout << "tjema" << std::endl;
            game.run(&playerNames, &playerColors, &window);
        }
        draw();
        window.display();
        sf::sleep(sf::milliseconds(10));
    }
    return 0;
}

void Menu::draw()
{
    std::cout << "tma" << std::endl;

    for (int i=0; i < NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }

}
