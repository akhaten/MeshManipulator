//
// Created by akhaten on 9/1/22.
//

#ifndef SCENE_HPP
#define SCENE_HPP

#include "Drawable.hpp"

class Scene
{
public:
    Scene();
    ~Scene();
    void addDrawable(Drawable* drawable);
    void draw();
    //void addCamera();
    //void addLight();

private:
    std::vector<Drawable*> drawables;
    //std::vector<Light*> lights;
    //std::vector<Camera*> cameras;

};


#endif //SCENE_HPP
