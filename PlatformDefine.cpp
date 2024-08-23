// Platform Define.
#include <iostream>

// #define WIN_64
#define OSX

int main() {

  #ifdef WIN_64
  // Execute max specific code.
  std::cout << "We're on Windows." << std::endl;
  #else
  #ifdef OSX
  // Execute max specific code.
  std::cout << "We're on Mac." << std::endl;
  #endif
  #endif
  
}