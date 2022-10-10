
#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>

#include "MyViewer.hpp"


#include <iostream>

MyViewer::MyViewer(Camera* camera):
    Viewer(camera)
{

    this->sensitivity = 0.01f;
    this->radius = 3.0f;
    this->camera_mod = false;

}

// void MyViewer::setWindow(GLFWwindow* window)
// {
//     Viewer::setWindow(window);
// }

void MyViewer::processKeyboard(GLFWwindow *window, int key, int scancode, int action, int mods)
{

    if(key == GLFW_KEY_LEFT_SHIFT && action == GLFW_PRESS)
    {
        this->camera_mod = true;

        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

        glfwGetCursorPos(window, &this->lastX, &this->lastY);

        int width, height;
        glfwGetWindowSize(window, &width, &height);
        glfwSetCursorPos(window, width/2, height/2);

       

        
    }

    if(key == GLFW_KEY_LEFT_SHIFT && action == GLFW_RELEASE)
    {
        this->camera_mod = false;
        glfwSetCursorPos(window, this->lastX, this->lastY);
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }

    

}


void MyViewer::processMouse(GLFWwindow *window, double xpos, double ypos)
{

    if(this->camera_mod){

        int width, height;
        glfwGetWindowSize(window, &width, &height);

        double cursor_x, cursor_y;
        glfwGetCursorPos(window, &cursor_x, &cursor_y);
        
        float xoffset = cursor_x - ((float)width / 2);
        float yoffset = cursor_y - ((float)height / 2);

        xoffset *= this->sensitivity;
        yoffset *= this->sensitivity;

        // FPS View
        glm::mat4 transformation = glm::mat4(1.0f);
        // if(abs(yoffset) > abs(xoffset)){
            transformation = glm::rotate(transformation, xoffset, this->camera->getWorldUp());
            this->camera->update(transformation);
        // }else{
        transformation = glm::mat4(1.0f);
        // if(abs(yoffset) > abs(xoffset)){
            transformation = glm::rotate(transformation, -yoffset, this->camera->getRight());
            this->camera->update(transformation);
           
        // }
        // this->camera->update(transformation);
    

        glfwSetCursorPos(window, width/2, height/2);

    
        
        
    }

}