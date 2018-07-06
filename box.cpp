#include "Box.hpp"

Box::Box() {
	newHeight = 0.0;
	newWidth = 0.0;
	newLength = 0.0;
}
Box::Box(double height, double width, double length) {
	newHeight = height;
	newWidth = width;
	newLength = length;
}
Box::~Box() {

}
double Box::getHeight() const {
	return newHeight;
}
double Box::getWidth() const {
	return newWidth;
}
double Box::getLength() const {
	return newLength;
}
void Box::setHeight(double height) {
	newHeight = height;
}
void Box::setWidth(double width) {
	newWidth = width;
}
void Box::setLength(double length) {
	newLength = length;
}

double Box::calculateVolume() const {
	return(newHeight * newWidth * newLength);
}
double Box::calculateSurfaceArea() const {
	return(2 * ((newWidth * newLength) + (newHeight * newLength) + (newHeight * newWidth)));
}