//
// Created by Gavin T McRoy on 5/12/2022.
//

#ifndef SIMPLE_RAYTRACER_CAMERA_H
#define SIMPLE_RAYTRACER_CAMERA_H

#include "vec3.h"
#include "ray.h"

class camera {
private:
    point3 origin;
    point3 lower_left_corner;
    vec3 horizontal;
    vec3 vertical;
    vec3 u, v, w;
    double lens_radius;

public:
    camera(point3 lookFrom, point3 lookAt, vec3 vUp, double vfov, double aspect_ratio,
           double aperture, double focus_dist) {

        auto theta = degrees_to_radians(vfov);
        auto h = tan(theta / 2.0);
        auto viewport_height = 2.0 * h;
        auto viewport_width = aspect_ratio * viewport_height;

        w = unit_vector(lookFrom - lookAt);
        u = unit_vector(cross(vUp, w));
        v = cross(w, u);

        origin = lookFrom;
        horizontal = focus_dist * viewport_width * u;
        vertical = focus_dist * viewport_height * v;
        lower_left_corner = origin - horizontal / 2.0 - vertical / 2.0 - focus_dist * w;

        lens_radius = aperture/2.0;

    }


    ray get_ray(double s, double t) const {
        vec3 rd = lens_radius * random_in_unit_disk();
        vec3 offset = u * rd.x() + v* rd.y();

        return ray(origin+offset,lower_left_corner+s*horizontal+t*vertical-origin-offset);
    }
};


#endif //SIMPLE_RAYTRACER_CAMERA_H
