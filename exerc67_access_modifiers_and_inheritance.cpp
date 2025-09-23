#include <iostream>

class Shape {
  public:
    int area = 0;
    int GetArea() { return area; }

  protected:
    std::string color = "";

  private:
    bool hasOutline = false;
};

class Color {
  public:
    std::string color = "";
    std::string GetColor() { return color; }
};

// class Square : private Shape {
class Square : public Shape {
  public:
    Square() {
      area = 5;
      color = "red";
      hasOutline = true; 
      // (inherited private Shape) error: 'hasOutline' is a private member of 'Shape'
      // (inherited protected Shape) error: 'hasOutline' is a private member of 'Shape'
      // (ihnerited public Shape) error: 'hasOutline' is a private member of 'Shape'
    }
};

class Circle : public Shape, public Color {

};

class Triangle : public Shape, public Color {

};



int main() {
  Square mySquare;
  Circle myCircle;
  Triangle myTriangle;

  // mySquare.area = 5;
  // mySquare.color = "red";
  std::cout << "Square Area: " << mySquare.area << std::endl;
  // (inherited private Shape) error: 'area' is a private member of 'Shape'
  // (inherited protected Shape) error: 'area' is a protected member of 'Shape'
  std::cout << "Square Color: " << mySquare.color << std::endl;
  // (inherited private Shape)  error: 'color' is a private member of 'Shape'
  // (inherited protected Shape) error: 'color' is a protected member of 'Shape'
  // (ihnerited public Shape) error: 'color' is a protected member of 'Shape'
  std::cout << "Square Has Outline: " << mySquare.hasOutline << std::endl;
  // (inherited private Shape)  error: 'hasOutline' is a private member of 'Shape'
  // (inherited protected Shape) error: 'hasOutline' is a private member of 'Shape'
  // (ihnerited public Shape) error: 'hasOutline' is a private member of 'Shape'

  return 0;
}