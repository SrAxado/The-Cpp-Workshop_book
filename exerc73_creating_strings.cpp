#include <iostream>
#include <string>

using namespace std;

int main() {
  // creating an empty string using the string() constructor
  string str;

  // creating a string using the C-style string(const char* s) constructor
  string str1("Hello, I'm a string!");

  // creating a string from a copy of another string with string(const string& str)
  string str2(str1);

  // creating a string from  substring of an existing string with string(const string& str, size_tpos, size_t len = npos)
  string str3(str1, 0, 5);

  // creating a string from  substring of a C-style char array with string(const char* s, size_t pos, size_t n)
  string str4("Hello, I'm a string!", 0, 5);

  // creating a string using a character and the length required with string(size_t n, char c)
  string str5(10, 'x');

  // creating a string from a substring of an existing string, but using iterators to miss out the first and last characters
  // with <class InputIterator> string(InputIterator first, InputIterator last)
  string str6(str4.begin() + 1, str4.end() - 1);
  

  cout << str << endl;
  cout << str1 << endl;
  cout << str2 << endl;
  cout << str3 << endl;
  cout << str4 << endl;
  cout << str5 << endl;
  cout << str6 << endl;


  // ASSIGNING TO STRINGS

  // creating a string from a copy of a C-style character array
  string str7 = "Hello, I'm a string!";

  // using the assignment operator, initialize the string from a copy of an existing string
  string str8 = str1;

  
  // initializing the string with a character
  string str9;
  str9 = 'x';

  cout << str7 << endl;
  cout << str8 << endl;
  cout << str9 << endl;


  // OPERATIONS ON STRINGS

  string str10("Hello, I'm a string");
  
  // pushes a character onto the end of a string
  str10.push_back('!');
  str10.push_back('!');

  cout << str10 << endl;
  // deletes the last character of a string
  str10.pop_back();
  cout << str10 << endl;

  // this will keep existing contents and append x for the rest 
  str10.resize(25, 'x');
  cout << str10 << endl;

  // changes the string's capacity to allow 50 chars
  str10.reserve(50);
  cout << str10 << endl;

  // '!' is pushed after the last char and not the end of the allocate space
  str10.push_back('!');
  cout << str10 << endl;

  // provides the current capacity of the string, which does not necessarly correspond to the size of the string
  cout << "Capacity: " << str10.capacity() << endl;
  cout << "Size: " << str10.size() << endl;

  // sets the capacity of the string to its current size
  str10.shrink_to_fit();
  // note: shrink_to_fit is not garanteed to be exactly the same as size()
  cout << "Capacity: " << str10.capacity() << endl;
  cout << "Size: " << str10.size() << endl;


  // ITERATORS

  for (string::iterator it = str10.begin(); it != str10.end(); ++it) {
    cout << *it;
  }
  cout << endl;


  for (string::reverse_iterator rit = str10.rbegin(); rit != str10.rend(); ++rit) {
    cout << *rit;
  }
  cout << endl;


  return 0;
}