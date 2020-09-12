//Eli Moore
//hittable_list.h
//hittable_list is a list of hittables that are in the scene

//Credit to Peter Shirley
#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class hittable_list : public hittable 
{
public:

    hittable_list() {}
    hittable_list(shared_ptr<hittable> object) { add(object); }

    void clear() { objects.clear(); objectCount--; }
    void add(shared_ptr<hittable> object) { objects.push_back(object); objectCount++; }

    virtual bool hit(
        const ray& r, double tmin, double tmax, hit_record& rec) const override;

public:
    std::vector<shared_ptr<hittable>> objects;
    int objectCount = 0; 
};

//RETURNS WHETHER STUFF WAS HIT BETWEEN TMIN AND TMAX
bool hittable_list::hit(const ray& r, double t_min, double t_max, hit_record& rec) const 
{
    hit_record temp_rec;
    bool hit_anything = false;
    double closest_so_far = t_max;

    for (int i = 0; i < objectCount; i++) {
        if (objects[i]->hit(r, t_min, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }

    return hit_anything;
}

#endif