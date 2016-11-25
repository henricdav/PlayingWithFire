
#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

class GameEngine
{
public:
    GameEngine() = default;
    ~GameEngine() = default;
    int run(sf::RenderWindow* windowPtr);    
};

#endif
//std::vector<std::string>, std::vector<int>);//, sf::renderWindow*)
