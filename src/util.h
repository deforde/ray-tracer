#pragma once

#include <fstream>
#include <cstdint>

#include "vec.h"
#include "hittable_list.h"

double clamp(double x, double min, double max);

void write_colour(std::ofstream& image_file, const Colour& pixel_colour, size_t samples_per_pixel);

double random_double(double min, double max);

double random_double();

Vec3 random_vec(double min, double max);

Vec3 random_vec_in_unit_sphere();

Vec3 random_unit_vec();

Vec3 random_vec_in_hemisphere(const Vec3& normal);

Colour ray_colour(const Ray& r, const HittableList& world, int32_t depth);

bool is_vec_near_zero(const Vec3& v);

Vec3 vec_reflect(const Vec3& v, const Vec3& n);
