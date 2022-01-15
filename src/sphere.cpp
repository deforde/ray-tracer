#include "sphere.h"

#include <cmath>

Sphere::Sphere(const Point3& cen, double r, const std::shared_ptr<Material>& mat):
    center(cen),
    radius(r),
    material(mat)
{}

bool Sphere::hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const
{
    const Vec3 oc = r.origin - center;
    const auto a = r.dir.length_squared();
    const auto half_b = dot(oc, r.dir);
    const auto c = oc.length_squared() - radius*radius;

    const auto discriminant = half_b*half_b - a*c;
    if(discriminant < 0)
        return false;
    const auto sqrtd = std::sqrt(discriminant);

    // Find the nearest root that lies in the acceptable range.
    auto root = (-half_b - sqrtd) / a;
    if(root < t_min || t_max < root) {
        root = (-half_b + sqrtd) / a;
        if(root < t_min || t_max < root)
            return false;
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    Vec3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);
    rec.material = material;

    return true;
}