// Creating a Position Class with Private Member Variables
#include <iostream>
#include <cmath>
using namespace std;

class Position {
  public:
    Position(float x, float y) : m_x(x), m_y(y) {};

    float distance(float x, float y) {
      float xDiff = x - m_x;
      float yDiff = y - m_y;

      // return sqrt(pow(xDiff, 2) + pow(yDiff, 2));
      return sqrt(xDiff * xDiff + yDiff * yDiff);
    }

    float getX() { return m_x; }
    float getY() { return m_y; }

    void setX(float x) { m_x = x; }
    void setY(float y) { m_y = y; }

  private:
    float m_x;
    float m_y;

};

int main() {
  float maxDistance = 500.0f;
  Position pos(10.0f, 20.0f);
  Position pos2(100.0f, 200.0f);
  bool validDistance = true;
  int numberOfTimesMoved = 0;

  cout << "The distance from pos and pos2 is: "
    << pos.distance(pos2.getX(), pos2.getY()) << endl;

  while (validDistance) {
    float distance = pos.distance(pos2.getX(), pos2.getY());

    if (distance > maxDistance) {
      validDistance = false;
      break;
    }

    // get direction
    float xDirection = pos2.getX() - pos.getX();
    float yDirection = pos2.getY() - pos.getY();

    // normalize
    float xNormalized = xDirection / distance;
    float yNormalized = yDirection / distance;

    pos.setX(pos.getX() - xNormalized);
    pos.setY(pos.getY() - yNormalized);
    ++numberOfTimesMoved;
  }

  cout << "Too far apart." << endl;
  cout << "Moved " << numberOfTimesMoved << " times" << endl;

  return 0;
}