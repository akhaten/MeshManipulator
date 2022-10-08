#include <iostream>
#include <vector>


#include <glm/glm.hpp>



#include <MeshManipulator/Window/Application.hpp>

#include <MeshManipulator/Utils/Scene.hpp>
#include <MeshManipulator/Utils/Drawable.hpp>
#include <MeshManipulator/Utils/Shader.hpp>

#include <MeshManipulator/Mesh/Mesh.hpp>
#include <MeshManipulator/Mesh/CurveMesh.hpp>
#include <MeshManipulator/Mesh/ObjectMesh.hpp>
#include <MeshManipulator/Geometry/Curve/BezierCurve.hpp>
#include <MeshManipulator/Geometry/Surface/BezierSurface.hpp>

#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/PolyMesh_ArrayKernelT.hh>


// struct MyTrait:
//     OpenMesh::DefaultTraits
// {
//     using Point = glm::vec3;
// };

// using MyOpenMesh = OpenMesh::PolyMesh_ArrayKernelT<MyTrait>;

// typedef OpenMesh::PolyMesh_ArrayKernelT<MyTrait> MyOpenMesh;

// typedef OpenMesh::PolyMesh_ArrayKernelT<> MyOpenMesh;


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

ObjectMesh* makeBezierObjectMesh(std::vector<std::vector<glm::vec3>> control_points, const unsigned int nb_segments)
{


    BezierSurface* bezier_surface = new BezierSurface(control_points, nb_segments);

    MyOpenMesh mesh;
    
    std::vector<MyOpenMesh::VertexHandle> surface_points;

    for(unsigned int index_bezier = 0; index_bezier <= nb_segments; ++index_bezier)
    {
        for(unsigned int i = 0; i <= nb_segments;  ++i)
        {
            glm::vec3 point = bezier_surface->eval(index_bezier, (float)i/nb_segments);
            surface_points.push_back(mesh.add_vertex(MyOpenMesh::Point(point.x, point.y, point.z)));
        }
    }



    // std::vector<unsigned int> indices;
    unsigned int nb_point_bezier = nb_segments+1;


    std::vector<MyOpenMesh::VertexHandle> triangle_face;

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


    // std::vector<glm::vec3> points;
    // for(auto point : mesh.vertices()){
    //     auto p = mesh.point(point);
    //     points.push_back(glm::vec3(p[0], p[1], p[2]));
    // }

    // std::vector<unsigned int> indices;
    // for(auto face : mesh.faces()){
    //     for(auto pt : face.vertices())
    //         indices.push_back(pt.idx());
    // }


    // ObjectMesh* bezier_surface_mesh = new ObjectMesh(points, indices);
    ObjectMesh* bezier_surface_mesh = new ObjectMesh(&mesh);
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
            makeBezierObjectMesh(control_points, 10),
            shader
        )
    );

    app->run();

}



