// Activity 5: Using Pointers and References to Manipulate an Array of Strings
#include <iostream>
using namespace std;

char const* alphabet[26] {
  "alpha",
  "bravo",
  "charlie",
  "delta",
  "echo",
  "foxtrot",
  "gama"
};

int printarray(char const** first, char const** oneAfterLast, int& count) {
  // if (*first == nullptr || *oneAfterLast != nullptr) {  // the simplest of protections
  if (first == nullptr || oneAfterLast == nullptr || first > oneAfterLast || 
    oneAfterLast - first > 26) {
    return 0;
  }

  count = 0;

  cout << endl;
  for (auto entry = first; entry < oneAfterLast; ++entry) {
    if (*entry != nullptr) {
      cout << *entry << endl;
      ++count;
    }
  }
  return 1;
}

int main() {
  int nonNullEntries = 3;
  int arraySize = sizeof(alphabet)/sizeof(*alphabet);

  // cout << alphabet << endl;

  if (printarray(alphabet, &alphabet[arraySize], nonNullEntries)) {
    cout << endl << "All went well!" << endl;
    cout << "Count non-nulls: " << nonNullEntries << endl;
  } else {
    cout << "Error: problem with the arguments" << endl;
  };

  cout << endl;


////////////    Test Array    ////////////

  if (printarray(nullptr, nullptr, nonNullEntries) == 0 || nonNullEntries != 0) {
    cout << "Error in printarray(): test #1" << endl;
  } else {
    cout << "Test #1" << endl;
  }

  if (printarray(alphabet, &alphabet[4], nonNullEntries) == 0 || nonNullEntries != 4) {
    cout << "Error in printarray(): test #2" << endl;
  } else {
    cout << "Test #2" << endl;
  }

  if (printarray(&alphabet[4], &alphabet[3], nonNullEntries) == 0 || nonNullEntries != 0) {
    cout << "Error in printarray(): test #3" << endl;
  } else {
    cout << "Test #3" << endl;
  }
  
  if (printarray(&alphabet[4], &alphabet[10], nonNullEntries) == 0 || nonNullEntries != 1) {
    cout << "Error in printarray(): test #4" << endl;
  } else {
    cout << "Test #4" << endl;
  }

  if (printarray(&alphabet[0], &alphabet[100], nonNullEntries) == 0 || nonNullEntries != 0) {
    cout << "Error in printarray(): test #5" << endl;
  } else {
    cout << "Test #5" << endl;
  }

  return 0;
}