#ifndef MY_VIEWER_HPP
#define MY_VIEWER_HPP

#include <MeshManipulator/Utils/Viewer.hpp>

class MyViewer:
    public Viewer
{

    public:
    
        MyViewer(Camera* camera);
        void processKeyboard(GLFWwindow *window, int key, int scancode, int action, int mods) override;
        void processMouse(GLFWwindow *window, double xpos, double ypos) override;

        // void setWindow(GLFWwindow* window);

    private:
        float radius;
        double lastX;
        double lastY;
        float sensitivity;
        bool camera_mod;



};

#endif // MY_VIEWER_HPP