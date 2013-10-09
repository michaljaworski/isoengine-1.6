#ifndef _SCREENHUD_HPP
#define _SCREENHUD_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class ScreenHUD{

private:
    sf::Font HUDFont;

public:
    ScreenHUD();
    ~ScreenHUD();

    void DisplaySimpleHUD(void);
    void DrawHUD(sf::RenderWindow* rw, sf::String Text, double posx, double posy);

};

#endif
