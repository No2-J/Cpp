//Shape.h
#pragma once
#include<iostream>
#include<cmath>
#include <sstream>
#include "Point.h"
using namespace std;

// Shape Base Class
template <typename T>
class Shape {
protected:
	Point<T> p1;
public:
	Shape(Point<T> c = Point<T>(0,0)):p1(c){}
	virtual double area() const = 0;
	virtual string toString() const = 0;
	virtual ~Shape() {}

	friend ostream& operator<<(ostream& os, const Shape<T>& s) {
		return os << s.toString();
	}
};

// Circle Class
template <typename T>
class Circle : public Shape<T> {
	T radius;
public:
	Circle(Point<T> c, T r) : Shape<T>(c), radius(r) {}
	double area() const override {
		return 3.14159 * radius * radius;
	}
	string toString() const override {
		ostringstream oss;
		oss << "Circle at " << this->p1 << " with radius " << radius << " has area : " << area();
		return oss.str();
	}
};

// Line Class
template <typename T>
class Line : public Shape<T> {
	Point<T> p2;
public:
	Line(Point<T> a, Point<T> b) : Shape<T>(a), p2(b){}
	double area() const override {
		return 0.0; // Line has no area
	}
	double length() const {
		T dx = this->p1.getX() - p2.getX();
		T dy = this->p1.getY() - p2.getY();
		return sqrt(static_cast<double>(dx * dx + dy * dy));
	}
	string toString() const override {
		ostringstream oss;
		oss << "Line from " << this->p1 << " to " << p2 << " with length : " << length();
		return oss.str();
	}
	
};
template <typename T>
class Rectangle : public Shape<T> {
	Point<T> p2;
public:
	Rectangle(Point<T> topLeft, Point<T> bottomRight)
		: Shape<T>(topLeft), p2(bottomRight) {}

	double area() const override {
		T width = abs(p2.getX() - this->p1.getX());
		T height = abs(p2.getY() - this->p1.getY());
		return width * height;
	}
	string toString() const override {
		ostringstream oss;
		oss << "Ractangle from " << this->p1 << " to " << p2 << " with area : " << area();
		return oss.str();
	}
};
template <typename T>
class Triangle : public Shape<T> {
	Point<T> p2, p3;
public:
	Triangle(Point<T> a, Point<T> b, Point<T> c)
		: Shape<T>(a), p2(b), p3(c) {}

	double area() const override {
		T x1 = this->p1.getX(), y1 = this->p1.getY();
		T x2 = p2.getX(), y2 = p2.getY();
		T x3 = p3.getX(), y3 = p3.getY();
		return 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
	}
	string toString() const override {
		ostringstream oss;
		oss << "Triangle with vertices " << this->p1 << ", " << p2 << ", " << p3<<" and area : "<<area();
		return oss.str();
	}
};