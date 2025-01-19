#ifndef CURVES_H_
#define CURVES_H_

#include <numbers>
#include <ostream>

class Point3D {
	double x;
	double y;
	double z;

public:	
	Point3D(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}
	
	friend std::ostream & operator<<(std::ostream & os, const Point3D & p);
};

class Vector3D {
	double x;
	double y;
	double z;

public:	
	Vector3D(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}
	
	friend std::ostream & operator<<(std::ostream & os, const Vector3D & v);
};

class Curve {
public:
	virtual Point3D point(double t) const = 0;
	virtual Vector3D first_derivative(double t) const = 0;
	virtual ~Curve() {}
};

class Circle : public Curve {
	double radius;

public:	
	Circle(double r);

	Point3D point(double t) const;
	Vector3D first_derivative(double t) const;
	
	double get_radius() const {
		return radius;
	}
};

class Ellipse : public Curve {
	double a;
	double b;
	
public:	
	Ellipse(double a_, double b_);

	Point3D point(double t) const;
	Vector3D first_derivative(double t) const;
};

class Helix : public Curve {
	double radius;
	double step;
	const double pi = std::numbers::pi;
	
public:	
	Helix(double r, double s);

	Point3D point(double t) const;
	Vector3D first_derivative(double t) const;
};

#endif