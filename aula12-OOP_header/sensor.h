#ifndef sensor_H
#define sensor_H
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

#endif