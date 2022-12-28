
#include <iostream>
#include <chrono>
#include <thread>


static bool finished =false;



void Fun1() {
    std::cout << "Started Fun 1" << std::endl;
    int i{0};
    while(!finished){
        std::cout << "Fun 1 running undefinitely. Done " << i << " times" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        i++;
    }
    std::cout << "Finished Fun 1" << std::endl;
}


int main()
{
    
    std::cout << "Started main" << std::endl;
    
    std::thread s0(Fun1); // Inicia Fun1 em uma nova thread
    
    std::cin.get(); // waits an ENTER from the user
    finished =true;

    s0.join(); // Aguarda terminar a thread
    
    std::cin.get(); // waits an ENTER from the user
    
    std::cout << "Finished main" << std::endl;
    return 0;
}