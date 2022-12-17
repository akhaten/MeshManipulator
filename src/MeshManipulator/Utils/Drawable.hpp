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

        Drawable(ObjectMesh* mesh);
        ~Drawable();

        glm::mat4 modelMatrix();

        ObjectMesh* getMesh();

        
        

    private:
        ObjectMesh* mesh;
        glm::mat4 model;
    

};


#endif // DRAWABLE_HPP
