/*
* FILNAMN:       map_test.cc
* PROJEKT:       TDDC76-Projekt
* PROGRAMMERARE: Johan Almgren, johal611
*                Fredrik Björklund, frebj191
*                Henric Davidsson, henda274
*                Nils Larsén, nilla000
*
* DATUM:         2016-12-15
*
* BESKRIVNING:   Testprogram för klassen Map.
*/

#include "Map.h"
#include <SFML/Graphics.hpp>
#include <string>


int main()
{
    std::string fileName{"level_template.map"};
    Map map{};
    MapCoords coords{13,13};
    MapCoords coords2{12,12};

    MapCoords coords3{coords+coords2};

    map.setCoord(coords, shoebox);
    map.print();
    std::cout << std::endl;

    std::cout << map.getCoord(coords) << std::endl;

}
