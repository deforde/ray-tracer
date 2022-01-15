#include "camera.h"

#include <cmath>

#include "util.h"

Camera::Camera(Point3 lookfrom, Point3 lookat, Vec3 vup, double vfov, double aspect_ratio, double aperture, double focus_dist)
{
    const auto theta = degrees_to_radians(vfov);
    const auto h = std::tan(theta/2);
    const auto viewport_height = 2.0 * h;
    const auto viewport_width = aspect_ratio * viewport_height;

    w = unit_vec(lookfrom - lookat);
    u = unit_vec(cross(vup, w));
    v = cross(w, u);

    origin = lookfrom;
    horizontal = u * viewport_width * focus_dist;
    vertical = v * viewport_height * focus_dist;
    lower_left_corner = origin - horizontal / 2 - vertical / 2 - w * focus_dist;

    lens_radius = aperture / 2;
}

Ray Camera::get_ray(double s, double t) const
{
    Vec3 rd = random_vec_in_unit_disk() * lens_radius;
    Vec3 offset = u * rd.x + v * rd.y;
    return {origin + offset, lower_left_corner + horizontal * s + vertical * t - origin - offset};
}
