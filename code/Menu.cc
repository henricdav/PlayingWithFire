#include "Menu.h"

Menu::Menu()
    :   playerNames{}, playerColors{},
        window(sf::VideoMode(750,750), "Lek inte med elden II"), font{},
        game{}, item_index{}, game_running{}
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
    game_running = false;
}

int Menu::run()
{
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    moveUp();
                    break;

                case sf::Keyboard::Down:
                    moveDown();
                    break;

                case sf::Keyboard::Space:
                    switch (selectedItem())
                    {
                    case 0:
                        configBeforeRun();
                        if (playerNames.size() == 2)
                        {
                            game_running = true;
                        }

                        while (game_running)
                        {
                            game.run(&playerNames, &playerColors, &window);
                        }
                    case 1:
                        while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                        {
                            std::cout << "GO TO HIGHSCORE LIST" << std::endl;
                        }
                        break;
                    case 2:
                        window.close();
                        break;
                    }
                    default: break;
                case sf::Keyboard::Escape:
                    window.close();
                    break;
                }
                default: break;
            }
        }

        window.clear(sf::Color::Black);

        draw();

        window.display();
        //sf::sleep(sf::milliseconds(10));
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

    playerNames.push_back("NiPPeFlaXxX");
    playerNames.push_back("FriPPeFlaXxX");
    playerColors.push_back(1);
    playerColors.push_back(2);
    window.clear(sf::Color::Blue);
    window.display();
    return 0;
}
