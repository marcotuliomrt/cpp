#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
  
void Fun1(int *x){
    cout << "Started Fun 1" << endl;
    while(1){
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Fun 1 running undefinitely. i = " << *x << endl;
    }
    cout << "Finished Fun 1" << endl;
}

void Fun2(int y) {
    cout << "Started Fun 2 (runs for 4 seconds)" << endl;
    this_thread::sleep_for(chrono::seconds(5));
    y = 2;
    cout << "Finished Fun 2" << endl;
}

void Fun3(int *z) {
    cout << "Started Fun 3 (runs for 8 seconds)" << endl;
    this_thread::sleep_for(chrono::seconds(8));
    *z = 5;
    cout << "Finished Fun 3" << endl;
}


int main()
{
    int i{0};

    cout << "Started main" << endl;
    cout << "i=" << i << endl;
    this_thread::sleep_for(chrono::seconds(2));
    thread s1(Fun1, &i); // Inicia Fun1 em uma nova thread
    thread s2(Fun2, i); // Inicia Fun1 em uma nova thread
    thread s3(Fun3, &i); // Inicia Fun1 em uma nova thread


    s2.join(); // Aguarda terminar a thread
    s3.join(); // Aguarda terminar a thread

    s1.detach(); // Finaliza a thread 3
    cout << "Thread s3 detached" << endl;

    cout << "Finished main" << endl;
    return 0;
}