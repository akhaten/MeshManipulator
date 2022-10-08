//
// Created by akhaten on 9/1/22.
//

#ifndef APPLICATION_HPP
#define APPLICATION_HPP


#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Mesh.hpp"
#include "Scene.hpp"

class Application
{

public:
    Application();
    ~Application();
    void run();
    Scene* scene;

private:
    GLFWwindow* window;
    void processInput(GLFWwindow *window);

};


#endif // APPLICATION_HPP
