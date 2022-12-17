//
// Created by akhaten on 9/1/22.
//

#include "Drawable.hpp"

Drawable::Drawable(OpenGLObject* object)
{

    this->object = object;
    this->model = glm::mat4(1.0f);

}

Drawable::~Drawable() {}

glm::mat4 Drawable::modelMatrix()
{
    return this->model;
}

OpenGLObject* Drawable::getOpenGLObject()
{
    return this->object;
}