#include <iostream>
#include <memory>
#include <cstring>
using namespace std;

struct noisy {
  noisy() {
    cout << "default constructing noisy" << endl;
  }
  noisy(int i) {
    cout << "constructing noisy: arg " << i << endl;
  }
  ~noisy() {
    cout << "destryoing noisy" << endl;
  }
};

int main() {
  unique_ptr<noisy> u1(new noisy);
  unique_ptr<noisy> u2;
  u2.reset(new noisy(100)); // delete the noisy dynamic variable and points u2 to nullptr

  unique_ptr<noisy[]> u3(new noisy[3]);  // unique_ptr to an array
  // u3 accepts the ownership of a dynamic variable (noisy[3]) created outside of unique_ptr<>

  // Initialize u4 to a new dynamic array of two instances
  // (the first initialized to 1 and the second default-initialized because there are not enough initializers)
  unique_ptr<noisy[]> u4(new noisy[2]{1});

  unique_ptr<noisy> u5; // u5 is default-initialized to nullptr

  cout << "before transfer of ownership of u1 = " << u1.get()
    << ", u5 = " << u5.get() << endl;
  
  // Transfer of ownership of the dynamic variable in u1 to u5
  u5.reset(u1.release());

  cout << "after transfer of ownership u1 = " << u1.get()
    << ", u5 = " << u5.get() << endl;
  
  // Transfer ownership of u5 to u1 by move semantics
  // (at the end of this statement u5 is nullptr)
  u1 = move(u5);

  cout << "after second transfer u1 = " << u1.get()
    << ", u5 = " << u5.get() << endl;
  
  unique_ptr<char[]> buf(new char[20]);
  strcpy(buf.get(), "xyzzy");
  cout << "buf = " << buf.get() << endl;

  return 0;
}

/// PROGRAM OUTPUT
///
// default constructing noisy
// constructing noisy: arg 100 -- the constructor is only called by the reset() member function
// default constructing noisy
// default constructing noisy
// default constructing noisy
// constructing noisy: arg 1
// default constructing noisy
// before transfer of ownership of u1 = 0x600003e04030, u5 = 0x0
// after transfer of ownership u1 = 0x0, u5 = 0x600003e04030
// after second transfer u1 = 0x600003e04030, u5 = 0x0
// buf = xyzzy
// destryoing noisy
// destryoing noisy
// destryoing noisy
// destryoing noisy
// destryoing noisy
// destryoing noisy
// destryoing noisy