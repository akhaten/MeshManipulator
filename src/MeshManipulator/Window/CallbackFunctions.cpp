#include "CallbackFunctions.hpp"
#include <iostream>


CallbackFunctions::CallbackFunctions(GLFWwindow* window, Viewer* Viewer)
    // window(window),
    // viewer(viewer)
{


    this->i = 1;
    this->window = window;
    this->viewer = viewer;
    glfwSetFramebufferSizeCallback(this->window, framebufferSizeCallback);
    glfwSetKeyCallback(this->window, keyCallback);
    glfwSetCursorPosCallback(this->window, cursorPosCallback);

    // glfwSetMouseButtonCallback(window, mouseButtonCallback);

    glfwSetWindowUserPointer(this->window, this);



}

CallbackFunctions::~CallbackFunctions() {}

void CallbackFunctions::framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    std::cout << "framebufferSizeCallback" << std::endl;
    glViewport(0, 0, width, height);
}

void CallbackFunctions::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    std::cout << "keyCallback" << std::endl;
    CallbackFunctions* callback_f = (CallbackFunctions*) glfwGetWindowUserPointer(window);;
    // callback_f->viewer->processKeyboard(window, key, scancode, action, mods);

    if (key == GLFW_KEY_X)
		if (action == GLFW_PRESS || action == GLFW_REPEAT)
		{
            
			std::cout << callback_f->i << std::endl;
		}
    
}

void CallbackFunctions::cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{

    std::cout << "cursorPosCallback" << std::endl;
    CallbackFunctions* callback_f = (CallbackFunctions*) glfwGetWindowUserPointer(window);

    // double i, j;
    // glfwGetCursorPos(callback_f->window, &i, &j);
    // std::cout << i << ", " << j << std::endl;
    
    // callback_f->viewer->processMouse(xpos, ypos);

}