// Using a Dynamic Variable after deleting it
//// ERROR: accesses invalid memory data
#include <iostream>
using namespace std;

int main() {
  char* p = new char[10];

  p[0] = '!';

  delete[] p;

  cout << "p[0] = " << p[0] << endl;

  return 0;
}