#include "Renderer.hpp"


Renderer::Renderer(Viewer* viewer)
{

    this->viewer = viewer;

    const GLchar* vertex_shader_source =
            
			"#version 460 core\n"
			
			"layout (location = 0) in vec3 vertex_position_in;"
			"layout (location = 1) in vec3 vertex_color_in;"
			"layout (location = 2) in vec3 vertex_normal_in;"
			
			"uniform mat4 model;"
            "uniform mat4 view;"
            "uniform mat4 projection;"
			"uniform bool on_screen;"
			
			"out vec3 vertex_color;"
			"out vec3 vertex_normal;"
			"out vec3 fragment_position;"
			
			"void main()"
            "{"
			"	mat4 mvp = on_screen ? model : projection * view * model;"
			//"	gl_Position = mvp * vec4(vertex_position_in, 1.0f);"
			"	vertex_color = vertex_color_in;"
            "	fragment_position = vec3(model*vec4(vertex_position_in, 1.0f));"
			"	vertex_normal = mat3(transpose(inverse(model)))*vertex_normal_in;"

            "	gl_Position = projection*view*vec4(fragment_position, 1.0f);"
			
			"}";

    const GLchar* fragment_shader_source =
            
			"#version 460 core\n"
			
			"in vec3 vertex_color;"
			"in vec3 vertex_normal;"
			
			"in vec3 fragment_position;"

			"uniform vec3 camera_position;"

			"uniform vec3 light_position;"			
			"uniform vec3 light_color;"
            
			"out vec4 FragColor;"
            
			"void main()"
            "{"
			
			"	float ambient_strength = 0.1f;"
			"	vec3 ambient = ambient_strength*light_color;"

			"	vec3 norm = normalize(vertex_normal);"
			"	vec3 light_direction = normalize(light_position-fragment_position);"
			"	float alpha = max(dot(norm, light_direction), 0.0f);"
			"	vec3 diffuse = alpha*light_color;"

			"	float specular_strength = 1.0f;"
			"	vec3 view_direction = normalize(camera_position-fragment_position);"
			"	vec3 reflection_direction = reflect(-light_direction, norm);"
			"	float beta = pow(max(dot(view_direction, reflection_direction), 0.0f), 32);"
			"	vec3 specular = specular_strength*beta*light_color;"

			"	vec3 result = (ambient+diffuse+specular)*vertex_color;"
			"	FragColor = vec4(result, 1.0f);"
            
			"}";

    this->shader = new Shader(vertex_shader_source, fragment_shader_source);

}


Renderer::~Renderer() {}

void Renderer::render(Drawable* drawable)
{

	Light* light = this->lights[0];

	Camera* camera = this->viewer->getCamera();

    this->shader->use();
	this->shader->setBool("on_screen", drawable->isOnScreen());
    this->shader->setMat4("model", drawable->getModelMatrix());
    this->shader->setMat4("view", this->viewer->viewMatrix());
    this->shader->setMat4("projection", this->viewer->projectionMatrix());
	
	this->shader->setVec3("light_position", light->getPosition());
	this->shader->setVec3("light_color", light->getColor());
	
	this->shader->setVec3("camera_position", camera->getPosition());
    //this->shader->use();
	//drawable->update();
	//drawable->draw();
	drawable->getOpenGLObject()->draw();

}


Shader* Renderer::getShader()
{
    return this->shader;
}

Viewer* Renderer::getViewer()
{
    return this->viewer;
}

void Renderer::setShader(Shader* shader)
{
    this->shader = shader;
}

void Renderer::setViewer(Viewer* viewer)
{
    this->viewer = viewer;
}

void Renderer::addLight(Light* light)
{
	this->lights.push_back(light);
}
