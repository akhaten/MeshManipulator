//
// Created by akhaten on 9/1/22.
//

#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include "Mesh.hpp"
#include "Shader.hpp"
//#include "Texture.hpp"

class Drawable
{

public:
    Drawable(Mesh* mesh, Shader* shader);
    ~Drawable();
    void draw();
    //void attachTexture(Texture* texture);

private:
    Mesh* mesh;
    Shader* shader;
    //Texture* texture;

};


#endif // DRAWABLE_HPP
