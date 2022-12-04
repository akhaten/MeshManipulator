#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "Shader.hpp"
#include "Viewer.hpp"
#include "Mesh.hpp"
#include "Drawable.hpp"


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