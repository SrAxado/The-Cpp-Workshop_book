// Deleting a Dynamic Variable with delete[] instead of delete
//// COMPILE WARNING: 'delete' applied to a pointer that was allocated with new; did you mean 'delete'?
//// ERROR: 
#include <iostream>
using namespace std;

struct noisy {
  noisy() { cout << "constructing noisy" << endl; }
  ~noisy() { cout << "destryoing noisy" << endl; }
};


int main() {
  noisy* p = new noisy;

  delete[] p;

  return 0;
}