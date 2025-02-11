#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <memory>

using namespace std;

const double infinity = numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees) {
  return degrees * pi / 180.0;
}

inline double random_double() { return rand() / (RAND_MAX + 1.0); }

inline double random_double(double min, double max) {
  return min + (max - min) * random_double();
}
// common headers

#include "color.h"
#include "interval.h"
#include "ray.h"
#include "vec3.h"

#endif
