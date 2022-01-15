#include "ray.h"

Ray::Ray()
{}

Ray::Ray(const Vec3& orig, const Vec3& d) :
    origin(orig),
    dir(d)
{
}

Point3 Ray::at(double t) const
{
    return origin + dir * t;
}
