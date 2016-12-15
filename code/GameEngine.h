/*
Klassen Gameengine
*/
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

#define TEXT_FIELDS 9


class GameEngine
{
public:
    GameEngine();
    ~GameEngine() = default;

    // HUvudloop för spelsessionen. Får in spelarnamn, färger och referens till aktuellt fönster
    void run(std::vector<std::string> &, std::vector<int> &, sf::RenderWindow &);

private:
    // Laddar texturer
    void initTextures();

    //
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
    void setUpText();

    bool gameOver;
    std::vector<bool> commands{};
    std::vector<int> scores{};
    std::vector<std::shared_ptr<Bomb>> bombs{};
    Character player1{};
    Character player2{};
    std::vector<Character> characters{};

    Map map{};
    sf::Sprite static_object{};
    std::vector<sf::Sprite> static_objects;
    std::vector<sf::Texture> static_textures;
    sf::Clock gameTimer{};
    sf::Font font;
    sf::Text text[TEXT_FIELDS];
    GameMusic music{};
    Highscore highscore{};
    sf::Text gameOverText{};
};

#endif
