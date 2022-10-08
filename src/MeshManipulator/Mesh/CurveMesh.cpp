#include "CurveMesh.hpp"

CurveMesh::CurveMesh(
    std::vector<glm::vec3> vertices
){
    this->vertices = vertices;
    for(unsigned int index = 0; index < vertices.size(); ++index)
        this->indices.push_back(index);
    this->loadDatas();
}

void CurveMesh::draw()
{
    Mesh::draw();
    glDrawElements(GL_LINE_STRIP, this->indices.size(), GL_UNSIGNED_INT, (void*)0);
}