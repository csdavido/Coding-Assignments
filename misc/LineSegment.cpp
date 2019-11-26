#include <iostream>
#include "LineSegment.hpp"
#include "Point.hpp"

LineSegment::LineSegment(Point p1, Point p2) {
	setEnd1(p1);
	setEnd2(p2);
}
LineSegment::LineSegment() {
	setEnd1(Point (0, 0));
	setEnd2(Point (0, 0));
}
double LineSegment::setEnd1(Point p1) {
	p1.setXCoord(0.0);
	p1.setYCoord(0.0);
}
Point LineSegment::getEnd1() {
	return p1;
}
double LineSegment::setEnd2(Point p2) {
	p2.setXCoord(0);
	p2.setYCoord(0);
}
Point LineSegment::getEnd2() {
	return p2;
}
double LineSegment::length() {
	return p1.distanceTo(p2);
}
double LineSegment::slope() {
	if (p2.getXCoord() - p1.getXCoord() == 0.0) {
		return 0.0/0.0;
	}
	else {
		return (p2.getYCoord() - p1.getYCoord()) / (p2.getXCoord() - p1.getXCoord());
	}
}
