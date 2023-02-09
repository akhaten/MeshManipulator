//
// Created by akhaten on 1/19/23.
//

#include "MeshManipulator/Utils/Lights/DirectionalLight.hpp"

void DirectionalLight::setDirection(glm::vec3 direction)
{
    this->direction = direction;
}

glm::vec3 DirectionalLight::getDirection()
{
    return this->direction;
}
