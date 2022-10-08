//
// Created by akhaten on 8/7/22.
//

#include "BezierCurve.hpp"

BezierCurve::BezierCurve(std::vector<glm::vec3> control_points)
{
    this->control_points = control_points;
    this->bernstein_polynom = new BernsteinPolynom(this->control_points.size());
}

BezierCurve::~BezierCurve() {}

glm::vec3 BezierCurve::eval(const float t)
{
    const unsigned int n = this->control_points.size();
    glm::vec3 point(0.f, 0.f, 0.f);

    for(unsigned int k = 0; k < n; ++k)
    {

        float bern_value = this->bernstein_polynom->eval(k, t);
        glm::vec3 control_pt = this->control_points[k];
        //point += bern_value*control_pt;
        point.x += bern_value * control_pt.x;
        point.y += bern_value * control_pt.y;
        point.z += bern_value * control_pt.z;

    }

    return point;
}
