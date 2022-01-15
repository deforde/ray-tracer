#pragma once

#include <memory>

#include "ray.h"
#include "vec.h"

class Material;

class HitRecord {
public:
    HitRecord();
    void set_face_normal(const Ray& r, const Vec3& outward_normal);

    Point3 p;
    Vec3 normal;
    double t = 0.0;
    bool front_face = false;
    std::shared_ptr<Material> material;
};
