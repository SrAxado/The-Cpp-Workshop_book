#include <iostream>
#include <vector>

using namespace std;


// determines if a value exists or not in a vector
bool contains(const int value, const vector<int>& vec) {
  return (find(vec.begin(), vec.end(), value) != vec.end());
}

// returns the index of the element within the vector
long idxContains(const int value, const vector<int>& vec) {
  vector<int>::const_iterator it = find(vec.begin(), vec.end(), value);

  if (it != vec.end()) {  // the element is found
    return distance(vec.begin(), it);
  }
  
  return -1;
}

template<typename T>
long idxTContains(const T& value, const vector<T>& vec) {
  auto it = find(vec.begin(), vec.end(), value);

  if (it != vec.end()) {  // the element was found
    return distance(vec.begin(), it);
  }
  return -1;
}


int main() {
  // create vector vec and prefill it with some values using the initializer list constructor
  vector<int> vec = {1,2,3,4,5,6,7,8,9,10};

  // iterating over the elements in the container
  for (auto v : vec) {
    cout << v << " ";
  }
  cout << endl;

  // acessing an element in the vec vector
  cout << vec[3] << endl;

  const int numToCheck = 9;

  // using the contains() to determine if numToCheck exists or not
  cout << "Vector contains " << numToCheck << "? " << (contains(numToCheck, vec) ? "YES" : "NO") << endl;

  // using the idxContains() to determine if numToCheck exists and in which position of the vector exists at
  long index = idxContains(numToCheck, vec);
  cout << "Vector contains " << numToCheck << "? " << (index != -1 ? "YES" : "NO");
  if (index != -1) {
    cout << " and its index is " << index;
  }
  cout << endl;

  // using the idxContains() to determine if numToCheck exists and in which position of the vector exists at
  long indexT = idxTContains(numToCheck, vec);
  cout << "Vector contains " << numToCheck << "? " << (indexT != -1 ? "YES" : "NO");
  if (indexT != -1) {
    cout << " and its index is " << indexT;
  }
  cout << endl;


  return 0;
}

/*
OUTPUT:

1 2 3 4 5 6 7 8 9 10 
4
Vector contains 9? YES
Vector contains 9? YES and its index is 8
Vector contains 9? YES and its index is 8

*/