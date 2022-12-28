#include<iostream>


class Sensor{
    private: //stuff that can be acceced just inside the class (by other methods, ..) -> default mode
        std::string supplier;
        void start();
        void stop();

    public: //stuff that can be acceced outside the class 
        std::string name;
        int id;
        void read_value();
        void set_sensor(std::string supplier_val, std::string name_val, int id_val);
        void print_sensor();
        Sensor();
        Sensor(const Sensor &source);
        ~Sensor();
        
};

void Sensor::start(){
    std::cout << "Sensor has been started" << std::endl;
}
void Sensor::read_value(){
    std::cout << "Sensor is reading values" << std::endl;
}
void Sensor::print_sensor(){
    std::cout << "Nome: " << name << "; supplier: " << supplier << "; id: " << id << std::endl;
    std::cout << "-------------------------------------" << std::endl;
}
//Sets all atributes 
void Sensor::set_sensor(std::string supplier_val, std::string name_val, int id_val){
    id = id_val;
    name = name_val;
    supplier = supplier_val;
}

// Contructor -> function called when an object is created
Sensor::Sensor(){
    std::cout << "Object "<< name <<" has been created" << std::endl;
}
// Copy Contructor -> function called when an object is created
Sensor::Sensor(const Sensor &source){
    std::cout << "Object "<< name <<" has been created" << std::endl;
}
// Destructor -> function called when an object is deleted
Sensor::~Sensor(){
    std::cout << "Object "<< name <<" has been destroyed" << std::endl;
}




int main(){
    Sensor my_sensor;
    Sensor *sensor_ptr {&my_sensor};
    //sensor_ptr = &my_sensor;
    //(*sensor_ptr).name = "PTC";
    (*sensor_ptr).set_sensor("bla", "blablabla", 12);
    //(*sensor_ptr).read_value();
    (*sensor_ptr).print_sensor();


    Sensor sen2;
    sen2.set_sensor("abc", "def", 3);
    sen2.print_sensor();

    Sensor sen3;
    sen3 = sen2;
    sen3.print_sensor();
    
    return 0;
}