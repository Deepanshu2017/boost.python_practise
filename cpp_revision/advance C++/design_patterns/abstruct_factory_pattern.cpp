//In this pattern we create factories which itself create other specified
//objects. So Factory of factories

#include <iostream>
#include <string>
using namespace std;

class Shape {
	public:
		virtual void draw() = 0;
		virtual ~Shape() {};
};

class Circle : public Shape {
	public:
		virtual void draw() override {
			cout << "Inside Circle::draw method" << endl;
		}
		virtual ~Circle() { cout << "destructor of Circle" << endl; }
};

class Rectangle : public Shape {
	public:
		virtual void draw() override {
			cout << "Inside Rectangle::draw method" << endl;
		}
		virtual ~Rectangle() { cout << "destructor of Rectangle" << endl; }
};

class Square : public Shape {
	public:
		virtual void draw() override {
			cout << "Inside Square::draw method" << endl;
		}
		virtual ~Square() { cout << "destructor of Square" << endl; }
};

class Color {
	public:
		virtual void fill() = 0;
		virtual ~Color() {}
};

class Red : public Color {
	public:
		virtual void fill() override {
			cout << "Inside Red::fill method" << endl;
		}
		virtual ~Red() { cout << "destructor of Red" << endl; }
};

class Green : public Color {
	public:
		virtual void fill() override {
			cout << "Inside Green::fill method" << endl;
		}
		virtual ~Green() { cout << "destructor of Green" << endl; }
};

class Blue : public Color {
	public:
		virtual void fill() override {
			cout << "Inside Blue::fill method" << endl;
		}
		virtual ~Blue() { cout << "destructor of Blue" << endl; }
};

class AbstractFactory {
	public:
		virtual Color* getColor(string color) = 0;
		virtual Shape* getShape(string shape) = 0;
		virtual ~AbstractFactory() {}
};

class ShapeFactory : public AbstractFactory {
	public:
		virtual Shape* getShape(string shape) override {
			if(shape == "Circle")
				return new Circle();
			else if(shape == "Rectangle")
				return new Rectangle();
			else if(shape == "Square")
				return new Square();
			else
				return nullptr;
		}
		virtual Color* getColor(string color) override {
			return nullptr;
		}
		virtual ~ShapeFactory() {cout << "destructor of ShapeFactory" << endl;}
};

class ColorFactory : public AbstractFactory {
	public:
		virtual Shape* getShape(string shape) override {
			return nullptr;
		}
		virtual Color* getColor(string color) override {
			if(color == "Red")
				return new Red();
			else if(color == "Green")
				return new Green();
			else if(color == "Blue")
				return new Blue();
			else
				return nullptr;	
		}
		virtual ~ColorFactory() {cout << "destructor of ColorFactory" << endl;}
};

class FactoryProducer {
	public:
		static AbstractFactory* getFactory(string choice) {
			if(choice == "Shape")
				return new ShapeFactory();
			else if(choice == "Color")
				return new ColorFactory;
			else
				return nullptr;
		}
};

int main(void) {
	AbstractFactory* shapeFactory = FactoryProducer::getFactory("Shape");
	Shape* circle = shapeFactory->getShape("Circle");
	circle->draw();
	Shape* rectangle = shapeFactory->getShape("Rectangle");
	rectangle->draw();
	Shape* square = shapeFactory->getShape("Square");
	square->draw();
	AbstractFactory* colorFactory = FactoryProducer::getFactory("Color");
	Color* red = colorFactory->getColor("Red");
	red->fill();
	Color* green = colorFactory->getColor("Green");
	green->fill();
	Color* blue = colorFactory->getColor("Blue");
	blue->fill();
	delete shapeFactory;
	delete circle;
	delete rectangle;
	delete square;
	delete colorFactory;
	delete red;
	delete green;
	delete blue;
}
