
#include "Map.h"

Map::Map()
    : mapArray{}
{
    std::string fileName = "level_template.map";
    std::ifstream mapFile;
    mapFile.open(fileName);
    int tile;
    while(mapFile >> tile)
    {
        mapArray.push_back(tile);
    }
    mapFile.close();
}

void Map::setCoord(int xCoord, int yCoord, int type)
{
    if (!validIndices(xCoord, yCoord))
        throw std::out_of_range("Tried to set index out of range in Map::setCoord");

    mapArray.at((yCoord)*TILES_X + xCoord) = type;
}

int Map::getCoord(int xCoord, int yCoord) const
{
    if (!validIndices(xCoord, yCoord))
        throw std::out_of_range("Tried to set index out of range in Map::getCoord");

    return mapArray.at((yCoord)*TILES_X + xCoord);
}

sf::Sprite Map::getBoundings(int xCoord, int yCoord) const
{
    if (!validIndices(xCoord, yCoord))
        throw std::out_of_range("Tried to set index out of range in Map::getBoundings");

    sf::Sprite tempStaticSprite;
    tempStaticSprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
    if (getCoord(xCoord, yCoord) == 1)
    {
        tempStaticSprite.setPosition(sf::Vector2f(X_OFFSET + (xCoord-1)*TILE_WIDTH, Y_OFFSET + (yCoord-1)*TILE_HEIGHT));
        //std::cout << (X_OFFSET + (xCoord)*TILE_WIDTH) << std::endl;
        //std::cout << (Y_OFFSET + (yCoord)*TILE_HEIGHT) << std::endl;
    }
    return tempStaticSprite;

    //return sf::IntRect(X_OFFSET + (xCoord - 1)*TILE_WIDTH, Y_OFFSET + (yCoord - 1)*TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT);
}

bool Map::validIndices(int xCoord, int yCoord) const
{
    return (xCoord <= TILES_X || yCoord <= TILES_Y || xCoord >= 0 || yCoord >= 0);
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
