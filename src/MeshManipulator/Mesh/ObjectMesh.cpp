//
// Created by akhaten on 9/1/22.
//

#include "ObjectMesh.hpp"

#include <OpenMesh/Core/IO/MeshIO.hh>


ObjectMesh::ObjectMesh(char* pathfile)
{
    OpenMesh::IO::read_mesh(*this, pathfile);
    //this->toOpenGL();
}

ObjectMesh::ObjectMesh() {}

ObjectMesh::~ObjectMesh(){}


void ObjectMesh::update()
{
    this->toOpenGL();
}

void ObjectMesh::toOpenGL()
{

    this->opengl_vertices.clear();
    this->opengl_indices.clear();
	
	this->request_vertex_colors();
	this->request_vertex_normals();

    for(auto vertex : this->vertices()){

        auto v_position = this->point(vertex);	
		this->opengl_vertices.push_back(glm::vec3(v_position[0], v_position[1], v_position[2]));

		//this->set_color(vertex, OpenMesh::Vec3d(1.0f, 0.5f, 0.31f));
		auto v_color = this->color(vertex);
		this->opengl_vertices.push_back(glm::vec3(v_color[0], v_color[1], v_color[2]));
		
		auto v_normal = this->calc_normal(vertex);
		//this->set_normal(vertex, v_normal);
		//this->update_normal(vertex);
		//std::cout << "Normal :" << v_normal[0] << "; " << v_normal[1] << "; " << v_normal[2] << std::endl;
		this->opengl_vertices.push_back(glm::vec3(v_normal[0], v_normal[1], v_normal[2]));

    }


    std::vector<unsigned int> indices;
    
	for(auto face : this->faces()){
        for(auto vertex : face.vertices())
            this->opengl_indices.push_back(vertex.idx());
    }

    OpenGLObject::toOpenGL();

}




void ObjectMesh::draw()
{
	this->update();
    OpenGLObject::draw();
    //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glDrawElements(GL_TRIANGLES, this->opengl_indices.size(), GL_UNSIGNED_INT, (void*)0);
    //glDrawElements(GL_LINE_STRIP, this->opengl_indices.size(), GL_UNSIGNED_INT, (void*)0);
}
