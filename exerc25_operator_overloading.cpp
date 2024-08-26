// Operator Overloading Example.
#include <iostream>

class Person {
  float age = 0;
  std::string name = "";
  
  public:
    Person(int age, std::string name) : age(age), name(name) {};

    bool operator == (Person const& other) {
      return ((age == other.age) && (name == other.name));
    }

    bool operator != (Person const& other) {
      std::cout << "I just like being different!" << std::endl;
      return false;
    }
};


int main() {
  Person personA = Person(27, "Lucy");
  Person personB = Person(27, "Lucy");
  Person personC = Person(27, "Susan");

  std::cout << (personA == personB) << std::endl;
  std::cout << (personB == personC) << std::endl;

  std::cout << !(personB == personC) << std::endl;

  std::cout << (personA != personB) << std::endl;
  
  return 0;
}