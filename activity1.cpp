#include <iostream>

#define AGE_A 18
#define AGE_B 30
#define AGE_C 60
#define AGE_D 90

void pleaseEnter(std::string info) {std::cout << "Please enter your " << info << ": ";}

void getAnswer(std::string& name) {getline(std::cin, name);}
void getAnswer(int& age) {std::cin >> age;}

int main() {

  std::string name;
  int age = 0;

  pleaseEnter("name");
  getAnswer(name);

  pleaseEnter("age");
  getAnswer(age);

  std::cout << "Welcome " << name << ". You are in Group ";
  if (age < AGE_A) {std::cout << "A.\n";}
  else if (age < AGE_B) {std::cout << "B.\n";}
  else if (age < AGE_C) {std::cout << "C.\n";}
  else if (age < AGE_D) {std::cout << "D.\n";}
  else {std::cout << "---- ERROR ---\n";}
  
  return 0;
}