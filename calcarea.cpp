#include<iostream>
#include<cmath>

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

int main() {
/**	Square square(3.0);
	Rectangle rectangle (4.0, 5.0);
	Circle circle(6.0);
**/
	double side, length, width, radius;

	std::cout << "Enter side of the square: ";
	std::cin >> side;
	Square square(side);

	std::cout << "Enter length of the rectangle: ";
	std::cin >> length;
	std::cout << "Enter width of the rectangle: ";
	std::cin >> width;
	Rectangle rectangle(length, width);

	std::cout << "Enter the radius of the circle: ";
	std::cin>> radius;
	Circle circle(radius);

	std::cout << "Area of square: " << square.calcArea() << std::endl;
	std::cout << "Area of rectangle: " << rectangle.calcArea() << std::endl;
	std::cout << "Area of circle: " << circle.calcArea() << std::endl;

	return 0;
}
