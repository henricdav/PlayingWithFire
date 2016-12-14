
#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Bomb.h"
#include "Character.h"
#include "Map.h"
#include "globaldefines.h"
#include <SFML/Audio.hpp>
#include "GameMusic.h"
#include "Highscore.h"



/*
Defined in MAP_H:
enum tile{empty = 0, wall = 1, flames, emptybox, shoebox};
*/

#define TEXT_FIELDS 9


class GameEngine
{
public:
    GameEngine();
    ~GameEngine() = default;
    void run(std::vector<std::string> &, std::vector<int> &, sf::RenderWindow &);

private:
    void initTextures();
    void setUpText();
    void drawWindowFromMap(sf::RenderWindow &);
    void getCommands();
    void moveObjects();
    void dropBombs();
    void drawObjects(sf::RenderWindow &);
    void updateBombs();
    void updateCharacters();
    void checkGameOver(bool &);
    void showTimer(sf::RenderWindow &);
    void drawText(sf::RenderWindow &);
    sf::Text showGameOver();

    bool gameOver;
    std::vector<bool> commands{};
    std::vector<int> scores{};
    std::vector<std::shared_ptr<Bomb>> bombs{};
    Character player1{};
    Character player2{};
    std::vector<Character> characters{};

    Map map{};//(std::string Fil);
    sf::Sprite static_object{};
    std::vector<sf::Sprite> static_objects;
    std::vector<sf::Texture> static_textures;
    sf::Clock gameTimer{};
    sf::Font font;
    sf::Text text[TEXT_FIELDS];
    GameMusic music{};
    Highscore highscore{};
};

#endif
