/**
 * @author akhaten
 * @file BezierCurve.hpp
 */

#ifndef BEZIER_CURVE_HPP
#define BEZIER_CURVE_HPP

#include <vector>
#include <glm/glm.hpp>

#include "BernsteinPolynom.hpp"

class BezierCurve
{

public:
    BezierCurve(std::vector<glm::vec3> control_points);
    ~BezierCurve();
    glm::vec3 eval(const float t);

private:
    std::vector<glm::vec3> control_points;
    BernsteinPolynom* bernstein_polynom;

};

#endif // BEZIER_CURVE_HPP
