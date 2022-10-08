//
// Created by akhaten on 9/1/22.
//

#include "Drawable.hpp"

Drawable::Drawable(Mesh* mesh, Shader* shader)
{
    this->mesh = mesh;
    this->shader = shader;
}

Drawable::~Drawable() {}

void Drawable::draw()
{
    this->shader->use();
    this->mesh->draw();
}