//
// Created by akhaten on 9/1/22.
//

#ifndef SURFACE_MESH_HPP
#define SURFACE_MESH_HPP

#include <vector>
#include <glm/glm.hpp>

#include <OpenMesh/Core/Mesh/PolyMesh_ArrayKernelT.hh>

// struct MyTrait:
//     OpenMesh::DefaultTraits
// {
//     typedef glm::vec3 Point;
//     // using Point = glm::vec3;
// };

// using MyOpenMesh = OpenMesh::PolyMesh_ArrayKernelT<MyTrait>;
// typedef OpenMesh::PolyMesh_ArrayKernelT<MyTrait> MyOpenMesh;
typedef OpenMesh::PolyMesh_ArrayKernelT<> MyOpenMesh;


#include "Mesh.hpp"

class ObjectMesh:
    public Mesh
{
    
public:

    // ObjectMesh(std::vector<glm::vec3> vertices, std::vector<unsigned int> indices);
    ObjectMesh(char* pathfile);
    ObjectMesh(MyOpenMesh* my_mesh);
    ~ObjectMesh();

    void draw() override;

    MyOpenMesh* getMyOpenMesh();
    

private:
    MyOpenMesh* my_mesh;
    void toOpenGL();

};


#endif // SURFACE_MESH_HPP
