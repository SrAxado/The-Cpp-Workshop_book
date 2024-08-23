#include <iostream>

#define GRADE_A_THRESHOLD 75
#define GRADE_B_THRESHOLD 50
#define GRADE_C_THRESHOLD 25

int main() {

  int value = 0;

  std::cout << "Please enter test score (0 - 100): ";
  std::cin >> value;

  std::cout << "You're grade is ";
  if (value < GRADE_C_THRESHOLD) {
    std::cout << "C\n";
    std::cout << "Fail!\n";
  } else if (value < GRADE_B_THRESHOLD) {
    std::cout << "B\n";
    std::cout << "Pass\n";
  } else if (value <= 100) {
    std::cout << "A\n";
    std::cout << "Pass! Well done!!\n";
  } else {
    std::cout << "--- ERROR ---\n";
  }

  return 0;
}