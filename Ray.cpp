#include "Ray.h"

Ray::Ray(const Vec& o, const Vec& d) :
        o(o),
        d(d) {}

Ray::Ray(Vec&& o, Vec&& d) :
        o(std::move(o)),
        d(std::move(d)) {}
