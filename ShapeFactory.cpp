#include "ShapeFactory.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"

std::unique_ptr<Shape> ShapeFactory::createShape(const std::string& shapeType, double param1, double param2) {
    if (shapeType == "square") {
        return std::make_unique<Square>(param1);
    } else if (shapeType == "rectangle") {
        return std::make_unique<Rectangle>(param1, param2);
    } else if (shapeType == "circle") {
        return std::make_unique<Circle>(param1);
    } else {
        return nullptr; 
    }
}
