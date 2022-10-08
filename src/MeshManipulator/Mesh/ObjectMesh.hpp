//
// Created by akhaten on 9/1/22.
//

#ifndef SURFACE_MESH_HPP
#define SURFACE_MESH_HPP

#include <vector>
#include <glm/glm.hpp>

#include <OpenMesh/Core/Mesh/PolyMesh_ArrayKernelT.hh>
typedef OpenMesh::PolyMesh_ArrayKernelT<> MyOpenMesh;

#include "Mesh.hpp"

class ObjectMesh:
    public Mesh
{
    
public:
    ObjectMesh(std::vector<glm::vec3> vertices, std::vector<unsigned int> indices);
    ObjectMesh(MyOpenMesh* my_mesh);
    ~ObjectMesh();
    void draw() override;

private:
    MyOpenMesh* my_mesh;

};


#endif // SURFACE_MESH_HPP
