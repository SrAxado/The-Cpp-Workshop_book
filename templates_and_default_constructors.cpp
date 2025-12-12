#include <iostream>
using namespace std;

template<typename T>
class Position {
  public:
    Position(T x, T y) : m_x_(x), m_y_(y) {
      cout << "Position: (" << m_x_ << ", " << m_y_ << ")" << endl;
    }

    Position(const T& t) : m_x_(t.m_x_), m_y_(t.m_y_) {}

    T const getX() { return m_x_; }

    T const getY() { return m_y_; }

  private:
    T m_x_;
    T m_y_;
};

template<class T>
class PositionHolder {
  public:
    PositionHolder() {}
    
    template<typename U>
    PositionHolder(U x, U y) : m_position_(x, y) {}
    
    PositionHolder(const T& t) : m_position_(t) {}


    T getPosition() { return m_position_; }

  private:
    T m_position_;
};




int main() {
  
  //// PositionHolder<Position<float>> positionHolder;

  // error: constructor for 'PositionHolder<Position<float>>' must explicitly initialize the member 'm_position_' 
  // which does not have a default constructor



  // one option to fix this error is to make the PositionHolder constructor a template function that pass the values
  // of the correct type to the constructor of Position<T>

  //// PositionHolder<Position<float>> positionHolder(20.0f, 30.0f);
  
  // creating PositionHolder now requires passing in th values of the variables that the T parameter requires in its constructor.
  // Essentially, we now give PositionHolder the responsability of passing appropriate values to the constructor T


  PositionHolder<Position<float>> positionHolder(Position<float>(20.0f, 30.0f));


  return 0;
}