#pragma once

#ifndef Point_HPP
#define Point_HPP

class Point {

public:
	Point();

	Point(double x, double y);

	~Point();

	double getXCoord() const;
	double getYCoord() const;

	void setXCoord(double);
	void setYCoord(double);

	double distanceTo(const Point&);

private:
	double XCoord,
		YCoord;
};

#endif