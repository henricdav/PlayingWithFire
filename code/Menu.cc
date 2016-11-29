#include "Menu.h"

Menu::Menu()
    :   playerNames{}, playerColors{},
        window(sf::VideoMode(750,750), "Lek inte med elden II - Aterkomsten"),
        font{}, game{}, item_index{}, game_running{}
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
    /*
    rect.setSize(sf::Vector2f(200, 500));
    rect.setFillColor(sf::Color::Black);
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(5);
    rect.setPosition(sf::Vector2f(width/10, height/3));
    */
    if (!start_page_tex[0].loadFromFile("Figures/flame_sprite.png"))
    {
        std::cout << "Failed to load flame sprite" << std::endl;
    }
    start_page_sprite[0].setTexture(start_page_tex[0]);
    start_page_sprite[0].setPosition(width/2-50, height/2);

    if (!start_page_tex[1].loadFromFile("Figures/monster_sprite.png"))
    {
        std::cout << "Failed to load monster sprite" << std::endl;
    }

    start_page_sprite[1].setTexture(start_page_tex[1]);
    start_page_sprite[1].setPosition(width-200, height-300);

    if (!start_page_tex[2].loadFromFile("Figures/menu-title.png"))
    {
        std::cout << "Failed to load title" << std::endl;
    }
    start_page_sprite[2].setTexture(start_page_tex[2]);
    start_page_sprite[2].setPosition(100, 30);
    start_page_sprite[2].setTextureRect(sf::IntRect(0, 0, 534, 214));

    // SET THE WIDTH BELOW IN A BETTER WAY!

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::White);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width/6, height/(NUMBER_OF_ITEMS+1)*1+100));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Highscore");
    menu[1].setPosition(sf::Vector2f(width/6, height/(NUMBER_OF_ITEMS+1)*2+100));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(width/6, height/(NUMBER_OF_ITEMS+1)*3+100));

    item_index = 0;
    game_running = false;
}

int Menu::run()
{   int count1 = 0;
    int count2 = 0;
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

        window.clear(sf::Color::Black);
        //window.draw(rect);
        draw();

        window.display();
        sf::sleep(sf::milliseconds(50));
    }
    return 0;
}

void Menu::draw()
{
    for (int i=0; i < NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
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
    int count = 0;

    config_text[0].setPosition(750/2-100, 50);
    config_text[0].setColor(sf::Color::Green);
    config_text[0].setFont(font);
    config_text[0].setString("CONFIG MENU");
    config_text[0].setStyle(sf::Text::Underlined);

    config_text[1].setPosition(200, 200);
    config_text[1].setColor(sf::Color::White);
    config_text[1].setFont(font);
    config_text[1].setString("Player 1: ");

    //INPUT PLAYER 1
    config_text[2].setPosition(425, 200);
    config_text[2].setColor(sf::Color::White);
    config_text[2].setFont(font);

    config_text[3].setPosition(200, 400);
    config_text[3].setColor(sf::Color::White);
    config_text[3].setFont(font);
    config_text[3].setString("Player 2: ");

    //INPUT PLAYER 2
    config_text[4].setPosition(425, 400);
    config_text[4].setColor(sf::Color::White);
    config_text[4].setFont(font);

    sf::Texture tex;
    tex.loadFromFile("Figures/WalkingGirl-300px.png");
    sf::Sprite menu_girl;
    menu_girl.setTexture(tex);
    menu_girl.setPosition(50, 200-87/2);
    //menu_girl.setTextureRect(sf::IntRect(300/4 * count, 0, 300/4, 87));

    while (playerNames.size() < 2)
    {
        menu_girl.move(0, 0);
        menu_girl.setTextureRect(sf::IntRect(300/4 * count, 0, 300/4, 87));
        sf::sleep(sf::milliseconds(100));
        count++;
        if (count == 3)
        {
            count = 0;
        }
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
        window.draw(menu_girl);

        playerColors.push_back(1);
        playerColors.push_back(2);
        window.display();

    }
    return 0;


}
