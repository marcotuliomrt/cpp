#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class ponto{
    // friend permite colocar um protÃ³tipo que nÃ£o Ã© da clase, dentro da class
    friend ponto operator*(double gain, const ponto &lhs);
    private:
        double coords[3];
    public:
        void print_point();
        // Constructors
        ponto();
        ponto(double x_val, double y_val, double z_val);
        // Destructor
        ~ponto();
        // Operator = (Copy assignment)
        ponto &operator=(const ponto &rhs);
        // Operator +
        ponto operator+(const ponto &rhs) const;
        // ExercÃ­cio: Operator -
        ponto operator-(const ponto &rhs) const;
        // ExercÃ­cio: Operator - (negation)
        ponto operator-() const;
        // ExercÃ­cio: Operator * (gain) // p2 = [x*gain, y*gain, z*gain]
        ponto operator*(double gain) const;
        // ExercÃ­cio: Operator ++ pre-increment // p2 = p1 + p1.normalized()
        ponto operator++();
        // ExercÃ­cio: Operator ++ post-increment // p2 = p1 + p1.normalized()
        ponto operator++(int);
        // ExercÃ­cio: Operator -- pre-decrement // p2 = p1 - p1.normalized()
        ponto operator--();
        // ExercÃ­cio: Operator -- post-decrement // p2 = p1 - p1.normalized()
        ponto operator--(int);
        // ExercÃ­cio: Method ponto.norm() // norm(p) = sqrt(x^2+y^2+z^2)
        double norm() const;
        // ExercÃ­cio: Method ponto.normalize() // normalized(p) = [x/norm(p), y/norm(p), z/norm(p)]
        ponto normalize();
};

void ponto::print_point() {
    cout << "[" << coords[0] << ", " << coords[1] << ", " << coords[2] << "]" << endl;
};

// Constructors
ponto::ponto(double x_val, double y_val, double z_val) {
    coords[0] = x_val;
    coords[1] = y_val;
    coords[2] = z_val;
    cout << "Object at " << this << " has been created" << endl;
};
ponto::ponto(): ponto(0.0,0.0,0.0){ };

// Destructor
ponto::~ponto() {
    cout << "Destructor for object at " << this << endl;
};

// Operator = (Copy assignment)
ponto &ponto::operator=(const ponto &rhs) {
    coords[0] = rhs.coords[0];
    coords[1] = rhs.coords[1];
    coords[2] = rhs.coords[2];
    cout << "Object at " << this << " received copy-assignment from " << &rhs << endl;
    return *this;
};

// Operator +
ponto ponto::operator+(const ponto &rhs) const {
    double x = coords[0]+rhs.coords[0];
    double y = coords[1]+rhs.coords[1];
    double z = coords[2]+rhs.coords[2];
    cout << "Add objetct " << this << " and " << &rhs << endl;
    return ponto(x,y,z);
};

// Operator -
ponto ponto::operator-(const ponto &rhs) const {
    double x = coords[0]-rhs.coords[0];
    double y = coords[1]-rhs.coords[1];
    double z = coords[2]-rhs.coords[2];
    cout << "Sub objetct " << this << " and " << &rhs << endl;
    return ponto(x,y,z);
};

// Operator - (negation)
ponto ponto::operator-() const {
    cout << "Negation of the objetct " << this << endl;
    return ponto(-coords[0], -coords[1], -coords[2]);
};

// ExercÃ­cio: Operator * (gain) // p 2 [x*gain, y*gain, z*gain]
ponto ponto::operator*(double gain) const {
    cout << "Gain of the objetct " << this << " by " << gain << endl;
    return ponto(coords[0]*gain, coords[1]*gain, coords[2]*gain);
}
        
// ExercÃ­cio: Operator ++ pre-increment // p2 = p1 + p1.normalized()
ponto ponto::operator++(){
    double d{norm()};
    coords[0] = coords[0] + coords[0]/d; 
    coords[1] = coords[1] + coords[1]/d; 
    coords[2] = coords[2] + coords[2]/d; 
    cout << "Pre increment of the objetct " << this << endl;
    return *this;
}

// ExercÃ­cio: Operator ++ post-increment // p2 = p1 + p1.normalized()
ponto ponto::operator++(int){
    ponto temp{*this};
    ++(*this);
    cout << "Post increment of the objetct " << this << endl;
    return temp;
}

// ExercÃ­cio: Operator -- pre-decrement // p2 = p1 + p1.normalized()
ponto ponto::operator--(){
    double d{norm()};
    coords[0] = coords[0] - coords[0]/d;
    coords[1] = coords[1] - coords[1]/d;
    coords[2] = coords[2] - coords[2]/d;
    cout << "Decrement of the objetct " << this << endl;
    return *this;
}

// ExercÃ­cio: Operator -- post-decrement // p2 = p1 + p1.normalized()
ponto ponto::operator--(int){
    ponto temp{*this};
    --(*this);
    cout << "Post decrement of the objetct " << this << endl;
    return temp;
}

// ExercÃ­cio: Method ponto.norm() // norm(p) = sqrt(x^2+y^2+z^2)
double ponto::norm() const{
    cout << "Norm of " << this << endl;
    return sqrt(pow(coords[0],2.0) + pow(coords[1],2.0) + pow(coords[2],2.0));
};

// ExercÃ­cio: Method ponto.normalize() // normalized(p) = [x/norm(p), y/norm(p), z/norm(p)]
ponto ponto::normalize(){
    double d{norm()};
    coords[0] /= d;
    coords[1] /= d;
    coords[2] /= d;
    cout << "Normalization of " << this << endl;
    return *this;
}

ponto operator*(const double gain, const ponto &lhs){
    cout << "Gain of the objetct " << &lhs << " by " << gain << endl;
    return lhs*gain;
}

int main() {
    cout << "# Criando um ponto #" << endl;
    ponto p1(1.0,2.0,3.0);
    p1.print_point();
    cout << "============================" << endl;

    cout << "# Copia e atribui um ponto #" << endl;
    ponto p2;
    p2 = p1;
    p2.print_point();
    cout << "============================" << endl;

    cout << "# Soma dois pontos #" << endl;
    ponto p3;
    p3 = p1 + p2;
    p3.print_point();
    cout << "============================" << endl;

    cout << "# Pre Incrementa um pontos #" << endl;
    p3 = ++p1;
    p1.print_point();
    p3.print_point();
    cout << "============================" << endl;

    cout << "# Post Incrementa um pontos #" << endl;
    p3 = p1++;
    p1.print_point();
    p3.print_point();
    cout << "============================" << endl;

    cout << "# Pre Decrementa um pontos #" << endl;
    p3 = --p1;
    p1.print_point();
    p3.print_point();
    cout << "============================" << endl;
    
    cout << "# post Decrementa um pontos #" << endl;
    p3 = p1--;
    p1.print_point();
    p3.print_point();
    cout << "============================" << endl;

    cout << "# Normaliza um pontos #" << endl;
    p1.normalize();
    p1.print_point();
    cout << "============================" << endl;

    cout << "# Ganho de um pontos #" << endl;
    p1 = p1*10.0;
    p1.print_point();
    cout << "============================" << endl;

    cout << "# Ganho de um pontos 2 #" << endl;
    p1 = 0.1*p1;
    p1.print_point();
    cout << "============================" << endl;

    return 0;
}