//
// Created by akhaten on 9/1/22.
//

#include "Application.hpp"

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include <iostream>


// #include "CallbackFunctions.hpp"



Application::Application(const char* name, int width, int height)
{

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


  
    this->window = glfwCreateWindow(width, height, name, NULL, NULL);

    glfwMakeContextCurrent(this->window);

    // Callback configuration
    glfwSetFramebufferSizeCallback(this->window, framebufferSizeCallback);
    glfwSetKeyCallback(this->window, keyCallback);
    glfwSetCursorPosCallback(this->window, cursorPosCallback);
   
    
    // glfwSetCursorPosCallback(this->window, processMouse);
    
    

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

Application::~Application(){}

void Application::setViewer(Viewer* viewer)
{
    this->viewer = viewer;
    this->viewer->setWindow(this->window);
    glfwSetWindowUserPointer(this->window, this->viewer);
}

void Application::run()
{

    
    // glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

    while(!glfwWindowShouldClose(this->window))
    {


        if(glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(this->window, true);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        // wipe the drawing surface clear
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        // this->processMesh();
        this->scene->draw();

        // update other events like input handling
        glfwPollEvents();
        // put the stuff we've been drawing onto the display
        glfwSwapBuffers(this->window);

    }

    glfwTerminate();

}

void Application::processMesh()
{

    int width;
    int height;
    glfwGetWindowSize(this->window, &width, &height);
    
    for(auto object_drawable : scene->drawables){    
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);
        object_drawable->projection = projection;
    }

}

void Application::framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void Application::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    Viewer* callback_viewer = (Viewer*) glfwGetWindowUserPointer(window);;
    callback_viewer->processKeyboard(window, key, scancode, action, mods);   
}

void Application::cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
    Viewer* callback_viewer = (Viewer*) glfwGetWindowUserPointer(window);
    callback_viewer->processMouse(window, xpos, ypos);
}

void Application::addDrawable(Drawable* drawable)
{
    drawable->setViewer(this->viewer);
    this->scene->addDrawable(drawable);
}



