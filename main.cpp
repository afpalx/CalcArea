#include <iostream>
#include "UserInput.h"

int main() {
    std::unique_ptr<Shape> shape = getUserInput();

    if (shape) {
        std::cout << "Area of the shape: " << shape->calculateArea() << std::endl;
    }

    return 0;
}

