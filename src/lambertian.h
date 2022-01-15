#pragma once

#include "material.h"
#include "vec.h"

class Lambertian : public Material {
public:
    Lambertian(const Colour& a);

    bool scatter(const Ray& r_in, const HitRecord& rec, Colour& attenuation, Ray& scattered) const final;

    Colour albedo;
};
