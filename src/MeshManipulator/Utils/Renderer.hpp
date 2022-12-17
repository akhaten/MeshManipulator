/**
 * @author akhaten
 * @file Renderer.hpp
 */

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "MeshManipulator/Utils/Shader.hpp"
#include "MeshManipulator/Window/Viewer.hpp"
#include "MeshManipulator/Mesh/OpenGLObject.hpp"
#include "MeshManipulator/Utils/Drawable.hpp"


class Renderer
{

    public:

        /**
         * Constructor of Renderer
         * @param viewer : viewer to make render
         */
        Renderer(Viewer* viewer);

        /**
         * Destructor of Renderer
         */
        ~Renderer();

        /**
         * Render an object
         * @param mesh : render the drawable
         */
        void render(Drawable* drawable);

        /**
         * Get shader of renderer
         * @return shader
         */
        Shader* getShader();

        /**
         * Get viewer of renderer
         * @return viewer
         */
        Viewer* getViewer();

        /**
        * Set shader of renderer
        * @param shader : new shader
        */
        void setShader(Shader* shader);

        /**
        * Set viewer of renderer
        * @param viewer : new viewer
        */
        void setViewer(Viewer* viewer);

    private:

        /**
         * Shader of renderer
         */
        Shader* shader;

        /**
         * Viewer of renderer
         */
        Viewer* viewer;
        

};


#endif // RENDERER_HPP