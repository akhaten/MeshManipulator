//
// Created by akhaten on 9/1/22.
//

#ifndef SCENE_HPP
#define SCENE_HPP

#include "MeshManipulator/Utils/Drawable.hpp"
#include "MeshManipulator/Window/Viewer.hpp"
#include "MeshManipulator/Utils/Renderer.hpp"
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
