
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

    // this->matrix[0] = glm::vec4(this->right, 0.0f);
    // this->matrix[1] = glm::vec4(this->up, 0.0f);
    // this->matrix[2] = glm::vec4(this->direction, 0.0f);
    // this->matrix[3] = glm::vec4(this->position, 1.0f);

    this->setRight(this->right);
    this->setUp(this->up);
    this->setDirection(this->direction);
    this->setPosition(this->position);


    // this->matrix = glm::transpose(this->matrix);

    std::cout << "position : " << position.x << ", " << position.y << ", " << position.z << std::endl;
    std::cout << "direction : " << direction.x << ", " << direction.y << ", " << direction.z << std::endl;
    // std::cout << position.x << ", " << position.y << ", " << position.z << std::endl;
    // std::cout << position.x << ", " << position.y << ", " << position.z << std::endl;
}


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


void Camera::setTarget(glm::vec3 target)
{
    this->target = target;
}


void Camera::setMatrix(unsigned int index, glm::vec3 value)
{
    for(unsigned int i = 0; i < 3; ++i)
        this->matrix[i][index] = value[i];
}

void Camera::setPosition(glm::vec3 position)
{
    this->setMatrix(3, position);
}

void Camera::setDirection(glm::vec3 direction)
{
    this->setMatrix(2, direction);
}

void Camera::setUp(glm::vec3 up)
{
    this->setMatrix(1, up);
}

void Camera::setRight(glm::vec3 right)
{
    this->setMatrix(0, right);
}

void Camera::update(glm::mat4 transformation)
{
    this->matrix = transformation * this->matrix;
}







