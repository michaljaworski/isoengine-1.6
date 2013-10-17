#include "engine.hpp"

Engine::Engine()
{
    //get desktop size
    sf::VideoMode DesktopMode = sf::VideoMode::GetDesktopMode();
    //create new window handle

    //standard full window mode
    window = new sf::RenderWindow(DesktopMode, "IsoEngine2", sf::Style::None);

    //test mode
    //window = new sf::RenderWindow(sf::VideoMode::GetMode(20), "IsoEngine2", sf::Style::Close);

    //get view of the window and use it as the default view
    fixed = window->GetDefaultView();
    modview = fixed;
    modview.SetCenter(DesktopMode.Width/2, DesktopMode.Height/2);
    //load camera view
    cameraview = new Camera();
    //load tileloader
    tileloader = new TileLoader();
    //HUD loader
    onscreen = new ScreenHUD();
    hudon = false;

}

Engine::~Engine()
{
    delete window;
}

bool Engine::Init()
{
    if(!window)
        return false;
    window->SetFramerateLimit(60);
    window->Clear(sf::Color::White);

    //tileloader->loadTileSet("./tileset.png", 32, 4, 2, 1);
    tileloader->loadTileSet("./terrain_0.png", 64, 10, 14, 1);
    //tileloader->loadTileSet("./tileset2.png", 64, 10, 14, 1);

    cameraview->drawCam(window, fixed);

    //tileloader->setDraw(window);      //draws set of available tiles at bottom of window

    //temp, used for testing map animation, delete
    //tileloader->mapDraw(1, window);
    tileloader->mapDraw_Diamond(1, window);
    tile_number = 1;


    //display all that is drawn to screen
    window->Display();

    return true;
}

void Engine::MainLoop()
{
    while(window->IsOpened())
    {
        ProcessInput();
        Update();
        RenderFrame();
    }
}

void Engine::ProcessInput()
{
    sf::Event evt;

    while(window->GetEvent(evt))
    {
        if((evt.Type == sf::Event::MouseButtonPressed))
        {
            sf::Vector2i input_coords(evt.MouseButton.X, evt.MouseButton.Y);
            fixed.SetCenter(input_coords.x, input_coords.y);
            changed = true;
        }

        if((evt.Type == sf::Event::KeyPressed))
        {
            switch(evt.Key.Code)
            {
                case sf::Key::Escape:
                {
                    window->Close();
                } break;
                case sf::Key::PageUp:
                {
                    tile_number++;
                    if(tile_number > tileloader->subRect.max_size()) tile_number = tileloader->subRect.max_size();
                } break;
                case sf::Key::PageDown:
                {
                    tile_number--;
                    if(tile_number < 0) tile_number = 0;
                } break;
                case sf::Key::X:
                {
                    cameraview->zoomCam(0.8f, window, fixed);
                    changed = true;
                } break;
                case sf::Key::Z:
                {
                    cameraview->zoomCam(1.2f, window, fixed);
                    changed = true;
                } break;
                case sf::Key::Right:
                {
                    cameraview->moveCam(tilewidth, 0.0f, window, fixed);
                    changed = true;
                } break;
                case sf::Key::Left:
                {
                    cameraview->moveCam(-tilewidth, 0.0f, window, fixed);
                    changed = true;
                } break;
                case sf::Key::Up:
                {
                    cameraview->moveCam(0.0f, -tileheight, window, fixed);
                    changed = true;
                } break;
                case sf::Key::Down:
                {
                    cameraview->moveCam(0.0f, tileheight, window, fixed);
                    changed = true;
                } break;

                //temp case
                case sf::Key::H:
                {
                    hudon ^= true;
                    sf::String test;
                    test.SetText("hud_info");
                    window->SetView(modview);
                    onscreen->DrawHUD(window, test, 200.0f, 300.0f);
                } break;
                case sf::Key::Tab:
                {
                    //this jumps to default view
                    window->SetView(modview);
                } break;

                default:
                {
                    changed = false;
                } break;
            }
            changed = true;
        }
    }
}

void Engine::RenderFrame()
{
    //constant hud for simple data
    if(hudon)
    {
        window->SetView(modview);
        sf::String test2;
        test2.SetText("temp_hud");
        onscreen->DrawHUD(window, test2, 100.0f, 100.0f);
    }
}

void Engine::Update()
{
    if(changed == true)
    {
        //tileloader->mapDraw(tile_number, window);
        tileloader->mapDraw_Diamond(tile_number, window);
        changed = false;
        window->SetView(fixed);
        //window->Display();
    } else
        window->Display();
}

void Engine::Go()
{
    if(!Init())
        throw "Could not initialize engine";
    MainLoop();
}
