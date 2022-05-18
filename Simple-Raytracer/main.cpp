#include <iostream>
#include <fstream>

#include "rtweekend.h"
#include "color.h"
#include "hittable_list.h"
#include "sphere.h"
#include "camera.h"
#include "vec3.h"
#include "material.h"

color ray_color(const ray &r, const hittable &world, int depth) {

    hit_record rec;

    if (depth <= 0) {
        return {0.0, 0.0, 0.0};
    }


    if (world.hit(r, 0.001, infinity, rec)) {
        ray scattered;
        color attenuation;
        if (rec.material_ptr->scatter(r, rec, attenuation, scattered)) {
            return attenuation * ray_color(scattered, world, depth - 1);
        }
        return {0.0, 0.0, 0.0};
    }
    vec3 unit_direction = unit_vector(r.direction());
    auto t = .5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(.5, .7, 1.0);
}

int main() {

    /* Output Image */
    const auto ASPECT_RATIO = 16.0 / 9.0;
    const int IMAGE_WIDTH = 400;
    const int IMAGE_HEIGHT = static_cast<int>(static_cast<double>(IMAGE_WIDTH) / ASPECT_RATIO);
    const int SAMPLES_PER_PIXEL = 100;
    const int MAX_DEPTH = 50;

    /* World */
    hittable_list world;

    auto material_ground = make_shared<lambertian>(color(.8, .8, 0.0));
    //auto material_center = make_shared<lambertian>(color(.7, .3, 0.3));
    auto material_center = make_shared<dielectric>(1.5);
    //auto material_left = make_shared<metal>(color(.8, .8, .8),.3);
    auto material_left = make_shared<dielectric>(1.5);
    auto material_right = make_shared<metal>(color(.8, .6, .2),1.0);

    world.add(make_shared<sphere>(point3(0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(make_shared<sphere>(point3(0.0, -0.0, -1.0), .5, material_center));
    world.add(make_shared<sphere>(point3(-1.0, -0.0, -1.0), .5, material_left));
    world.add(make_shared<sphere>(point3(1.0, 0.0, -1.0), .5, material_right));

    /* Camera */
    camera cam;


    /* Rendering Process */
    std::fstream file;
    file.open("file.ppm", std::ios::out);
    if (file.fail()) {
        std::cerr << "error" << std::endl;
    }

    file << "P3\n" << IMAGE_WIDTH << " " << IMAGE_HEIGHT << "\n" << "255\n";

    for (int j = IMAGE_HEIGHT - 1; j >= 0; j--) {
        std::cout << "\rScan lines Remaining:" << j << " " << std::flush;
        for (int i = 0; i < IMAGE_WIDTH; i++) {
            color pixel_color(0.0, 0.0, 0.0);
            for (int s = 0; s < SAMPLES_PER_PIXEL; s++) {
                auto u = (static_cast<double>(i) + random_double()) / static_cast<double>((IMAGE_WIDTH - 1));
                auto v = (static_cast<double>(j) + random_double()) / static_cast<double>((IMAGE_HEIGHT - 1));
                ray r = cam.get_ray(u, v);
                pixel_color += ray_color(r, world, MAX_DEPTH);
            }
            write_color(file, pixel_color, SAMPLES_PER_PIXEL);
        }
    }

    file.close();

    return 0;
}
