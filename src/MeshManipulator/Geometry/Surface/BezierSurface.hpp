/**
 * @author akhaten
 * @file BezierSurface.hpp
 */

#ifndef BEZIER_SURFACE_HPP
#define BEZIER_SURFACE_HPP

#include <vector>
#include <glm/glm.hpp>

#include "MeshManipulator/Geometry/Curve/BezierCurve.hpp"

class BezierSurface
{
public:
    //BezierSurface(std::vector<std::vector<glm::vec3>> control_points);
    BezierSurface(std::vector<std::vector<glm::vec3>> control_points, const unsigned int nb_segments);
    //glm::vec3 tensoriel_product(const unsigned int nb_segment);
    glm::vec3 eval(const unsigned int index_bezier, const float t);

private:
    std::vector<std::vector<glm::vec3>> control_points;
    std::vector<BezierCurve*> bezier_curves;

};

#endif // BEZIER_SURFACE_HPP
