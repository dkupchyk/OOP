#include "Segment.h"
#include "math.h"

//*******************************************
//       Developed by Daryna Kupchyk
//             on 30.01.2020
//*******************************************

int Segment::_freeID = 0;

// Конструктори відрізків
// 1) за координатами його кінців
Segment::Segment(const double x1, const double y1, const double x2, const double y2) : _a(x1, y1), _b(x2, y2), _myId(++_freeID) {
#ifndef NDEBUG    
	cout << "\nSegment " << _myId << " was created." << endl;
#endif 
}

// 2) за точками початку і кінця
Segment::Segment(const Point& start, const Point& end) : _a(start), _b(end), _myId(++_freeID) {
#ifndef NDEBUG    
	cout << "\nSegment " << _myId << " was created." << endl;
#endif
}

// 3) копіювальний конструктор
Segment::Segment(const Segment& s) : _a(s._a), _b(s._b), _myId(++_freeID) {
#ifndef NDEBUG    
	cout << "\nSegment " << _myId << " was created." << endl;
#endif
}

// Деструктор
Segment::~Segment() {
#ifndef NDEBUG    
	cout << "\nSegment " << _myId << " was deleted." << endl;
#endif
}

// Присвоєння
Segment& Segment::operator=(const Segment& s) {
	_a = s._a;
	_b = s._b;
	return *this;
}

// Обчислення довжини відрізка
double Segment::length() const {
	return sqrt((endX() - startX()) * (endX() - startX()) + (endY() - startY()) * (endY() - startY()));
}

double Segment::length(const Point& a, const Point& b) const {
	return sqrt((b.x() - a.x()) * (b.x() - a.x()) + (b.y() - a.y()) * (b.y() - a.y()));
}

// Обчислення відстані від відрізка до точки
double Segment::distance(const Point& p) const {
	double pToStart = length(p, (*this).start());
	double pToEnd = length(p, (*this).end());

	if (pToStart >= sqrt(length(p, (*this).end()) * length(p, (*this).end()) + length() * length())) {
		return pToEnd;
	}
	else if (pToEnd >= sqrt(length(p, (*this).start()) * length(p, (*this).start()) + length() * length())) {
		return pToStart;
	}
	else {
		return fabs((endY() - startY()) * p.x() - (endX() - startX()) * p.y() + endX() * startY() - endY() * startX()) / length();
	}
}

ostream& operator<<(ostream& os, const Segment& s) {
	os << '(' << '(' << s.startX() << ',' << s.startY() << ')' << ',' << '(' << s.endX() << ',' << s.endY() << ')' << ')';
	return os;
}

// Опція
// Обчислення відстані від відрізка до точки
double distance(const Segment& s, const Point& p) {
	double pToStart = s.length(p, s.start());
	double pToEnd = s.length(p, s.end());

	if (pToStart >= sqrt(s.length(p, s.end()) * s.length(p, s.end()) + s.length() * s.length())) {
		return pToEnd;
	}
	else if (pToEnd >= sqrt(s.length(p, s.start()) * s.length(p, s.start()) + s.length() * s.length())) {
		return pToStart;
	}
	else {
		return fabs((s.endY() - s.startY()) * p.x() - (s.endX() - s.startX()) * p.y() + s.endX() * s.startY() - s.endY() * s.startX()) / s.length();
	}
}