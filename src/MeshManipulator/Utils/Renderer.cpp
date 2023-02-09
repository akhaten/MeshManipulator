#include "Renderer.hpp"


Renderer::Renderer(Viewer* viewer)
{

    this->viewer = viewer;

    const GLchar* vertex_shader_source =
            "#version 460 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "uniform mat4 model;\n"
            "uniform mat4 view;\n"
            "uniform mat4 projection;\n"
            "void main()\n"
            "{\n"
            "gl_Position = projection * view * model * vec4(aPos, 1.0f);\n"
            "}\n";

    const GLchar* fragment_shader_source =
            "#version 460 core\n"
            "out vec4 FragColor;\n"
            "void main()\n"
            "{\n"
            "FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
            "}\n";

    this->shader = new Shader(vertex_shader_source, fragment_shader_source);

}


Renderer::~Renderer() {}

void Renderer::render(Drawable* drawable)
{

//	for(Light* light : this->lights){
//		Shader* light_shader = light->getShader();
//		light_shader->use();
//		// For get color, we take with "location = ???" because
//		// color will be take in datas on gpu.
//		// datas ~ [vertex_1.pos, vertex_2.color, ... , vertex_n.pos, vertex_n.color]
//		// light_shader->setVec3("object_color", drawable->getColor());
//		light_shader->setVec3("light_color", light->getColor());
//		light_shader->setMat4("model", light->getModel());
//	}

    this->shader->setMat4("model", drawable->modelMatrix());
    this->shader->setMat4("view", this->viewer->viewMatrix());
    this->shader->setMat4("projection", this->viewer->projectionMatrix());
    this->shader->use();
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
