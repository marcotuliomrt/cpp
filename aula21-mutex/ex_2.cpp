
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <random>


std::mutex m;

void doUnsynchronizedWork(){ // like calculating stuff, ...
    for(int i{0}; i<5; i++){
        std::cout << "Unsynchronized Work being executed. # = " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    }
}

void doSynchronizedWork(){  // like printing stuff, changing variables otside the function 
    for(int i{0}; i<5; i++){
        std::cout << "Synchronized Work being executed. # = " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    }
}


void foo() {
    std::unique_lock lock(m, std::try_to_lock);
    if (!lock) {
        doUnsynchronizedWork();
        
        lock.lock();
        doSynchronizedWork();
        lock.unlock();
        // Continua...
    } 
    else {
        doSynchronizedWork();
        lock.unlock();
        doUnsynchronizedWork();
        // Continua...
    }
}

int main(){
    std::thread s[4];
    
    for(int i{0}; i<4; i++){
        s[i] = std::move(std::thread(foo));
    }
    
    for(int i{0}; i<4; i++){
        s[i].join();
    }

    return 0;
}