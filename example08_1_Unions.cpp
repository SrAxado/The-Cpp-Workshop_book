// Unions example
#include <iostream>
using namespace std;

union Backpack {
  int contents[7];
  struct {
    int food, water, key, flashlight;
  } data;
  int simple_int, simple_int_2;
  int other_int;
  
  int int_data[];
  char alphabet[];
};

void DisplayContents(Backpack& backpack) {
  cout << "Food = " << backpack.data.food << endl;
  cout << "Water = " << backpack.data.water << endl;
  cout << "Key = " << backpack.data.key << endl;
  cout << "Flashlight = " << backpack.data.flashlight << endl;
}

void UpdateBackpack(Backpack& backpack, int contents[7]) {
  for (int i = 0; i < 7; ++i) {
    backpack.contents[i] = contents[i] > backpack.contents[i] ? contents[i] : backpack.contents[i];
  }
}

void RemoveFromBackPack(Backpack& backpack, int idx) {
  backpack.contents[idx] = 0;
}

int main () {
  Backpack camping;

  camping.data.food = 10;
  camping.data.key = 30;

  int coiso[7] {100, 200, 127, 400, 500, 600, 700};
  UpdateBackpack(camping, coiso);

  for (int i = 0; i < 7; ++i) {
    cout << camping.contents[i] << endl;
  }


  DisplayContents(camping);

  cout << camping.simple_int << endl;
  cout << camping.simple_int_2 << endl;
  cout << camping.other_int << endl;

  camping.alphabet[0] = 'f';
  camping.alphabet[1] = 'o';
  camping.alphabet[2] = 'i';

  cout << camping.int_data[2] << endl;

  cout << camping.alphabet << endl;

  return 0;
}

// OUTPUT
// 
// 100
// 32760
// 127
// 400
// 500
// 32759
// 1481363536
// Food = 100
// Water = 32760
// Key = 127
// Flashlight = 400
// 100
// 100
// 100
// 127
// foi