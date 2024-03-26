#include<iostream>
#include<cmath>
#include<vector>

class Shape {
	public:
		virtual double calcArea() const = 0;
		virtual std::string shapeName() const = 0;
};

class Square : public Shape {
	private:
		double side;
	public:
		Square(double s) : side(s) {}
		double calcArea() const override {
			return side * side;
		}
		std::string shapeName() const override {
			return "square";
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
		std::string shapeName() const override {
			return "rectangle";
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
		std::string shapeName() const override {
			return "circle";
		}
};

void printArea(const Shape& shape) {
	std::cout << "Area of " << shape.shapeName() << ": " << shape.calcArea() << std::endl;
}

int main() {

	double side, length, width, radius;
	std::vector<Shape*> shapes;

	std::cout << "Enter side of the square: ";
	std::cin >> side;
	shapes.push_back(new Square(side));

	std::cout << "Enter length of the rectangle: ";
	std::cin >> length;
	std::cout << "Enter width of the rectangle: ";
	std::cin >> width;
	shapes.push_back(new Rectangle(length, width));

	std::cout << "Enter the radius of the circle: ";
	std::cin>> radius;
	shapes.push_back(new Circle(radius));

	for(const auto& shape : shapes) {
		printArea(*shape);
	}


	for (const auto& shape : shapes) {
		delete shape;
	}

	return 0;
}
