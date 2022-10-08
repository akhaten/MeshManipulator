//
// Created by akhaten on 9/1/22.
//

#include "SurfaceMesh.hpp"


SurfaceMesh::SurfaceMesh(std::vector<glm::vec3> vertices, std::vector<unsigned int> indices):
        Mesh(vertices, indices)
{}

SurfaceMesh::~SurfaceMesh() {}

void SurfaceMesh::draw()
{
    Mesh::draw();
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glDrawElements(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_INT, (void*)0);
    //glDrawElements(GL_LINE_STRIP, this->indices.size(), GL_UNSIGNED_INT, (void*)0);
}