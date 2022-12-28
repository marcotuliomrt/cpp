#include <iostream>
#include <string>

using namespace std;

class city{
    private:
        string name;
        int pop;
    public:        
        void set_city(std::string name_val, int pop_val) {
            name = name_val;
            pop = pop_val;
        };

        void print_city() const {
            cout << "Nome: " << name << "; pop:" << pop << endl;
        };

        // Constructor
        city(){
            cout << "Object " << name << " has been created" << endl;
        };
        // Constructor
        city(string name_val, int pop_val) : name{name_val}, pop{pop_val}{
            cout << "Object " << name << " has been created" << endl;
        };
        // Destructor
        ~city(){
            cout << "Object " << name << " has been destroyed" << endl;
        };
};



int main() {    
    const city city1("Campinas", 1213792);
    //city1.set_city("Campinas", 1213791); // Erro! city1 Ã© const
    city1.print_city();

    // { // Cria objeto no escopo da chave
    //     city city1("Bauru", 381706); // Pode ter o mesmo nome, nesse escopo
    //     city1.print_city();
    // }

    city city2;
    city2.print_city();

    return 0;
}