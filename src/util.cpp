#include "util.h"

#include <algorithm>
#include <cmath>
#include <random>

#include "material.h"

double clamp(double x, double min, double max)
{
    x = std::max(x, min);
    x = std::min(x, max);
    return x;
}

void write_colour(std::ofstream& image_file, const Colour& pixel_colour, size_t samples_per_pixel)
{
    auto r = pixel_colour.x;
    auto g = pixel_colour.y;
    auto b = pixel_colour.z;

    // Divide the color by the number of samples and gamma-correct for gamma=2.0.
    const auto scale = 1.0 / samples_per_pixel;
    r = std::sqrt(scale * r);
    g = std::sqrt(scale * g);
    b = std::sqrt(scale * b);

    // Write the translated [0,255] value of each color component.
    image_file << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
}

double random_double(double min, double max)
{
    static std::uniform_real_distribution<double> distribution(min, max);
    static std::mt19937 generator;
    return distribution(generator);
}

double random_double()
{
    return random_double(0.0, 1.0);
}

Vec3 random_vec(double min, double max)
{
    return {random_double(min, max), random_double(min, max), random_double(min, max)};
}

Vec3 random_vec_in_unit_sphere()
{
    for(;;) {
        const auto p = random_vec(-1,1);
        if(p.length_squared() >= 1)
            continue;
        return p;
    }
}

Vec3 random_unit_vec()
{
    return unit_vec(random_vec_in_unit_sphere());
}

Vec3 random_vec_in_hemisphere(const Vec3& normal)
{
    Vec3 in_unit_sphere = random_vec_in_unit_sphere();
    if (dot(in_unit_sphere, normal) > 0.0) // In the same hemisphere as the normal
        return in_unit_sphere;
    else
        return in_unit_sphere * -1;
}

Colour ray_colour(const Ray& r, const HittableList& world, int32_t depth)
{
    if(depth <= 0)
        return {};

    HitRecord rec;
    if(world.hit(r, 0.001, std::numeric_limits<double>::max(), rec)) {
        Ray scattered;
        Colour attenuation;
        if(rec.material->scatter(r, rec, attenuation, scattered))
            return attenuation * ray_colour(scattered, world, depth-1);
        return {0,0,0};
    }

    const auto unit_direction = unit_vec(r.dir);
    auto t = 0.5 * (unit_direction.y + 1.0);
    return Colour(1.0, 1.0, 1.0) * (1.0 - t) + Colour(0.5, 0.7, 1.0) * t;
}

bool is_vec_near_zero(const Vec3& v)
{
    const auto s = 1e-8;
    return (std::fabs(v.x) < s) && (std::fabs(v.x) < s) && (std::fabs(v.x) < s);
}

Vec3 vec_reflect(const Vec3& v, const Vec3& n)
{
    return v - n * 2 * dot(v,n);
}
