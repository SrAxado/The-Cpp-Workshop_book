#include <iostream>
#include <string>

class Shape {
  public:
    virtual int CalculateArea() = 0;

  protected:
    int area = 0;
};

class Square : public Shape {
  public:
    int height = 0;
    int CalculateArea() override {
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
  std::cout << "Square Area: " << square->CalculateArea() << std::endl;

  Square* square2 = static_cast<Square*>(square);
  square2->height = 10;
  std::cout << "Square Area: " << square->CalculateArea() << std::endl;


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

  delete square;
  square = nullptr;
  delete circle;
  circle = nullptr;
}