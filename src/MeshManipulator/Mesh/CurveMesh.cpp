#include "CurveMesh.hpp"

CurveMesh::CurveMesh(
    std::vector<glm::vec3> vertices
){
    this->opengl_vertices = vertices;
    for(unsigned int index = 0; index < vertices.size()/2; ++index)
        this->opengl_indices.push_back(index);
    this->toOpenGL();
}

void CurveMesh::draw()
{
    OpenGLObject::draw();
    glDrawElements(GL_LINE_STRIP, this->opengl_indices.size(), GL_UNSIGNED_INT, (void*)0);
}
