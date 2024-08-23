#include <iostream>
using namespace std;

int main() {
  bool myBool = false;
  int myInt = 1;
  unsigned int myUnsignedInt = 1;
  short int myShortInt = 1;
  unsigned short int myUnsignedShortInt = 1;
  long int myLongInt = 1;
  unsigned long int myUnsignedLongInt = 1;
  char myChar = 'a';
  unsigned char myUnsignedChar = 'a';
  float myFloat = 1.0;
  double myDouble = 1.0;

  cout << "The size of a bool is " << sizeof(myBool) << ".\n";
  cout << "The size of an int is " << sizeof(myInt) << ".\n";
  cout << "The size of an unsigned int is " << sizeof(myUnsignedInt) << ".\n";
  cout << "The size of a short int is " << sizeof(myShortInt) << ".\n";
  cout << "The size of a short unsigned short int is " << sizeof(myUnsignedShortInt) << ".\n";
  cout << "The size of a long int is " << sizeof(myLongInt) << ".\n";
  cout << "The size of an unsigned long int is " << sizeof(myUnsignedLongInt) << ".\n";
  cout << "The size of a char is " << sizeof(myChar) << ".\n";
  cout << "The size of an unsigned char is" << sizeof(myUnsignedChar) << ".\n";
  cout << "The size of a float is " << sizeof(myFloat) << ".\n";
  cout << "The size of double is " << sizeof(myDouble) << ".\n";

  return 0;
}