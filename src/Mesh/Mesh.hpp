//
// Created by akhaten on 8/7/22.
//

#ifndef MESH_HPP
#define MESH_HPP

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <vector>

struct Vertex
{
    glm::vec3 position;
    glm::vec3 color;
    glm::vec2 coord_texture;
};

class Mesh
{

public:

    Mesh(std::vector<glm::vec3> vertices, std::vector<unsigned int> indices);
    Mesh(std::vector<glm::vec3> vertices);
    ~Mesh();
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
