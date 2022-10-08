//
// Created by akhaten on 8/7/22.
//

#ifndef Mesh2_HPP
#define Mesh2_HPP

#include <GL/glew.h>


#include <glm/glm.hpp>
#include <vector>



class Mesh2
{

public:

    Mesh2(MyOpenMesh mymesh);
    Mesh2(std::vector<glm::vec3> vertices);
    ~Mesh2();
    virtual void draw();

protected:
    std::vector<glm::vec3> vertices;
    std::vector<unsigned int> indices;
    GLuint vao;
    GLuint vbo;
    GLuint ebo;
    void loadDatas();

};

#endif // Mesh2_HPP
