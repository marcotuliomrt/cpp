#include<iostream>
#include<string>


struct User{
    std::string first_name;
    int income;
    User *next;

};



void show(User object[], int len){
    for(int i{0}; i<len; i++){
        std::cout << "Name: "<<object[i].first_name <<",   income: " << object[i].income << std::endl;
    }
}

void show_linked(User *head){
    while(head){
        std::cout << head->first_name << ": " << head->income << std::endl;
        head = head->next;
    }
}


User *include(User *head, std::string first_name, int income){
    User *novo{NULL}; // criar um lugar na memoria para um objeto
    novo = new User;
    novo->first_name = first_name;
    novo->income = income;
    novo->next = NULL;
    
    if(! head){ //if the list is empty
        return novo;
    }
    User *i{head};
    while(i->next){
        i=i->next;
    }
    i->next = novo;
    return head;

}



int main(){
    // User person[3];

    // person[0].first_name ="Walter";
    // person[0].income = 15000000;

    // person[1].first_name ="Gustavo";
    // person[1].income = 40000;

    User *head {NULL}; // pointer to the first node of the struct
    head = include(head, " Daciolo", 90000);
    head = include(head, " Tiririca", 800000);

    show_linked(head);

    //show(person, 2);

}