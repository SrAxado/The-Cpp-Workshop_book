#include <iostream>
#include <string>

class Shape {
  public:
    virtual int CalculateArea() = 0;
    int coiso;

  protected:
    int area = 2;
};

class Square : public Shape {
  public:
    int height = 1;
    int CalculateArea() override {
      std::cout << "Calculating... ";
      area = height * height;
      return area;
    }
};

class Circle : public Shape {
  public:
    int radius = 0;
    int CalculateArea() override {
      area = 3.14 * (radius * radius);
      return area;
    }
};


int main() {

  Shape* square = new Square();
  std::cout << "Square Area: " << square->CalculateArea() << std::endl; // we can only access the members defined in Shape
  // in this case, being a virtual method, we access the overrider method

  Square* square2 = static_cast<Square*>(square);
  square2->height = 10; // we have access to the members of the Square and Shape
  std::cout << "Square Area: " << square->CalculateArea() << std::endl; // still accessing the overrider method


  Shape* circle = new Circle();
  std::cout << "Circle Area: " << circle->CalculateArea() << std::endl;

  Circle* circle2 = static_cast<Circle*>(circle);
  circle2->radius = 10;
  std::cout << "Circle Area: " << circle->CalculateArea() << std::endl;


  // casting from a derived type to a base type is also possible
  Circle* circle3 = new Circle();
  circle3->radius = 1;
  Shape* shape3 = static_cast<Shape*>(circle3);
  // shape3->area = 3; // error: "Shape::area" is inaccessible
  // we're only able to access members declared in the base class
  std::cout << "Circle's Shape Area: " << shape3->CalculateArea() << std::endl;
  shape3->coiso = 25;

  delete square;
  square = nullptr;
  delete circle;
  circle = nullptr;
  // delete square2;
  // square2 = nullptr;
  // delete circle2;
  // circle2 = nullptr;
  // delete circle3;
  // circle3 = nullptr;
  delete shape3;
  shape3 = nullptr;
}

/*
OUTPUT:

Square Area: Calculating... 1
Square Area: Calculating... 100
Circle Area: 0
Circle Area: 314
Circle's Shape Area: 3
*/