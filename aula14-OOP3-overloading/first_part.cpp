#include <iostream>


class Cattle{
    private:
    static int num_cattle;

    public:
    std::string name;
    std::string breed;
    int id;

    void print_cattle() const{  //const is necessary to print const objectcs 
        std::cout << "Cattle name: "<< name << "; Breed: "<< breed << "; ID: "<< id <<std::endl;
        std::cout << "----------------"<< std::endl;
    }

    void set_cattle(std::string name, std::string breed, int id){
        this->name = name;
        this->breed = breed;
        this->id = id;
    }

    void print_this_ptr(){
        std::cout << "this: "<< this <<std::endl;
    }

    static int get_num_cattle(){
        return num_cattle;
    } 

    // Contructor
    Cattle(){
        std::cout << "An object has been created, num_cattle= "<< num_cattle <<std::endl;
        num_cattle++;
    }
    // Contructor with atributes -> does the role of the set_cattle, but directly on the object creating (for const objects it has to be like this because you cant change it later, like in a set_cattle function)
    Cattle(std::string val_name, std::string val_breed, int val_id) : name{val_name}, breed{val_breed}, id{val_id}{
        std::cout << "An object has been created, num_cattle= "<< num_cattle <<std::endl;
        num_cattle++;
    }
    // Destructor
    ~Cattle(){
        std::cout << "An object has been destoyed" <<std::endl;
        num_cattle--;
    }

};
int Cattle::num_cattle{1}; //initializing the static variable (must be outside the class)


int main(){

    // Object created with the normal contructor and its atributes were set by the set_cattle 
    Cattle cow1;
    cow1.set_cattle("Betsy", "angus", 4);
    cow1.print_this_ptr();
    std::cout << "&cow1: "<< &cow1 <<std::endl;
    cow1.print_cattle();

    Cattle cow2;
    cow2.set_cattle("Jeorge", "Texas longhorn", 9);
    cow2.print_this_ptr();
    std::cout << "&cow2: "<< &cow2 <<std::endl;
    cow2.print_cattle();

    // Object created with the contructor with atributes 
    const Cattle cow3("Jacob", "Red angus", 12);
    cow3.print_cattle();

}