#include <iostream>
#include <fstream>

#include "vec3.h"
#include "color.h"
#include "ray.h"


double hit_sphere(const point3 &center, double radius, const ray &r) {
    vec3 oc = r.origin() - center;
    auto a = dot(r.direction(), r.direction());
    auto b = 2.0 * dot(oc, r.direction());
    auto c = dot(oc, oc) - radius * radius;
    auto discriminant = b * b - 4 * a * c;
    /* return if there is a solution */
    if (discriminant < 0) {
        return -1.0;
    } else {
        return (-b - sqrt(discriminant)) / (2.0 * a);
    }
}

color ray_color(const ray &r) {
    auto t = hit_sphere(point3(0, 0, -1), .5, r);
    /* If there is a solution */
    if (t > 0.0) {
        vec3 N = unit_vector(r.at(t) - vec3(0, 0, -1));
        return .5 * color(N.x() + 1, N.y() + 1, N.z() + 1);
    }

    vec3 unit_direction = unit_vector(r.direction());
    t = .5 * (unit_direction.y()) + 1.0;
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(.5, .7, 1.0);
}

int main() {

    /* Output Image */
    const auto ASPECT_RATIO = 16.0 / 9.0;
    const int IMAGE_WIDTH = 400;
    const int IMAGE_HEIGHT = static_cast<int>(IMAGE_WIDTH / ASPECT_RATIO);

    /* Camera */
    double viewport_height = 2.0;
    double viewport_width = ASPECT_RATIO * viewport_height;
    double focal_length = 1.0;

    auto origin = point3(0, 0, 0);
    auto horizontal = vec3(viewport_width, 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length);


    /* Rendering Process */
    std::fstream file;
    file.open("file.ppm", std::ios::out);
    if (!file) {
        std::cerr << "error" << std::endl;
    }

    file << "P3\n" << IMAGE_WIDTH << " " << IMAGE_HEIGHT << "\n" << "255\n";

    for (int j = IMAGE_HEIGHT - 1; j >= 0; j--) {
        std::cout << "\rScan lines Remaining:" << j << " " << std::flush;
        for (int i = 0; i < IMAGE_WIDTH; i++) {
            double u = double(i) / (IMAGE_WIDTH - 1);
            double v = double(j) / (IMAGE_HEIGHT - 1);
            ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
            color pixel_color = ray_color(r);
            write_color(file, pixel_color);
        }
    }

    file.close();

    return 0;
}
