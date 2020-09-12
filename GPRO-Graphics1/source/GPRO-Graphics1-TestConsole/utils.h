//Eli Moore
//Utility functions and variables for the program
//Credit to Peter Shirley
#ifndef UTILS_H
#define UTILS_H

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>

using std::shared_ptr;
using std::make_shared;
using std::sqrt;


const double infinity = std::numeric_limits<double>::infinity();//Represents infinity
const double pi = 3.1415926535897932385;//Pi


inline double degrees_to_radians(double degrees) {//Degree to radian conversion
    return degrees * pi / 180.0;
}

#endif