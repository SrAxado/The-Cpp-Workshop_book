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

  cout << "The size of a bool is " << sizeof(myBool) << " bytes.\n";
  cout << "The size of an int is " << sizeof(myInt) << " bytes.\n";
  cout << "The size of an unsigned int is " << sizeof(myUnsignedInt) << " bytes.\n";
  cout << "The size of a short int is " << sizeof(myShortInt) << " bytes.\n";
  cout << "The size of a short unsigned short int is " << sizeof(myUnsignedShortInt) << " bytes.\n";
  cout << "The size of a long int is " << sizeof(myLongInt) << " bytes.\n";
  cout << "The size of an unsigned long int is " << sizeof(myUnsignedLongInt) << " bytes.\n";
  cout << "The size of a char is " << sizeof(myChar) << " bytes.\n";
  cout << "The size of an unsigned char is" << sizeof(myUnsignedChar) << " bytes.\n";
  cout << "The size of a float is " << sizeof(myFloat) << " bytes.\n";
  cout << "The size of double is " << sizeof(myDouble) << " bytes.\n";

  return 0;
}