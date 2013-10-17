#ifndef _ENGINE_HPP
#define _ENGINE_HPP

#include <SFML/Graphics.hpp>
#include "tileloader.hpp"
#include "maploader.hpp"
#include "camera.hpp"
#include "screenhud.hpp"

#include <iostream>

class Engine
{
private:
    //handle declarations
    sf::RenderWindow* window;
    TileLoader* tileloader;
    sf::View fixed;
    sf::View modview;
    ScreenHUD* onscreen;

    //init the engine
    bool Init();
    //main game loop
    void MainLoop();
    //renders a single frame, to be used with update
    void RenderFrame();
    //process user input
    void ProcessInput();
    //updates all engine variables
    void Update();

    //Camera view and update, if scene has changed, redraw it
    Camera* cameraview;
    bool changed;
    int tile_number;

    //temp
    bool hudon;

    //tilesizes
    double tilewidth = 64.0f, tileheight = 64.0f;

public:
    Engine();
    ~Engine();
    void Go();


};

#endif
