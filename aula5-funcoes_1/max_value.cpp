#include <iostream>

int main(){

    const int len {5};
    int lista[len] {3, 5, 9, 1, 6};
    int max_val;

    max_val = lista[0];
    for (int i=1; i<len; i++)
        max_val = (max_val<lista[i]) ? lista[i]:max_val;
    std::cout << max_val<< std::endl;
}