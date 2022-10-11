//
// Created by akhaten on 9/1/22.
//

#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Mesh.hpp"
#include "Shader.hpp"



class Drawable
{

    public:

        Drawable(Mesh* mesh);
        ~Drawable();

        glm::mat4 modelMatrix();

        Mesh* getMesh();

        
        

    private:
        Mesh* mesh;
        glm::mat4 model;
    

};


#endif // DRAWABLE_HPP
