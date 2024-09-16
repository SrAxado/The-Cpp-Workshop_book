#include <iostream>
using namespace std;

class noisy {
  int x_;

  public:
    noisy(int x): x_(x) {
      cout << "constructing noisy " << x_ << endl;
    }

    ~noisy() {
      cout << "destryoing noisy " << x_ << endl;
    }
};


int main() {
  noisy N(1);
  noisy* p = new noisy(2);

  delete p;


  return 0;
}