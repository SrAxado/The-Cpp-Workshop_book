// References as Function Arguments
#include <iostream>
using namespace std;

struct mydata {
  char const* name_;
  bool darkside_;
  mydata(char const* name, bool dark) : name_(name), darkside_(dark) {};
};

void printname(mydata& data) {
  cout << "Hello. I am " << data.name_ << endl;
  if (data.darkside_) {
    cout << "I was seduced by the dark side" << endl;
  }
}

int main() {
  mydata cast[] {
    {"Darth Vader", true},
    {"Luke Skywalker", false},
    {"Han Solo", false}
  };

  // for (mydata& data : cast) {
  for (auto& data : cast) {
  // for (auto data : cast) { // less efficient, because it copies elements of the array into data
    printname(data);
  }

  return 0;
}