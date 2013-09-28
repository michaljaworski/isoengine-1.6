#include "camera.hpp"

Camera::Camera()
{

}

Camera::~Camera()
{

}

void Camera::drawCam(sf::RenderWindow* rw, sf::View &cameraView)
{
    cameraView.Zoom(0.5f);
    std::cout << &cameraView << " drawCam - center: " << cameraView.GetCenter().x << ", " << cameraView.GetCenter().y << "\t" << std::endl;
    rw->SetView(cameraView);
}

void Camera::moveCam(float x, float y, sf::RenderWindow* rw, sf::View &cameraView)
{
    cameraView.SetCenter(cameraView.GetCenter().x, cameraView.GetCenter().y);
    cameraView.Move(x, y);
    rw->SetView(cameraView);
    std::cout << &cameraView << " moveCam - center: " << cameraView.GetCenter().x << ", " << cameraView.GetCenter().y << "\t" << std::endl;
}

void Camera::zoomCam(float z, sf::RenderWindow* rw, sf::View &cameraView)
{
    cameraView.Zoom(z);
    rw->SetView(cameraView);
    std::cout << &cameraView << " zoomCam - center: " << cameraView.GetCenter().x << ", " << cameraView.GetCenter().y << "\t" << std::endl;
}

void Camera::rotateCam(sf::View &cameraView)
{
    //
}
