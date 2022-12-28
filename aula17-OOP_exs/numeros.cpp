#include <iostream>



class Q {
    friend std::ostream &operator<<(std::ostream &os, const Q &rhs);
    private:
        MDC();
    public:
        int n;
        int d;
        // Constructors and destructors
        Q();
        Q(int n_val);
        Q(int n_val, int d_val);
        ~Q();
        // Operators
      
        

};



Q::Q();
Q::Q(int n_val);
Q::Q(int n_val, int d_val);

int G::MDC(){
    int x = this->n;
    int y = this->d;

    if (x == y){
        return x;
    }
    if (x<y){
        return MDC(y-x, x);
    }
    else{
        return MDC(x-y, y);
    }

}

Q operator+(const Q &)

int main(){
    Q x{}
}