//
// Created by akhaten on 9/1/22.
//

#ifndef SCENE_HPP
#define SCENE_HPP

#include "Drawable.hpp"
#include "Viewer.hpp"

class Scene
{
    public:

        Scene();
        ~Scene();

        void addDrawable(Drawable* drawable);
        void draw();

        void setViewer(Viewer* viewer);

        

    private:

        Viewer* viewer;
        std::vector<Drawable*> drawables;
        //std::vector<Light*> lights;glm::mat4 
        //std::vector<Camera*> cameras;

};


#endif //SCENE_HPP
