// Deleting a Dynami Variable Twice
//// ERROR: abort
////// malloc: *** error for object xxxxxxxx: pointer being freed was not allocated
////// malloc: *** set a breakpoint in malloc_error_break to debug
#include <iostream>
using namespace std;

int main() {
  char* p = new char[10];

  delete[] p;
  delete[] p;

  return 0;
}