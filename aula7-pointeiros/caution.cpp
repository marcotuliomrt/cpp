#include <iostream>
#include <chrono>

int main(){
 
    int q1 {3};
    int q2 {4};
    const int *ptr_1 {&q1}; // Protects the content

    std::cout << "ptr_1: " << ptr_1 << std::endl;
    std::cout << "const int *ptr_1: " << *ptr_1 << std::endl;
    std::cout << "------------------------------"<< std::endl;

    //*ptr_1 = 5;  -> ERROR  -> cant change the value it points to
    ptr_1 = &q2;

    std::cout << "ptr_1: " << ptr_1 << std::endl;
    std::cout << "*ptr_1: " << *ptr_1 << std::endl;
    std::cout << "------------------------------"<< std::endl;




    int q3 {5};
    int *const ptr_2 {&q3}; // Protects the address

    std::cout << "ptr_2: " << ptr_2 << std::endl;
    std::cout << "int const *ptr_2: " << *ptr_2 << std::endl;
    std::cout << "------------------------------"<< std::endl;

    *ptr_2 = 8;
    // prt_2 = &q3;  // -> ERROR  -> cant change the memory address it holds

    std::cout << "ptr_2: " << ptr_2 << std::endl;
    std::cout << "int const *ptr_2: " << *ptr_2 << std::endl;
    std::cout << "------------------------------"<< std::endl;


}