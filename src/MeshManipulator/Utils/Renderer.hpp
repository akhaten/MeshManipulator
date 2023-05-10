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
#include "MeshManipulator/Utils/Lights/Light.hpp"

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

		/**
		 * Add a light to renderer
		 * @param light : a light
		 */
		void addLight(Light* light);

		//unsigned int addShader(Shader* shader);
		//Shader* getShader(unsigned int index);
		//Shader* getShader(const char* name);


    private:

        /**
         * Shader of renderer
         */
        Shader* shader;

        /**
         * Viewer of renderer
         */
        Viewer* viewer;
       

		std::vector<Shader*> shaders;
		
		/**
		 * Lihts of renderer
		 */
		std::vector<Light*> lights;

};


#endif // RENDERER_HPP
