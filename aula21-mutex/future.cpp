#include <iostream>
#include <chrono>
#include <future>
 
int factorial(std::future<int> *fN) {
    std::cout << "Future started" << std::endl;
    int res = 1;
    std::cout << "wating promise... " << std::endl;
    int N = fN->get();     // espera, dentro da thread, o vavor FN ser passado pela funcao set_value()
    for (int i=N; i>1; i--)
        res *= i;

    std::cout << "result: " << res << std::endl;
    return res;
}

int main() {
    std::cout << "Main started" << std::endl;
    
    std::promise<int> p; // promisse object
    std::future<int> fp = p.get_future(); //future object, which is gonna receive the value of the promise 

    std::future<int> fu = std::async(factorial,&fp);  // async may or may not create a new thread
    
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Alguma outra tarefa... " << std::endl;

    std::cout << "Keep the promise! " << std::endl;
    p.set_value(6);

    std::cout << "Aguarda o resultado... " << std::endl;
    int x = fu.get();

    std::cout << "Terminou... x=" << x << std::endl;

    return 0;
}