// Exercicio: fazer o print_city() funcionar -> usa ponteiro mas o contrutor nao faz deep copy
// -> criar o copy contructor


#include <iostream>
#include <cctype>
#include <string>

using namespace std;

class city{
    private:
        string name;
        char *s_ptr{&name[0]};
        int pop;
    public:
        void set_city(std::string name_val, int pop_val) {
            name = name_val;
            pop = pop_val;
            for(unsigned int i{0}; i<name.length(); i++) // Para maiÃºsculo
                *(s_ptr+i) = toupper(*(s_ptr+i));
        };

        void print_city(){
            cout << "Nome: " << name << "; pop:" << pop << endl;
            cout << "---------------------" << endl;
        };
        city(){
            name = "Sem Nome";
            cout << "Object " << name << " has been created" << endl;
        };

        // Destructor
        ~city(){
            cout << "Object " << name << " has been destroyed" << endl;
        };

        //copy contructor
        city(const city &source){
            name = source.name + "-COPY";
            cout << "Object " << name << " has been created" << endl;
        };



};
int main() {
    city city1;
    city1.set_city("Campinas", 1213792);
    city1.print_city();

    city city2{city1}; // Cria uma cÃ³pia de city1
    city2.set_city("Santos", 433656); // Por que nÃ£o funciona?
    city2.print_city();

    return 0;
}