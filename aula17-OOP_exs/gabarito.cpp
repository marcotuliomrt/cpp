#include <iostream>
#include <string>
#include <vector>
#include <chrono>



class Q{
    friend std::ostream &operator<<(std::ostream &os, const Q &rhs);
    friend Q operator+(const Q &lhs, const Q &rhs);
    friend Q operator*(const Q &lhs, const Q &rhs);
    friend Q operator/(const Q &lhs, const Q &rhs);
   
    private:
        int MDC();
        void simplify();
    public:
        long int n;
        long int d;
        // Constructors and destructors
        Q();
        Q(long int n_val);
        Q(long int n_val, long int d_val);
        ~Q();
  

        Q operator+=(const Q &rhs);
   
};

Q::Q():n{0}, d{1} {};
Q::Q(long int n_val): n{n_val}, d{1} {};
Q::Q(long int n_val, long int d_val): n{n_val}, d{d_val} {
    simplify();
};
Q::~Q(){};

int Q::MDC(){
    long int x{abs(n)},y{abs(d)}, temp;
    while (x != y) {
        if (x>y) {
            x = x-y;
        }
        else if (x<y) {
            temp = x;
            x = y;
            y = temp;
        }  
    }
    return y;
}

void Q::simplify(){
    int mdc{MDC()};
    n = n/mdc;
    d = d/mdc;

    if (d<0) { // MantÃ©m o denominador positivo
        n = -n;
        d = -d;
    }
}

std::ostream &operator<<(std::ostream &os, const Q &rhs){
    if (rhs.d == 1){
        os << rhs.n;
    } else {
        os << rhs.n << "/" << rhs.d;
    }

    return os;
};

Q operator+(const Q &lhs, const Q &rhs){
    Q temp;
    temp.n = lhs.n*rhs.d + rhs.n*lhs.d;
    temp.d = lhs.d*rhs.d;
    temp.simplify(); // simplify Ã© um mÃ©todo private, mas esse mÃ©todo Ã© friend
    return temp;
};


Q operator*(const Q &lhs, const Q &rhs){
    Q temp;
    temp.n = lhs.n*rhs.n;
    temp.d = lhs.d*rhs.d;
    temp.simplify(); // simplify Ã© um mÃ©todo private, mas esse mÃ©todo Ã© friend
    return temp;
};

Q operator/(const Q &lhs, const Q &rhs){
    Q temp;
    temp.n = lhs.n*rhs.d;
    temp.d = lhs.d*rhs.n;
    temp.simplify(); // simplify Ã© um mÃ©todo private, mas esse mÃ©todo Ã© friend
    return temp;
};

Q Q::operator+=(const Q &rhs){
    *this = *this + rhs;
    return *this;
};





int main() {
    Q x{1,3}, y{4,5};
    //Q x{3}, y{5};

    // cout << "{" << x << ", " << y << "} in Q"<< endl;
    std::cout <<"x= " << x << std::endl;
    std::cout <<"y= " << y << std::endl;
    std::cout << "x+y = " << x + y << std::endl;
    std::cout << "x*y = " << x * y << std::endl;
    std::cout << std::boolalpha; // Para imprimir boolanos como true e false



    // Teste de precisÃ£o em funÃ§Ã£o recursiva: x(k+1) = xk + y;
    Q xq{5,11}, yq{5,11};
    float xf{5.0/11.0}, yf{5.0/11.0};

    for (int i{0}; i<1000; i++){ // Teste com i<100 atÃ© i<10000
        xq += yq;
        xf += yf;
    }
    std::cout << "NÃºmero racional: " << xq << std::endl;
    std::cout << "NÃºmero racional convertido para float: " << (static_cast<float>(xq.n)/static_cast<float>(xq.d)) << std::endl;
    std::cout << "NÃºmero ponto flutuante: " << xf << std::endl;


    return 0;
}