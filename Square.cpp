#include "Square.h"

Square::Square(double side) : side(side) {}

double Square::calculateArea() const {
    return side * side;
}
