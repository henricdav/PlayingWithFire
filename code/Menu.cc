#include "Menu.h"

Menu::Menu()
    :   playerNames{}, playerColors{},
        window(sf::VideoMode(750,750), "Lek inte med elden II"), font{},
        game{}, item_index{}
{
    window.setFramerateLimit(60);

    if (!font.loadFromFile("Figures/arial.ttf"))
    {
        std::cout << "fontfail" << std::endl;
        //return EXIT_FAILURE
    }

    double width = window.getSize().x;
    double height = window.getSize().y;

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::White);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width/2-15, height/(NUMBER_OF_ITEMS+1)*1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Highscore");
    menu[1].setPosition(sf::Vector2f(width/2-30, height/(NUMBER_OF_ITEMS+1)*2));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(width/2-15, height/(NUMBER_OF_ITEMS+1)*3));

    item_index = 0;
}

int Menu::run()
{
    while (window.isOpen())
    {
        window.clear(sf::Color::Black);

        // Check window events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                moveUp();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                moveDown();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                switch (selectedItem())
                {
                    case 0:
                    {
                        std::cout << "PLAY!" << std::endl;
                        while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                        {
                            configBeforeRun();
                            game.run(&playerNames, &playerColors, &window);
                        }
                    }
                    case 1:
                    {
                        while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                        {
                            // GO TO HIGHSCORE LIST
                        }
                    }
                    case 2:
                    {
                        std::cout << "EXIT" << std::endl;
                        // FUCKAR UPP AV NÅGON ANLEDNING
                        //window.close();
                    }
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }

        draw();
        window.display();
        sf::sleep(sf::milliseconds(10));
    }
    return 0;
}

void Menu::draw()
{
    for (int i=0; i < NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}

void Menu::moveUp()
{
    if (item_index - 1 >= 0)
    {
        menu[item_index].setColor(sf::Color::White);
        item_index--;
        menu[item_index].setColor(sf::Color::Green);
    }
}

void Menu::moveDown()
{
    if (item_index + 1 < NUMBER_OF_ITEMS)
    {
        menu[item_index].setColor(sf::Color::White);
        item_index++;
        menu[item_index].setColor(sf::Color::Green);
    }
}

int Menu::selectedItem()
{
    return item_index;
}

int Menu::configBeforeRun()
{
    playerNames.push_back("NiPPeHaXxX");
    playerNames.push_back("FriPPeFlaXxX");
    playerColors.push_back(1);
    playerColors.push_back(2);
    //window.clear(sf::Color::Blue);
    //window.display();
    return 0;
}
