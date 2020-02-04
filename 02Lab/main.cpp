#include "Segment.h"
#include <iostream>
using namespace std;

//*******************************************
//       Developed by Daryna Kupchyk
//             on 30.01.2020
//*******************************************

int main() {

	cout << "-------- CREATING SEGMENTS --------\n" << endl;

	//Creating a segment with default param
	Segment a;
	cout << "\nID of segment a: " << a.getID() << endl;
	cout << "Starting point of a: " << a.start() << endl;
	cout << "Ending point of a: " << a.end() << endl;
	cout << "Length of a: " << a.length() << "\n" << endl;

	Segment b(3, 3, 7, 3);
	cout << "\nID of segment b: " << b.getID() << endl;
	cout << "Starting point of b: " << b.start() << endl;
	cout << "Ending point of b: " << b.end() << endl;
	cout << "Length of b: " << b.length() << "\n" << endl;

	Point cX(5, 0);
	Point cY(0, 5);
	Segment c(cX, cY);
	cout << "\nID of segment c:" << c.getID() << endl;
	cout << "Starting point of c:" << c.start() << endl;
	cout << "Ending point of c: " << c.end() << endl;
	cout << "Length of c: " << c.length() << "\n" << endl;

	Segment d(c);
	cout << "\nID of segment d:" << d.getID() << endl;
	cout << "Starting point of d:" << d.start() << endl;
	cout << "Ending point of d: " << d.end() << endl;
	cout << "Length of d: " << d.length() << "\n" << endl;

	Segment e = b;
	cout << "\nID of segment e:" << e.getID() << endl;
	cout << "Starting point of e:" << e.start() << endl;
	cout << "Ending point of e: " << e.end() << endl;
	cout << "Length of e: " << e.length() << "\n" << endl;

	cout << "\n-------- CHECKING DISTANCE METHOD --------\n" << endl;

	//If the shortest distance is the perpendicular fron the point to the segment
	Point p(2, 1);
	Segment s(0, 0, 4, 0);
	cout << "\nPoint: " << p << endl;
	cout << "Segment: " << s << endl;
	cout << "Distance from point p1 to segment s: " << s.distance(p) << endl;

	//If the shortest distance is distance to the starting point of the segment
	p.x() = -1;
	cout << "\nPoint: " << p << endl;
	cout << "Segment: " << s << endl;
	cout << "Distance from point p1 to segment s: " << s.distance(p) << endl;

	//If the shortest distance is distance to the ending point of the segment
	p.x() = 5;
	cout << "\nPoint: " << p << endl;
	cout << "Segment: " << s << endl;
	cout << "Distance from point p1 to segment s: " << s.distance(p) << endl;

	//If a point is laying on the same line as the segment
	p.x() = 10;
	p.y() = 0;
	cout << "\nPoint: " << p << endl;
	cout << "Segment: " << s << endl;
	cout << "Distance from point p1 to segment s: " << distance(s, p) << endl;

	cout << "\n-------- CALLING DESTRUCTORS --------\n" << endl;

	return 0;
}