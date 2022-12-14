#ifndef MY_VIEWER_HPP
#define MY_VIEWER_HPP

#include <set>


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

        /**
         * My viewer for my deformation app
         * @param camera : camera for viewer
         */
        MyViewer(Camera* camera);
        ~MyViewer();

        /**
         * Process input keyboard
         * @param window
         * @param key
         * @param scancode
         * @param action
         * @param mods
         */
        void processKeyboard(GLFWwindow *window, int key, int scancode, int action, int mods) override;

        /**
         * Process input mouse
         * @param window : glfw window
         * @param xpos : x-position on window
         * @param ypos : y-position on window
         */
        void processMouse(GLFWwindow *window, double xpos, double ypos) override;

        /**
         * Set scene visible by viewer and dispay in application to
         * interact with objet
         * @param scene
         */
        void setScene(Scene* scene);
        void setWindow(GLFWwindow* window);

        void setObjectMesh(ObjectMesh* obj_mesh);


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

        ObjectMesh* obj_mesh;


        //std::vector<std::set<unsigned int>> rings;
        //std::vector<unsigned int> one_ring(unsigned int index);

        // std::set<unsigned int> one_ring(MyOpenMesh* mesh);
        void laplacian(ObjectMesh* obj_mesh, float alpha);
        void deformation(MyOpenMesh* open_mesh, unsigned int index, unsigned int rings);


        



};

#endif // MY_VIEWER_HPP