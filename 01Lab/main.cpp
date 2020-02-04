#include "Point.h"
#include <iostream>
using namespace std;

//*******************************************
//       Developed by Daryna Kupchyk
//             on 21.01.2020
//*******************************************

//double& x() { return _x; };
//double& y() { return _y; };
//const double& x()const { return _x; };
//const double& y()const { return _y; };
//const int getID() const { return pointID; };
//void setX(const double x);
//void setY(const double y);

int main(){

	Point a;
	cout << "\n------------------------- POINT " << a.getID() << "-------------------------\n" << endl;
	cout << "x = " << a.x() << endl;
	cout << "y = " << a.y() << endl;

	cout << "After setting points " << a.getID() << " x coordinate to 100 and y" << endl;
	cout << "coordinate to - 100: " << endl;
	a.setX(100);
	a.setY(-100);
	cout << "x = " << a.x() << endl;
	cout << "y = " << a.y() << "\n" << endl;

	const Point b(3.25, 5);

	cout << "\n------------------------- POINT " << b.getID() << "-------------------------\n" << endl;
	cout << "x = " << b.x() << endl;
	cout << "y = " << b.y() << "\n" << endl;

	Point c(b);

	cout << "\n------------------------- POINT " << c.getID() << "-------------------------\n" << endl;
	cout << "x = " << c.x() << endl;
	cout << "y = " << c.y() << "\n" << endl;

	//Checking the operator+=
	cout << "If we chandge the current point by adding to it another" << endl;
	cout << "point, we will get this coordinates." << endl;
	c += b;
	cout << "x = " << c.x() << endl;
	cout << "y = " << c.y() << "\n" << endl;

	//Checking operator== and operator!=
	cout << "Is point a == b? ";
	if(a == b) cout << "Yes." << endl;
	else cout << "No." << endl;
	cout << "Is point b == c? ";
	if (b == c) cout << "Yes." << endl;
	else cout << "No." << endl; 
	cout << "Is point a != c? ";
	if (a != c) cout << "Yes.\n" << endl;
	else cout << "No.\n" << endl;

	Point d = b;
	cout << "\n------------------------- POINT " << d.getID() << "-------------------------\n" << endl;
	cout << "x = " << d.x() << endl;
	cout << "y = " << d.y() << "\n" << endl;

	//Checking the operator+
	Point e;
	cout << "\n------------------------- POINT " << e.getID() << "-------------------------\n" << endl;
	e = a + b;
	cout << "This point was achieved by adding two points." << endl;
	cout << "x = " << e.x() << endl;
	cout << "y = " << e.y() << "\n" << endl;

	return 0;
}
