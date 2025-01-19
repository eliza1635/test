#include <ostream>
#include <cmath>
#include <exception>

#include "curves.h"

std::ostream & operator<<(std::ostream & os, const Point3D & p) {
	os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
	return os;
}

std::ostream & operator<<(std::ostream & os, const Vector3D & v) {
	os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
	return os;
}

Circle::Circle(double r) : Curve() {
	if (r < 0) throw std::invalid_argument("Negative radius of the circle");
	radius = r;
}

Point3D Circle::point(double t) const {
	return Point3D(radius * std::cos(t), radius * std::sin(t), 0);
}

Vector3D Circle::first_derivative(double t) const {
	return Vector3D(-radius * std::sin(t), radius * std::cos(t), 0);
}

Ellipse::Ellipse(double a_, double b_) : Curve() {
	if (a_ < 0 || b_ < 0) throw std::invalid_argument("Negative a or negative b of the ellipse");
	a = a_;
	b = b_;
}

Point3D Ellipse::point(double t) const {
	return Point3D(a * std::cos(t), b * std::sin(t), 0);
}

Vector3D Ellipse::first_derivative(double t) const {
	return Vector3D(-a * std::sin(t), b * std::cos(t), 0);
}

Helix::Helix(double r, double s) : Curve() {
	if (r < 0 || s < 0) throw std::invalid_argument("Negative radius or negative step of the helix");
	radius = r;
	step = s;
}

Point3D Helix::point(double t) const {
	return Point3D(radius * std::cos(t), radius * std::sin(t), step * t / (2 * pi));
}

Vector3D Helix::first_derivative(double t) const {
	return Vector3D(-radius * std::sin(t), radius * std::cos(t), step / (2 * pi));
}