#include "Viewer.hpp"

Viewer::Viewer(Camera* camera)
{
    
    this->camera = camera;
    
}

Viewer::~Viewer(){}

glm::mat4 Viewer::getView()
{
    glm::vec3 position = camera->getPosition();
    glm::vec3 target = camera->getTarget();
    glm::vec3 up = camera->getUp();
    return glm::lookAt(position, position+camera->getDirection(), up);
}

glm::mat4 Viewer::getProjectionMatrix()
{

    int width, height;
    glfwGetWindowSize(this->window, &width, &height);
    return glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);

}
void Viewer::setCamera(Camera* camera)
{
    this->camera = camera;
}

Camera* Viewer::getCamera()
{
    return this->camera;
}

void Viewer::setWindow(GLFWwindow* window)
{
    this->window = window;
}