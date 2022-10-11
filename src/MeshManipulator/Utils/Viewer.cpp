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

// Scene* Viewer::getScene()
// {
//     return this->scene;
// }


void Viewer::setWindow(GLFWwindow* window)
{
    this->window = window;
}

void Viewer::setCamera(Camera* camera)
{
    this->camera = camera;
}

// void Viewer::setScene(Scene* scene)
// {
//     this->scene = scene;
// }
 // void setWindow(GLFWwindow* window);


