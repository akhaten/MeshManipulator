//
// Created by akhaten on 9/1/22.
//

#include "Drawable.hpp"

Drawable::Drawable(Mesh* mesh)
{

    this->mesh = mesh;
    this->model = glm::mat4(1.0f);

}

Drawable::~Drawable() {}

glm::mat4 Drawable::modelMatrix()
{
    return this->model;
}

Mesh* Drawable::getMesh()
{
    return this->mesh;
}