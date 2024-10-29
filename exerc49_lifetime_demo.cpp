#include <iostream>
using namespace std;

class noisy {
  char const* s_;
  public:
    noisy(char const* s) {
      cout << "constructing " << s << endl;
      s_ = s;
    }

    ~noisy() {
      cout << "destroying " << s_ << endl;
    }
};

void func(char const* s) {
  noisy func(s);
}

noisy f("global 1");
noisy ff("global 2");

int main() {
  noisy n1("main() function local 1");

  func("function local 2");

  {
    noisy n("block local");
    func("function local 3");
  }

  return 0;
}

/// PROGRAM RESULT
///
// constructing global 1
// constructing global 2
// constructing main() function local 1
// constructing function local 2
// destroying function local 2
// constructing block local
// constructing function local 3
// destroying function local 3
// destroying block local
// destroying main() function local 1
// destroying global 2
// destroying global 1
