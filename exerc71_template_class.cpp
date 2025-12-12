#include <iostream>
#include <typeinfo> // in order to use the typeid(X).name() for the template

using namespace std;

template<typename T, typename U>  // multiple template parameters: T to x and y; U to z

class Position {
  public:
    Position(T x, T y, U zRot) : m_x_(x), m_y_(y), m_zRotation_(zRot) {}

    T const getX() { return m_x_; }
    T const getY() { return m_y_; }
    U const getZ() { return m_zRotation_; }

  private:
    T m_x_;
    T m_y_;
    U m_zRotation_;
};

int main() {
  Position<int, float> intPosition(1, 3, 80.0f);
  Position<float, int> floatPosition(1.5f, 3.14f, 80);
  Position<long, float> longPosition(1, 3, 80.0f);

  cout << "type: " << typeid(intPosition.getX()).name() << " X: "
    << intPosition.getX() << " Y: " << intPosition.getY() << endl;
  
  cout << "type: " << typeid(floatPosition.getX()).name() << " X: "
    << floatPosition.getX() << " Y: " << floatPosition.getY() << endl;

  cout << "type: " << typeid(longPosition.getX()).name() << " X: "
    << longPosition.getX() << " Y: " << longPosition.getY() << endl;

  cout << "type: " << typeid(intPosition.getZ()).name() << " Z Rot: "
    << intPosition.getZ() << endl;

  cout << "type: " << typeid(floatPosition.getZ()).name() << " Z Rot: "
    << intPosition.getZ() << endl;

  cout << "type: " << typeid(longPosition.getZ()).name() << " Z Rot: "
    << intPosition.getZ() << endl;
  
  return 0;
}