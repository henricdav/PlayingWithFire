#include "Menu.h"

Menu::Menu()
    :   playerNames{}, playerColors{},
        window(sf::VideoMode(X_OFFSET+TILES_X*TILE_SIZE,Y_OFFSET+TILES_Y*TILE_SIZE), "Lek inte med elden II - Aterkomsten"),
        font{}, item_index{}, game_running{}, game{}
{
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

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
    start_page_sprite[0].setPosition(width/5, height-300);

    if (!start_page_tex[1].loadFromFile("Figures/monster_sprite.png"))
    {
        std::cout << "Failed to load monster sprite" << std::endl;
    }
    start_page_sprite[1].setTexture(start_page_tex[1]);
    start_page_sprite[1].setPosition(width-350, height-250);

    if (!start_page_tex[2].loadFromFile("Figures/title_sprite.png"))
    {
        std::cout << "Failed to load title" << std::endl;
    }
    start_page_sprite[2].setTexture(start_page_tex[2]);
    start_page_sprite[2].setPosition(100, 50);
    start_page_sprite[2].setTextureRect(sf::IntRect(0, 0, 534, 165));

    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::White);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width/2-35, height/(NUMBER_OF_ITEMS)+50));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Highscore");
    menu[1].setPosition(sf::Vector2f(width/2-75, height/(NUMBER_OF_ITEMS)+100));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("About");
    menu[2].setPosition(sf::Vector2f(width/2-50, height/(NUMBER_OF_ITEMS)+150));

    menu[3].setFont(font);
    menu[3].setFillColor(sf::Color::White);
    menu[3].setString("Exit");
    menu[3].setPosition(sf::Vector2f(width/2-35, height/(NUMBER_OF_ITEMS)+200));

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
                        game.run(playerNames, playerColors, window);
                        break;

                    case 1: // OPEN HIGHSCORE
                        while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                        {
                            std::cout << "OPEN HIGHSCORE" << std::endl;
                        }
                        break;

                    case 2: // ABOUT
                        std::cout << "ABOUT PAGE" << std::endl;
                        break;

                    case 3: // EXIT GAME
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
    for (int i=0; i < NUMBER_OF_ITEMS; i++)
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
    if (item_index + 1 < NUMBER_OF_ITEMS)
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
    input_text[0].setPosition(330, 225);
    input_text[0].setFillColor(sf::Color::White);
    input_text[0].setFont(font);

    //INPUT PLAYER 2
    input_text[1].setPosition(330, 325);
    input_text[1].setFillColor(sf::Color::White);
    input_text[1].setFont(font);

    sf::Text config_text[4];

    config_text[0].setPosition(200, 225);
    config_text[0].setFillColor(sf::Color::White);
    config_text[0].setFont(font);
    config_text[0].setString("Player 1: ");

    config_text[1].setPosition(200, 325);
    config_text[1].setFillColor(sf::Color::White);
    config_text[1].setFont(font);
    config_text[1].setString("Player 2: ");

    config_text[2].setPosition(750/2-100, 50);
    config_text[2].setFillColor(sf::Color::Green);
    config_text[2].setFont(font);
    config_text[2].setString("CONFIG MENU");
    config_text[2].setStyle(sf::Text::Underlined);

    config_text[3].setPosition(750/2-125, 100);
    config_text[3].setFillColor(sf::Color::White);
    config_text[3].setFont(font);
    config_text[3].setCharacterSize(22);
    config_text[3].setString("Enter name and press enter");

    sf::RectangleShape line;
    line.setSize(sf::Vector2f(700, 300));
    line.setOutlineColor(sf::Color::White);
    line.setFillColor(sf::Color::Black);
    line.setOutlineThickness(1);
    line.setPosition(750/2-350, 150);

    sf::Texture tex[2];
    tex[0].loadFromFile("Figures/capguy_sprite.png");
    tex[1].loadFromFile("Figures/minecraft_sprite.png");

    sf::Sprite show_character[2];
    show_character[0].setTexture(tex[0]);
    show_character[0].setPosition(50, 180);
    show_character[1].setTexture(tex[1]);
    show_character[1].setPosition(50, 280);

    std::string tmp_name;
    int count = 0;

    while (playerNames.size() < 2)
    {
        while(window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::TextEntered:
                if (event.text.unicode >= 32 && event.text.unicode <= 126)
                {
                    tmp_name.push_back(static_cast<char>(event.text.unicode));
                    if (playerNames.size() == 0)
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
                    if (tmp_name.size() > 0)
                    {
                        tmp_name.pop_back();
                        if (playerNames.size() == 0)
                        {
                            input_text[0].setString(tmp_name);
                        }
                        else
                        {
                            input_text[1].setString(tmp_name);
                        }
                    }
                    break;

                case sf::Keyboard::Return:
                    if (tmp_name.size() > 0 && tmp_name != " ")
                    {
                        playerNames.push_back(tmp_name);
                        tmp_name = "";
                    }
                    break;

                    default: break;
                }
                default: break;
            }
        }

        show_character[0].setTextureRect(sf::IntRect(394/8 * count, 0, 394/8, 87));
        show_character[1].setTextureRect(sf::IntRect(394/8 * count, 0, 394/8, 87));
        sf::sleep(sf::milliseconds(50));
        count++;
        if (count == 7)
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
    if (playerNames.size() == 2)
    {
        game_running = true;
        playerColors.push_back(1);
        playerColors.push_back(2);
    }
    return 0;


}
