//
// Created by akhaten on 8/7/22.
//



#include "Shader.hpp"
#include <glm/gtc/type_ptr.hpp>


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


    this->setMat4("view", glm::mat4(1.0f));
    this->setMat4("model", glm::mat4(1.0f));

}

Shader::~Shader() {}

void Shader::use()
{
    
    glUseProgram(this->shader_program);
}

void Shader::setBool(const char* name, const bool value)
{
    glUniform1i(glGetUniformLocation(this->shader_program, name), (int)value);
}

void Shader::setInt(const char* name, const int value)
{
    glUniform1i(glGetUniformLocation(this->shader_program, name), value);
}

void Shader::setFloat(const char* name, const float value)
{
    glUniform1f(glGetUniformLocation(this->shader_program, name), value);

}

void Shader::setMat4(const char* name, const glm::mat4 value)
{
    glUniformMatrix4fv(glGetUniformLocation(this->shader_program, name), 1, GL_FALSE, glm::value_ptr(value));
}


