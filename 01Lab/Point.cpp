#include "Point.h"
#include <iostream>
#include <cassert>
using namespace std;

//*******************************************
//       Developed by Daryna Kupchyk
//             on 21.01.2020
//*******************************************

//Every point posesses its unique ID.
//In debug mode both constructor and destructor
//report the ID and the coordinates
//of a point created or resp. deleted

int Point::freeID = 0;

Point::Point(double x, double y) : _x(x), _y(y), pointID(++freeID) {
#ifndef NDEBUG 
	cout << "Point " << (*this).getID() << " constructor is called." << endl;
#endif 
	return;
}

Point::Point(const Point& p) :_x(p._x), _y(p._y), pointID(++freeID) {
#ifndef NDEBUG 
	cout << "Point " << (*this).getID() << " constructor is called." << endl;
#endif 
	return;
}

Point::~Point() {
#ifndef NDEBUG 
	cout << "Point " << (*this).getID() << " destructor is called." << endl;
#endif 
	return;
}

Point& Point::operator=(const Point& p) {
	_x = p._x;
	_y = p._y;
	return *this;
}

void Point::setX(const double x) {
	_x = x;
	return;
}

void Point::setY(const double y) {
	_y = y;
	return;
}

ostream& operator<<(ostream& os, const Point& p) {
	os << '(' << p.x() << ',' << p.y() << ')';
	return os;
}

const Point operator+ (const Point& u, const Point& v) {
	return Point(u.x() + v.x(), u.y() + v.y());
}

Point& operator+=(Point& u, const Point& v) {
	u.x() += v.x();
	u.y() += v.y();
	return u;
}

bool operator==(const Point& u, const Point& v) {
	if ((u.x() == v.x()) && (u.y() == v.y())) {
		return true;
	}
	return false;
}

bool operator!=(const Point& u, const Point& v) {
	if ((u.x() != v.x()) || (u.y() != v.y())) {
		assert(!(u == v));
		return true;
	}
	assert(u == v);
	return false;
}