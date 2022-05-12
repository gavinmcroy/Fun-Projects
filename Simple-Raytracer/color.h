//
// Created by Gavin T McRoy on 5/10/2022.
//

#ifndef SIMPLE_RAYTRACER_COLOR_H
#define SIMPLE_RAYTRACER_COLOR_H

#include <iostream>
#include "vec3.h"

void write_color(std::fstream &file, color pixel_color, int samples_per_pixel) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    /* Divide the color by the number of samples*/
    auto scale = 1.0 / samples_per_pixel;
    r = sqrt(scale * r);
    g = sqrt(scale * g);
    b = sqrt(scale * b);

    file << static_cast<int>(256 * clamp(r, 0.0, .999)) << " "
         << static_cast<int>(256 * clamp(g, 0.0, .999)) << " "
         << static_cast<int>(256 * clamp(b, 0, .999)) << "\n";
}


#endif //SIMPLE_RAYTRACER_COLOR_H
