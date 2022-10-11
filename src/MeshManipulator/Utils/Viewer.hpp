#ifndef VIEWER_HPP
#define VIEWER_HPP


#include <GLFW/glfw3.h>
#include "Camera.hpp"




class Viewer
{

    public:

        Viewer(Camera* camera);
        ~Viewer();


        glm::mat4 viewMatrix();
        glm::mat4 projectionMatrix();
    

        Camera* getCamera();


        void setWindow(GLFWwindow* window);
        void setCamera(Camera* camera);


        virtual void processKeyboard(GLFWwindow *window, int key, int scancode, int action, int mods) = 0;
        virtual void processMouse(GLFWwindow *window, double xpos, double ypos) = 0;

    protected:
        Camera* camera;
        GLFWwindow* window;


};

#endif // VIEWER_HPP