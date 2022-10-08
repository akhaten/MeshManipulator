//
// Created by akhaten on 9/1/22.
//

#include "SurfaceMesh2.hpp"

#include <OpenMesh/Core/Mesh/PolyMesh_ArrayKernelT.hh>
typedef OpenMesh::PolyMesh_ArrayKernelT<> MyOpenMesh;


SurfaceMesh2::SurfaceMesh2(MyOpenMesh op_mesh):
        Mesh(vertices, indices)
{


}

SurfaceMesh2::~SurfaceMesh2() {}

void SurfaceMesh2::draw()
{
    Mesh::draw();
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glDrawElements(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_INT, (void*)0);
    //glDrawElements(GL_LINE_STRIP, this->indices.size(), GL_UNSIGNED_INT, (void*)0);
}