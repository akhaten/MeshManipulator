//
// Created by akhaten on 1/19/23.
//

// #include "MeshManipulator/Utils/Lights/SpotLight.hpp"
#include "MeshManipulator/Utils/Lights/SpotLight.hpp"

SpotLight::SpotLight(const glm::vec3 position, const glm::vec3 color):
	Light(position, color)
{}



//SpotLight::SpotLight(
//{
//	#version 330 core
//	layout (location = 0) in vec3 aPos;   // the position variable has attribute position 0
//	layout (location = 1) in vec3 aColor; // the color variable has attribute position 1
//	  
//	out vec3 ourColor; // output a color to the fragment shader
//	
//	void main()
//	{
//	    gl_Position = vec4(aPos, 1.0);
//	    ourColor = aColor; // set ourColor to the input color we got from the vertex data
//	}  
//}
