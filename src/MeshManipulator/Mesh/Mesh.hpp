//
// Created by akhaten on 8/7/22.
//

#ifndef MESH_HPP
#define MESH_HPP

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <vector>



class Mesh
{

public:
    virtual void draw();

protected:
    std::vector<glm::vec3> vertices;
    std::vector<unsigned int> indices;
    GLuint vao;
    GLuint vbo;
    GLuint ebo;
    void loadDatas();

};

#endif // MESH_HPP
