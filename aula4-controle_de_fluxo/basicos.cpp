#include<iostream>
#include<math.h>

#include<string>

// Ex 1
void separa_numeros(int num){
    // Calcular o numero de casas decimais 
    int tmp {num};
    int casa {1};
    while(tmp/10 > 0){
        tmp = tmp/10; 
        casa +=1;
    }
    // Pega cada algarismo individualmente
    int tmp2 {num};
    for(int i{casa-1}; i>=0; i--){
        int power = static_cast<int>(pow(10, i));
        int tmp3 = tmp2/power;
        std::cout << tmp3 << std::endl;
        tmp2 = tmp2 - tmp3*power;
       
    }
}


// Ex 2

void make_rectangles(int x, int y){
    std::cout << "+";
    for(int i{x}; i>0; i--){
            std::cout << "-";
        }
    std::cout << "+" << std::endl;
    
    for(int j{y}; j>0; j--){
        std::cout << "|";
        for(int i{x}; i>0; i--){
            std::cout << " ";
        }
    std::cout << "|" << std::endl; 
    }


    std::cout << "+";
    for(int i{x}; i>0; i--){
            std::cout << "-";
        }
    std::cout << "+" << std::endl;
}



// Ex 3
// void piramid(int height){
//     int spaces{height};
//     //int i{height};
//     for (int i{0}; i< heigth;i++){

//         while(spaces>0){
//             std::cout << " ";
//             spaces= spaces-1;
            
//         }
//         std::cout << "." << std::endl;
//         spaces -=i;
//         // for (int j{0}; ; j++){
//         //     std::cout << i << std::endl;


//         //}
    
//     }

// }




// Ex 4
int notas[6] {100, 50, 20, 10, 5, 1};
int len {6};
int count(int num){
    if (num/10 == 0){
        return 1;
    }
    else{
        return 1 + count(num/10);
    }
}
void price(int val){
    std::cout << "Notas: " << std::endl;
    for(int i{0}; i<len; i++){
        int n = val/notas[i];
        std::cout << n << " notas de "<< notas[i] << std::endl;
        val -= notas[i]*n;
    } 

}




int main(){
    int x = 349756;

    separa_numeros(x);
    //make_rectangles(5, 3);
    //price(x);
}