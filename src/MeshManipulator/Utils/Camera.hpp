/**
 * @author akhaten
 * @file Camera.hpp
 */

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


class Camera
{


    public:

        /**
         * Camera constructor
         * @param position : position of camera into scene
         * @param target : point target
         */
        Camera(glm::vec3 position, glm::vec3 target);

        /**
         * Camera destructor
         */
        ~Camera();

        /**
         * Apply an transformation
         * @param transformation : matrix 4x4 (rotation + translation)
         */
        void update(glm::mat4 transformation);

        /**
         * Get view matrix
         * @return matrix 4x4
         */
        glm::mat4 viewMatrix();

        /**
        * Get projection matrix
        * @return projection matrix 4x4
        */
        glm::mat4 projectionMatrix();


        /**
         * Get target point of camera
         * @return target point
         */
        glm::vec3 getTarget();

        /**
         * Get position of camera
         * @return position of camera
         */
        glm::vec3 getPosition();

        /**
         * Get view direction
         * @return view direction
         */
        glm::vec3 getDirection();

        /**
         * Get up vector of camera
         * @return up vector
         */
        glm::vec3 getUp();

        /**
         * Get right vector of camera
         * @return right vector
         */
        glm::vec3 getRight();

        /**
         * Get world/fixed up vector of camera
         * @return world up vector
         */
        glm::vec3 getWorldUp();

        /**
         * Get field of view
         * @return field of view
         */
        float getFov();

        /**
         * Get near plane distance
         * @return near distance
         */
        float getNear();

        /**
         * Get aspect
         * @return aspect
         */
        float getAspect();

        /**
         * Get far plane distance
         * @return far distance
         */
        float getFar();

        /**
        * Set target point of camera
        * @param target : new target point
        */
        void setTarget(glm::vec3 target);

        /**
        * Set new position of camera
        * @param position : new position
        */
        void setPosition(glm::vec3 position);

        /**
        * Set new direction of camera
        * @param direction : new direction
        */
        void setDirection(glm::vec3 direction);

        /**
        * Set up vector of camera
        * @param up : new up vector
        */
        void setUp(glm::vec3 up);

        /**
        * Set right vector of camera
        * @param right : new up vector
        */
        void setRight(glm::vec3 right);

        /**
        * Set fov of camera
        * @param fov : new fov
        */
        void setFov(const float fov);

        /**
        * Set near of camera
        * @param near : new near distance
        */
        void setNear(const float near);

        /**
        * Set aspect of camera
        * @param aspect : new aspect distance
        */
        void setAspect(const float width, const float height);

        /**
        * Set far of camera
        * @param far : new far distance
        */
        void setFar(const float far);


    private:

        /**
        * First column is right vector \n
        * Second column is up vector \n
        * Thirty column is direction vector \n
        * Fourty column is position \n
        */
        enum VectorInfo {
            Right = 0,
            Up = 1,
            Direction = 2,
            Position = 3
        };

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
         * camera matrix \n
         * Allow apply transformation more easy \n
         * First column is right vector \n
         * Second column is up vector \n
         * Thirty column is direction vector \n
         * Fourty column is position \n
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
        
        /**
         * Aspect
         */
        float aspect;

        /**
         * Width
         */
        int width;

        /**
         * Height
         */
        int height;

        /**
         * Near distance
         */
        float near;

        /**
         * Far distance
         */
        float far;

        /**
         * Change vector of matrix
         */
        void setMatrix(unsigned int index, glm::vec3 value);

};


#endif // CAMERA_HPP