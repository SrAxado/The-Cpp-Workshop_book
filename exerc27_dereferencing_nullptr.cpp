// Dereferencing nullptr
#include <iostream>

int main() {
  int *p1 = nullptr;
  std::cout << "p1 = " << p1 << std::endl;  // error: segmentation fault
  
  *p1 = 22;
  std::cout << "*p1 = " << *p1 << std::endl;  // error: segmentation fault

  return 0;
}