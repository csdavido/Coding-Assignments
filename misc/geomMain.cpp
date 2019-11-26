#include <iostream>
#include <string>

#include "Point.hpp"
#include "LineSegment.hpp"
//compile with g++ Point.cpp LineSegment.cpp geomMain.Cpp -o geom
using namespace std;

int main() {
	Point p1(-1.5, 0.0);
	Point p2(1.5, 4.0);

	LineSegment linecheck1; (p1, p2);

	double length = linecheck1.length();
	double slope = linecheck1.slope();

	double dist = p1.distanceTo(p2);

	cout << "Distance: " << dist << endl;
	cout << "End-point Length: " << length << endl;
	cout << "Slope: " << slope << endl;
	return 0;
}
