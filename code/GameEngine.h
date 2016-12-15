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

    // Ritar ut de statiska objekten i aktuell map i fönstret.
    void drawWindowFromMap(sf::RenderWindow &);

    // Tar in kommandon/inmatningar från spelarna.
    void getCommands();

    // Utför förflyttningar av spelare och bomber.
    void moveObjects();

    // Släpper bomber
    void dropBombs();

    // Uppdaterar bombens tillstånd. Flyttar om någon sparkat på den.
    void updateBombs();

    // Ritar ut bomber och spelare
    void drawObjects(sf::RenderWindow &);

    // Uppdaterar spelarnas attribut. Liv, bombradie, extrabomb osv.
    void updateCharacters();

    // Kontrollerar om någon förlorat.
    void checkGameOver(bool &);

    // Visar en timer vid start av spelet som räknar ned till start.
    void showTimer(sf::RenderWindow &);

    // Skriver ut spelarnamn, -liv och poäng i fönstret.
    void drawText(sf::RenderWindow &);

    // Sätter positionen för text av spelnamn, liv och poäng.
    void setUpText();

    bool gameOver;
    std::vector<bool> commands{};
    std::vector<int> scores{};
    std::vector<std::shared_ptr<Bomb>> bombs{};

    // Spelare av klassen Character.
    Character player1{};
    Character player2{};

    std::vector<Character> characters{};

    // En map av klassen Map.
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
