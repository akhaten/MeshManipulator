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
        /**
         * Constructor of Shader
         * Create a shader for render an opengl object
         * @param vertex_shader_source : vertex shader source
         * @param fragment_shader_source : fragment shader source
         */
        Shader(const GLchar* vertex_shader_source, const GLchar * fragment_shader_source);

        /**
         * Destructor of Shader
         */
        ~Shader();

        /**
         * Use shader to render
         */
        void use();

        /**
         * Set boolean variable in shader
         * @param name : name of variable
         * @param value : new value
         */
        void setBool(const char* name, const bool value);

        /**
         * Set integer variable in shader
         * @param name : name of variable
         * @param value : new value
         */
        void setInt(const char* name, const int value);

        /**
         * Set float variable in shader
         * @param name : name of variable
         * @param value : new value
         */
        void setFloat(const char* name, const float value);

        /**
         * Set matrix (4x4) variable in shader
         * @param name : name of variable
         * @param value : new value
         */
        void setMat4(const char* name, const glm::mat4 value);

        /**
         * ID of shader program
         */
        GLuint shader_program;
    
    

};

#endif // SHADER_HPP
