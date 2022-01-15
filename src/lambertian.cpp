
#include "lambertian.h"
#include "util.h"

Lambertian::Lambertian(const Colour& a) :
    albedo(a)
{
}

bool Lambertian::scatter(const Ray& r_in, const HitRecord& rec, Colour& attenuation, Ray& scattered) const
{
    auto scatter_direction = rec.normal + random_unit_vec();

    if(is_vec_near_zero(scatter_direction))
        scatter_direction = rec.normal;

    scattered = Ray(rec.p, scatter_direction);
    attenuation = albedo;
    return true;
}
