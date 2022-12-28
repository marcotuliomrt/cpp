// Client side C/C++ program to demonstrate Socket programming
// https://www.geeksforgeeks.org/socket-programming-cc/

#include <iostream>
#include <string>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <thread>
#include <chrono>
#define PORT 8080

 // Classe client: estabelece conexao com o servidor
class Client{
    private:
        int sock = 0, valread, client_fd, valid_addr;
        struct sockaddr_in serv_addr;
        
    public:
        std::string type;
        char buffer[1024] = { 0 };
        char ip[11] {"127.0.0.1"};
        
        virtual void set(std::string type){
            this->type = type;
            std::cout << "The client has been set" << std::endl;
        }

        int create_config_socket();
        int publish_str(char cmd[]);
        int publish_measure(int measure, int sample_period, int sample_num);
        Client();
        ~Client();
};


// Método para criar e configurar o socket
int Client::create_config_socket(){
    // Creating socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cout << "\033[1;31mError:\033[0m Socket failed" << std::endl;
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    valid_addr = inet_pton(AF_INET, ip, &serv_addr.sin_addr);
    if (valid_addr <= 0) {
        std::cout << "\033[1;31mError:\033[0m Invalid address. Address not supported" << std::endl;
        return -1;
    }
 
    // Creating socket file descriptor
    client_fd = connect(sock, reinterpret_cast<sockaddr*>(&serv_addr), sizeof(serv_addr));
    if (client_fd < 0) {
        std::cout << "\033[1;31mError:\033[0m Connection Failed" << std::endl;
        return -1; 
    }
    else {
        std::cout << "\033[1;32mConnection:\033[0m Connected to " << inet_ntoa(serv_addr.sin_addr) << std::endl;
    }
    return 0;
}
// Método para enviar ao servidor um comando no formato string (por exemplo: "time")
int Client::publish_str(char cmd[]){
    // char cmd[] {"time"};
    for (int i{0}; i<5; ++i){
        // Send info
        std::cout << "Send to server " << inet_ntoa(serv_addr.sin_addr) << ": \"" << cmd << "\"" << std::endl;
        send(sock, cmd, strlen(cmd), 0);
        valread = read(sock, buffer, 1024);
        if (valread > 0){
            std::cout << "Received from server " << inet_ntoa(serv_addr.sin_addr) << ": \"" << buffer << "\"" << std::endl;
        }

        // Sleep for 2s
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    // closing the connected socket
    close(client_fd);
    std::cout << "\033[1;32mDisconnected\033[0m" << std::endl;

    return 0;
}
// Método para enviar ao servidor um valor da medida de um sensor
int Client::publish_measure(int measure, int sample_period, int sample_num){
    std::string t = std::to_string(measure);
    char const *cmd = t.c_str();

    for (int i{0}; i<sample_num; ++i){
        // Send info
        std::cout << "Sent to server " << inet_ntoa(serv_addr.sin_addr) << ": \"" << "Sensor measure:" << cmd << "\"" << std::endl;
        send(sock, cmd, strlen(cmd), 0);
        valread = read(sock, buffer, 1024);
        if (valread > 0){
            std::cout << "Received from server " << inet_ntoa(serv_addr.sin_addr) << ": \"" << buffer << "\"" << std::endl;
        }
        // Sleep for 2s
        std::this_thread::sleep_for(std::chrono::seconds(sample_period));
    }

    // closing the connected socket
    close(client_fd);
    std::cout << "\033[1;32mDisconnected\033[0m" << std::endl;

    return 0;
}
// Construtor
Client::Client(){}
// Destrutor
Client::~Client(){}




// Classe sensor: realiza medições
class Sensor: public Client{
    public:
        std::string type;
        std::string unit;
        int get_measure();

        // Operator = (Copy assignment)
        Sensor &operator=(const Sensor &rhs);

        void set(std::string val_type, std::string val_unit){
            this->type = type;
            this->unit = unit;
            std::cout << "The sensor has been set" << std::endl;
        }
};
// Método para simular uma medição do sensor
int Sensor::get_measure(){
    std::cout << "Getting measures" << std::endl;
    return 10;
}

// Overload operator = (Copy assignment)
Sensor &Sensor::operator=(const Sensor &rhs) {
    unit = rhs.unit;

    std::cout << "Object at " << this << " received copy-assignment from " << &rhs << std::endl;
    return *this;
};




int main()
{
    Sensor s1;
    s1.set("LM35", "celsius");
    Sensor s2 = s1;


    int s_value = s2.get_measure();
    int num = 5;
    int period = 2;
    std::cout<< s_value <<std::endl;

    Client c1;
    std::cout << "Trasmissão das medidas do sensor para o servidor" << std::endl;
    c1.create_config_socket();
    c1.publish_measure(s_value, period, num);
    //c1.publish_str("time");  //requests the time to the server



    // Client *client_1_ptr {new Sensor};
    
    // std::string type {"temp_sensor"};
    // client_1_ptr->set(type);


    // Sensor s1;
    // Client c1;
    // Sensor s2 = s1;


    // int s_value = s2.get_measure();
    // int num = 5;
    // int period = 2;
    // std::cout<<s_value<<std::endl;


    
    // c1.create_config_socket();
    // c1.publish_measure(s_value, period, num);
    // //client_1_ptr->publish_str("time");
    
    
    

    return 0;
}