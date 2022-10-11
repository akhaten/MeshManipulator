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


void Drawable::draw(glm::mat4 projection_matrix, glm::mat4 view_matrix)
{

    this->shader->setMat4("model", this->model);
    this->shader->setMat4("view", view_matrix);
    this->shader->setMat4("projection", projection_matrix);
    this->shader->use();
    this->mesh->draw();

}

