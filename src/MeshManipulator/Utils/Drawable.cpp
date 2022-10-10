//
// Created by akhaten on 9/1/22.
//

#include "Drawable.hpp"

Drawable::Drawable(Mesh* mesh, Shader* shader)
{

    this->mesh = mesh;
    this->shader = shader;

    this->model = glm::mat4(1.0f);
    // this->model = glm::rotate(this->model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    

}

Drawable::~Drawable() {}

void Drawable::setViewer(Viewer* viewer)
{
    this->viewer = viewer;
}


void Drawable::draw()
{

    
    glUniformMatrix4fv(this->shader->model_loc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(this->shader->view_loc, 1, GL_FALSE, glm::value_ptr(this->viewer->getView()));
    glUniformMatrix4fv(this->shader->projection_loc, 1, GL_FALSE, glm::value_ptr(this->viewer->getProjectionMatrix()));
    this->shader->use();
    this->mesh->draw();
}

