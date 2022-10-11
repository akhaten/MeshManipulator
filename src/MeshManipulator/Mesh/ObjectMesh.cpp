//
// Created by akhaten on 9/1/22.
//

#include "ObjectMesh.hpp"


ObjectMesh::ObjectMesh(std::vector<glm::vec3> vertices, std::vector<unsigned int> indices)
{
    this->vertices = vertices;
    this->indices = indices;
    this->loadDatas();
}

ObjectMesh::ObjectMesh(MyOpenMesh* my_mesh)
{

    this->my_mesh = my_mesh;

    std::vector<glm::vec3> points;
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