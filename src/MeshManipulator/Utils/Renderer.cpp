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