// Bad References
#include <iostream>

// this function returns a reference to a local variable on the function call stack
// The variable goes out of scope and will become invalid when the function returns,
// producing an invalid reference
// The program won't necessarily crash, but it wont' reliably produce a correct answer either.
int& invalid_ref() {
  int a = 10;
  return a;
}


int main() {
  char* p = nullptr;
  char& r = *p;

  // r = '!'; // Error: segmentation fault
    // p pointer points to nullptr -> reference r is set to point to nullptr
    // dereferencing nullptr will cause the OS to stop the program

    int& a = invalid_ref();

    std::cout << "&a = " << &a << ", a = " << a << std::endl;

  return 0;
}