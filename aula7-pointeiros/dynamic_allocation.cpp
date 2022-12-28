 
 #include <iostream>


int *create_array(size_t size) {

    int *new_array {nullptr};

    new_array = new int[size];

    return new_array;
}

int main(){
    int *my_array;

    my_array = create_array(5);

    my_array[5];
    // Use of the my_array
    std::cout << my_array[0] << std::endl;


    // Deletion of the array
    delete [] my_array;
    return 0;
}