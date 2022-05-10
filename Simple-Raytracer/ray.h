//
// Created by Gavin T McRoy on 5/10/2022.
//

#ifndef SIMPLE_RAYTRACER_RAY_H
#define SIMPLE_RAYTRACER_RAY_H

#include "vec3.h"

class ray {
public:
    point3 orig;
    point3 dir;
    int test = 5;

    ray() {}

    ray(const point3 &origin, const vec3 &direction) : orig(origin), dir(direction) {

    }

    point3 origin() const { return orig; }

    int test1() const { return test - 5; }

};


#endif //SIMPLE_RAYTRACER_RAY_H
