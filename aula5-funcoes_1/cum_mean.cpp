#include <iostream>
#include <cstdint>
#include <vector>

std::vector <double> cum_mean(std::vector <double> &list, int n) // pass by reference --> "&"
{
    //int n = sizeof(list)/sizeof(int);
    std::vector <double> y_barra (n);
    y_barra[0] = list[0];
    for (int i {1}; i<n; i++)
        {   
            y_barra[i] = (y_barra[i-1]*(i) + list[i])/(i+1);
            //std::cout << y_barra[i] << std::endl;
        }
return y_barra;
}

int main()
{
    std::vector <double> y {3,2,1,6,4,2,1,0};

    size_t len {y.size()};
    std::vector <double> result = cum_mean(y, len);
    for (int i {0}; i<(len-1); i++)
        std::cout << result[i] << std::endl;



  
}

