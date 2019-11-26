#pragma once
#include <iostream>
#include <string>

using namespace std;

#ifndef Box_HPP
#define Box_HPP

class Box {
public:

		//default constructor
	Box();

		//overload constructor
	Box(double, double, double);

	   //destructor
	~Box();

		//Accessor Functions
	double getHeight() const;
	double getWidth() const;
	double getLength() const;

		//mutator functions
	void setHeight(double);
	void setWidth(double);
	void setLength(double);

	double calculateVolume() const;
	double calculateSurfaceArea() const;

private:
		//member variables
	double newHeight,
		newWidth,
		newLength;
};

#endif
