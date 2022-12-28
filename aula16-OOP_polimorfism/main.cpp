
#include <iostream>

class Base
{
  public:
    void Method1 ()  {  std::cout << "Base::Method1" << std::endl;  }
    virtual void Method2 ()  {  std::cout << "Base::Method2" << std::endl;  }
};

class Derived : public Base
{
  public:
    void Method1 ()  {  std::cout << "Derived::Method1" << std::endl;  }
    void Method2 ()  {  std::cout << "Derived::Method2" << std::endl;  }
};




int main(){

    Base *basePtr {new Derived()}; //  Note - constructed as Derived, but pointer stored as Base*

    basePtr->Method1 ();  //  Prints "Base::Method1"
    basePtr->Method2 ();  //  Prints "Derived::Method2"

    // Base b1;
    // Derived d1;

    // b1.Method2();
    // d1.Method2();
}
