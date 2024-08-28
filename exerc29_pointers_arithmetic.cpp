// Pointers Arithmetic
#include <iostream>
using namespace std;

int main() {
  int numbers[5] = {0, 100, 200, 300, 400};
  int* pint = numbers;
  int* p2 = &numbers[3];

  cout << "pint = " << pint << ", pint+1 = " << pint + 1 << ", sizeof(int) = " << sizeof(int) << endl;

  cout << "*(pint + 1) = " << *(pint + 1) << ", pint[1] = " << pint[1] << endl;
  cout << "*(pint + 3) = " << *(pint + 3) << ", pint[3] = " << pint[3] << "p" << ", *p2 = " << *p2 << endl;

  cout << "p2 - pint = " << p2 - pint << endl;

  cout << "(p2 == pint) = " << boolalpha << (p2 == pint) << endl;
  cout << "(p2 > pint) = " << boolalpha << (p2 > pint) << endl;
  cout << "(p2 == (pint + 3)) = " << boolalpha << (p2 == (pint + 3)) << endl;
  
  cout << "(&a[1] == (pint + 1)) = " << boolalpha << (&numbers[1] == (pint + 1)) << endl;

  return 0;
}