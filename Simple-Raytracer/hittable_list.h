//
// Created by Gavin T McRoy on 5/12/2022.
//

#ifndef SIMPLE_RAYTRACER_HITTABLE_LIST_H
#define SIMPLE_RAYTRACER_HITTABLE_LIST_H

#include <memory>
#include <vector>
#include "hittable.h"

using std::shared_ptr;
using std::make_shared;

class hittable_list : public hittable {
public:

    std::vector<shared_ptr<hittable>> objects;

    hittable_list() {

    }

    hittable_list(shared_ptr<hittable> object) {
        add(object);
    }

    void clear() {
        objects.clear();
    }

    void add(shared_ptr<hittable> object) {
        objects.push_back(object);
    }

    virtual bool hit(const ray &r,double t_min, double t_max, hit_record &rec) const override;


};


#endif //SIMPLE_RAYTRACER_HITTABLE_LIST_H
