#include <iostream>
#include <iomanip>
#include <thread>
#include <string>
#include <random>
#include <chrono>

using namespace std;
std::chrono::high_resolution_clock::time_point t1, t2;
std::chrono::duration<double, std::milli> time_span;

void print_fila(double *fila, size_t n, int DeltaT); // Imprime a fila
double calculateSD(double data[], int n);

int main(){
    // Variáveis para geração de nÃºmeros randÃ´micos
    std::random_device rd;
    std::default_random_engine g;
    g.seed( rd() );
    normal_distribution<double> chegadas(5.0,1.0); // Chega 5 pessoas por minuto
    normal_distribution<double> atendimento1(6.0,5.0); // SÃ£o atendidos 6 pessoas por minuto (std=5, há atendimentos muito rÃ¡pidos e muito lentos)

    // Variáveis para controle da fila
    
    double atendido{0.0};
    int amostra = 1000;  // Critério de correção 3
    int soma {0};
    int media {0};
    double std {0};
    double fila[60]{0.0};
    double fila_soma[amostra]{0.0};

    // Pega valor inicial de tempo
    t1 = std::chrono::high_resolution_clock::now();


    // Critério de correção 1
    // Ciclo principal
    for (int i{1}; i<=amostra; i++){  // simulacao de n dias
        for (int t{1}; t<=60; ++t){ // simulacao de 1 hira (60 minutos)
            fila[t] = fila[t-1] + chegadas(g); // Chegada na fila
            atendido = min(max(atendimento1(g),0.0), fila[t]); // NÃºmeros atendidos na fila
            fila[t] -= atendido; // Reduz fila

            fila_soma[i] += fila[t];  // Será usado para calcular a media
        }
    }

// Critério de correção 2
// -------------- Cálculo das métricas -----------------------

    // Cálculo da média
    for(int j{1}; j<=amostra; j++){
        soma += fila_soma[j];
    }
    media = soma/amostra;
    


    // // Print da fila_soma
    // for(int j{1}; j<amostra; j++){
    //         std::cout<< "Itens da fila_soma # " << j << " = " <<  fila_soma[j] << std::endl;
    // }


    // Cálculo do std
    for(int j{0}; j<amostra; j++){
        std += std::pow(media - fila_soma[j] , 2);
    }

// -------------------------------------------------------------


    
    // Pega o valor final de tempo sem threads
    t2 = std::chrono::high_resolution_clock::now();

    // Critério de correção 4
    // imprime o time span
    time_span = t2 - t1;
    std::cout << "Elapsed time: " << time_span.count() << " ms" << std::endl;





    // Imprime a fila
    //print_fila(fila, 60, 5);

    // Imprime a media
    std::cout<< "Média (soma/amostra) = " <<  media << std::endl;

    std::cout << "Desvio padrao = " << sqrt(std/amostra) << std::endl;


    return 0;
}


void print_fila(double *fila, size_t n, int DeltaT){
    cout << "Minutes| Queue" << endl;

    for (size_t i{0}; i<n; i += DeltaT) {
        double avg_time{0};
        for (size_t k{i}; k<i+DeltaT; ++k){
            avg_time += fila[i];
        }
        cout << setw(4) << i << "-" << setw(2) << (i+DeltaT) << "| ";
        cout << string(static_cast<int>(avg_time/DeltaT),'*') << endl;
    }
    cout << string(30,'-') << endl;
}



