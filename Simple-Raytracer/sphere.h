//
// Created by Gavin T McRoy on 5/10/2022.
//

#ifndef SIMPLE_RAYTRACER_SPHERE_H
#define SIMPLE_RAYTRACER_SPHERE_H


#include "hittable.h"
#include "vec3.h"

class sphere : public hittable {
public:
    point3 center;
    double radius;

    sphere() {

    }

    sphere(point3 center, double radius) : center(center), radius(radius) {

    };

    bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const;


};


#endif //SIMPLE_RAYTRACER_SPHERE_H
