//
// Created by Gavin T McRoy on 5/10/2022.
//

#ifndef SIMPLE_RAYTRACER_COLOR_H
#define SIMPLE_RAYTRACER_COLOR_H

#include <iostream>
#include "vec3.h"

void write_color(std::fstream &file, color pixel_color) {
    file << static_cast<int>(255.999 * pixel_color.x()) << " "
            << static_cast<int>(255.999 * pixel_color.y()) << " "
            << static_cast<int>(255.999 * pixel_color.z()) << "\n";
}


#endif //SIMPLE_RAYTRACER_COLOR_H
