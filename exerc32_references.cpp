// References
#include <iostream>
using namespace std;

int main() {
  int i = 10;
  int& ir = i;

  cout << "i = " << i << ", ir = " << ir << endl;
  cout << "&i = " << &i << ", &ir = " << &ir << endl;

  i = i + 10;
  ir = ir * 10;

  cout << "i = " << i << ", ir = " << ir << endl;

  int* ip = &ir;
  *ip = 33;

  cout << "i = " << i << ", ip = " << ip << ", *ip = " << *ip << ", ir = " << ir << endl;

  return 0;
}