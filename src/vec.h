#pragma once

class Vec3
{
public:
    Vec3();
    Vec3(double a, double b, double c);

    double length() const;
    double length_squared() const;

    double x = 0;
    double y = 0;
    double z = 0;
};

Vec3 operator*(const Vec3& v, const double& r);
Vec3 operator/(const Vec3& v, const double& r);
Vec3 operator*(const Vec3& a, const Vec3& b);
Vec3 operator+(const Vec3& a, const Vec3& b);
Vec3 operator-(const Vec3& a, const Vec3& b);

Vec3 unit_vector(const Vec3& v);

double dot(const Vec3& a, const Vec3& b);

using Point3 = Vec3;
using Colour = Vec3;
