

#include "Map.h"
#include <SFML/Graphics.hpp>
#include <string>


int main()
{
    std::string fileName{"level_template.map"};
    Map map{};

    map.setCoord(13,13, shoebox);
    map.print();
    std::cout << std::endl;

    std::cout << map.getCoord(3,3) << std::endl;

}
