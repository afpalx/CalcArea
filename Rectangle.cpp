#include "Rectangle.h"

Rectangle::Rectangle(double length, double width) : length(length), width(width) {}

double Rectangle::calculateArea() const {
    return length * width;
}
