// Creating a Position Class with Private Member Variables
#include <iostream>
#include <cmath>
using namespace std;

class Position {
  public:
    Position(float x, float y) : m_x(x), m_y(y) {};

    float Distance(float x, float y) {
      float xDiff = x - m_x;
      float yDiff = y - m_y;

      // return sqrt(pow(xDiff, 2) + pow(yDiff, 2));
      return sqrt(xDiff * xDiff + yDiff * yDiff);
    }

  private:
    float m_x;
    float m_y;

};

int main() {
  Position pos(10.0f, 20.0f);

  cout << "The distance from pos to (100, 400) is: "
    << pos.Distance(100.0f, 400.0f) << endl;

  return 0;
}