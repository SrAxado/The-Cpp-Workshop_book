#include <iostream>

class Shape {
  public:
    int area = 10;
    int GetArea() { return area; }
};

class Color {
  public:
    std::string color = "";
    std::string GetColor() { return color; }
};

class Square : public Shape, public Color {

};

class Circle : public Shape, public Color {

};

class Triangle : public Shape, public Color {

};



int main() {
  Square mySquare;
  Circle myCircle;
  Triangle myTriangle;

  mySquare.area = 5;
  mySquare.color = "red";
  std::cout << "Square Area: " << mySquare.GetArea() << std::endl;
  std::cout << "Square Color: " << mySquare.GetColor() << std::endl;

  myCircle.area = 15;
  myCircle.color = "red";
  std::cout << "Circle Area: " << myCircle.GetArea() << std::endl;
  std::cout << "Circle Color: " << myCircle.GetColor() << std::endl;

  myTriangle.area = 5;
  myTriangle.color = "red";
  std::cout << "Triangle Area: " << myTriangle.GetArea() << std::endl;
  std::cout << "Triangle Color: " << myTriangle.GetColor() << std::endl;

  return 0;
}