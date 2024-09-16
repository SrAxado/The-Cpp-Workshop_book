// Deleting a Dynamic Array with delete instead of delete[]
//// COMPILE WARNING: 'delete' applied to a pointer that was allocated with new[]; did you mean 'delete[]'?
//// ERROR: abort
////// malloc: *** error for object xxxxxxxxxxx: pointer being freed was not allocated
#include <iostream>
using namespace std;

struct noisy {
  noisy() { cout << "constructing noisy" << endl; }
  ~noisy() { cout << "destryoing noisy" << endl; }
};


int main() {
  noisy* p = new noisy[3];

  delete p;

  return 0;
}