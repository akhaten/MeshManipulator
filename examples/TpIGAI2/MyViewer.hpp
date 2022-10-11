#ifndef MY_VIEWER_HPP
#define MY_VIEWER_HPP

/**
 * First include else probleme glew include before gl
 */
#include <MeshManipulator/Utils/Shader.hpp>
#include <MeshManipulator/Window/Viewer.hpp>
#include <MeshManipulator/Utils/Drawable.hpp>
#include <MeshManipulator/Utils/Scene.hpp>

#include <MeshManipulator/Mesh/ObjectMesh.hpp>



class MyViewer:
    public Viewer
{

    public:
    
        MyViewer(Camera* camera);
        ~MyViewer();

        void processKeyboard(GLFWwindow *window, int key, int scancode, int action, int mods) override;
        void processMouse(GLFWwindow *window, double xpos, double ypos) override;

        void setScene(Scene* scene);
        void setWindow(GLFWwindow* window);


    private:

        GLFWwindow* window;
        Scene* scene;
        ObjectMesh* obj_mesh;

        float radius;
        double lastX;
        double lastY;
        float sensitivity;
        bool camera_mod;

        // Shader* shaderSelector();
        // void moveSelector();

        



};

#endif // MY_VIEWER_HPP