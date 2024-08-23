// switch exercise
#include <iostream>
using namespace std;

int main() 
{
  string input;
  int number;
  bool bIsRunning = true;

  while (bIsRunning) {

    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
    cout << "Menu\n";
    cout << "1: Fries\n";
    cout << "2: Burger\n";
    cout << "3: Shake\n";

    cout << "Please enter a number (1 - 3) to view an item price: ";
    getline(cin, input);
    number = stoi(input);

    switch (number) {
      case 1:
        cout << "Fries: $0.99\n";
        break;
      case 2:
        cout << "Burger: $1.25\n";
        break;
      case 3:
        cout << "Shake: $1.50\n";
        break;
      default:
        cout << "Invalid choice.\n";
        cout << "Exiting\n";
        bIsRunning = false;
        break;
    }
  }


  return 0;
}