/**
 * @author akhaten
 * @file CurveMesh.hpp
 */

#ifndef CURVE_MESH_HPP
#define CURVE_MESH_HPP

#include "OpenGLObject.hpp"

class CurveMesh:
    protected OpenGLObject
{
public:
    CurveMesh(std::vector<glm::vec3> vertices);
    ~CurveMesh();
    void draw() override;
};


#endif // CURVE_MESH_HPP