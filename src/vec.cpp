#include "vec.h"

#include <cmath>

Vec3::Vec3()
{}

Vec3::Vec3(double a, double b, double c) :
    x(a),
    y(b),
    z(c)
{}

double Vec3::length() const
{
    return std::sqrt(length_squared());
}

double Vec3::length_squared() const
{
    return x*x + y*y + z*z;
}

Vec3 operator*(const Vec3& v, const double& r)
{
    return {v.x * r, v.y * r, v.z * r};
}

Vec3 operator/(const Vec3& v, const double& r)
{
    return v * (1 / r);
}

Vec3 operator*(const Vec3& a, const Vec3& b)
{
    return {a.x * b.x, a.y * b.y, a.z * b.z};
}

Vec3 operator+(const Vec3& a, const Vec3& b)
{
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

Vec3 operator-(const Vec3& a, const Vec3& b)
{
    return a + b * -1.0;
}

Vec3 unit_vector(const Vec3& v)
{
    return v / v.length();
}

double dot(const Vec3& a, const Vec3& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
