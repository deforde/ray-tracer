#pragma once

#include "material.h"

class Dielectric : public Material {
public:
    Dielectric(double index_of_refraction);

    bool scatter(const Ray& r_in, const HitRecord& rec, Colour& attenuation, Ray& scattered) const final;

    double ir; // Index of Refraction
};
