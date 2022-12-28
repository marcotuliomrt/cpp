#include <iostream>
#include <iomanip>
#include <thread>
#include <string>
#include <random>
#include <chrono>

using namespace std;
std::chrono::high_resolution_clock::time_point t1, t2, t3, t4;
std::chrono::duration<double, std::milli> time_span;
std::chrono::duration<double, std::milli> time_span_threads;

void print_fila(double *fila, size_t n, int DeltaT); // Imprime a fila
double calculateMean(int *mean, double data[], int i0, int i1);
double calculateSTD(int *mean, double data[], int i0, int i1);


int main(){
    // Variáveis para geração de nÃºmeros randÃ´micos
    std::random_device rd;
    std::default_random_engine g;
    g.seed( rd() );
    normal_distribution<double> chegadas(5.0,1.0); // Chegam 5 pessoas por minuto
    normal_distribution<double> atendimento1(6.0,5.0); // SÃ£o atendidos 6 pessoas por minuto (std=5, há atendimentos muito rÃ¡pidos e muito lentos)

    // Variáveis para controle da fila
    
    double atendido{0.0};
    int amostra = 4000;  // Critério de correção 3

    double fila[60]{0.0};
    double fila_soma[amostra]{0.0};
    //double soma {0};
    int media {0};


//----------------- Without threads --------------------------------------
    // Pega valor inicial de tempo
    t1 = std::chrono::high_resolution_clock::now();

    double fila_soma1[1000] {0}, fila_soma2[1000] {0}, fila_soma3[1000] {0}, fila_soma4[1000] {0};
    // Critério de correção 1
    // Ciclo principal
    for (int i{1}; i<=amostra-10; i++){  // simulacao de n dias
        for (int t{1}; t<=60; ++t){ // simulacao de 1 hira (60 minutos)
            fila[t] = fila[t-1] + chegadas(g); // Chegada na fila
            atendido = min(max(atendimento1(g),0.0), fila[t]); // NÃºmeros atendidos na fila
            fila[t] -= atendido; // Reduz fila
            if (i<1000)
                fila_soma1[i] += fila[t];  // Será usado para calcular a media
            else if (i>=1000 && i<2000)
                fila_soma2[i] += fila[t];
            else if (i>=2000 && i<3000)
                fila_soma3[i] += fila[t];
            else if (i>=3000 && i<4000)
                fila_soma4[i] += fila[t];
            else
                break;
        }
    }

    // Imprime a media
    std::cout<< "Média = " <<   calculateMean(&media, fila_soma, 0, 1000) << std::endl;
    // Imprime o desvio padrao
    std::cout << "Desvio padrao = " << calculateSTD(&media, fila_soma, 0, 1000) << std::endl;


    // Pega o valor final de tempo sem threads
    t2 = std::chrono::high_resolution_clock::now();

    // Critério de correção 4
    // imprime o time span
    time_span = t2 - t1;
    std::cout << "Elapsed time without threads: " << time_span.count() << " ms" << std::endl;


// Critério de correção 5
//----------------- With threads --------------------------------------

    t3 = std::chrono::high_resolution_clock::now();



    int media1{0}, media2{0}, media3{0}, media4{0};
    
    // std::thread thr1(calculateMean, &media1, fila_soma1, 0, 1000);
    // std::thread thr2(calculateMean, &media2, fila_soma2, 1000, 2000);
    // std::thread thr3(calculateMean, &media3, fila_soma3, 2000, 3000);
    // std::thread thr4(calculateMean, &media4, fila_soma4, 3000, 4000);

    // thr1.join();
    // thr2.join();
    // thr3.join();
    // thr4.join();

    // Imprime a media
    std::cout<< "Média = " <<   calculateMean(&media, fila_soma, 0, 1000) << std::endl;
    // Imprime o desvio padrao
    // Critério de correção 6
    std::cout << "Desvio padrao = " << media1 + media2 + media3 + media4 << std::endl;


    t4 = std::chrono::high_resolution_clock::now();

    // Critério de correção 7
    time_span_threads = t3 - t4;
    std::cout << "Elapsed time with threads: " << time_span_threads.count() << " ms" << std::endl;


   

    return 0;
}


// Critério de correção 2
double calculateMean(int *mean, double data[], int i0, int i1){
    
    for(int j{i0}; j<=i1; j++){
        *mean += data[j];
    }
    return *mean/(i1-i0);
}




// Critério de correção 2
double calculateSTD(int *mean, double data[], int i0, int i1){
   // Cálculo do std
    double std {0};
    for(int j{i0}; j<i1; j++){
        std += std::pow(*mean - data[j] , 2);
    }
    return sqrt(std/(i1-i0));
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



