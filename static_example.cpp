// Static example.
#include <iostream>

int MySimpleInt() {
  int myInt = 0;
  return ++myInt;
}

int MyStaticInt() {
  // the static variable is only initialized once during the application,
  // and therefore maintain their value throughout
  static int myInt = 0;
  return ++myInt;
}

int main() {
  
  for (int i = 0; i < 5; ++i) {
    std::cout << MySimpleInt();
  }

  std::cout << std::endl;

  for (int i = 0; i < 5; ++i) {
    std::cout << MyStaticInt();
  }
  std::cout << std::endl;

  return 0;
}