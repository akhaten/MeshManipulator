/**
 * @author akhaten
 * @file ObjectMesh.hpp
 */

#ifndef OBJECT_MESH_HPP
#define OBJECT_MESH_HPP

#include <vector>
#include <glm/glm.hpp>

//#include <OpenMesh/Core/Mesh/PolyMesh_ArrayKernelT.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>

struct MyTrait:
	OpenMesh::DefaultTraits
{
	typedef OpenMesh::Vec3d Point;
	typedef OpenMesh::Vec3d Color;
	typedef OpenMesh::Vec3d Normal;
	// using Point = glm::vec3;
};

// using MyOpenMesh = OpenMesh::PolyMesh_ArrayKernelT<MyTrait>;
// typedef OpenMesh::PolyMesh_ArrayKernelT<MyTrait> MyOpenMesh;
// typedef OpenMesh::PolyMesh_ArrayKernelT<> MyOpenMesh;
typedef OpenMesh::TriMesh_ArrayKernelT<MyTrait> MyOpenMesh;
//typedef OpenMesh::TriMesh_ArrayKernelT<OpenMesh::DefaultTraits> MyOpenMesh;


#include "OpenGLObject.hpp"

class ObjectMesh:
    public MyOpenMesh,
    public OpenGLObject
{
    
public:

    ObjectMesh();
    ObjectMesh(char* pathfile);
    ~ObjectMesh();

    void draw() override;
    void update();
    

private:

	/**
	 * Prepare vertex datas (position, color, normal...) for the pipeline OpenGL (vao, vbo, ebo...)
	 */
    void toOpenGL();

};


#endif // SURFACE_MESH_HPP
