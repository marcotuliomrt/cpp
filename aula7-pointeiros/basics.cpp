#include <iostream>
#include <chrono>

int main(){
    int q1 {3};  // q1 INITIALIZED with value 3
    int q2;  // 

    std::cout << "q2: " << q2 << std::endl;
    std::cout << "&q2 " << &q2 << std::endl;
    std::cout << "------------------------------"<< std::endl;
    //void *ptr = NULL; // empty pointer 

    int *ptr {&q1}; // pointer that points to q1 value = pointer value is the memory address of q1
    q2 = *ptr;  // q2 value is q1 memory address    


    std::cout << "q1: " << q1 << std::endl;
    std::cout << "&q1: " << &q1 << std::endl;
    std::cout << "ptr: " << ptr << std::endl; // stores an adress
    std::cout << "*ptr: " << *ptr << std::endl; // variable whose the address it stores
    std::cout << "q2: " << q2 << std::endl;
    std::cout << "&q2: " << &q2 << std::endl;
    std::cout << "------------------------------"<< std::endl;


    *ptr = 10;  //changing the value the pointer points to (q1)


    std::cout << "q1: " << q1 << std::endl;
    std::cout << "&q1 " << &q1 << std::endl;
    std::cout << "ptr: " << ptr << std::endl;
    std::cout << "*ptr: " << *ptr << std::endl;
    std::cout << "q2: " << q2 << std::endl;
    std::cout << "&q2: " << &q2 << std::endl;
    std::cout << "------------------------------"<< std::endl;



    int list[5];
    
    std::cout << "list: " << list << std::endl;
    std::cout << "&list " << list << std::endl;
    std::cout << "------------------------------"<< std::endl;

   
    // (*ptr).some_struct_object == ptr -> some_struct_object

}