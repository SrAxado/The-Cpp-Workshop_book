// if/else exercise
#include <iostream>
using namespace std;

int main() {
  string input;
  int number;

  cout << "Menu\n";
  cout << "1: Fries\n";
  cout << "2: Burger\n";
  cout << "3: Shake\n";

  cout << "Please enter a number (1 - 3) to view an item price: ";
  getline(cin, input);
  number = stoi(input);

  if (number == 1) {
    cout << "Fries: $0.99\n";
  } else if (number == 2) {
    cout << "Burger: $1.25\n";
  } else if (number == 3) {
    cout << "Shake: $1.50\n";
  } else {
    cout << "Invalid choice.\n";
  }


  return 0;
}