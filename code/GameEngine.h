
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

/*
Defined in MAP_H:
enum tile{empty = 0, wall = 1, flames, emptybox, shoebox};
*/

class GameEngine
{
public:
    GameEngine();
    ~GameEngine() = default;
    void initTextures();
    void run(std::vector<std::string> &, std::vector<int> &, sf::RenderWindow &);
    void drawWindowFromMap(sf::RenderWindow &);
    void getCommands();
    void moveObjects();
    void dropBombs();

    void drawObjects(sf::RenderWindow &);
    void updateBombs();

    void updateAttribute(int);

private:
    std::vector<bool> commands{};
    std::vector<int> scores{};
    std::vector<Character> characters{};
    std::vector<std::shared_ptr<Bomb>> bombs{};
    Character player1{};
    Character player2{};

    Map map{};//(std::string Fil);
    sf::Sprite static_object{};
    std::vector<sf::Sprite> static_objects;
    std::vector<sf::Texture> static_textures;
};

#endif
