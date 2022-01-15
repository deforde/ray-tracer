#pragma once

#include <memory>

#include "hittable.h"

class Sphere : public Hittable {
public:
    Sphere(const Point3& cen, double r, const std::shared_ptr<Material>& mat);

    bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const final;

    Point3 center;
    double radius;
    std::shared_ptr<Material> material;
};
