//
// Created by akhaten on 8/7/22.
//

#ifndef SHADER_HPP
#define SHADER_HPP

#include <GL/glew.h>


class Shader
{

public:
    //Shader(const char* path_vertex_shader_source, const char* path_fragment_shader_source);
    Shader(const GLchar* vertex_shader_source, const GLchar * fragment_shader_source);
    ~Shader();
    void use();


private:
    GLuint shader_program;

};

#endif // SHADER_HPP
