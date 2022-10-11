//
// Created by akhaten on 9/1/22.
//

#include "Application.hpp"

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include <iostream>

// #include "Scene.hpp"


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
    glfwSetFramebufferSizeCallback(this->window, this->framebufferSizeCallback);
    glfwSetKeyCallback(this->window, this->keyCallback);
    glfwSetCursorPosCallback(this->window, this->cursorPosCallback);

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


Scene* Application::getScene()
{
    return this->scene;
}


Viewer* Application::getViewer()
{
    return this->viewer;
}


void Application::setViewer(Viewer* viewer)
{

    this->viewer = viewer;
    // this->viewer->setWindow(this->window);
    glfwSetWindowUserPointer(this->window, this->viewer);

    // Camera configuration
    int width, height;
    glfwGetWindowSize(this->window, &width, &height);
    Camera* camera = this->viewer->getCamera();
    camera->setAspect((float)width, (float)height);

    this->scene->setViewer(this->viewer);

}


/**
 * CALLBACKS
 */


void Application::framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    
    glViewport(0, 0, width, height);
    Viewer* callback_viewer = (Viewer*) glfwGetWindowUserPointer(window);
    Camera* callback_camera = callback_viewer->getCamera();
    callback_camera->setAspect(width, height);

}

void Application::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    Viewer* callback_viewer = (Viewer*) glfwGetWindowUserPointer(window);
    callback_viewer->processKeyboard(window, key, scancode, action, mods);   
}

void Application::cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
    Viewer* callback_viewer = (Viewer*) glfwGetWindowUserPointer(window);
    callback_viewer->processMouse(window, xpos, ypos);
}



