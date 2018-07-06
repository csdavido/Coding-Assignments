#pragma once
#include "Point.hpp"

#ifndef LineSegment_HPP
#define LineSegment_HPP

class LineSegment {
public:
	LineSegment();
	LineSegment(Point p1, Point p2);
	
	double setEnd1(Point);
	double setEnd2(Point);

	Point getEnd1();
	Point getEnd2();

	double length();
	double slope();

private:
	Point p1;
	Point p2;
};

#endif