//
// Created by akhaten on 8/7/22.
//

#include "Shader.hpp"

Shader::Shader(const GLchar* vertex_shader_source, const GLchar* fragment_shader_source)
{

    GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
    glCompileShader(vertex_shader);

    GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
    glCompileShader(fragment_shader);

    this->shader_program = glCreateProgram();
    glAttachShader(this->shader_program, vertex_shader);
    glAttachShader(this->shader_program, fragment_shader);
    glLinkProgram(this->shader_program);

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);



}

Shader::~Shader() {}

void Shader::use()
{
    glUseProgram(this->shader_program);
}


