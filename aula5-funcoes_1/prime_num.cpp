
#include <iostream>

int isprime(int x)
{
    bool prime {true};
    for(int i{2}; i<x/2; i++)
    {
        if (x%i ==0)
        {
            prime = false;
        }
    }
    return prime;
}

int main()
{
    std::cout << isprime(17) << std::endl;
}