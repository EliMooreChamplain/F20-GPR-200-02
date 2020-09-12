//Eli Moore
//ray.h
//The ray class has an origin and a direction

//Credit to Peter Shirley
#ifndef RAY_H
#define RAY_H

#include "gpro/gpro-math/gproVector.h"
using color = vec3;
using point3 = vec3;
class ray {
public:
    ray() {}
    ray(const point3& origin, const vec3& direction)//Constructor that gives the origin and direction
        : orig(origin), dir(direction)
    {}

    //getters for origin and direction
    point3 origin() const { return orig; }
    vec3 direction() const { return dir; }

    point3 at(double t) const {//Returns the point for the time t
        return orig + t * dir;
    }

public:
    point3 orig;//ORIGIN
    vec3 dir;   //DIRECTION
};

#endif