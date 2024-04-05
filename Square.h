#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape {
private:
    double side;

public:
    Square(double side);
    double calculateArea() const override;
};

#endif
