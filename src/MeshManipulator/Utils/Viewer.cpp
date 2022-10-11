#include "Viewer.hpp"

Viewer::Viewer(Camera* camera)
{
    
    this->camera = camera;
    
}

Viewer::~Viewer(){}

glm::mat4 Viewer::viewMatrix()
{

    return glm::lookAt(
        this->camera->getPosition(),
        this->camera->getPosition()+this->camera->getDirection(),
        this->camera->getUp()
    );

}

glm::mat4 Viewer::projectionMatrix()
{

    return glm::perspective(
        this->camera->getFov(),
        this->camera->getAspect(),
        this->camera->getNear(),
        this->camera->getFar()
    );

}

Camera* Viewer::getCamera()
{
    return this->camera;
}

void Viewer::setCamera(Camera* camera)
{
    this->camera = camera;
}


