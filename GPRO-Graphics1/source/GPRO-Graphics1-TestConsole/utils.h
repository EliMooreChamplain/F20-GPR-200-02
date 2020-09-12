#ifndef UTILS_H
#define UTILS_H

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>

using std::shared_ptr;
using std::make_shared;
using std::sqrt;


const double infinity = std::numeric_limits<double>::infinity();
const double pi = double(3.1415926535897932385);


inline double degrees_to_radians(double degrees) {
    return double(degrees) * double(pi / 180.0);
}

#endif