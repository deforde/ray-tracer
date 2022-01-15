#include "metal.h"

#include <algorithm>

#include "util.h"

Metal::Metal(const Colour& a, double f) :
    albedo(a),
    fuzz(std::min(f, 1.0))
{
}

bool Metal::scatter(const Ray& r_in, const HitRecord& rec, Colour& attenuation, Ray& scattered) const
{
    Vec3 reflected = vec_reflect(unit_vec(r_in.dir), rec.normal);
    scattered = Ray(rec.p, reflected + random_vec_in_unit_sphere() * fuzz);
    attenuation = albedo;
    return dot(scattered.dir, rec.normal) > 0;
}
