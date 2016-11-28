
#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Bomb.h"
#include "Character.h"

enum validCommands {A = 0, D, W, S, B, Left, Right, Up, Down, Numpad0};

class GameEngine
{
public:
    GameEngine() : commands{std::vector<bool>(10, false)}, Map{1,0,1,0,1,0} {};
    ~GameEngine() = default;
    int run(std::vector<std::string>*, std::vector<int>*, sf::RenderWindow*);
    void drawWindowFromMap(sf::RenderWindow*);
    void getCommands();
    void moveObjects();
    void dropBombs();
    bool checkCollisions();

private:
    std::vector<bool> commands{};
    std::vector<int> scores{};
    std::vector<Character> characters{};
    std::vector<Bomb*> bombs{};
    Character player1{};

    std::vector<int> Map{};
    sf::Texture texture2;
    texture2.loadFromFile("Textures/Ground_2.jpg");
    game.sprite4.setTexture(texture2); //Sprite class in class Game
    game.sprite4.setTextureRect(sf::IntRect(0, 0, 50, 50));

};

#endif
