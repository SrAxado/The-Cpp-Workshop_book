// Vector example.
#include <iostream>
#include <vector>

// std::vector<int> myVector;
std::vector<int> myVector {1, 2, 3, 4, 5};
// std::vector<int> myVector(3, 1);  // (vector size, default value for all)
// std::vector<int> myVector(myArray, myArray + myArraySize);  // create vector from existing array
// std::vector<int> myVector(myVector2.begin(), myVector2.end());  // create vector from existing vector
void PrintVector() {
  for (int i = 0; i < myVector.size(); ++i) {
    std::cout << myVector[i] << " ";
  }
  std::cout << "\n\n";
}

int main() {
  myVector.pop_back();
  PrintVector();

  myVector.push_back(6);
  PrintVector();

  myVector.erase(myVector.begin() + 1);
  PrintVector();

  myVector.insert(myVector.begin() + 3, 8);
  PrintVector();

  return 0;
}