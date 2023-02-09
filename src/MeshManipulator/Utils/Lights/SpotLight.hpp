//
// Created by akhaten on 1/19/23.
//

#ifndef SPOTLIGHT_HPP
#define SPOTLIGHT_HPP

#include "MeshManipulator/Utils/Lights/Light.hpp"

class SpotLight:
    public Light
{

	SpotLight(const char* fragment_shader_source, const char* vertex_shader_source);
	~SpotLight();

};

#endif //SPOTLIGHT_HPP
