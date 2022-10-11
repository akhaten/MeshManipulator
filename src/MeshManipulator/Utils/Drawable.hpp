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
#include "Viewer.hpp"





class Drawable
{

public:
    Drawable(Mesh* mesh, Shader* shader);
    ~Drawable();
    void draw();
    void setViewer(Viewer* viewer);
    //void attachTexture(Texture* texture);

    Mesh* mesh;
    Shader* shader;

    glm::mat4 model;
    

private:
    
    Viewer* viewer;

};


#endif // DRAWABLE_HPP
