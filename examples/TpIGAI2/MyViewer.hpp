#ifndef MY_VIEWER_HPP
#define MY_VIEWER_HPP

/**
 * First include else probleme glew include before gl
 */
#include <MeshManipulator/Utils/Shader.hpp>
#include <MeshManipulator/Utils/Viewer.hpp>



class MyViewer:
    public Viewer
{

    public:
    
        MyViewer(Camera* camera);

        void processKeyboard(GLFWwindow *window, int key, int scancode, int action, int mods) override;
        void processMouse(GLFWwindow *window, double xpos, double ypos) override;


    private:

        float radius;
        double lastX;
        double lastY;
        float sensitivity;
        bool camera_mod;

        // Shader* shaderSelector();
        // void moveSelector();

        



};

#endif // MY_VIEWER_HPP