#ifndef _CAMERA_HPP
#define _CAMERA_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Camera{
private:
    //sf::View cameraView;

public:
    Camera();
    ~Camera();

    void drawCam(sf::RenderWindow* rw, sf::View &cameraView);
    void moveCam(float x, float y, sf::RenderWindow* rw, sf::View &cameraView);
    void zoomCam(float z, sf::RenderWindow* rw, sf::View &cameraView);
    void rotateCam(sf::View &cameraView);

};

#endif
