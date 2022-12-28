#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <random>

std::mutex m;



void SensorIOT(int *x) {
    std::unique_lock<std::mutex> lck (m);       // Trava na linha (nao roda) enquanto tiver outra instancia dela rodando
    // m.lock(); // Possibility 2 for locking
    //----------------------------------
    ++*x; // regiao critica: altera uma variavel comum a diferentes instancia ou funcoes que alteram ela tambem
    int t_sleep{std::rand()%1000}; // gera um valor aleatorio para a variavel do tempo
    std::this_thread::sleep_for(std::chrono::milliseconds(t_sleep));
    std::cout << "Atualizou... " << *x << std::endl;
    // --------------------------------- 
    lck.unclock(); // Possibility 2 for unlocking
    // m.unlock();                               // Destrava 
}

int main() 
{
    int cont{1};

    std::thread s[4];
    
    for(int i{0}; i<4; i++){
        s[i] = std::move(std::thread(SensorIOT, &cont));
    }
    
    for(int i{0}; i<4; i++){
        s[i].join();
    }

    return 0;
}