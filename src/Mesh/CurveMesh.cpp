#include "CurveMesh.hpp"

CurveMesh::CurveMesh(std::vector<glm::vec3> vertices):
    Mesh(vertices)
{}

void CurveMesh::draw()
{
    Mesh::draw();
    glDrawElements(GL_LINE_STRIP, this->indices.size(), GL_UNSIGNED_INT, (void*)0);
}