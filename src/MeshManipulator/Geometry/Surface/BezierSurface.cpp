//
// Created by akhaten on 8/7/22.
//

#include "BezierSurface.hpp"

BezierSurface::BezierSurface(
        std::vector<std::vector<glm::vec3>> control_points,
        const unsigned int nb_segments)
{

    this->control_points = control_points;

    std::vector<BezierCurve*> tmp_bezier_curve;
    for(auto bezier_control_points : this->control_points)
        tmp_bezier_curve.push_back(new BezierCurve(bezier_control_points));


    for(unsigned int u = 0; u <= nb_segments; ++u)
    {
        std::vector<glm::vec3> bezier_control_points;
        for (BezierCurve *bezier_curve : tmp_bezier_curve)
        {
            bezier_control_points.push_back(bezier_curve->eval((float)u/nb_segments));
        }
        this->bezier_curves.push_back(new BezierCurve(bezier_control_points));
    }
}


glm::vec3 BezierSurface::eval(const unsigned int index_bezier, const float t)
{
    BezierCurve* bezier_curve = this->bezier_curves[index_bezier];
    return bezier_curve->eval(t);
}