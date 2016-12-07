
#include "Map.h"

Map::Map()
    : mapArray{}
{
    std::string fileName = "level1.map";
    std::ifstream mapFile;
    mapFile.open(fileName);
    int tile;
    while(mapFile >> tile)
    {
        mapArray.push_back(tile);
    }
    mapFile.close();
}

void Map::setCoord(MapCoords coords, int type)
{
    if (!validIndices(coords))
        throw std::out_of_range("Tried to set index out of range in Map::setCoord");

    mapArray.at((coords.y)*TILES_X + coords.x) = type;
}

int Map::getCoord(MapCoords coords) const
{
    if (!validIndices(coords))
        throw std::out_of_range("Tried to set index out of range in Map::getCoord");

    return mapArray.at((coords.y)*TILES_X + coords.x);
}

sf::Sprite Map::getBoundings(MapCoords coords)
{
    if (!validIndices(coords))
        throw std::out_of_range("Tried to set index out of range in Map::getBoundings");

    sf::Sprite tempStaticSprite;
    tempStaticSprite.setTextureRect(sf::IntRect(0, 0, TILE_WIDTH, TILE_HEIGHT));
    int tempCoord = getCoord(coords);
    if (tempCoord == wall || tempCoord == emptybox || tempCoord == shoebox ||
        tempCoord == extrabombbox || tempCoord == bombradiusbox ||
        tempCoord == lifebox || tempCoord == bombmoverbox)
    {
        tempStaticSprite.setPosition(sf::Vector2f(X_OFFSET + coords.x*TILE_WIDTH, Y_OFFSET + (coords.y)*TILE_HEIGHT));
    }
    else if (tempCoord == shoes || tempCoord == extrabomb || tempCoord == bombradius ||
        tempCoord == life || tempCoord == bombmover)
    {
        /*tempStaticSprite.setPosition(sf::Vector2f(0, 0));
        updateAttribute(tempCoord);
        setCoord(coords, empty);*/
    }
    else
    {
        tempStaticSprite.setPosition(sf::Vector2f(0, 0));
    }

    return tempStaticSprite;

    //return sf::IntRect(X_OFFSET + (xCoord - 1)*TILE_WIDTH, Y_OFFSET + (yCoord - 1)*TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT);
}

bool Map::validIndices(MapCoords coords) const
{
    return (coords.x <= TILES_X || coords.y <= TILES_Y || coords.x >= 0 || coords.y >= 0);
}

// Only for testing
void Map::print()
{
    for(unsigned int i {0}; i < mapArray.size(); ++i)
    {
        std::cout << mapArray[i] << " ";
        if ((i+1) % TILES_X == 0)
            std::cout << std::endl;
    }
}
