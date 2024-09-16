// Not deleting Dynamic Variable
//// ERROR: the storage occupied by the variable will become inaccessible to the program;
// that is, the memory will leak from the program; sending the computer to the hell of memory exhaustion.
#include <iostream>
using namespace std;

int main() {
  char* p = new char[10];

  p[0] = '!';

  cout << "p[0] = " << p[0] << endl;

  return 0;
}