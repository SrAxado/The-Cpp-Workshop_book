// Throwing Uncaught Exceptions
#include <iostream>

using namespace std;

int deeply_nested() {
  throw 123;
  cout << "in deeply_neste() after throw" << endl;
  return 0;
}

int intermediate() {
  int rc = deeply_nested();
  cout << "in intermediate(), after deeply_nested()";
  return 0;
}

int main() {
  // throw "An exception of some type";
  intermediate();

  return 0;
}