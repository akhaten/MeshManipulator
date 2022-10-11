//
// Created by akhaten on 9/1/22.
//

#include "Drawable.hpp"

Drawable::Drawable(Mesh* mesh, Shader* shader)
{

    this->mesh = mesh;
    this->shader = shader;
    this->model = glm::mat4(1.0f);

}

Drawable::~Drawable() {}

void Drawable::setViewer(Viewer* viewer)
{
    this->viewer = viewer;
}


void Drawable::draw()
{

    this->shader->setMat4("model", this->model);
    this->shader->setMat4("view", this->viewer->viewMatrix());
    this->shader->setMat4("projection", this->viewer->projectionMatrix());
    this->shader->use();
    this->mesh->draw();

}

