//Eli Moore
//Sphere object that is used for the renderer
//Credit to Peter Shirley
#ifndef SPHERE_H
#define SPHERE_H

#include <cmath>
#include "hittable.h"
#include "gpro/gpro-math/gproVector.h"
using color = vec3;
using point3 = vec3;

class sphere : public hittable 
{
public:
    //sphere() {}//Empty constructor, causes a warning when included
    sphere(point3 cen, double r) : center(cen), radius(r) {};

    virtual bool hit(//Hit function from hittable
        const ray& r, double tmin, double tmax, hit_record& rec) const override;

public:
    point3 center;
    double radius;
};

//SPHERE IS HIT IF BETWEEN T_MIN AND T_MAX
bool sphere::hit(const ray& r, double t_min, double t_max, hit_record& rec) const 
{
    
    //Hard-coded ray-sphere intersection algorithm
    vec3 oc = r.origin() - center;
    double a = r.direction().length_squared();
    double half_b = dot(oc, r.direction());
    double c = oc.length_squared() - radius * radius;
    double discriminant = half_b * half_b - a * c;

    if (discriminant > 0) {
        double root = std::sqrt(discriminant);
        double temp = (-half_b - root) / a;//+-
        if (temp < t_max && temp > t_min) {//If between t_max and t_min
            rec.t = temp;
            rec.p = r.at(rec.t);
            vec3 outward_normal = (rec.p - center) / radius;
            rec.set_face_normal(r, outward_normal);
            return true;
        }

        temp = (-half_b + root) / a;//+-; same as before
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.at(rec.t);
            vec3 outward_normal = (rec.p - center) / radius;
            rec.set_face_normal(r, outward_normal);
            return true;
        }
    }

    return false;
}


#endif