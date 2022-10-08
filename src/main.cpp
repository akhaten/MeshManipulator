#include <iostream>
#include <vector>


#include <glm/glm.hpp>

#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/PolyMesh_ArrayKernelT.hh>

#include "Window/Application.hpp"

#include "Scene.hpp"
#include "Drawable.hpp"
#include "Utils/Shader.hpp"
#include "Mesh/CurveMesh.hpp"
#include "Mesh/SurfaceMesh.hpp"
#include "Geometry/Curve/BezierCurve.hpp"
#include "Geometry/Surface/BezierSurface.hpp"


// struct MyTrait:
//     OpenMesh::DefaultTraits
// {
//     using Point = glm::vec3;
// };

// using MyMesh = OpenMesh::PolyMesh_ArrayKernelT<MyTrait>;

// typedef OpenMesh::PolyMesh_ArrayKernelT<MyTrait> MyMesh;

typedef OpenMesh::PolyMesh_ArrayKernelT<> MyMesh;


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

    const GLchar* vertex_shader_source =
            "#version 460 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "void main()\n"
            "{\n"
            "gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
            "}\n";

    const GLchar* fragment_shader_source =
            "#version 460 core\n"
            "out vec4 FragColor;\n"
            "void main()\n"
            "{\n"
            "FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
            "}\n";

    Shader* shader = new Shader(vertex_shader_source, fragment_shader_source);
    return shader;

}

// SurfaceMesh* makeBezierSurfaceMesh(std::vector<std::vector<glm::vec3>> control_points, const unsigned int nb_segments)
// {

//     BezierSurface* bezier_surface = new BezierSurface(control_points, nb_segments);
    

//     std::vector<glm::vec3> surface_points;

//     for(unsigned int index_bezier = 0; index_bezier <= nb_segments; ++index_bezier)
//     {
//         for(unsigned int i = 0; i <= nb_segments;  ++i)
//         {
//             surface_points.push_back(bezier_surface->eval(index_bezier, (float)i/nb_segments));
//         }
//     }

//     std::vector<unsigned int> indices;
//     unsigned int nb_point_bezier = nb_segments+1;
//     for(unsigned int j = 0; j < nb_segments; ++j) {

//         for (unsigned int i = 0; i < nb_segments; ++i) {

//             unsigned int k = j*nb_point_bezier;

//             indices.push_back(i+k);
//             indices.push_back(i+1+k);
//             indices.push_back(i+nb_point_bezier+k);

//             //printf("%i, %i; %i\n", i+k, i+k+1, i+k+nb_point_bezier);
//             // if((k % (nb_segments-1) == 0) && (k != 0)){
//             //     indices.push_back(i+1+k);
//             //     indices.push_back(i+nb_point_bezier+k);
//             //     indices.push_back(i+1+nb_point_bezier+k);
//             // }

//             // if((i % (nb_segments-1) == 0) && (i != 0)){
//             //     indices.push_back(i+1+k);
//             //     indices.push_back(i+nb_point_bezier+k);
//             //     indices.push_back(i+1+nb_point_bezier+k);
//             // }

//             //printf("%i, %i; %i\n\n", i+1+k, i+nb_point_bezier+k, i+1+nb_point_bezier+k);

//         }
//     }


//     SurfaceMesh* bezier_surface_mesh = new SurfaceMesh(surface_points, indices);
//     return bezier_surface_mesh;

// }

SurfaceMesh* makeBezierSurfaceMesh(std::vector<std::vector<glm::vec3>> control_points, const unsigned int nb_segments)
{


    BezierSurface* bezier_surface = new BezierSurface(control_points, nb_segments);

    MyMesh mesh;
    
    std::vector<MyMesh::VertexHandle> surface_points;

    for(unsigned int index_bezier = 0; index_bezier <= nb_segments; ++index_bezier)
    {
        for(unsigned int i = 0; i <= nb_segments;  ++i)
        {
            glm::vec3 point = bezier_surface->eval(index_bezier, (float)i/nb_segments);
            surface_points.push_back(mesh.add_vertex(MyMesh::Point(point.x, point.y, point.z)));
        }
    }



    // std::vector<unsigned int> indices;
    unsigned int nb_point_bezier = nb_segments+1;


    std::vector<MyMesh::VertexHandle> triangle_face;

    for(unsigned int j = 0; j < nb_segments; ++j) {

        for (unsigned int i = 0; i < nb_segments; ++i) {

            unsigned int k = j*nb_point_bezier;

            triangle_face.clear();
            triangle_face.push_back(surface_points[i+k]);
            triangle_face.push_back(surface_points[i+1+k]);
            triangle_face.push_back(surface_points[i+nb_point_bezier+k]);
            mesh.add_face(triangle_face);

            triangle_face.clear();
            triangle_face.push_back(surface_points[i+k+1]);
            triangle_face.push_back(surface_points[i+1+k+nb_point_bezier]);
            triangle_face.push_back(surface_points[i+nb_point_bezier+k]);
            mesh.add_face(triangle_face);

        }

    }


    std::vector<glm::vec3> points;
    for(auto point : mesh.vertices()){
        auto p = mesh.point(point);
        points.push_back(glm::vec3(p[0], p[1], p[2]));
    }

    std::vector<unsigned int> indices;
    for(auto face : mesh.faces()){
        for(auto pt : face.vertices())
            indices.push_back(pt.idx());
    }

    // std::cout << "Points : " << points.size() << std::endl;
    // std::cout << "Faces : " << indices.size() / 3 << std::endl;

    SurfaceMesh* bezier_surface_mesh = new SurfaceMesh(points, indices);
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
            makeBezierSurfaceMesh(control_points, 10),
            shader
        )
    );

    app->run();

}



