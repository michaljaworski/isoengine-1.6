#include "screenhud.hpp"


ScreenHUD::ScreenHUD()
{
    try
    {
        HUDFont.LoadFromFile("arial.ttf", 30);
        std::cout << "Font load success" << std::endl;
    } catch(char* e)
    {
        std::cout << "Error: " << e << std::endl;
    }

}

ScreenHUD::~ScreenHUD()
{

}

void ScreenHUD::DisplaySimpleHUD(void)
{

}

void ScreenHUD::DrawHUD(sf::RenderWindow* rw, sf::String Text, double posx, double posy)
{
    //std::cout << "Writing text: " << std::endl;
    Text.SetFont(HUDFont);
    Text.SetSize(200);
    Text.SetColor(sf::Color::Red);
    Text.SetPosition(posx, posy);
    //Text.SetText("work you piece of shit");
    //rw->Clear(sf::Color::Blue);
    rw->Draw(Text);
    rw->Display();
}
