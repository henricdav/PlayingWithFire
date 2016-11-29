#include "Menu.h"

Menu::Menu()
    :   playerNames{}, playerColors{},
        window(sf::VideoMode(750,750), "Lek inte med elden II - Återkomsten"),
        font{}, game{}, item_index{}, game_running{}, rect{}
{
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    if (!font.loadFromFile("Figures/arial.ttf"))
    {
        std::cout << "fontfail" << std::endl;
        //return EXIT_FAILURE
    }

    double width = window.getSize().x;
    double height = window.getSize().y;

    rect.setSize(sf::Vector2f(200, 500));
    rect.setFillColor(sf::Color::Black);
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(5);
    rect.setPosition(sf::Vector2f(width/10, height/5));

    // SET THE WIDTH BELOW IN A BETTER WAY!

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::White);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width/6, height/(NUMBER_OF_ITEMS+1)*1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Highscore");
    menu[1].setPosition(sf::Vector2f(width/6, height/(NUMBER_OF_ITEMS+1)*2));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(width/6, height/(NUMBER_OF_ITEMS+1)*3));

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
                    case 0: // PLAY GAME
                        configBeforeRun(event);
                        if (playerNames.size() == 2)  // REMOVE HÅRDKOD
                        {
                            game_running = true;
                        }
                        while (game_running)
                        {
                            game.run(&playerNames, &playerColors, &window);
                        }
                        break;

                    case 1: // OPEN HIGHSCORE
                        while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                        {
                            std::cout << "GO TO HIGHSCORE LIST" << std::endl;
                        }
                        break;

                    case 2: // EXIT GAME
                        window.close();
                        break;
                    }
                    default: break;

                case sf::Keyboard::Escape:  // MAYBE REMOVE THIS LATER
                    window.close();
                    break;
                }
                default: break;
            }
        }

        window.clear(sf::Color::Black);
        window.draw(rect);
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

int Menu::configBeforeRun(sf::Event event)
{
    std::string name;
    sf::Text config_text[5];

    config_text[0].setPosition(750/2-100, 50);
    config_text[0].setColor(sf::Color::Green);
    config_text[0].setFont(font);
    config_text[0].setString("CONFIG MENU");
    config_text[0].setStyle(sf::Text::Underlined && sf::Text::Bold);

    config_text[1].setPosition(100, 100);
    config_text[1].setColor(sf::Color::White);
    config_text[1].setFont(font);
    config_text[1].setString("Name player 1: ");

    //INPUT PLAYER 1
    config_text[2].setPosition(325, 100);
    config_text[2].setColor(sf::Color::White);
    config_text[2].setFont(font);

    config_text[3].setPosition(100, 200);
    config_text[3].setColor(sf::Color::White);
    config_text[3].setFont(font);
    config_text[3].setString("Name player 2: ");

    //INPUT PLAYER 2
    config_text[4].setPosition(325, 200);
    config_text[4].setColor(sf::Color::White);
    config_text[4].setFont(font);

    while (playerNames.size() < 2)
    {
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode >= 32 && event.text.unicode <= 126)
                {
                    name.push_back(static_cast<char>(event.text.unicode));
                    if (playerNames.size() == 0)
                    {
                        config_text[2].setString(name);
                    }
                    else
                    {
                        config_text[4].setString(name);
                    }
                }
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
            {
                if (name.size() > 0)
                {
                    name.pop_back();
                    if (playerNames.size() == 0)
                    {
                        config_text[2].setString(name);
                    }
                    else
                    {
                        config_text[4].setString(name);
                    }
                }
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
            {
                if (name.size() > 0)
                {
                    playerNames.push_back(name);
                    name = "";
                }
            }
        }

        window.clear(sf::Color::Black);

        for (int i=0; i < 5; i++)
        {
            window.draw(config_text[i]);
        }


        playerColors.push_back(1);
        playerColors.push_back(2);
        window.display();

    }
    return 0;


}
