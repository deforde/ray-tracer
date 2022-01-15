#pragma once

#include "ray.h"
#include "hit_record.h"

class Hittable {
public:
    virtual ~Hittable() = default;
    virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const = 0;
};
