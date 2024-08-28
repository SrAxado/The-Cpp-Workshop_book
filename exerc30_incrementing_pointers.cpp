// Incrementing Pointers
#include <iostream>

int main() {
  int a[] = {10, 20, 30, 40, 50};
  int* p = nullptr;

  // Loop #1
  for (p = &a[0]; p < &a[5]; p = p + 1) {
    std::cout << *p << " ";
  }
  std::cout << std::endl;

  // Loop #2
  for (p = a; p < a + sizeof(a) / sizeof(a[0]); ++p) {
    std::cout << *p << " ";
  }
   std::cout << std::endl;

  return 0;
}