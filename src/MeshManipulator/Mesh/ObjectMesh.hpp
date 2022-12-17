/**
 * @author akhaten
 * @file ObjectMesh.hpp
 */

#ifndef OBJECT_MESH_HPP
#define OBJECT_MESH_HPP

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


#include "OpenGLObject.hpp"

class ObjectMesh:
    public MyOpenMesh,
    protected OpenGLObject
{
    
public:

    ObjectMesh();
    ObjectMesh(char* pathfile);
    ~ObjectMesh();

    void draw() override;

    void update();
    

private:
    void toOpenGL();

};


#endif // SURFACE_MESH_HPP
