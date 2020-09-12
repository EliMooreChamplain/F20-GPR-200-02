//Eli Moore
//hittable.h
//Holds the abstract class "hittable", and the hit_record struct

//Credit to Peter Shirley

#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"


struct hit_record {
    point3 p = point3(0,0,0);//Point
    vec3 normal = vec3(0,0,0);//Normal vector
    double t = 0.0;           //the t value; 0-1
    bool front_face = false;  //Direction it is facing

    //Sets the vector
    inline void set_face_normal(const ray& r, const vec3& outward_normal) {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;//Outward_normal if front_face is true, -outward_normal is front_face is false
    }
};

class hittable {
public:
    //Returns whether the ray hits
    virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};

#endif