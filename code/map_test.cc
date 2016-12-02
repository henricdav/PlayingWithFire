

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
