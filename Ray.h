#ifndef RAY_H
#define RAY_H

#include "Vec.h" // Assuming you have a separate Vec class
#include <algorithm>

class Ray {
public:
    Vec o; // origin
    Vec d; // direction

public:
    Ray(const Vec& o, const Vec& d);
    Ray(Vec&& o, Vec&& d);
};

#endif  // RAY_H
