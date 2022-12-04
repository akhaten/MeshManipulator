//
// Created by akhaten on 9/1/22.
//

#ifndef SCENE_HPP
#define SCENE_HPP

#include "Drawable.hpp"
#include "Viewer.hpp"
#include "Renderer.hpp"

class Scene
{
    public:

        Scene();
        ~Scene();

        void addDrawable(Drawable* drawable);
        void draw();

        Renderer* getRenderer();

        void setViewer(Viewer* viewer);

        std::vector<Drawable*> drawables;

        

    private:

        Viewer* viewer;
        Renderer* renderer;
     

};


#endif //SCENE_HPP
