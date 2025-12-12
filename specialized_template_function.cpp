#include <iostream>
#include <string.h>

using namespace std;

// template function
template<typename T>
bool compare(T t1, T t2) { 
  return t1 == t2;
}

// since const char* is a pointer, the equality operator would only compare the pointer addresses 
// and not the content of the strings, hence the need for a specialization of the template


// specialized template function
template<>  // mind that the concrete data type is used in place of the generic T
bool compare<const char*>(const char* c1, const char* c2) {
  return strcmp(c1, c2) == 0;
}


// the same can be achieved using classes instead of functions

template <class T>
class MyClass {
  public:
    MyClass() { cout << "My class generic" << endl; }
};

template<>
class MyClass <int> {
  public:
    MyClass() { cout << "My class int specialization" << endl; }
};


const char* TRUE_STR = "TRUE";
const char* FALSE_STR = "FALSE";

int main() {
  cout << (compare(1, 1) ? TRUE_STR : FALSE_STR) << endl;
  cout << (compare("hello", "hello") ? TRUE_STR : FALSE_STR) << endl;
  cout << (compare(1, 2) ? TRUE_STR : FALSE_STR) << endl;
  cout << (compare("hello", "goodbye") ? TRUE_STR : FALSE_STR) << endl;

  MyClass<float> floatClass;
  MyClass<int> intClass;


  return 0;
}