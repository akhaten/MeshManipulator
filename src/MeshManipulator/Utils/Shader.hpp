/**
 * @author akhaten
 * @file Shader.hpp
 */

#ifndef SHADER_HPP
#define SHADER_HPP

#include <GL/glew.h>
#include <glm/glm.hpp>



class Shader
{

    public:
        //Shader(const char* path_vertex_shader_source, const char* path_fragment_shader_source);
        Shader(const GLchar* vertex_shader_source, const GLchar * fragment_shader_source);
        ~Shader();
        void use();

        void setBool(const char* name, const bool value);
        void setInt(const char* name, const int value);
        void setFloat(const char* name, const float value);
        void setMat4(const char* name, const glm::mat4 value);

        GLuint shader_program;
    
    

};

#endif // SHADER_HPP
