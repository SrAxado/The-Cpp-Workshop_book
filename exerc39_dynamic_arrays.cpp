#include <iostream>
using namespace std;

struct noisy {
  noisy() { cout << "constructing noisy" << endl; }
  ~noisy() { cout << "destroying noisy" << endl; }
};


int main() {
  /*
    CREATING AND DELETING DYNAMIC ARRAYS OF BASIC TYPES
  */
  char const* cp = "arbitrary null terminated text string";
  // creates a dynamic array of type char
  char* buffer = new char[strlen(cp) + 1];

  strcpy(buffer, cp);

  cout << "buffer = " << buffer << endl;

  // deletes the dynamic array
  delete[] buffer;


  /*
    CREATING AND DELETING DYNAMIC ARRAYS OF CLASSES
  */
  // each instance in an array is constructed, that is, its constructor member function is called.
  // destroying an array of class instances calls the destructor of each instance.

  cout << "getting a noisy array" << endl;
  noisy* pnoisy = new noisy[3];

  cout << "deleting noisy array" << endl;
  delete[] pnoisy;

  return 0;
}