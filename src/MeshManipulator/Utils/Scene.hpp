/**
 * @author akhaten
 * @file Scene.hpp
 */

#ifndef SCENE_HPP
#define SCENE_HPP

#include "MeshManipulator/Utils/Drawable.hpp"
#include "MeshManipulator/Window/Viewer.hpp"
#include "MeshManipulator/Utils/Renderer.hpp"

class Scene
{
    public:

        /**
         * Constructor of scene
         */
        Scene();

        /**
         * Destrictor of scene
         */
        ~Scene();

        /**
         * Add a drawable in scene
         * @param drawable : drawable
         */
        void addDrawable(Drawable* drawable);

        /**
         * Draw the scene
         */
        void draw();

        /**
         * Get renderer of scene
         * @return renderer
         */
        Renderer* getRenderer();

        /**
         * Set viewer to observe the scene
         * @param viewer : viewer
         */
        void setViewer(Viewer* viewer);

        /**
         * Collections of drawables
         */
        std::vector<Drawable*> drawables;

        

    private:

        /**
         * Viwer of scene
         */
        Viewer* viewer;

        /**
         * Renderer of scene
         */
        Renderer* renderer;
     

};


#endif //SCENE_HPP
