
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


//enum validCommands {A = 0, D, W, S, B, Left, Right, Up, Down, Numpad0};

class GameEngine
{
public:
    GameEngine();
    ~GameEngine() = default;
    void run(std::vector<std::string>*, std::vector<int>*, sf::RenderWindow*);
    void drawWindowFromMap(sf::RenderWindow*);
    void getCommands();
    void moveObjects();
    void dropBombs();
    bool checkCollisions();
    void drawObjects(sf::RenderWindow*);
    void updateBombs();

private:
    std::vector<bool> commands{};
    std::vector<int> scores{};
    std::vector<Character> characters{};
    std::vector<Bomb*> bombs{};
    Character player1{};
    Character player2{};

    const std::string Fil = "level_template.map";
    Map map{};//(std::string Fil);

    sf::Sprite static_object{};
    sf::Texture static_texture{};
};

#endif
