// Exceptions Thrown by C++
#include <iostream>
#include <exception>
#include <string>

using namespace std;

int deeply_nested() {
  // will initialize a string and ask for its 100th character, throwing an exception
  string("xyzzy").at(100);
  return 0;
}


int main() {

  try {
    deeply_nested();
  }
  catch(exception& e) {
   cout << "caught " << e.what() << endl; 
  }
  catch (...) {
    cout << "in catch ..." << endl;
  }

  cout << "in main(), after try/catch" << endl;

  return 0;
}

/* OUTPUT:

caught basic_string
in main(), after try/catch

*/

