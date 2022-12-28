#include <iostream>
#include "/home/marco/cpp_work/aula12-classes_header/sensor.h"
#include "sensors_children.h"



void PressureSensor::get_Pa(){
    std::cout << "Getting Pascal measures" << std::endl;
};
void PressureSensor::get_Atm(){
    std::cout << "Getting Pascal measures" << std::endl;
};


int main(){
    Sensor my_sensor;
    Sensor *sensor_ptr {&my_sensor};
    //sensor_ptr = &my_sensor;
    //(*sensor_ptr).name = "PTC";
    (*sensor_ptr).set_sensor("bla", "blablabla", 12);
    //(*sensor_ptr).read_value();
    (*sensor_ptr).print_sensor();


    Sensor sen2;
    sen2.set_sensor("abc", "defgh", 3);
    sen2.print_sensor();

    Sensor sen3;
    sen3 = sen2;
    sen3.print_sensor();
    
    return 0;
}