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

hittable_list random_scene() {
    hittable_list world;
    auto ground_material = make_shared<lambertian>(color(.5, .5, .5));
    world.add(make_shared<sphere>(point3(0.0, -1000.0, 0), 1000.0, ground_material));

    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            auto choose_mat = random_double();
            point3 center(a + .9 * random_double(), 0.2, b + .9 * random_double());

            if ((center - point3(4.0, 0.2, 0.0)).length() > .9) {
                shared_ptr<material> sphere_material;

                if (choose_mat < .8) {
                    //diffuse
                    auto albedo = color::random() * color::random();
                    sphere_material = make_shared<lambertian>(albedo);
                    world.add(make_shared<sphere>(center, .2, sphere_material));
                } else if (choose_mat < 0.95) {
                    //metal
                    auto albedo = color::random(.5, 1.0);
                    auto fuzz = random_double(0.0, .5);
                    sphere_material = make_shared<metal>(albedo, fuzz);
                    world.add(make_shared<sphere>(center, .2, sphere_material));
                } else {
                    //glass
                    sphere_material = make_shared<dielectric>(1.5);
                    world.add(std::make_shared<sphere>(center, .2, sphere_material));
                }
            }
        }
    }

    auto material1 = make_shared<dielectric>(1.5);
    world.add(make_shared<sphere>(point3(0.0, 1.0, 0.0), 1.0, material1));

    auto material2 = make_shared<lambertian>(color(0.4, 0.2, 0.1));
    world.add(make_shared<sphere>(point3(-4.0, 1.0, 0.0), 1.0, material2));

    auto material3 = make_shared<metal>(color(0.7, 0.6, 0.5), 0.0);
    world.add(make_shared<sphere>(point3(4.0, 1.0, 0.0), 1.0, material3));

    return world;

}

int main() {

    /* Output Image */
    const auto ASPECT_RATIO = 3.0 / 2.0;
    const int IMAGE_WIDTH = 400;
    const int IMAGE_HEIGHT = static_cast<int>(IMAGE_WIDTH / ASPECT_RATIO);
    const int SAMPLES_PER_PIXEL = 50;
    const int MAX_DEPTH = 50;

    /* World */
    //auto world = random_scene();
    hittable_list world;

    auto material_ground = make_shared<lambertian>(color(0.8, 0.8, 0.0));
    auto material_center = make_shared<lambertian>(color(0.1, 0.2, 0.5));
    auto material_left   = make_shared<dielectric>(1.5);
    auto material_right  = make_shared<metal>(color(0.8, 0.6, 0.2), 0.0);

    world.add(make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(make_shared<sphere>(point3( 0.0,    0.0, -1.0),   0.5, material_center));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.5, material_left));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0), -0.45, material_left));
    world.add(make_shared<sphere>(point3( 1.0,    0.0, -1.0),   0.5, material_right));

    /* Camera */
    point3 lookFrom(13.0, 2.0, 3.0);
    point3 lookaAt(0.0, 0.0, 0.0);
    vec3 vUp(0.0, 1.0, 0.0);
    auto dist_to_focus = 10.0;
    auto aperture = .1;
    camera cam(lookFrom, lookaAt, vUp, 20.0, ASPECT_RATIO, aperture, dist_to_focus);


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
