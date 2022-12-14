//
// Created by akhaten on 9/1/22.
//

#include "ObjectMesh.hpp"

#include <OpenMesh/Core/IO/MeshIO.hh>


ObjectMesh::ObjectMesh(char* pathfile)
{

    this->my_mesh = new MyOpenMesh();
    OpenMesh::IO::read_mesh(*(this->my_mesh), pathfile);
    this->toOpenGL();

}

ObjectMesh::ObjectMesh(MyOpenMesh* my_mesh)
{

    this->my_mesh = my_mesh;
    this->toOpenGL();
    
}

void ObjectMesh::update()
{
    this->toOpenGL();
}

void ObjectMesh::toOpenGL()
{

    this->vertices.clear();
    this->indices.clear();

    for(auto point : this->my_mesh->vertices()){
        auto p = this->my_mesh->point(point);
        this->vertices.push_back(glm::vec3(p[0], p[1], p[2]));
        // this->vertices.push_back(p);
    }

    std::vector<unsigned int> indices;
    for(auto face : this->my_mesh->faces()){
        for(auto pt : face.vertices())
            this->indices.push_back(pt.idx());
    }

    this->loadDatas();
}


ObjectMesh::~ObjectMesh() {}

void ObjectMesh::draw()
{
    Mesh::draw();
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glDrawElements(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_INT, (void*)0);
    //glDrawElements(GL_LINE_STRIP, this->indices.size(), GL_UNSIGNED_INT, (void*)0);
}

MyOpenMesh* ObjectMesh::getMyOpenMesh()
{
    return this->my_mesh;
}