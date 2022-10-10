#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


class Camera
{


    public:

        Camera(glm::vec3 position, glm::vec3 target);
        ~Camera();

        glm::vec3 getTarget();
        glm::vec3 getPosition();
        glm::vec3 getDirection();
        glm::vec3 getUp();
        glm::vec3 getRight();
        glm::vec3 getWorldUp();

        void update(glm::mat4 transformation);

        void setTarget(glm::vec3 target);
        void setPosition(glm::vec3 position);
        void setDirection(glm::vec3 direction);
        void setUp(glm::vec3 up);
        void setRight(glm::vec3 right);


    private:

        // Position in world space
        glm::vec3 position;
        glm::vec3 direction;
        glm::vec3 target;
        glm::vec3 up;
        glm::vec3 right;

        // Up vector in space world
        glm::vec3 world_up;

        glm::mat4 matrix;
        glm::mat3 matrix2;

        
        void setMatrix(unsigned int index, glm::vec3 value);


};


#endif // CAMERA_HPP