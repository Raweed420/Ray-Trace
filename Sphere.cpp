#include "Sphere.h"
#include <cmath>
#include <algorithm>

Sphere::Sphere(const Vec& c, double const r) : c(c), r(r) {}

Vec Sphere::getNormal(const Vec& pi) const {
	return (pi - c) / r;
}

bool Sphere::intersect(const Ray& ray, double& t) const {
	const Vec& oc = ray.o - c;
	double const b = 2 * oc.dot(ray.d);
	double const c = oc.dot(oc) - r * r;
	double const discriminant = b * b - 4 * c;

	if (discriminant < 0)
		return false;

	double const sqrt_discriminant = std::sqrt(discriminant);
	double const t0 = -b - sqrt_discriminant;
	double const t1 = -b + sqrt_discriminant;
	t = std::min(t0, t1);
	return true;
}
