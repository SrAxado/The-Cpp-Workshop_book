#include <iostream>
#include <memory>
#include <cstring>
using namespace std;

struct noisy {
  noisy() { cout << "constructing noisy" << endl; }
  ~noisy() { cout << "destryoing noisy" << endl; }
};

class autobuf {
  unique_ptr<noisy> np_;
  unique_ptr<char[]> ptr_;
  public:
    autobuf(char const* str);
    char* get();
};


int main() {
  autobuf buffer("My favorite test string.");
  cout << "Hello World! " << buffer.get() << endl;

  return 0;
}

autobuf::autobuf(char const* str)
  : np_(make_unique<noisy>()),
    ptr_(make_unique<char[]>(strlen(str) + 1))
{
  strcpy(ptr_.get(), str);
}

char* autobuf::get() {
  return ptr_.get();
}