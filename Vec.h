#ifndef VEC_H
#define VEC_H

#include <cmath>

class Vec {
public:
	double x = 0;
	double y = 0;
	double z = 0;

public:
	Vec() = default;

	Vec(double const x, double const y, double const z) :
		x(x),
		y(y),
		z(z) {}

	Vec operator+(const Vec& v) const;
	Vec operator-(const Vec& v) const;
	Vec operator*(double const scalar) const;
	Vec operator/(double const scalar) const;
	double magnitude() const;
	Vec normalize() const;
	double dot(const Vec& v) const;
};

#endif
