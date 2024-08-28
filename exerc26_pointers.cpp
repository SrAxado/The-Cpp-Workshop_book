// Pointers and References
#include <iostream>

int main() {
  int i = 12345;
  int *p = &i;

  std::cout << "p = " << p << ", &i = " << &i << std::endl;
  std::cout << "i = " << i << ", *p = " << *p << std::endl;

  *p = *p + 2;

  std::cout << "i = " << i << std::endl;

  return 0;
}