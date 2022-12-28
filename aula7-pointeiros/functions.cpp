
#include <iostream>



// -------- pointer as parameter ---------------------
// The value of using pointers on functions is that you can alter the original variable (without creating copies)
// Parameters are pointers and the arguments must be memory addresses


void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;

}




//------------ returning a pointer -----------------------

int *get_bigger(int *ptr_1, int *ptr_2 ){
    if(*ptr_1 > *ptr_2){
        return ptr_1;
    }
    else{
        return ptr_2;
    }
}


void maisum(int *&x){
    *x =*x +1;
    x = new int;
}






int main()
{
    int a{1};
    int b{3};

    std::cout << "x= " << a << ", y= " << b << std::endl;
    std::cout << "After swap:" << std::endl;
    swap(&a, &b);
    std::cout << "x= " << a << ", y= " << b << std::endl;


}