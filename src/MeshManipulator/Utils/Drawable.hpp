/**
 * @author akhaten
 * @file Drawable.hpp
 */

#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "MeshManipulator/Mesh/ObjectMesh.hpp"
#include "MeshManipulator/Utils/Shader.hpp"



class Drawable
{

    public:

        /**
         * Constrictor of Drawable
         * @param object : object to draw
         */
        Drawable(OpenGLObject* object);

        /**
         * Destructor of Drawable
         */
        ~Drawable();

        /**
         * Get model/transformation matrix
         * @return model matrix
         */
        glm::mat4 getModelMatrix();

		/**
		 * Know if we draw only on 2D screen
		 * @return Is it 2D drawable
		 */
		bool isOnScreen();

		/**
		 * Set draw mode
		 */
		void setIsOnScreen(const bool on_screen);

        /**
         * Get Opengl object
         * @return opengl object
         */
        OpenGLObject* getOpenGLObject();


    private:

        /**
         * OpenGl object to display
         */
        OpenGLObject* object;

        /**
         * Transformation matrix
         */
        glm::mat4 model;

		/**
		 * Boolean for use only medel matrix in fragment shader
		 * i.e draw only on 2D screen.
		 * Example : draw a crosshair for fps
		 */
		bool on_screen;

    

};


#endif // DRAWABLE_HPP
