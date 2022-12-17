//
// Created by akhaten on 8/7/22.
//

#include "OpenGLObject.hpp"


void OpenGLObject::loadDatas()
{

    glGenVertexArrays(1, &this->vao);
    glBindVertexArray(this->vao);

    glGenBuffers(1, &this->ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->opengl_indices.size() * sizeof(unsigned int), this->opengl_indices.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &this->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
    glBufferData(GL_ARRAY_BUFFER, this->opengl_vertices.size() * sizeof(glm::vec3), this->opengl_vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
    glEnableVertexAttribArray(0);

    

}

void OpenGLObject::draw()
{
    glBindVertexArray(this->vao);
}
