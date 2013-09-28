#include "tileloader.hpp"

TileLoader::TileLoader()
{

}

TileLoader::~TileLoader()
{

}

void TileLoader::loadTileSet(std::string filename, int setsize,
                            int setwidth, int setheight, int tile)
{
    tileImage.resize(2);
    try
    {
        tileImage[0].LoadFromFile(filename);
    } catch(char* e)
    {
        std::cout << "Could not load tileset: " << e << std::endl;
    }

    subRect.resize(setwidth*setheight);
    int i, j, tilecnt;
    for(i = 0, tilecnt = 0; i < setheight-1; i++, tilecnt++)
    {
        for(j = 0; j < setwidth-1; j++, tilecnt++)
        {
            subRect[tilecnt].Left = 0 + (setsize*j)-1;
            subRect[tilecnt].Right = setsize + (setsize*j);
            subRect[tilecnt].Top = 0 + (setsize*i)-1;
            subRect[tilecnt].Bottom = setsize + (setsize*i)-1;
        }
    }

    tileSprite.SetImage(tileImage[0]);
    tileSprite.SetSubRect(subRect[tile]);
    tileSprite.SetBlendMode(sf::Blend::Alpha);
}

void TileLoader::tileDraw(int x, int y, int subTile, sf::RenderWindow* rw)
{
    tileSprite.SetPosition(x, y);
    tileSprite.SetSubRect(subRect[subTile]);
    rw->Draw(tileSprite);
    //std::cout << "drawing sprite\n" << std::endl;
}

void TileLoader::setDraw(sf::RenderWindow* rw)
{
    sf::Sprite spritebar;
    spritebar = tileSprite;
    spritebar.SetScale(0.3f, 0.3f);
    for(int i = 0; i < subRect.size(); i++)
    {
        spritebar.SetSubRect(subRect[i]);
        spritebar.SetPosition(0.0f+32*i, rw->GetHeight()-64);
        rw->Draw(spritebar);
    }
}

void TileLoader::mapDraw(int subTile, sf::RenderWindow* rw)
{
    rw->Clear(sf::Color::Black);
    int i, j, k, tilecnt = 0;
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            tileSprite.SetPosition((0+64*j), (0+64*i)/2);
            tileSprite.SetSubRect(subRect[subTile]);
            rw->Draw(tileSprite);
            tilecnt++;
            //tileloader->tileDraw((0+64*j), (0+64*i)/2, 1, window);
        }
        for(k = 0; k < 10; k++)
        {
            tileSprite.SetPosition((32+64*k), (32+64*i)/2);
            tileSprite.SetSubRect(subRect[subTile]);
            rw->Draw(tileSprite);
            tilecnt++;
            //tileloader->tileDraw((32+64*k), (32+64*i)/2, 3, window);
        }
    }
    //std::cout << "total tiles: " << tilecnt << std::endl;
}
