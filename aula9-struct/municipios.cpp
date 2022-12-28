// Credate an array with 8 counties

#include <iostream>
#include <string>

// cria a struct municipio
struct municipio{
    std::string nome;
    std::string UF;
    int pop;
};



void swap(municipio *m1, municipio *m2){ // funcao q recebe os ponteiros dos objetos e troca um pelo outro
    municipio tmp = *m1;
    *m1 = *m2;
    *m2 = tmp;
}

void sort(municipio m[], size_t len) // pass by reference
// OBS: "m[]" refers to the same thing as "*m" -> both are memory adresses
{
    //size_t len {mun.size()};
    for (int i{0}; i<len; i++){
        for (int j{0}; j<len-1; j++){
            if (m[j].pop > m[j+1].pop){
                swap(&m[j], &m[j+1]);
            }
        }
    }

}

void show(municipio *m, size_t len){
    for (int i{0}; i<len; i++){
        std::cout << i << ": "<< "Municipio: " << m[i].nome << ";   " << "Populacao: "  << m[i].pop << std::endl;
    }
}

int main(){
    municipio mun[8]; // cria 8 elementos municipio

    mun[0].nome = "sao paulo";
    mun[0].pop = 9;

    mun[1].nome = "belo horizonte";
    mun[1].pop = 4;

    mun[2].nome = "Manaus";
    mun[2].pop = 7;
    
    mun[3].nome = "Fortaleza";
    mun[3].pop = 2;

    show(mun, 4);
    sort(mun, 4);
    std::cout <<  "---------------------------------------------" << std::endl;
    show(mun, 4);


}