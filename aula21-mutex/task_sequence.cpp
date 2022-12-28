#include <iostream>
#include <chrono>
#include <future>
#include <string>
#include <thread>


/*
                 ----> Task 2  ----                      
     Task 1 ---<                    >-----> Task 4      
                 ----> Task 3  ----        
 */


void tarefa1(std::future<int> *f1, std::promise<int> *p1){
    std::cout << "Started task 1" << std::endl;
    int f1res = f1->get();

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        
    p1->set_value(f1res); // Dispara tarefas 1 e 2 (atribuindo uma valor ao promise )
}

void tarefa2(std::shared_future<int> *f2, std::promise<int> *p2){
    int f2res = f2->get();
    std::cout << "Started task 2" << std::endl;


    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    
    p2->set_value(f2res+1); // Dispara tarefas 1 e 2
}

void tarefa3(std::shared_future<int> *f3, std::promise<int> *p3){
    int f3res = f3->get();
    std::cout << "Started task 3" << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

   
    p3->set_value(f3res+1); // Dispara tarefas 1 e 2
}

int tarefa4(std::future<int> *f42, std::future<int> *f43){
    int f42res = f42->get();
    int f43res = f43->get();
    std::cout << "Started task 4" << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

  
    return f42res+f43res;
}

int main() {

    std::cout << "             ----> Task 2  ----                       " << std::endl;
    std::cout << " Task 1 ---<                    >-----> Task 4        " << std::endl;
    std::cout << "             ----> Task 3  ----                       " << std::endl;
    std::cout << " " << std::endl;



    std::srand(time(nullptr));

    // Promise para a tarefa 1
    std::promise<int> p0;
    std::future<int> f1 = p0.get_future();
    // Future da tarefa 1
    std::promise<int> p1;
    std::future<void> T1 = std::async(tarefa1, &f1, &p1);

    // Promise para as tarefa 2 e 3
    std::shared_future<int> f2 = p1.get_future();

    // Future da tarefa 2
    std::promise<int> p2;
    std::future<void> T2 = std::async(tarefa2, &f2, &p2);
    // Future da tarefa 3
    std::promise<int> p3;
    std::future<void> T3 = std::async(tarefa3, &f2, &p3);

    // Promise para a tarefa 4
    std::future<int> f42 = p2.get_future();
    std::future<int> f43 = p3.get_future();
    // Promise para a tarefa 4
    std::future<int> f4 = std::async(tarefa4, &f42, &f43);

    

    int x;
    std::cout << " Type a number: ";
    std::cin >> x; // waits an input from the user
    p0.set_value(x); // Inicia a primeira tarefa


    int y = f4.get();
    std::cout << "Result = " << y << std::endl;

    return 0;
}