

#include "Map.h"
#include <string>


int main()
{
    std::string fileName{"level_template.map"};
    Map map{fileName};

    map.setCoord(13, 13, shoebox);
    map.print();
    std::cout << std::endl;

    std::cout << map.getCoord(3, 3) << std::endl;

}
