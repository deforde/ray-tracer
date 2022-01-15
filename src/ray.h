#pragma once

#include "vec.h"

class Ray
{
public:
    Ray();
    Ray(const Vec3& orig, const Vec3& d);

    Point3 at(double t) const;

    Point3 origin;
    Vec3 dir;
};
