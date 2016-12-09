

#include "GameEngine.h"


GameEngine::GameEngine()
: commands{std::vector<bool>(10, false)}
{
    initTextures();
}

void GameEngine::initTextures()
{
    static_textures.resize(TILE_TYPES);
    static_objects.resize(TILE_TYPES);
    std::vector<std::string> filenames{
        "Texture/Ground_2.jpg",
        "Texture/explosion.png",
        "Texture/RTS_Crate.png",
        "Texture/RTS_Crate.png",
        "Texture/RTS_Crate.png",
        "Texture/RTS_Crate.png",
        "Texture/RTS_Crate.png",
        "Texture/RTS_Crate.png",
        "Texture/shoe-powerup.png",
        "Texture/extrabomb-powerup.png",
        "Texture/bombrange-powerup.png",
        "Texture/health-powerup.png",
        "Texture/bombmover-powerup.jpg"};

    for (int i = 0; i < TILE_TYPES; ++i)
    {
        static_textures[i].loadFromFile(filenames[i]);
        static_objects[i].setTexture(static_textures[i]);
        static_objects[i].setTextureRect(sf::IntRect(0, 0, 50, 50));
        static_object.setTexture(static_textures[0]);
        static_object.setTextureRect(sf::IntRect(0, 0, 50, 50));
    }

    setUpText();
}

void GameEngine::setUpText()
{
    if (!font.loadFromFile("Figures/arial.ttf"))
    {
        std::cerr << "Couldn't load font" << std:: endl;
    }

    for (int i = 0; i < TEXT_FIELDS; i++)
    {
        text[i].setFont(font);
        text[i].setFillColor(sf::Color::Black);
        if (i == 0)
        {
            text[i].setCharacterSize(150);
        }
    }

    text[0].setPosition(sf::Vector2f(TILE_SIZE*TILES_X/2-75+X_OFFSET, TILE_SIZE*TILES_Y/2-150+Y_OFFSET));
    text[1].setPosition(sf::Vector2f(TILE_SIZE, TILE_SIZE/4));
    text[2].setPosition(sf::Vector2f(TILE_SIZE, TILE_SIZE*TILES_Y-TILE_SIZE*(1-1/4)));
    text[3].setPosition(sf::Vector2f(TILE_SIZE*7, TILE_SIZE/4));
    text[4].setPosition(sf::Vector2f(TILE_SIZE*7, TILE_SIZE*TILES_Y-TILE_SIZE*(1-1/4)));
    text[5].setPosition(sf::Vector2f(TILE_SIZE*4, TILE_SIZE/4));
    text[6].setPosition(sf::Vector2f(TILE_SIZE*4, TILE_SIZE*TILES_Y-TILE_SIZE*(1-1/4)));
}


void GameEngine::run(std::vector<std::string> & playerNames,
                     std::vector<int> & playerColors,
                     sf::RenderWindow & window)
{
    player1.initCharacter(playerNames.at(0), playerColors.at(0));
    player2.initCharacter(playerNames.at(1), playerColors.at(1));

    characters.push_back(player1);
    characters.push_back(player2);

    bool terminated{false};
    while (!terminated)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                terminated = true;
            }
        }

        window.clear(sf::Color::White);

        drawWindowFromMap(window);
        drawObjects(window);
        drawText(window);

        if (gameTimer.getElapsedTime().asSeconds() > 3)
        {
            getCommands();
            moveObjects();
            dropBombs();
            updateBombs();
            updateCharacters();
            checkGameOver(terminated);
        }
        else
        {
            showTimer(window);
        }

        window.display();

        sf::sleep(sf::milliseconds(20));

    }
}

void GameEngine::drawText(sf::RenderWindow & window)
{
    text[1].setString(characters[0].getName());
    text[2].setString(characters[1].getName());
    text[3].setString(std::to_string(characters[0].getLife()));
    text[4].setString(std::to_string(characters[1].getLife()));
    text[5].setString("| HEALTH");
    text[6].setString("| HEALTH");
    for (int i{1}; i < TEXT_FIELDS; ++i)
    {
        window.draw(text[i]);
    }

}

void GameEngine::drawWindowFromMap(sf::RenderWindow & window)
{
    for (int i{0}; i < TILES_X; i++)
    {
        for (int j{0}; j < TILES_Y; j++)
        {
            int curr{map.getCoord(MapCoords(i, j))};
            if (curr != 0) // No texture for empty tiles.
            {
                static_objects[curr - 1].setPosition(sf::Vector2f(X_OFFSET + i * 50, Y_OFFSET + j * 50));
                window.draw(static_objects[curr - 1]);
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
    commands[9] = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P);
}

void GameEngine::moveObjects()
{
    if (commands[0]) {characters[0].move(sf::Vector2f(-characters[0].getSpeed(), 0), std::make_shared<Map>(map));}
    if (commands[1]) {characters[0].move(sf::Vector2f(characters[0].getSpeed(), 0), std::make_shared<Map>(map));}
    if (commands[2]) {characters[0].move(sf::Vector2f(0, -characters[0].getSpeed()), std::make_shared<Map>(map));}
    if (commands[3]) {characters[0].move(sf::Vector2f(0, characters[0].getSpeed()), std::make_shared<Map>(map));}
    if (commands[4]) {}
    if (commands[5]) {characters[1].move(sf::Vector2f(-characters[1].getSpeed(), 0), std::make_shared<Map>(map));}
    if (commands[6]) {characters[1].move(sf::Vector2f(characters[1].getSpeed(), 0), std::make_shared<Map>(map));}
    if (commands[7]) {characters[1].move(sf::Vector2f(0, -characters[1].getSpeed()), std::make_shared<Map>(map));}
    if (commands[8]) {characters[1].move(sf::Vector2f(0, characters[1].getSpeed()), std::make_shared<Map>(map));}
    if (commands[9]) {}
}

void GameEngine::dropBombs()
{
    if (!(bombs.empty()) && (*bombs.begin())->isDetonated())
    {
        bombs.erase(bombs.begin());
    }

    if (commands[4] && characters[0].dropBomb())
    {
        characters[0].resetBombTimer();
        bombs.push_back(std::make_unique<Bomb>(characters[0], map));
    }
    if (commands[9] && characters[1].dropBomb())
    {
        characters[1].resetBombTimer();
        bombs.push_back(std::make_unique<Bomb>(characters[1], map));
    }
}

void GameEngine::updateBombs()
{
    for (unsigned int i{0}; i < bombs.size(); ++i)
    {
        bombs[i]->update();
    }
}

void GameEngine::drawObjects(sf::RenderWindow & window)
{
    for (unsigned int i{0}; i < bombs.size(); ++i)
    {
        window.draw(bombs[i]->sprite);
    }
    window.draw(characters[0].sprite);
    window.draw(characters[1].sprite);
}

void GameEngine::updateCharacters()
{
    for (unsigned int it{0}; it < characters.size(); it++)
    {
        switch (map.getCoord(characters[it].tileCoordinates()))
        {
        case shoes:
            characters[it].setSpeed();
            map.setCoord(characters[it].tileCoordinates(), empty);
            break;
        case extrabomb:
            characters[it].setBombTime();
            map.setCoord(characters[it].tileCoordinates(), empty);
            break;
        case bombradius:
            characters[it].setBombRadius();
            map.setCoord(characters[it].tileCoordinates(), empty);
            break;
        case life:
            characters[it].setLife();
            map.setCoord(characters[it].tileCoordinates(), empty);
            break;
        case bombmover:
            characters[it].setBombMover();
            map.setCoord(characters[it].tileCoordinates(), empty);
            break;
        case flames:
            if (characters[it].getRespawnTimer().getElapsedTime().asSeconds() > 3)
            {
            characters[it].eraseLife();
            characters[it].setRespawnTimer();
            switch (it)
            {
                case 0:
                    characters[1].setPoints(500);
                    break;
                case 1:
                    characters[0].setPoints(500);
                    break;
            }
            std::cerr << characters[it].getLife() << std::endl;
            }
            break;
        }
    }
}

void GameEngine::checkGameOver(bool & terminated)
{
    for (unsigned int it{0}; it < characters.size(); it++)
    {
        if (characters[it].getLife() == 0 && !terminated)
        {
            std::cerr << "GAME OVER " << characters[it].getName() << std::endl;
            std::cerr << ""
            terminated = true;
        }
    }
}

void GameEngine::showTimer(sf::RenderWindow & window)
{
    if (gameTimer.getElapsedTime().asSeconds() >= 0 && gameTimer.getElapsedTime().asSeconds() < 1)
    {
        text[0].setString("3");
        window.draw(text[0]);
    }
    else if (gameTimer.getElapsedTime().asSeconds() >= 1 && gameTimer.getElapsedTime().asSeconds() < 2)
    {
        text[0].setString("2");
        window.draw(text[0]);
    }
    else if (gameTimer.getElapsedTime().asSeconds() >= 2 && gameTimer.getElapsedTime().asSeconds() < 3)
    {
        text[0].setString("1");
        window.draw(text[0]);
    }
}

void GameEngine::restartGameTimer()
{
    gameTimer.restart();
}
