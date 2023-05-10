//
// Created by akhaten on 8/7/22.
//

#include "OpenGLObject.hpp"


void OpenGLObject::toOpenGL()
{

    glGenVertexArrays(1, &this->vao);
    glBindVertexArray(this->vao);

    glGenBuffers(1, &this->ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->opengl_indices.size() * sizeof(unsigned int), this->opengl_indices.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &this->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
    glBufferData(GL_ARRAY_BUFFER, this->opengl_vertices.size() * sizeof(glm::vec3), this->opengl_vertices.data(), GL_STATIC_DRAW);
	
	// Vertex position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(glm::vec3), (void*)0);
    glEnableVertexAttribArray(0);

	// Vertex color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3*sizeof(glm::vec3), (void*)(sizeof(glm::vec3)));
	glEnableVertexAttribArray(1);

	// Vertex normal
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 3*sizeof(glm::vec3), (void*)(2*sizeof(glm::vec3)));
	glEnableVertexAttribArray(2);
}

void OpenGLObject::draw()
{
    glBindVertexArray(this->vao);
}
