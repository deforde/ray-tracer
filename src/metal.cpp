#include "metal.h"
#include "util.h"

Metal::Metal(const Colour& a) :
    albedo(a)
{}

bool Metal::scatter(const Ray& r_in, const HitRecord& rec, Colour& attenuation, Ray& scattered) const
{
    Vec3 reflected = reflect(unit_vector(r_in.dir), rec.normal);
    scattered = Ray(rec.p, reflected);
    attenuation = albedo;
    return (dot(scattered.dir, rec.normal) > 0);
}
