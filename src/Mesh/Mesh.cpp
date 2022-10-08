//
// Created by akhaten on 8/7/22.
//

#include "Mesh.hpp"

Mesh::Mesh(std::vector<glm::vec3> vertices, std::vector<unsigned int> indices)
{

    this->vertices = vertices;
    this->indices= indices;

    this->loadDatas();

}

Mesh::Mesh(std::vector<glm::vec3> vertices)
{

    this->vertices = vertices;
    for(unsigned int index = 0; index < vertices.size(); ++index)
        this->indices.push_back(index);

    this->loadDatas();

}

Mesh::~Mesh() {}

void Mesh::loadDatas()
{

    glGenVertexArrays(1, &this->vao);
    glBindVertexArray(this->vao);

    glGenBuffers(1, &this->ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices.size()*sizeof(unsigned int), this->indices.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &this->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
    glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(glm::vec3), this->vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
    glEnableVertexAttribArray(0);

}

void Mesh::draw()
{
    glBindVertexArray(this->vao);
}
