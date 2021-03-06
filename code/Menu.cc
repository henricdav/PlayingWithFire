/*
 * FILNAMN:       Menu.cc
 * PROJEKT:       TDDC76-Projekt
 * PROGRAMMERARE: Johan Almgren, johal611
 *                Fredrik Björklund, frebj191
 *                Henric Davidsson, henda274
 *                Nils Larsén, nilla000
 *
 * DATUM:         2016-12-15
 *
 * BESKRIVNING:   Implementeringsfil för klassen Menu.
 */


#include "Menu.h"

Menu::Menu()
    :   playerNames{}, playerColors{},
        window(sf::VideoMode(X_OFFSET+TILES_X*TILE_SIZE,Y_OFFSET+TILES_Y*TILE_SIZE), "Lek inte med elden II - Aterkomsten"),
        font{}

{
    window.setFramerateLimit(60);

    if (!font.loadFromFile("Figures/arial.ttf"))
    {
        std::cout << "Failed to load font" << std::endl;
    }

    double width = window.getSize().x;
    double height = window.getSize().y;

    if (!start_page_tex[0].loadFromFile("Figures/flame_sprite.png"))
    {
        std::cout << "Failed to load flame sprite" << std::endl;
    }
    start_page_sprite[0].setTexture(start_page_tex[0]);
    start_page_sprite[0].setPosition(width/5+X_OFFSET, height-300+Y_OFFSET);

    if (!start_page_tex[1].loadFromFile("Figures/monster_sprite.png"))
    {
        std::cout << "Failed to load monster sprite" << std::endl;
    }
    start_page_sprite[1].setTexture(start_page_tex[1]);
    start_page_sprite[1].setPosition(width-350+X_OFFSET, height-250+Y_OFFSET);

    if (!start_page_tex[2].loadFromFile("Figures/title_sprite.png"))
    {
        std::cout << "Failed to load title" << std::endl;
    }
    start_page_sprite[2].setTexture(start_page_tex[2]);
    start_page_sprite[2].setPosition(100+X_OFFSET, 50+Y_OFFSET);
    start_page_sprite[2].setTextureRect(sf::IntRect(0, 0, 534, 165));

    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::White);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width/2-35+X_OFFSET, height/(NUMBER_OF_TEXT_FIELDS)+50+Y_OFFSET));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Highscore");
    menu[1].setPosition(sf::Vector2f(width/2-75+X_OFFSET, height/(NUMBER_OF_TEXT_FIELDS)+100+Y_OFFSET));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(width/2-35+X_OFFSET, height/(NUMBER_OF_TEXT_FIELDS)+150+Y_OFFSET));

    item_index = 0;
    count1 = 0;
    count2 = 0;
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
                    {
                        configBeforeRun(event);
                        if (playerNames.size() != NUMBER_OF_PLAYERS)
                        {
                            break;
                        }

                        GameEngine game{};
                        game.run(playerNames, playerColors, window);

                        for (unsigned int i{0}; i <= playerNames.size();  ++i)
                        {
                            playerNames.erase(playerNames.begin());
                            playerColors.erase(playerColors.begin());
                        }
                        break;
                    }

                    case 1: // OPEN HIGHSCORE
                    {
                        Highscore highscore{};
                        highscore.showHighscore(window);
                        break;
                    }

                    case 2: // EXIT GAME
                        window.close();
                        break;
                    }
                    default: break;

                case sf::Keyboard::Escape:
                    window.close();
                    break;
                }
                default: break;

            case sf::Event::MouseButtonPressed:
                std::cout << "Mouse click not supported" << std::endl;
                break;
            }
        }

        window.clear(sf::Color::Black);
        drawMenuText();
        drawMenuSprites();

        window.display();
        sf::sleep(sf::milliseconds(50));
    }
    return 0;
}

void Menu::drawMenuText()
{
    for (int i=0; i < NUMBER_OF_TEXT_FIELDS; i++)
    {
        window.draw(menu[i]);
    }
}

void Menu::drawMenuSprites()
{
    start_page_sprite[0].setTextureRect(sf::IntRect(1536/6*count1, 0, 1536/6, 256));
    count1++;
    if (count1 == 5)
    {
        count1 = 0;
    }

    start_page_sprite[1].setTextureRect(sf::IntRect(910/7*count2, 0, 910/7, 130));
    count2++;
    if (count2 == 6)
    {
        count2 = 0;
    }
    for (int i=0; i < NUMBER_OF_SPRITES; i++)
    {
        window.draw(start_page_sprite[i]);
    }
}

void Menu::moveUp()
{
    if (item_index - 1 >= 0)
    {
        menu[item_index].setFillColor(sf::Color::White);
        item_index--;
        menu[item_index].setFillColor(sf::Color::Green);
    }
}

void Menu::moveDown()
{
    if (item_index + 1 < NUMBER_OF_TEXT_FIELDS)
    {
        menu[item_index].setFillColor(sf::Color::White);
        item_index++;
        menu[item_index].setFillColor(sf::Color::Green);
    }
}

int Menu::selectedItem()
{
    return item_index;
}

int Menu::configBeforeRun(sf::Event event)
{
    sf::Text input_text[2];

    //INPUT PLAYER 1
    input_text[0].setPosition(330+X_OFFSET, 225+Y_OFFSET);
    input_text[0].setFillColor(sf::Color::White);
    input_text[0].setFont(font);

    //INPUT PLAYER 2
    input_text[1].setPosition(330+X_OFFSET, 325+Y_OFFSET);
    input_text[1].setFillColor(sf::Color::White);
    input_text[1].setFont(font);

    sf::Text config_text[4];

    config_text[0].setPosition(200+X_OFFSET, 225+Y_OFFSET);
    config_text[0].setFillColor(sf::Color::White);
    config_text[0].setFont(font);
    config_text[0].setString("Player 1: ");

    config_text[1].setPosition(200+X_OFFSET, 325+Y_OFFSET);
    config_text[1].setFillColor(sf::Color::White);
    config_text[1].setFont(font);
    config_text[1].setString("Player 2: ");

    config_text[2].setPosition(275+X_OFFSET, 50+Y_OFFSET);
    config_text[2].setFillColor(sf::Color::Green);
    config_text[2].setFont(font);
    config_text[2].setString("CONFIG MENU");
    config_text[2].setStyle(sf::Text::Underlined);

    config_text[3].setPosition(175+X_OFFSET, 100+Y_OFFSET);
    config_text[3].setFillColor(sf::Color::White);
    config_text[3].setFont(font);
    config_text[3].setCharacterSize(22);
    config_text[3].setString("Enter name and press space - Esc to go back");

    sf::RectangleShape line;
    line.setSize(sf::Vector2f(700+X_OFFSET, 300+Y_OFFSET));
    line.setOutlineColor(sf::Color::White);
    line.setFillColor(sf::Color::Black);
    line.setOutlineThickness(1);
    line.setPosition(25+X_OFFSET, 150+Y_OFFSET);

    sf::Texture tex[NUMBER_OF_PLAYERS];
    tex[0].loadFromFile("Figures/adaRed.png");
    tex[1].loadFromFile("Figures/danteBlue.png");

    sf::Sprite show_character[NUMBER_OF_PLAYERS];
    show_character[0].setTexture(tex[0]);
    show_character[0].setPosition(50+X_OFFSET, 200+Y_OFFSET);
    show_character[1].setTexture(tex[1]);
    show_character[1].setPosition(50+X_OFFSET, 300+Y_OFFSET);

    std::string tmp_name;
    int count = 0;
    bool config_menu_running = true;

    while (config_menu_running)
    {
        while(window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::TextEntered:
                if (event.text.unicode >= 32 && event.text.unicode <= 126)
                {
                    tmp_name.push_back(static_cast<char>(event.text.unicode));
                    if (playerNames.empty())
                    {
                        input_text[0].setString(tmp_name);
                    }
                    else
                    {
                        input_text[1].setString(tmp_name);
                    }
                }
                break;

            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::BackSpace:
                    if (!tmp_name.empty())
                    {
                        tmp_name.pop_back();
                        if (playerNames.empty())
                        {
                            input_text[0].setString(tmp_name);
                        }
                        else
                        {
                            input_text[1].setString(tmp_name);
                        }
                    }
                    break;

                case sf::Keyboard::Space:
                    if (!tmp_name.empty() && tmp_name != " ")
                    {
                        tmp_name.pop_back();
                        playerNames.push_back(tmp_name);
                        tmp_name = "";
                    }
                    if (playerNames.size() == NUMBER_OF_PLAYERS)
                    {
                        config_menu_running = false;
                    }
                    break;

                case sf::Keyboard::Escape:
                    if (playerNames.size() == NUMBER_OF_PLAYERS - 1)
                    {
                        playerNames.pop_back();
                        tmp_name = "";
                    }
                    config_menu_running = false;
                    break;

                    default: break;
                }
                default: break;
            }
        }

        show_character[0].setTextureRect(sf::IntRect(150, 50*count, 50, 50));
        show_character[1].setTextureRect(sf::IntRect(150, 50*count, 50, 50));
        sf::sleep(sf::milliseconds(50));
        count++;
        if (count == 3)
        {
            count = 0;
        }

        window.clear(sf::Color::Black);

        window.draw(line);
        window.draw(config_text[0]);
        window.draw(config_text[1]);
        window.draw(config_text[2]);
        window.draw(config_text[3]);
        window.draw(input_text[0]);
        window.draw(input_text[1]);
        window.draw(show_character[0]);
        window.draw(show_character[1]);

        window.display();

    }

    // playerColors are binded to player1 and player2 atm.
    if (playerNames.size() == NUMBER_OF_PLAYERS)
    {
        playerColors.push_back(1);
        playerColors.push_back(2);
    }
    return 0;


}
