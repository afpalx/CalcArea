#include<iostream>
#include<cmath>
#include<vector>

class Shape {
	public:
		virtual double calcArea() const = 0;
};

class Square : public Shape {
	private:
		double side;
	public:
		Square(double s) : side(s) {}
		double calcArea() const override {
			return side * side;
		}
};

class Rectangle : public Shape {
	private:
		double length;
		double width;
	public:
		Rectangle(double l, double w) : length (l), width (w) {}
		double calcArea() const override {
			return length * width;
		}
};

class Circle : public Shape {
	private:
		double radius;
	public:
		Circle(double r) : radius(r) {}
		double calcArea() const override {
			return M_PI * radius * radius;
		}
};

void printArea(const Shape& shape) {
	if(dynamic_cast<const Square*>(&shape)) {
		std::cout << "Area of square: ";
	} else if(dynamic_cast<const Rectangle*>(&shape)) {
		std::cout << "Area of rectangle: ";
	} else if(dynamic_cast<const Circle*>(&shape)) {
		std::cout << "Area of circle: ";
	}
	std::cout << shape.calcArea() << std::endl;
}

int main() {
/**	Square square(3.0);
	Rectangle rectangle (4.0, 5.0);
	Circle circle(6.0);
**/
	double side, length, width, radius;
	std::vector<Shape*> shapes;

	std::cout << "Enter side of the square: ";
	std::cin >> side;
	shapes.push_back(new Square(side));

/**
	Square square(side);
**/

	std::cout << "Enter length of the rectangle: ";
	std::cin >> length;
	std::cout << "Enter width of the rectangle: ";
	std::cin >> width;
	shapes.push_back(new Rectangle(length, width));

/**
	Rectangle rectangle(length, width);
**/

	std::cout << "Enter the radius of the circle: ";
	std::cin>> radius;
	shapes.push_back(new Circle(radius));

/**	
	Circle circle(radius);
**/

/**
	for (const auto& shape : shapes) {
		if (dynamic_cast<Square*>(shape)) {
			std::cout << "Area of square: ";
		} else if (dynamic_cast<Rectangle*>(shape)) {
			std::cout << "Area of rectangle: ";
		} else if (dynamic_cast<Circle*>(shape)) {
			std::cout << "Area of circle: ";
		}
		std::cout << shape->calcArea() << std::endl;
	}
**/

	for(const auto& shape : shapes) {
		printArea(*shape);
	}


	for (const auto& shape : shapes) {
		delete shape;
	}

/**
	std::cout << "Area of square: " << square.calcArea() << std::endl;
	std::cout << "Area of rectangle: " << rectangle.calcArea() << std::endl;
	std::cout << "Area of circle: " << circle.calcArea() << std::endl;
**/

	return 0;
}
