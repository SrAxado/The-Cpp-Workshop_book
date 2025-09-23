#include <iostream>
#include <string>

class MyClassA {
  protected:
    int myInt;
};

class MyClassB: public MyClassA {

};

class MyClassC: public MyClassA {

};

class MyClassD: public MyClassB, public MyClassC {
  MyClassD() {
    // myInt = 1; // "MyClassD::myInt" is ambiguous
    MyClassB::myInt = 1; // one way to solve the problem: qualifying which version of myInt to use
  }
};


int main() {


}

/*

We can see that MyClassB and MyClassC both inherit from MyClassA.
MyClassD then goes to inherit from both MyClassB and MyClassC. This results in
MyClassD having two copies of everything within MyClassA as it was instantiated
twice, once from MyClassB and once from MyClassC.

*/