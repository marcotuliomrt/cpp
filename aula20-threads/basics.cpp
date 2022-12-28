#include <iostream>
#include <chrono>
#include <thread>

// Esse roda as 2 funcoes simultaneamente sem nenhum mecanismo de exclusao mutua, entao as duas podem printar coisas SIMULTANEAMENTE
// no terminal (com tempo = 2s da pra ver o problema) -> solucao esta na proxima aula

void Fun1() {
    std::cout << "Started Fun 1 on the thread id= " << std::this_thread::get_id() << std::endl;
    int i{1};
    while(1){
        std::cout << "Fun 1 running undefinitely. Done " << i << " times" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        i++;
    }
}

void Fun2() {
    std::cout << "Started Fun 2 on the thread id= " << std::this_thread::get_id() << std::endl;
    for(int i{6}; i>0; i--){
        std::cout << "Fun 2 running for " << i << " more times" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}


int main()
{
    std::cout << "Started main thread on the id= " << std::this_thread::get_id() << std::endl;
    //this_thread::sleep_for(chrono::seconds(5));
    std::thread s1(Fun1); // Inicia Fun1 em uma nova thread
    std::thread s2(Fun2);


    s2.join(); // Aguarda terminar a thread s2

    //s1.join(); // Aguarda terminar a thread s1 // (como ela so tem um while(1), n termina)
    s1.detach();  // finaliza a thread s1
    

    std::cout << "Finished main" << std::endl;
    return 0;
}