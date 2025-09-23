// Type casting
#include <iostream>

class MyClassA {
  public:
    int myInt = 0;
    virtual void func() = 0; // a virtual function to allow dynamic down-casting
};

class MyClassB: public MyClassA {
  public:
    std::string myString = "";
    void func() override {
      std::cout << "This function only exists to allow dynamic down-casting" << std::endl;
    }

};


int main() {
  MyClassA* myClass = new MyClassB();
  std::cout << myClass->myInt << std::endl;
  // myClass being a MyClassA, one can't access member from MyClassB
  // std::cout << myClass->myString << std::endl; 

  // Static Cast
  // static_cast<type_to_cast_to*>(object_to_cast_from);
  MyClassB* myClassB = static_cast<MyClassB*>(myClass);
  std::cout << myClassB->myString << std::endl; // this way we can access the myString member

  // Dynamic Cast
  // dynamic_cast<type_to_cast_to*>(object_to_cast);
  // --> For dynamic_cast to work when down-casting, the base class must contain at least one virtual function.
  // error: (source type is not polymorphic)
  // MyClassB* myClassB = dynamic_cast<MyClassB*>(myClass);
  myClassB = dynamic_cast<MyClassB*>(myClass);

  // C-Style Cast
  // (type_to_cast_to *) object_to_cast
  // MyClassB* myClassB = (MyClassB*)myClass;
  myClassB = (MyClassB*)myClass;
  std::cout << myClassB->myString << std::endl; //since myClass is a MyClassB type object, this cast is OK
  
  delete myClass;
  myClass = nullptr;
  delete myClassB;
  myClassB = nullptr;
}