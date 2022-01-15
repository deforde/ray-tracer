#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <memory>
#include <vector>
#include <limits>
#include <random>

#include "camera.h"
#include "hit_record.h"
#include "hittable_list.h"
#include "hittable.h"
#include "lambertian.h"
#include "material.h"
#include "metal.h"
#include "ray.h"
#include "sphere.h"
#include "util.h"
#include "vec.h"

int main()
{
    // Image
    const auto aspect_ratio = 16.0 / 9.0;
    const size_t image_width = 400;
    const auto image_height = static_cast<size_t>(image_width / aspect_ratio);
    const char* image_output_file_path = "image.ppm";
    const size_t samples_per_pixel = 100;
    const int32_t max_depth = 50;

    std::ofstream file(image_output_file_path, std::ios::out);
    if(!file.is_open()) {
        std::cerr << "Failed to open: " << image_output_file_path << '\n';
        return EXIT_FAILURE;
    }
    file << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    // World
    HittableList world;
    const auto material_ground = std::make_shared<Lambertian>(Colour(0.8, 0.8, 0.0));
    const auto material_center = std::make_shared<Lambertian>(Colour(0.7, 0.3, 0.3));
    const auto material_left   = std::make_shared<Metal>(Colour(0.8, 0.8, 0.8), 0.3);
    const auto material_right  = std::make_shared<Metal>(Colour(0.8, 0.6, 0.2), 1.0);
    world.add(std::make_shared<Sphere>(Point3( 0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(std::make_shared<Sphere>(Point3( 0.0,    0.0, -1.0),   0.5, material_center));
    world.add(std::make_shared<Sphere>(Point3(-1.0,    0.0, -1.0),   0.5, material_left));
    world.add(std::make_shared<Sphere>(Point3( 1.0,    0.0, -1.0),   0.5, material_right));

    // Camera
    Camera cam;

    // Rendering
    std::cout << "Rendering...\n";
    for(int64_t i = image_height - 1; i >= 0; --i) {
        std::cout << std::setw(3) << static_cast<uint32_t>(100.0 * (1.0 - (static_cast<double>(i) / image_height))) << "%\r" << std::flush;
        for(size_t j = 0; j < image_width; ++j) {
            Colour pixel_colour;
            for(size_t n = 0; n < samples_per_pixel; ++n) {
                const auto u = (static_cast<double>(j) + random_double()) / (image_width - 1);
                const auto v = (static_cast<double>(i) + random_double()) / (image_height - 1);
                const auto r = cam.get_ray(u, v);
                pixel_colour = pixel_colour + ray_colour(r, world, max_depth);
            }
            write_colour(file, pixel_colour, samples_per_pixel);
        }
    }
    std::cout << "100%\n";

    file.close();

    return EXIT_SUCCESS;
}
