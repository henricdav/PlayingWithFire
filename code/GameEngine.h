
#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

enum validCommands {A = 0, D, W, S, B, Left, Right, Up, Down, Numpad0};

class GameEngine
{
public:
    GameEngine() : commands{std::vector<bool>(10, false)} {};
    ~GameEngine() = default;
    int run(std::vector<std::string>*, std::vector<int>*, sf::RenderWindow*);

    void getCommands();
private:
    std::vector<bool> commands;
};

#endif
