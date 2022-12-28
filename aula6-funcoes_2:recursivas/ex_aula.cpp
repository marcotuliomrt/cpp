#include<iostream>
#include<math.h>





// Ex 1: somatorio de 1 a N
int somatorio(int num){
    int soma{0};
    for(int i{num}; i>0; i--){
        soma += i;
    }

    return  soma;
}



int somatorio_rec(int num){
    if(num<=0){
        return num;
    }
    return num + somatorio_rec(num - 1);
}


// Ex 2
int eleva_rec(int num, int exp){
    if(exp<=1){
        return num;
    }
    return num*eleva_rec(num, exp-1);
}


// Ex 3
int mdc_rec(int x, int y){

    if (x == y){
        return x;
    }
    if (x<y){
        return mdc_rec(y-x, x);
    }
    else{
        return mdc_rec(x-y, y);
    }

}

// Ex extra: Fibonacci

int fib(int idx){
    if(idx<=1)
        return idx;
    else{
        return fib(idx-1) + fib(idx-2) ;
    }
}





int main(){
    int x{4};
    // std::cout << somatorio(x) << std::endl;
    // std::cout << somatorio_rec(x) << std::endl;
     std::cout << eleva_rec(2, 8) << std::endl;
    // std::cout << mdc_rec(20, 8) << std::endl;
    //std::cout << fib(3) << std::endl;
}
