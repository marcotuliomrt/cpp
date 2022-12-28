#include <thread>
#include <iostream>
#include <chrono>



bool testa_primo(int x){
    for (int i{2}; i<x/2; ++i)
        if (x%i == 0 )
            return false;
    return true;
}

void conta_primo(int i0, int i1, int *n){
    for (int i{i0}; i<=i1; ++i)
        if (testa_primo(i))
            ++(*n);
}
  
int main()
{
    using namespace std::chrono;

  	high_resolution_clock::time_point t1, t2;
    duration<double, std::milli> time_span;
    
    //------------------ Not using threads ----------------------------

    t1 = high_resolution_clock::now();
    int quant{0};
    conta_primo(100000,500000, &quant);
    t2 = high_resolution_clock::now();
    
    std::cout << "quantidade de nÃºmeros primos entre 10000 e 50000: "
        << quant << std::endl;

    time_span = t2 - t1;
    std::cout << "Elapsed time: " << time_span.count() << " ms" << std::endl;

    //------------------ Using threads ----------------------------

   std::this_thread::sleep_for(std::chrono::seconds(5));

    t1 = high_resolution_clock::now();
    int quant1{0},quant2{0},quant3{0},quant4{0};
    std::thread th1(conta_primo, 100000, 200000, &quant1);
    std::thread th2(conta_primo, 200000, 300000, &quant2);
    std::thread th3(conta_primo, 300000, 400000, &quant3);
    std::thread th4(conta_primo, 400000, 500000, &quant4);

    th1.join();
    th2.join();
    th3.join();
    th4.join();

    t2 = high_resolution_clock::now();
    
    std::cout << "quantidade de nÃºmeros primos entre 10000 e 50000: "
        << quant1+quant2+quant3+quant4 << std::endl;

    time_span = t2 - t1;
    std::cout << "Elapsed time: " << time_span.count() << " ms" << std::endl;


    return 0;
}