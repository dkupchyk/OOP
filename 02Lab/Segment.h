#pragma once
#include "Point.h"
#include <iostream>
using namespace std;


//*******************************************
//       Developed by Daryna Kupchyk
//             on 30.01.2020
//*******************************************

//Every segment posesses its unique ID.
//In debug mode both constructor and destructor
//report the ID and the coordinates
//of a segment created or resp. deleted

// ���� ������
class Segment {

private:
	// ������ ���������� ������
	static int _freeID;
	const int _myId;
	// ����� ������� ������
	Point _a;
	// ����� ���� ������
	Point _b;

public:
	// ������������ ������
	// 1) �� ������������ ���� �����
	Segment(const double x1 = 0, const double y1 = 0, const double x2 = 1, const double y2 = 0);
	// 2) �� ������� ������� � ����
	Segment(const Point& start, const Point& end);
	// 3) ����������� �����������
	Segment(const Segment&);

	// ����������
	~Segment();

	// ���������
	Segment& operator=(const Segment&);

	// ���������  �����
	const Point& start() const { return _a; }
	const Point& end() const { return _b; }

	// ���������-������������ �����
	Point& start() { return _a; }
	Point& end() { return _b; }

	// ��������� ��������� �����
	const double& startX() const { return _a.x(); }
	const double& startY() const { return _a.y(); }
	const double& endX() const { return _b.x(); }
	const double& endY() const { return _b.y(); }

	// ���������-������������ ��������� �����
	double& startX() { return _a.x(); }
	double& startY() { return _a.y(); }
	double& endX() { return _b.x(); }
	double& endY() { return _b.y(); }

	// ���������� ������� ������
	double length() const;
	double length(const Point& a, const Point& b) const;

	// ���������� ������ �� ������ �� �����
	double distance(const Point&) const;

	// �������� ID
	const int getID() const { return _myId; }
};

ostream& operator<<(ostream&, const Segment&);

// �����
// ���������� ������ �� ������ �� �����
double distance(const Segment&, const Point&);