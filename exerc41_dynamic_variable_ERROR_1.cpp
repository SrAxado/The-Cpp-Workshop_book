// Using a Dynamic Variable before creating it
//// ERROR: segmentation fault
#include <iostream>
using namespace std;

int main() {
  char* p = nullptr;

  p[10] = '!';

  return 0;
}