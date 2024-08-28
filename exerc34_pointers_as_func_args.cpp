// Pointers as Function Arguments
#include <iostream>
using namespace std;

void copychars(char* from, char* to, int count) {
  if (from == nullptr || to == nullptr) {
    return;
  }

  while (count-- > 0) {
    // the two ++ operators are post-increment: 
    // they use the variable they will increment and then increment it later as a side effect.
    *to++ = *from++;
  }
}


int main() {
  char string[] = {"uvwxyz"};
  char buffer[10];
  
  copychars(string, buffer, 7);

  cout << buffer << endl;

  return 0;
}