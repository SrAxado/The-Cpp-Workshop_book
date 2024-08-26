// Activity 4: Fizz Buzz 
#include <iostream>

int main() {
  for (int i = 1; i < 100; ++i) {
    // ==== Solution #1 ====
    // if ((i % 3 == 0) && (i % 5 == 0)) {
    //   std::cout << "FizzBuzz, ";
    // } else if (i % 3 == 0) {
    //   std::cout << "Fizz, ";
    // } else if (i % 5 == 0) {
    //   std::cout << "Buzz, ";
    // } else {
    //   std::cout << i << ", ";
    // }
    // ==== Solution #2 =====
    if ((i % 3 == 0) || (i % 5 == 0)) {
      if (i % 3 == 0) {
        std::cout << "Fizz";
      }
      if (i % 5 == 0) {
        std::cout << "Buzz";
      }
    } else {
      std::cout << i;
    }
    std::cout << ", ";
  }
  
  std::cout << "Buzz" << std::endl; // 100 is multiple of 5
  // this isolated last statement was to save multiple comparisons 
  // to check if it was the last element (100)

  return 0;
}