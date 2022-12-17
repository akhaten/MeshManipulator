
#include "Camera.hpp"

#include <iostream>

Camera::Camera(glm::vec3 position, glm::vec3 target)
{

    this->position = position;
    this->target = target;
    this->direction = glm::normalize(this->position-this->target);
    this->world_up = glm::vec3(0.0f, 1.0f, 0.0f);
    this->right = glm::normalize(glm::cross(this->world_up, this->direction));
    this->up = glm::normalize(glm::cross(this->direction, this->right));


    this->matrix = glm::mat4(1.0f);
    this->setRight(this->right);
    this->setUp(this->up);
    this->setDirection(this->direction);
    this->setPosition(this->position);

    // Default
    this->fov = glm::radians(45.0f);
    this->near = 0.01f;
    this->far = 100.0f;

}

Camera::~Camera() {}

void Camera::update(glm::mat4 transformation)
{
    this->matrix = transformation * this->matrix;
}

glm::mat4 Camera::viewMatrix()
{
    return glm::lookAt(
        this->getPosition(),
        this->getPosition()+this->getDirection(),
        this->getUp()
    );
}

glm::mat4 Camera::projectionMatrix()
{
    return glm::perspective(this->fov, this->aspect, this->near, this->far);
}


/**
 * GETTERS
 */

glm::vec3 Camera::getTarget()
{
    return this->target;
}

glm::vec3 Camera::getPosition()
{
    return glm::vec3(this->matrix[0][3], this->matrix[1][3], this->matrix[2][3]);
}

glm::vec3 Camera::getDirection()
{
    return glm::vec3(this->matrix[0][2], this->matrix[1][2], this->matrix[2][2]);
}

glm::vec3 Camera::getUp()
{
    return glm::vec3(this->matrix[0][1], this->matrix[1][1], this->matrix[2][1]);
}

glm::vec3 Camera::getRight()
{
    return glm::vec3(this->matrix[0][0], this->matrix[1][0], this->matrix[2][0]);
}

glm::vec3 Camera::getWorldUp()
{
    return this->world_up;
}

float Camera::getFov()
{
    return this->fov;
}

float Camera::getNear()
{
    return this->near;
}

float Camera::getAspect()
{
    return this->width/this->height;
}

float Camera::getFar()
{
    return this->far;
}

/**
 * SETTERS
 */

void Camera::setTarget(glm::vec3 target)
{
    this->target = target;
}

void Camera::setMatrix(unsigned int index, glm::vec3 value)
{
    for(unsigned int i = 0; i < 3; ++i)
        this->matrix[i][index] = value[i];
}

void Camera::setRight(glm::vec3 right)
{
    this->setMatrix(0, right);
}

void Camera::setUp(glm::vec3 up)
{
    this->setMatrix(1, up);
}

void Camera::setDirection(glm::vec3 direction)
{
    this->setMatrix(2, direction);
}

void Camera::setPosition(glm::vec3 position)
{
    this->setMatrix(3, position);
}

void Camera::setNear(const float near)
{
    this->near = near;
}

void Camera::setAspect(const float width, const float height)
{
    this->width = width;
    this->height = height;
}

void Camera::setFar(const float far)
{
    this->far = far;
}














