//
// Created by akhaten on 9/1/22.
//

#ifndef APPLICATION_HPP
#define APPLICATION_HPP



#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "Mesh.hpp"
#include "Scene.hpp"
#include "Viewer.hpp"

class Application
{

    public:

        Application(const char* name, int width, int height);
        ~Application();

        void run();
        

        Scene* getScene();
        Viewer* getViewer();

    
        void setViewer(Viewer* viewer);

        


    protected:
    
        GLFWwindow* window;
        Viewer* viewer;
        Scene* scene;
        
        static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
        static void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
        static void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);


    


};


#endif // APPLICATION_HPP
