#pragma once

#include "material.h"

class Metal : public Material {
public:
    Metal(const Colour& a);

    bool scatter(const Ray& r_in, const HitRecord& rec, Colour& attenuation, Ray& scattered) const final;

    Colour albedo;
};
