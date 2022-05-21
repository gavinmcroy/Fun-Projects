//
// Created by Gavin T McRoy on 5/17/2022.
//

#ifndef SIMPLE_RAYTRACER_RAY_H
#define SIMPLE_RAYTRACER_RAY_H

#include "vec3.h"

class ray {
public:
    point3 orig;
    vec3 dir;

    ray() {

    }

    ray(const point3 &origin, const vec3 &direction) : orig(origin), dir(direction) {

    }

    point3 origin() const {
        return orig;
    }

    vec3 direction() const {
        return dir;
    }

    point3 at(double t) const {
        return orig+(t * dir);
    }

};


#endif //SIMPLE_RAYTRACER_RAY_H
