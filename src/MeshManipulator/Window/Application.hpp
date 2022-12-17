/**
 * @author akhaten
 * @file Application.hpp
 */

#ifndef APPLICATION_HPP
#define APPLICATION_HPP



#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "MeshManipulator/Mesh/OpenGLObject.hpp"
#include "MeshManipulator/Utils/Scene.hpp"
#include "MeshManipulator/Window/Viewer.hpp"

class Application
{

    public:

        /**
         * Constructor of Appliation
         * @param name : name of application/ window opened
         * @param width : width of window
         * @param height : height of window
         */
        Application(const char* name, int width, int height);

        /**
         * Destructor of Application
         */
        ~Application();

        /**
         * Run application / Open the window
         */
        void run();
        
        /**
         * Get the scene of Application
         * @return the scene
         */
        Scene* getScene();

        /**
         * Get the viewer
         * @return viewer
         */
        Viewer* getViewer();

        /**
         * Set a viewer
         * @param viewer : new viewer
         */
        void setViewer(Viewer* viewer);


    protected:

        /**
         * GLFW window
         */
        GLFWwindow* window;

        /**
         * Viewer
         */
        Viewer* viewer;

        /**
         * Scene
         */
        Scene* scene;

        /**
         * Callback to change size of window
         * @param window : glfw window
         * @param width : width of window
         * @param height : height of window
         */
        static void framebufferSizeCallback(GLFWwindow* window, int width, int height);

        /**
         * Callback for key event
         * @param window
         * @param key
         * @param scancode
         * @param action
         * @param mods
         */
        static void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);

        /**
         * Callback for mouse/cursor event
         * @param window
         * @param xpos
         * @param ypos
         */
        static void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);


    


};


#endif // APPLICATION_HPP
