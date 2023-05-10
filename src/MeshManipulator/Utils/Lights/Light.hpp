//
// Created by akhaten on 1/19/23.
//

#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <glm/glm.hpp>

#include "MeshManipulator/Utils/Shader.hpp"

class Light
{

    protected:
		GLint vao;

		// unsigned int vao;
		glm::mat4 matrix;
        glm::vec3 position;
        glm::vec3 color;
		float ambient;
		float diffuse;
		float specular;
        Shader* shader;

    public:

		/**
		 * Constructor of Light
		 * @param position : position of light
		 * @param color : color of light
		 */
		Light(glm::vec3 position, glm::vec3 color);

        /**
         * Set a new position
         * @param position : new position
         */
        void setPosition(glm::vec3 position);

        /**
         * Set a new color
         * @param color : new color
         */
        void setColor(glm::vec3 color);

        /**
         * Get position
         * @return position of light
         */
        glm::vec3 getPosition();

        /**
         * Get color
         * @return color of light
         */
        glm::vec3 getColor();

		/**
		 * Get shader of light
		 * @return shader of light
		 */
		Shader* getShader();

		/**
		 * Load light to OpenGL 
		 */
		void toOpenGL();

};

#endif //LIGHT_HPP
