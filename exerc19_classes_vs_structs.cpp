// Classes / Structs
// Classes Accessibility Modifiers
#include <iostream>

class MyClass {
  public: // by default the accessibility in a class is "private"
    int myInt = 0;
    bool myBool = false;

    std::string GetString() {
      return "Hello World!";
    }
};


struct MyStruct {
  // by default the accessibility in a struct is "public"
  int myInt = 0;
  bool myBool = false;

  std::string GetString() {
    return "Hello World!";
  }
};


class MyClassModifiers {
  public: // available to all
    MyClassModifiers() {
      std::cout << "My Class Constructor Called\n";
      myPublicInt = 5;
    }

    ~MyClassModifiers() {
      std::cout << "My Class Destrctor Called\n";
    }

    int myPublicInt = 0;

  protected:  // available to the object and children
    int myProtectedInt = 0;

  private:  // available only to the object
    int myPrivateInt = 0;
};


int main() {
  MyClass classObject;

  // error: 'int MyClass::myInt/myBool/GetString()' is private
  // involving the members with the acccess modifier public will fix the problem
  std::cout << "classObject::myInt -- " << classObject.myInt << std::endl;
  std::cout << "classObject::myInt -- " << classObject.myBool << std::endl;
  std::cout << "classObject::myInt -- " << classObject.GetString() << std::endl;

  MyStruct structObject;

  std::cout <<"structObject::myInt -- " << structObject.myInt << std::endl;
  std::cout <<"structObject::myBool -- " << structObject.myBool << std::endl;
  std::cout <<"structObject::GetSring() -- " << structObject.GetString() << std::endl;

  {
    /* data */
  };
  

  
  MyClassModifiers testClass;

  std::cout << testClass.myPublicInt << std::endl;
  // std::cout << testClass.myProtectedInt << std::endl; // error: 'int MyClass::mProtectedInt' is protected
  // std::cout << testClass.myPrivateInt << std::endl; // error: 'int MyClass::mPrivatedInt' is private

  return 0;
}