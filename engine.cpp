#include "engine.hpp"

Engine::Engine()
{
    //get desktop size
    sf::VideoMode DesktopMode = sf::VideoMode::GetDesktopMode();
    //create new window handle
    //window = new sf::RenderWindow(DesktopMode, "IsoEngine2", sf::Style::None);
    window = new sf::RenderWindow(sf::VideoMode::GetMode(20), "IsoEngine2", sf::Style::Close);
    //get view of the window and use it as the default view
    fixed = window->GetDefaultView();
    modview = fixed;
    //load camera view
    cameraview = new Camera();
    //load tileloader
    tileloader = new TileLoader();

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
    window->Display();

    //tileloader->loadTileSet("tileset.png", 32, 4, 2, 1);
    tileloader->loadTileSet("terrain_0.png", 64, 10, 14, 1);

    cameraview->drawCam(window, fixed);

    //tileloader->setDraw(window);      //draws set of available tiles at bottom of window


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
        if((evt.Type == sf::Event::KeyPressed) && (evt.Key.Code == sf::Key::Escape))
            window->Close();
        if((evt.Type == sf::Event::KeyPressed) && (evt.Key.Code == sf::Key::Up))
        {
            cameraview->moveCam(0.0f, -10.0f, window, fixed);
        }
        if((evt.Type == sf::Event::KeyPressed) && (evt.Key.Code == sf::Key::Down))
        {
            cameraview->moveCam(0.0f, 10.0f, window, fixed);
        }
        if((evt.Type == sf::Event::KeyPressed) && (evt.Key.Code == sf::Key::Left))
        {
            cameraview->moveCam(-10.0f, 0.0f, window, fixed);
        }
        if((evt.Type == sf::Event::KeyPressed) && (evt.Key.Code == sf::Key::Right))
        {
            cameraview->moveCam(10.0f, 0.0f, window, fixed);
        }
        if((evt.Type == sf::Event::KeyPressed) && (evt.Key.Code == sf::Key::Z))
        {
            cameraview->zoomCam(1.1f, window, fixed);
        }
        if((evt.Type == sf::Event::KeyPressed) && (evt.Key.Code == sf::Key::X))
        {
            cameraview->zoomCam(0.9f, window, fixed);
        }

        if((evt.Type == sf::Event::MouseButtonPressed))
        {
            sf::Vector2i input_coords(evt.MouseButton.X, evt.MouseButton.Y);
            fixed.SetCenter(input_coords.x, input_coords.y);
        }
    }
}

void Engine::RenderFrame()
{
    window->Display();
    std::cout << window->GetFrameTime() << std::endl;
}

void Engine::Update()
{
    tileloader->mapDraw(1, window);
    window->SetView(fixed);
}

void Engine::Go()
{
    if(!Init())
        throw "Could not initialize engine";
    MainLoop();
}
