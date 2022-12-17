/**
 * @author akhaten
 * @file Viewer.hpp
 */

#ifndef VIEWER_HPP
#define VIEWER_HPP


#include <GLFW/glfw3.h>
#include "MeshManipulator/Utils/Camera.hpp"

// struct VertexRing {
//     unsigned int id_vertex_om;
//     unsigned int index_in_matrix;
// };


class Viewer
{

    public:

        /**
         * Constructor of Viewer
         * @param camera : a camera
         */
        Viewer(Camera* camera);

        /**
         * Destructor of Viewer
         */
        ~Viewer();

        /**
         * Get view matrix
         * @return view matrix
         */
        glm::mat4 viewMatrix();

        /**
         * Get projection matrix
         * @return projection matrix
         */
        glm::mat4 projectionMatrix();
    
        /**
         * Get camera
         * @return camera
         */
        Camera* getCamera();

        /**
         * Set a camera
         * @param camera : new camera
         */
        void setCamera(Camera* camera);

        /**
         * Process event from keyboard
         * @param window
         * @param key
         * @param scancode
         * @param action
         * @param mods
         */
        virtual void processKeyboard(GLFWwindow *window, int key, int scancode, int action, int mods) = 0;

        /**
         *  Process event from mouse
         * @param window
         * @param xpos
         * @param ypos
         */
        virtual void processMouse(GLFWwindow *window, double xpos, double ypos) = 0;

    protected:

        /**
         * Camera
         */
        Camera* camera;
        


};

#endif // VIEWER_HPP