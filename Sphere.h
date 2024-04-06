#ifndef SPHERE_H
#define SPHERE_H

#include "Vec.h"
#include "Ray.h"

class Sphere {
public:
	Vec c; // Center position
	double r; // Radius

public:
	Sphere(const Vec& c, double const r);

	Vec getNormal(const Vec& pi) const;

	bool intersect(const Ray& ray, double& t) const;
};

#endif  // SPHERE_H
