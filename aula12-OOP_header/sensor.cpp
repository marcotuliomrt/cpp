#include "sensor.h"
#include<iostream>


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




