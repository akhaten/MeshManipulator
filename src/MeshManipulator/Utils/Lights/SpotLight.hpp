//
// Created by akhaten on 1/19/23.
//

#ifndef SPOTLIGHT_HPP
#define SPOTLIGHT_HPP

#include <glm/glm.hpp>

#include "MeshManipulator/Utils/Lights/Light.hpp"

class SpotLight:
    public Light
{
	
	public:

		/**
		 * Constructor of SpotLight
		 * @param position : position of SpotLight
		 * @param color : color of SpotLight
		 */
		SpotLight(const glm::vec3 position, const glm::vec3 color);

		/**
		 * Destuctor of SpotLight
		 */
		~SpotLight();

};

#endif //SPOTLIGHT_HPP
