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

        void setMyOpenMesh(MyOpenMesh* obj_mesh);


    private:


        GLFWwindow* window;
        Scene* scene;
        

        float radius;
        double lastX;
        double lastY;
        float sensitivity;
        bool camera_mod;
        bool moveset_mode;
        //bool zoom_mod;


        // Shader* shaderSelector();
        // void moveSelector();

        MyOpenMesh* obj_mesh;

    
        /**
         * rings has a list
        */
        /*std::vector<std::vector<unsigned int>> rings;
        std::vector<unsigned int> one_ring(unsigned int index);
        void laplacian(MyOpenMesh* open_mesh, float alpha);
        void deformation(MyOpenMesh* open_mesh, unsigned int index, unsigned int rings);*/


        



};

#endif // MY_VIEWER_HPP