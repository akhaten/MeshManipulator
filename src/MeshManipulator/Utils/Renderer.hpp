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

        Renderer(Viewer* viewer);
        ~Renderer();

        void render(Drawable* mesh);

        Shader* getShader();
        Viewer* getViewer();

        void setShader(Shader* shader);
        void setViewer(Viewer* viewer);

    private:
        Shader* shader;
        Viewer* viewer;
        

};


#endif // RENDERER_HPP