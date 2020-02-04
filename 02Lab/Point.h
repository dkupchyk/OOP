#pragma once
#include <iostream>
using namespace std;

//*******************************************
//       Developed by Daryna Kupchyk
//             on 30.01.2020
//*******************************************

//Every point posesses its unique ID.
//In debug mode both constructor and destructor
//report the ID and the coordinates
//of a point created or resp. deleted

class Point {
private:

	static int freeID;
	const int pointID;
	double _x;
	double _y;

public:

	Point(double x = 0, double y = 0);
	Point(const Point& p);
	~Point();
	Point& operator=(const Point& p);
	double& x() { return _x; };
	double& y() { return _y; };
	const double& x() const { return _x; };
	const double& y() const { return _y; };
	const int getID() const { return pointID; };
	static int amount() { return freeID; }
};

ostream& operator<<(ostream& os, const Point& p);
const Point operator+ (const Point& u, const Point& v);
Point& operator+=(Point& u, const Point& v);
bool operator==(const Point& u, const Point& v);
bool operator!=(const Point& u, const Point& v);