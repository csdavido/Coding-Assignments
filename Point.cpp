#include <iostream>
#include <cmath>
#include "Point.hpp"

Point::Point() {
	setXCoord(0);
	setYCoord(0);
}
Point::Point(double x, double y) {
	setXCoord(x);
	setYCoord(y);
}
Point::~Point() {

}
double Point::getXCoord() const {
	return XCoord;
}
double Point::getYCoord() const {
	return YCoord;
}

void Point::setXCoord(double x) {
	XCoord = x;
}
void Point::setYCoord(double y) {
	YCoord = y;
}
double Point::distanceTo(const Point &otherpoint) {
	double x1,
		x2,
		y1,
		y2;
	double distanceX,
		distanceY,
		distanceSquare,
		distance;
	x1 = XCoord;
	x2 = otherpoint.XCoord;
	y1 = YCoord;
	y2 = otherpoint.YCoord;
	distanceX = x1 - x2;
	distanceY = y1 - y2;
	distanceSquare = pow(distanceX, 2) + pow(distanceY, 2);
	distance = sqrt(distanceSquare);
	return distance;
}