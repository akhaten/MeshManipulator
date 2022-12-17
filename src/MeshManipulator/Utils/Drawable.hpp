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
#include "Shader.hpp"



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
        glm::mat4 modelMatrix();

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
    

};


#endif // DRAWABLE_HPP
