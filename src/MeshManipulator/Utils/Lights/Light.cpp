//
// Created by akhaten on 1/19/23.
//

#include "MeshManipulator/Utils/Lights/Light.hpp"

Light::Light(glm::vec3 position, glm::vec3 color)
{
	this->setPosition(position);
	this->setColor(color);
}

void Light::setPosition(glm::vec3 position)
{
	this->position = position;
}

void Light::setColor(glm::vec3 color)
{
	this->color = color;
}

glm::vec3 Light::getPosition()
{
	return this->position;
}

glm::vec3 Light::getColor()
{
	return this->color;
}

Shader* Light::getShader()
{
	return this->shader;
}

void Light::toOpenGL()
{
	
}
