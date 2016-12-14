#include "Highscore.h"

Highscore::Highscore()
    : highscore{}
{}

void Highscore::getHighscore()
{
    std::string highscoreName = "Highscore.list";
    std::ifstream inputFile;
    inputFile.open(highscoreName);
    std::string listInput;

    while(getline(inputFile, listInput))
    {
        stringFromFileVector.push_back(listInput);
    }
    splitVectorIntoPair();
    sortHighscore();
    inputFile.close();
}

void Highscore::splitVectorIntoPair()
{
    std::string name;
    int points;

    for (unsigned int i{0}; i < stringFromFileVector.size(); i++)
    {
        std::istringstream ss(stringFromFileVector[i]);
        ss >> points >> name;
        highscore.emplace_back(points, name);
    }
}

void Highscore::sortHighscore()
{
    std::sort(highscore.begin(), highscore.end(), std::greater<>());
}

void Highscore::setHighscore(std::string name, int value)
{
    std::cout << "setHighscore " << value << " for " << name << std::endl;
    std::string highscoreName = "Highscore.list";
    std::ofstream highscoreFile;
    highscoreFile.open(highscoreName, std::ios::app);

    highscoreFile << value << " " << name << std::endl;
    highscoreFile.close();
}

void Highscore::showHighscore(sf::RenderWindow & window)
{
    prepareEverythingToDraw();

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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                terminated = true;
            }
        }
        window.clear(sf::Color::Black);

        drawHighscore(window);

        window.display();
    }
}

void Highscore::drawHighscore(sf::RenderWindow & window)
{
    window.draw(text[0]);
    window.draw(text[1]);
    window.draw(text[2]);
    for (int i{0}; i < NR_OF_HIGHSCORES; i++)
    {
        window.draw(highscoreNames[i]);
        window.draw(highscorePoints[i]);
    }
}

void Highscore::prepareEverythingToDraw()
{
    if (!font.loadFromFile("Figures/arial.ttf"))
    {
        std::cerr << "Could not load font in highscore view" << std::endl;
    }

    //Text that is not the actual scores
    text[0].setString("HIGHSCORE LIST");
    text[0].setFont(font);
    text[0].setFillColor(sf::Color::Green);
    text[0].setPosition(TILE_SIZE*TILES_X/5, TILES_Y*2);
    text[0].setCharacterSize(60);

    text[1].setString("NAME                            SCORE");
    text[1].setFont(font);
    text[1].setFillColor(sf::Color::White);
    text[1].setPosition(TILE_SIZE*TILES_X/4, TILE_SIZE*TILES_Y/6);
    text[1].setStyle(sf::Text::Underlined);

    text[2].setString("Hit Q to return to Menu");
    text[2].setFont(font);
    text[2].setFillColor(sf::Color::White);
    text[2].setPosition(TILE_SIZE*TILES_X/2.7, TILE_SIZE*TILES_Y-2*TILE_SIZE);
    text[2].setCharacterSize(20);

    for (unsigned int i{0}; i < NR_OF_HIGHSCORES; i++)
    {
        highscoreNames[i].setFont(font);
        highscorePoints[i].setFont(font);

        highscoreNames[i].setFillColor(sf::Color::White);
        highscorePoints[i].setFillColor(sf::Color::White);

        highscoreNames[i].setPosition(TILE_SIZE*TILES_X/4, 2*TILES_Y*i+TILE_SIZE*TILES_Y/4);
        highscorePoints[i].setPosition(TILE_SIZE*TILES_X/1.5, 2*TILES_Y*i+TILE_SIZE*TILES_Y/4);

        unsigned int h = highscore.size();
        // Check if there are fewer highscore entries than specifid
        if (i >= h)
        {
            highscoreNames[i].setString(" ");
            highscorePoints[i].setString(" ");
        }
        else
        {
            highscoreNames[i].setString(std::to_string(i+1) + ".  " + highscore[i].second);
            highscorePoints[i].setString(std::to_string(highscore[i].first));
        }

    }
}
