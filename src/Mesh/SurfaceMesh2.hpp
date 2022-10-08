//
// Created by akhaten on 9/1/22.
//

#ifndef SURFACE_MESH_HPP
#define SURFACE_MESH_HPP

#include <vector>
#include <glm/glm.hpp>

#include "Mesh.hpp"

class SurfaceMesh2:
    public Mesh
{
public:
    SurfaceMesh(std::vector<glm::vec3> vertices, std::vector<unsigned int> indices);
    ~SurfaceMesh();
    void draw() override;

};


#endif // SURFACE_MESH_HPP
