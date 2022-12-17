//
// Created by akhaten on 9/1/22.
//

#include "ObjectMesh.hpp"

#include <OpenMesh/Core/IO/MeshIO.hh>


ObjectMesh::ObjectMesh(char* pathfile)
{
    OpenMesh::IO::read_mesh(*this, pathfile);
    this->toOpenGL();
}

ObjectMesh::~ObjectMesh() {}


void ObjectMesh::update()
{
    this->toOpenGL();
}

void ObjectMesh::toOpenGL()
{

    this->opengl_vertices.clear();
    this->opengl_indices.clear();

    for(auto point : this->vertices()){
        auto p = this->point(point);
        this->opengl_vertices.push_back(glm::vec3(p[0], p[1], p[2]));
        // this->opengl_vertices.push_back(p);
    }

    std::vector<unsigned int> indices;
    for(auto face : this->faces()){
        for(auto pt : face.vertices())
            this->opengl_indices.push_back(pt.idx());
    }

    this->loadDatas();
}




void ObjectMesh::draw()
{
    OpenGLObject::draw();
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glDrawElements(GL_TRIANGLES, this->opengl_indices.size(), GL_UNSIGNED_INT, (void*)0);
    //glDrawElements(GL_LINE_STRIP, this->opengl_indices.size(), GL_UNSIGNED_INT, (void*)0);
}