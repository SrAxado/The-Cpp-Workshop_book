// Polymorphism
#include <iostream>

class MyClassA {
  public:
    virtual std::string GetString() = 0;
};

class MyClassB: public MyClassA {
  public:
    std::string GetString() override {
      return "Hello ";
    }
};

class MyClassC: public MyClassA {
  public:
    std::string GetString() override {
      return "world!";
    }
};


int main() {
  MyClassA* myClass = new MyClassB();
  std::cout << myClass->GetString();
  myClass = new MyClassC();
  std::cout << myClass->GetString();

  delete myClass;
  myClass = nullptr;
}

/*
Since these objects share that common base class, MyClassA, we can store
them in a pointer to this type (MyClassA*) and access any members declared in that
base class. When we call them, however, we get their derived implementations.
*/