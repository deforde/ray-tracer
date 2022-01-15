#pragma once

#include "vec.h"
#include "ray.h"

class Camera {
public:
    Camera();

    Ray get_ray(double u, double v) const;

    Point3 origin;
    Point3 lower_left_corner;
    Vec3 horizontal;
    Vec3 vertical;
};
