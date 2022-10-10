#ifndef VIEWER_HPP
#define VIEWER_HPP

#include <GLFW/glfw3.h>
#include "Camera.hpp"

class Viewer
{

    public:

        Viewer(Camera* camera);
        ~Viewer();
    
        void setWindow(GLFWwindow* window);
        void setCamera(Camera* camera);

        Camera* getCamera();
        glm::mat4 getView();
        glm::mat4 getProjectionMatrix();

        virtual void processKeyboard(GLFWwindow *window, int key, int scancode, int action, int mods) = 0;
        virtual void processMouse(GLFWwindow *window, double xpos, double ypos) = 0;

    protected:
        Camera* camera;
        GLFWwindow* window;


};

#endif // VIEWER_HPP