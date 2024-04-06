#include "Vec.h"

Vec Vec::operator+(const Vec& v) const {
	return Vec(
		x + v.x,
		y + v.y,
		z + v.z
	);
}

Vec Vec::operator-(const Vec& v) const {
	return Vec(
		x - v.x,
		y - v.y,
		z - v.z
	);
}

Vec Vec::operator*(double const scalar) const {
	return Vec(
		x * scalar,
		y * scalar,
		z * scalar
	);
}

Vec Vec::operator/(double const scalar) const {
	return Vec(
		x / scalar,
		y / scalar,
		z / scalar
	);
}

double Vec::magnitude() const {
	return std::sqrt(x*x + y*y + z*z);
}

Vec Vec::normalize() const {
	double mg = magnitude();
	return Vec(
		x / mg,
		y / mg,
		z / mg
	);
}

double Vec::dot(const Vec& v) const {
	return
		x * v.x +
		y * v.y +
		z * v.z;
}
