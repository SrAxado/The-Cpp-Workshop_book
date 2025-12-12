// USING A SET TO GET THE NUMBER OF UNIQUE ELEMENTS IN A MULTISET
// Since a set does not allow non-unique elements, we will use it to determine the unique elements of a multiset
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
  set<int> intSet;
  multiset<int> intMultiSet;

  for (unsigned int i = 0; i < 100; ++i) {
    intMultiSet.insert(1 + rand() % 100);
  }

  // for (auto i : intMultiSet) {
  //   cout << i << " ";
  // }

  for (auto i : intMultiSet) {
    intSet.insert(i);
  }

  cout << "There are " << intSet.size() << " unique elements in the " 
    << intMultiSet.size() << " elements multiset" << endl;

  return 0;
}