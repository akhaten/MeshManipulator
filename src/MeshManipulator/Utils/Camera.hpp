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
        void update(glm::mat4 transformation);
        glm::mat4 viewMatrix();
        glm::mat4 projectionMatrix();


        glm::vec3 getTarget();
        glm::vec3 getPosition();
        glm::vec3 getDirection();
        glm::vec3 getUp();
        glm::vec3 getRight();
        glm::vec3 getWorldUp();
        float getFov();
        float getNear();
        float getAspect();
        float getFar();

    
        void setTarget(glm::vec3 target);
        void setPosition(glm::vec3 position);
        void setDirection(glm::vec3 direction);
        void setUp(glm::vec3 up);
        void setRight(glm::vec3 right);
        void setFov(const float fov);
        void setNear(const float near);
        void setAspect(const float width, const float height);
        void setFar(const float far);
        
        



    private:

        /**
         * Position of camera in world space
         */
        glm::vec3 position;

        /**
         * Direction of view
         */
        glm::vec3 direction;

        /**
         * Point looking by camera
         */
        glm::vec3 target;

        /**
         * Up of camera
         */
        glm::vec3 up;

        /**
         * Right of camera
         */
        glm::vec3 right;

        /**
         * Up vector in world space
         */
        glm::vec3 world_up;

        /**
         * Camera matrix
         * Allow apply transformation more easy
         * First column is right vector
         * Second column is up vector
         * Thirty column is direction vector
         * Fourty column is position
         */
        glm::mat4 matrix;

        /**
         * Projection/Perspective matrix
         */
        glm::mat4 projection;

        /**
         * Field of view
         */
        float fov;
        

        float aspect;

        int width;

        int height;
       

        float near;
       

        float far;
        

        void setMatrix(unsigned int index, glm::vec3 value);

    
        

        


};


#endif // CAMERA_HPP