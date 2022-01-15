#pragma once

#include "vec.h"
#include "ray.h"

class Camera {
public:
    Camera(Point3 lookfrom, Point3 lookat, Vec3 vup, double vfov, double aspect_ratio, double aperture, double focus_dist);

    Ray get_ray(double s, double t) const;

    Point3 origin;
    Point3 lower_left_corner;
    Vec3 horizontal;
    Vec3 vertical;
    Vec3 u;
    Vec3 v;
    Vec3 w;
    double lens_radius;
};
