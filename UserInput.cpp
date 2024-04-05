#include "UserInput.h"
#include "ShapeFactory.h"
#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <limits>

std::string lowerCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

std::unique_ptr<Shape> getUserInput() {
    std::string shapeType;
    double param1, param2;

    while (true) {
        std::cout << "Enter the shape type (square, rectangle, circle): ";
        std::cin >> shapeType;
	
	shapeType = lowerCase(shapeType);

        if (shapeType == "square" || shapeType == "rectangle" || shapeType == "circle") {
            break;
	} else {
            std::cerr << "Invalid shape type! Please try again." << std::endl;
	}
    }

    while (true) {
        std::cout << "Enter parameter 1: ";
        std::cin >> param1;
	
	if (!std::cin.fail()) {
            break;
	} else {
            std::cerr << "Invalid input for parameter 1. Please enter a numerical value." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    if (shapeType == "rectangle") {
        while (true) {
            std::cout << "Enter parameter 2: ";
            std::cin >> param2;
	    
	    if (!std::cin.fail()) {
                break;
            } else {
                std::cerr << "Invalid input for parameter 2. Please enter a numerical value." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }

    return ShapeFactory::createShape(shapeType, param1, param2);
}
