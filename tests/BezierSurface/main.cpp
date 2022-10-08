#include <iostream>
#include <vector>


#include "Application.hpp"

#include "Scene.hpp"
#include <glm/glm.hpp>
#include "Drawable.hpp"
#include "Utils/Shader.hpp"
#include "Mesh/CurveMesh.hpp"
#include "Mesh/SurfaceMesh.hpp"
#include "Geometry/Curve/BezierCurve.hpp"
#include "Geometry/Surface/BezierSurface.hpp"


CurveMesh* makeBezierCurveMesh(std::vector<glm::vec3> control_points, const unsigned int nb_segments)
{

    BezierCurve* bezier_curve = new BezierCurve(control_points);
    std::vector<glm::vec3> curve_points;

    for(unsigned int i = 0; i <= nb_segments;  ++i)
    {
        curve_points.push_back(bezier_curve->eval((float)i/nb_segments));
    }

    CurveMesh* curve = new CurveMesh(curve_points);

    return curve;

}

Shader* makeShader()
{

    GLchar* vertex_shader_source =
            "#version 460 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "void main()\n"
            "{\n"
            "gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
            "}\n";

    GLchar* fragment_shader_source =
            "#version 460 core\n"
            "out vec4 FragColor;\n"
            "void main()\n"
            "{\n"
            "FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
            "}\n";

    Shader* shader = new Shader(vertex_shader_source, fragment_shader_source);
    return shader;

}

SurfaceMesh* makeBezierSurfaceMesh(std::vector<std::vector<glm::vec3>> control_points, const unsigned int nb_segments)
{

    BezierSurface* bezier_surface = new BezierSurface(control_points, nb_segments);


    std::vector<glm::vec3> surface_points;

    for(unsigned int index_bezier = 0; index_bezier <= nb_segments; ++index_bezier)
    {
        for(unsigned int i = 0; i <= nb_segments;  ++i)
        {
            surface_points.push_back(bezier_surface->eval(index_bezier, (float)i/nb_segments));
        }
    }

    std::vector<unsigned int> indices;
    unsigned int nb_point_bezier = nb_segments+1;
    for(unsigned int j = 0; j < nb_segments; ++j) {

        for (unsigned int i = 0; i < nb_segments; ++i) {

            unsigned int k = j*nb_point_bezier;

            indices.push_back(i+k);
            indices.push_back(i+1+k);
            indices.push_back(i+nb_point_bezier+k);

            //printf("%i, %i; %i\n", i+k, i+k+1, i+k+nb_point_bezier);

            indices.push_back(i+1+k);
            indices.push_back(i+nb_point_bezier+k);
            indices.push_back(i+1+nb_point_bezier+k);

            //printf("%i, %i; %i\n\n", i+1+k, i+nb_point_bezier+k, i+1+nb_point_bezier+k);

        }
    }

    SurfaceMesh* bezier_surface_mesh = new SurfaceMesh(surface_points, indices);
    return bezier_surface_mesh;

}


int main(int argc, char** argv)
{

    Application* app = new Application();

    Shader* shader = makeShader();

    std::vector<std::vector<glm::vec3>> control_points = {
        {
            glm::normalize(glm::vec3(-1.5f, -1.5f, 4.0f)),
            glm::normalize(glm::vec3(-0.5f, -1.5f ,2.0)),
            glm::normalize(glm::vec3(0.5f, -1.5f ,-1.0f)),
            glm::normalize(glm::vec3(1.5f, -1.5f, 2.0f))
        },
        {
            glm::normalize(glm::vec3(-1.5f, -0.5f, 1.0f)),
            glm::normalize(glm::vec3(-0.5f, -0.5f, 3.0f)),
            glm::normalize(glm::vec3(0.5f, -0.5f, 0.0f)),
            glm::normalize(glm::vec3(1.5f, -0.5f, -1.0f))
        },
        {
            glm::normalize(glm::vec3(-1.5f, 0.5f, 4.0f)),
            glm::normalize(glm::vec3(-0.5f, 0.5f, 0.0f)),
            glm::normalize(glm::vec3(0.5f, 0.5f, 3.0f)),
            glm::normalize(glm::vec3(1.5f, 0.5f, 4.0f))
        },
        {
            glm::normalize(glm::vec3(-1.5f, 1.5f, -2.0f)),
            glm::normalize(glm::vec3(-0.5f, 1.5f, -2.0f)),
            glm::normalize(glm::vec3(0.5f, 1.5f, 0.0f)),
            glm::normalize(glm::vec3(1.5f, 1.5f, -1.0f))
        }
    };

    app->scene->addDrawable(
new Drawable(
        makeBezierSurfaceMesh(control_points, 50),
            shader
        )
    );

    app->run();

}



