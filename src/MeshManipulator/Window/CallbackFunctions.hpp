#ifndef CALLBACK_HPP
#define CALLBACK_HPP

#include <GLFW/glfw3.h>
#include "Viewer.hpp"

class CallbackFunctions
{

    public:
        CallbackFunctions(GLFWwindow* window, Viewer* Viewer);
        ~CallbackFunctions();
        static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
        static void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
        static void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);
        GLFWwindow* window;
        Viewer* viewer;
        int i = 1;

    protected:
        

};


#endif // CALLBACK_HPP