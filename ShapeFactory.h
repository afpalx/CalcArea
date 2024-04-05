#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H

#include "Shape.h"
#include <memory>
#include <string>

class ShapeFactory {
public:
    static std::unique_ptr<Shape> createShape(const std::string& shapeType, double param1, double param2 = 0);
};

#endif 
