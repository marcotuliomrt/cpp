// Server side C/C++ program to demonstrate Socket programming
// https://www.geeksforgeeks.org/socket-programming-cc/

#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <chrono>
#define PORT 8080

class Measure_Analizer{
    private:
    public:
        
};

class Server{
    private:
        int setsockopt_status, bind_status;
        struct sockaddr_in address;
        int opt = 1;
        int addrlen = sizeof(address);
        
        time_t local_time;
        char msg[1024]{0};
        
    public:
        char buffer[1024]{0};
        int server_fd, new_socket, valread;
        int create_config_socket();
        int client_listen();
        void closing();
        void publish();
        Server();
        ~Server();
        Measure_Analizer ma;
};

int Server::create_config_socket(){
    // Creating socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        std::cout << "\033[1;31mError:\033[0m Socket failed" << std::endl;
        return -1;
    }
 
    // Configure socket
    setsockopt_status = setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
    if (setsockopt_status < 0) {
        std::cout << "\033[1;31mError:\033[0m Setsockopt failed" << std::endl;
        return -1;
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
 
    // Attaching socket to INADDR_ANY at the port 8080
    bind_status = bind(server_fd, reinterpret_cast<sockaddr*>(&address), sizeof(address));
    if (bind_status < 0) {
        std::cout << "\033[1;31mError:\033[0m Bind failed" << std::endl;
        return -1;
    }
}

int Server::client_listen(){
    // Listening to new connections
    if (listen(server_fd, 3) < 0) {
        std::cout << "\033[1;31mError:\033[0m Client listen failed" << std::endl;
        return -1;
    }
    else {
        std::cout << "\033[1;32mListening:\033[0m Accepting new connections " << std::endl;
    }
    
    new_socket = accept(server_fd, reinterpret_cast<sockaddr*>(&address), reinterpret_cast<socklen_t*>(&addrlen));
    if (new_socket < 0) {
        std::cout << "\033[1;31mError:\033[0m Client accept failed" << std::endl;
        return -1;
    }
    else {
        std::cout << "\033[1;32mConnection:\033[0m Connection from " << inet_ntoa(address.sin_addr) << std::endl;
    }
}

void Server::publish(){
    if (valread){
        //std::cout << "Received from client " << inet_ntoa(address.sin_addr) << ": \"" << buffer << "\"" << std::endl;
    }
    
    // compares the val received from the client and pushishes something according with the value 
    if (strcmp(buffer,"time")==0 && valread>0){ // Service to send time
        // Prepare time message
        local_time = std::time(nullptr);
        strcpy(msg, std::ctime(&local_time));
        strtok(msg, "\n"); // Remove "\n"
        // Send to client
        //std::cout << "Sent to client"  << inet_ntoa(address.sin_addr) << ": \"" << msg << "\"" << std::endl;
        send(new_socket, msg, strlen(msg), 0);
    }
    else { 
        int measure = std::stoi(buffer);
        if(valread){
            // Send to client
            if (measure >15){
                char str[] {"Measure above 15"};
                //std::cout << "Send to client"  << inet_ntoa(address.sin_addr) << ": \"" << str << "\"" << std::endl;
                send(new_socket, str, strlen(str), 0);
            }
            else{
                char str[] {"Measure bellow 15"};
                send(new_socket, str, strlen(str), 0);
            }
        }
        else{}
    }

}
void Server::closing(){
        // closing the connected socket
    close(new_socket);
    // closing the listening socket
    shutdown(server_fd, SHUT_RDWR);
    std::cout << "\033[1;32mDisconnected\033[0m" << std::endl;
}
Server::Server(){
    create_config_socket();
    client_listen();
}
Server::~Server(){}










int main()
{
    Server s1;

    // socket initialized on the constructor 

    // loop for reading waht the client publishes
    while(1){
        s1.valread = read(s1.new_socket, s1.buffer, 1024); // Read data from new_socket
        s1.publish();
    }

    s1.closing();

    return 0;
}