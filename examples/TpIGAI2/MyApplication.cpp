#include "MyApplication.hpp"

MyApplication::MyApplication(const char* name, int width, int height):
    Application(name, width, height)
{

};

MyApplication::~MyApplication() {}


void MyApplication::setViewer(MyViewer* viewer)
{
    Application::setViewer(viewer);
    viewer->setScene(this->scene);
}