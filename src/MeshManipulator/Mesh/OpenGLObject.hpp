/**
 * @author akhaten
 * @file OpenGLObject.hpp
 */

#ifndef OPENGL_OBJECT_HPP
#define OPENGL_OBJECT_HPP

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
        void toOpenGL();

    private:
        GLuint vao;
        GLuint vbo;
        GLuint ebo;


};

#endif // OPENGL_OBJECT_HPP
