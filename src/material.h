#pragma once

#include "hit_record.h"
#include "ray.h"
#include "vec.h"

class Material {
public:
    virtual ~Material() = default;
    virtual bool scatter(const Ray& r_in, const HitRecord& rec, Colour& attenuation, Ray& scattered) const = 0;
};
