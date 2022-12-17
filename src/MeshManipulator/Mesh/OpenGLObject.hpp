/**
 * @author akhaten
 * @file Mesh.hpp
 */

#ifndef MESH_HPP
#define MESH_HPP

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <vector>



class OpenGLObject
{

public:
    virtual void draw();

protected:
    std::vector<glm::vec3> opengl_vertices;
    std::vector<unsigned int> opengl_indices;
    GLuint vao;
    GLuint vbo;
    GLuint ebo;
    void loadDatas();

};

#endif // MESH_HPP
