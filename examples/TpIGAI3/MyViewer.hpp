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

		void setRadius(const float radius);
		void setTarget(const glm::vec3 target);

    private:

        GLFWwindow* window;
        Scene* scene;

        float radius;
		glm::vec3 target;
        double lastX;
        double lastY;
        float sensitivity;
        bool camera_mod;
        bool moveset_mode;


};

#endif // MY_VIEWER_HPP
