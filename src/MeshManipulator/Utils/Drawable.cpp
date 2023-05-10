//
// Created by akhaten on 9/1/22.
//

#include "Drawable.hpp"

Drawable::Drawable(OpenGLObject* object)
{

    this->object = object;
    this->model = glm::mat4(1.0f);
	this->on_screen = false;

}

Drawable::~Drawable() {}



bool Drawable::isOnScreen()
{
	return this->on_screen;
}

glm::mat4 Drawable::getModelMatrix()
{
    return this->model;
}

OpenGLObject* Drawable::getOpenGLObject()
{
    return this->object;
}

void Drawable::setIsOnScreen(const bool on_screen)
{
	this->on_screen = on_screen;
}


