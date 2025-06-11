//Point.h
#pragma once
#include <iostream>

template <typename T>
class Point {
	T x, y;
public:
	Point(T xx = 0, T yy = 0) : x(xx), y(yy) {}
	~Point() {}

	T getX() const { return x; }
	T getY() const { return y; }

	Point<T> operator+(const Point<T>& p) const {
		return Point<T>(x + p.x, y + p.y);
	}

	Point<T> operator-(const Point<T>& p) const {
		return Point<T>(x - p.x, y - p.y);
	}

	friend Point<T> operator*(double s, const Point<T>& p) {
		return Point<T>(static_cast<T>(s * p.x), static_cast<T>(s * p.y));
	}

	friend ostream& operator<<(ostream& os, const Point<T>& p) {
		os << "(" << p.x << "," << p.y << ")";
		return os;
	}
};