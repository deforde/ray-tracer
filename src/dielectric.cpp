#include "dielectric.h"

#include <cmath>

#include "util.h"

Dielectric::Dielectric(double index_of_refraction) :
    ir(index_of_refraction)
{
}

bool Dielectric::scatter(const Ray& r_in, const HitRecord& rec, Colour& attenuation, Ray& scattered) const
{
    attenuation = Colour(1.0, 1.0, 1.0);
    const double refraction_ratio = rec.front_face ? (1.0/ir) : ir;

    const Vec3 unit_direction = unit_vec(r_in.dir);
    const double cos_theta = std::min(dot(unit_direction * -1, rec.normal), 1.0);
    const double sin_theta = std::sqrt(1.0 - cos_theta*cos_theta);

    const bool cannot_refract = refraction_ratio * sin_theta > 1.0;
    Vec3 direction;

    if (cannot_refract || reflectance(cos_theta, refraction_ratio) > random_double())
        direction = vec_reflect(unit_direction, rec.normal);
    else
        direction = vec_refract(unit_direction, rec.normal, refraction_ratio);

    scattered = Ray(rec.p, direction);

    return true;
}
