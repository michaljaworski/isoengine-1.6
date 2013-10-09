#ifndef _TILELOADER_HPP
#define _TILELOADER_HPP

#include <SFML/Graphics.hpp>
#include <rapidxml/rapidxml.hpp>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

class TileLoader{
private:
    std::vector<sf::Image> tileImage;
    sf::Sprite tileSprite;
    //std::vector<sf::IntRect> subRect;
    std::vector<int> xmlMap;

public:
    TileLoader();
    ~TileLoader();

    std::vector<sf::IntRect> subRect;

    void loadTileSet(std::string filename, int setsize, int setwidth, int setheight, int tile);
    void tileDraw(int x, int y, int subTile, sf::RenderWindow* rw);
    void mapDraw(int subTile, sf::RenderWindow* rw);
    void mapDraw_byTile(int subTile, sf::RenderWindow* rw);

    //draw tiles at bottom of window in tileset
    void setDraw(sf::RenderWindow* rw);

    //load xml file with map info
    void xmlLoad(std::vector<int> xmlMap);

};

#endif
