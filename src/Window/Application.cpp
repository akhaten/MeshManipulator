//
// Created by akhaten on 9/1/22.
//

#include "Application.hpp"

#include <GL/glew.h>
#include <iostream>

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

Application::Application()
{

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    glfwMakeContextCurrent(this->window);
    glfwSetFramebufferSizeCallback(this->window, framebufferSizeCallback);

    //Now we have a valid context as current, let's allow glew to do its job
    glewExperimental = GL_TRUE; //Ensure it get all pointers
    if (GLEW_OK != glewInit())
    {
        //glewInit failed, something is seriously wrong.
        std::cout << "pb glew" << std::endl;
        exit(EXIT_FAILURE); //or any handling here
    }

    this->scene = new Scene();

}

void Application::processInput(GLFWwindow *window)
{

    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

}

void Application::run()
{

    while(!glfwWindowShouldClose(this->window))
    {

        processInput(this->window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        // wipe the drawing surface clear
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        scene->draw();

        // update other events like input handling
        glfwPollEvents();
        // put the stuff we've been drawing onto the display
        glfwSwapBuffers(this->window);

    }

    glfwTerminate();

}
