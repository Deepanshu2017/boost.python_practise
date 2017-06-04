//In Factory pattern, we create object without exposing the creation logic to 
//the client and refer to newly created object using a common interface.

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

class ShapeFactory {
	public:
		static Shape* createShape(string type) {
			if(type == "Circle")
				return new Circle();
			else if(type == "Rectangle")
				return new Rectangle();
			else if(type == "Square")
				return new Square();
			else
				return nullptr;
		}
};

int main(void) {

	Shape* shape_1 = ShapeFactory::createShape("Circle");
	shape_1->draw();
	Shape* shape_2 = ShapeFactory::createShape("Rectangle");
	shape_2->draw();
	Shape* shape_3 = ShapeFactory::createShape("Square");
	shape_3->draw();

	delete shape_1;
	delete shape_2;
	delete shape_3;

	return 0;
}
