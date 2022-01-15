#pragma once

#include "hittable.h"

class Sphere : public Hittable {
public:
    Sphere(const Point3& cen, double r);

    bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const final;

    Point3 center;
    double radius;
};
