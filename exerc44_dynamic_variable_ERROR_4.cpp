// Overwriting a Pointer to a Dynamic Variable
//// ERROR: noisy(2) will become inaccessible but present in memory
#include <iostream>
using namespace std;

class noisy {
  int i_;

  public:
    noisy(int i): i_(i) {
      cout << "constructing noisy" << i_ << endl;
    }
    ~noisy() {
      cout << "destryoing noisy" << i_ << endl;
    }
};

int main() {
  noisy N(1);
  noisy* p = new noisy(2);
  p = new noisy(3);
  delete p;

  return 0;
}