//
// Created by Gavin T McRoy on 5/10/2022.
//

#ifndef SIMPLE_RAYTRACER_HITTABLE_H
#define SIMPLE_RAYTRACER_HITTABLE_H

#include "ray.h"
#include "rtweekend.h"

class material;

struct hit_record {
public:
    point3 p;
    vec3 normal;
    shared_ptr<material> material_ptr;
    double t;
    bool front_face;

    inline void set_face_normal(const ray &r, const vec3 &outward_normal) {
        front_face = dot(r.direction(), outward_normal) < 0.0;
        normal = front_face ? outward_normal : -outward_normal;
    }

};

class hittable {
public:
    virtual bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const = 0;

};


#endif //SIMPLE_RAYTRACER_HITTABLE_H
