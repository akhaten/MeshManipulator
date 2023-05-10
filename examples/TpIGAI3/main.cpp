#include <iostream>
#include <vector>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



// #include <MeshManipulator/Window/Application.hpp>
#include "MyApplication.hpp"

#include <MeshManipulator/Utils/Scene.hpp>
#include <MeshManipulator/Utils/Drawable.hpp>
#include <MeshManipulator/Utils/Shader.hpp>
#include <MeshManipulator/Utils/Camera.hpp>

//#include "OpenGLObject.hpp"
#include <MeshManipulator/Mesh/CurveMesh.hpp>
#include <MeshManipulator/Mesh/ObjectMesh.hpp>
#include <MeshManipulator/Utils/Lights/SpotLight.hpp>


#include "MyViewer.hpp"



int main(int argc, char** argv)
{

    MyApplication* app = new MyApplication("TP-IGAI3", 800, 600);
    Scene* scene = app->getScene();

    Camera* camera = new Camera(
        glm::vec3(0.0f, 0.0f, 5.0f),
        glm::vec3(0.0f, 0.0f, 1.0f)
    );

    MyViewer* viewer = new MyViewer(camera);
	viewer->setRadius(10.0f);

    app->setViewer(viewer);


	SpotLight* spot = new SpotLight(glm::vec3(1.0f, 1.0f, -10.0f), glm::vec3(1.0f, 1.0f, 1.0f));
	scene->getRenderer()->addLight(spot);


//	glm::vec3 color = glm::vec3(1.0f, 0.0f, 0.0f);
//	// Make crosshair
//	CurveMesh* line_left = new CurveMesh({glm::vec3(-0.05f, 0.0f, 0.0f), color, glm::vec3(-0.01f, 0.0f, 0.0f), color});
//	CurveMesh* line_right = new CurveMesh({glm::vec3(0.01f, 0.0f, 0.0f), color, glm::vec3(0.05f, 0.0f, 0.0f), color});
//	CurveMesh* line_down = new CurveMesh({glm::vec3(0.0f, -0.05f, 0.0f), color, glm::vec3(0.0f, -0.01f, 0.0f), color});
//	CurveMesh* line_up = new CurveMesh({glm::vec3(0.0f, 0.01f, 0.0f), color, glm::vec3(0.0f, 0.05f, 0.0f), color});
//
//	Drawable* d_left = new Drawable(line_left);
//	d_left->setIsOnScreen(true);
//	scene->addDrawable(d_left);
//
//	Drawable* d_right = new Drawable(line_right);
//	d_right->setIsOnScreen(true);
//	scene->addDrawable(d_right);
//
//	Drawable* d_down = new Drawable(line_down);
//	d_down->setIsOnScreen(true);
//	scene->addDrawable(d_down);
//
//	Drawable* d_up = new Drawable(line_up);
//	d_up->setIsOnScreen(true);
//	scene->addDrawable(d_up);

	// Cube
	ObjectMesh* mesh = new ObjectMesh();
	ObjectMesh::VertexHandle vhandle[8];
		
	vhandle[0] = mesh->add_vertex(ObjectMesh::Point(-1, -1,  1));
	vhandle[1] = mesh->add_vertex(ObjectMesh::Point( 1, -1,  1));
	vhandle[2] = mesh->add_vertex(ObjectMesh::Point( 1,  1,  1));
	vhandle[3] = mesh->add_vertex(ObjectMesh::Point(-1,  1,  1));
	vhandle[4] = mesh->add_vertex(ObjectMesh::Point(-1, -1, -1));
	vhandle[5] = mesh->add_vertex(ObjectMesh::Point( 1, -1, -1));
	vhandle[6] = mesh->add_vertex(ObjectMesh::Point( 1,  1, -1));
	vhandle[7] = mesh->add_vertex(ObjectMesh::Point(-1,  1, -1));
	// generate (quadrilateral) faces
	std::vector<ObjectMesh::VertexHandle>  face_vhandles;
	face_vhandles.clear();
	face_vhandles.push_back(vhandle[0]);
	face_vhandles.push_back(vhandle[1]);
	face_vhandles.push_back(vhandle[2]);
	face_vhandles.push_back(vhandle[3]);
	mesh->add_face(face_vhandles);
 
	face_vhandles.clear();
	face_vhandles.push_back(vhandle[7]);
	face_vhandles.push_back(vhandle[6]);
	face_vhandles.push_back(vhandle[5]);
	face_vhandles.push_back(vhandle[4]);
	mesh->add_face(face_vhandles);
	face_vhandles.clear();
	face_vhandles.push_back(vhandle[1]);
	face_vhandles.push_back(vhandle[0]);
	face_vhandles.push_back(vhandle[4]);
	face_vhandles.push_back(vhandle[5]);
	mesh->add_face(face_vhandles);
	face_vhandles.clear();
	face_vhandles.push_back(vhandle[2]);
	face_vhandles.push_back(vhandle[1]);
	face_vhandles.push_back(vhandle[5]);
	face_vhandles.push_back(vhandle[6]);
	mesh->add_face(face_vhandles);
	face_vhandles.clear();
	face_vhandles.push_back(vhandle[3]);
	face_vhandles.push_back(vhandle[2]);
	face_vhandles.push_back(vhandle[6]);
	face_vhandles.push_back(vhandle[7]);
	mesh->add_face(face_vhandles);
	face_vhandles.clear();
	face_vhandles.push_back(vhandle[0]);
	face_vhandles.push_back(vhandle[3]);
	face_vhandles.push_back(vhandle[7]);
	face_vhandles.push_back(vhandle[4]);
	mesh->add_face(face_vhandles);

	mesh->request_vertex_colors();
	mesh->request_vertex_normals();

	for(auto vertex : mesh->vertices()){                                                                                                                                                                         
		mesh->set_color(vertex, OpenMesh::Vec3d(1.0f, 0.5f, 0.31f));
		auto v_normal = mesh->calc_normal(vertex);
		mesh->set_normal(vertex, v_normal);
	}

	mesh->update_normals();

	scene->addDrawable(new Drawable(mesh));

	// Load object from .obj
    //ObjectMesh* humanoid = new ObjectMesh(
    //    "/home/akhaten/Documents/github/MeshManipulator/examples/TpIGAI2/obj_files/bunny.obj"
    //);

    //viewer->setObjectMesh(humanoid);
    //scene->addDrawable(new Drawable(humanoid));
	
	

    app->run();

    return 0;

}

/*
#include <iostream>
// -------------------- OpenMesh
#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/PolyMesh_ArrayKernelT.hh>
// ----------------------------------------------------------------------------
typedef OpenMesh::PolyMesh_ArrayKernelT<>  MyMesh;
// ----------------------------------------------------------------------------
// Build a simple cube and write it to std::cout

#include <set>
  
int main()
{
  MyMesh mesh;
  // generate opengl_vertices
  MyMesh::VertexHandle vhandle[8];
  vhandle[0] = mesh.add_vertex(MyMesh::Point(-1, -1,  1));
  vhandle[1] = mesh.add_vertex(MyMesh::Point( 1, -1,  1));
  vhandle[2] = mesh.add_vertex(MyMesh::Point( 1,  1,  1));
  vhandle[3] = mesh.add_vertex(MyMesh::Point(-1,  1,  1));
  vhandle[4] = mesh.add_vertex(MyMesh::Point(-1, -1, -1));
  vhandle[5] = mesh.add_vertex(MyMesh::Point( 1, -1, -1));
  vhandle[6] = mesh.add_vertex(MyMesh::Point( 1,  1, -1));
  vhandle[7] = mesh.add_vertex(MyMesh::Point(-1,  1, -1));
  // generate (quadrilateral) faces
  std::vector<MyMesh::VertexHandle>  face_vhandles;
  face_vhandles.clear();
  face_vhandles.push_back(vhandle[0]);
  face_vhandles.push_back(vhandle[1]);
  face_vhandles.push_back(vhandle[2]);
  face_vhandles.push_back(vhandle[3]);
  mesh.add_face(face_vhandles);
 
  face_vhandles.clear();
  face_vhandles.push_back(vhandle[7]);
  face_vhandles.push_back(vhandle[6]);
  face_vhandles.push_back(vhandle[5]);
  face_vhandles.push_back(vhandle[4]);
  mesh.add_face(face_vhandles);
  face_vhandles.clear();
  face_vhandles.push_back(vhandle[1]);
  face_vhandles.push_back(vhandle[0]);
  face_vhandles.push_back(vhandle[4]);
  face_vhandles.push_back(vhandle[5]);
  mesh.add_face(face_vhandles);
  face_vhandles.clear();
  face_vhandles.push_back(vhandle[2]);
  face_vhandles.push_back(vhandle[1]);
  face_vhandles.push_back(vhandle[5]);
  face_vhandles.push_back(vhandle[6]);
  mesh.add_face(face_vhandles);
  face_vhandles.clear();
  face_vhandles.push_back(vhandle[3]);
  face_vhandles.push_back(vhandle[2]);
  face_vhandles.push_back(vhandle[6]);
  face_vhandles.push_back(vhandle[7]);
  mesh.add_face(face_vhandles);
  face_vhandles.clear();
  face_vhandles.push_back(vhandle[0]);
  face_vhandles.push_back(vhandle[3]);
  face_vhandles.push_back(vhandle[7]);
  face_vhandles.push_back(vhandle[4]);
  mesh.add_face(face_vhandles);
  // write mesh to output.obj

  for(MyMesh::VertexIter v_it = mesh.vertices_sbegin(); v_it != mesh.vertices_end(); ++v_it){
    std::cout << v_it.handle().idx() << std::endl;
  }
  
  // for(auto v : mesh.opengl_vertices())
  //   std::cout << v.idx() << std::endl;


  // std::vector<std::vector<unsigned int>> rings;
  // std::vector<unsigned int> ring;
  // ring.push_back(0);
  // rings.push_back(ring);
  // ring.clear();
  // std::cout << rings[0].size() << std::endl;

  std::set<unsigned int> s1;
  std::set<unsigned int> s2;

  std::set<unsigned int> res;

  s1.insert(0);
  s1.insert(1);
  s1.insert(2);

  s2.insert(1);
  s2.insert(2);

  // std::cout << s1.size() << std::endl;
  // std::cout << s2.size() << std::endl;

  //std::set_union(s1.begin(), s1.end(), res.begin(), res.end(), std::inserter(res, res.begin()));
  //std::set_union(s2.begin(), s2.end(), res.begin(), res.end(), std::inserter(res, res.begin()));

  std::cout << "res :" << std::endl;
  for(unsigned int i : res)
    std::cout << i << std::endl;

  std::set_difference(
          s1.begin(),
          s1.end(),
          s2.begin(),
          s2.end(),
          std::inserter(res, res.begin())
    );

    std::cout << "res :" << std::endl;
    for(unsigned int i : res)
        std::cout << i << std::endl;

}*/


