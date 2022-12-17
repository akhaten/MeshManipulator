/**
 * @author akhaten
 * @file CurveMesh.hpp
 */

#ifndef CURVE_MESH_HPP
#define CURVE_MESH_HPP

#include "Mesh.hpp"

class CurveMesh:
    public Mesh
{
public:
    CurveMesh(std::vector<glm::vec3> vertices);
    ~CurveMesh();
    void draw() override;
};


#endif // CURVE_MESH_HPP