
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

void print_fila(double *fila, size_t n, int DeltaT); // prints the queue
void simulation(int i0, int i1, double *fila_avg, double *empty);  // Simulates the queue
double calculateSTD(double *fila, int n); // Calculates standard deviation



int main(){
    // ------------------------ Without threads --------------------------------------

    int sample {40000};
    double fila_avg[60]{0.0};  // Each element is the average of people in the queue in the minute n
    double empty {0.0};
    


    t1 = std::chrono::high_resolution_clock::now();

    simulation(0, sample, fila_avg, &empty);    // Monte Carlo simulation
    
    t2 = std::chrono::high_resolution_clock::now();

    double std = calculateSTD(fila_avg, 60);    
    double usage_rate = (1 - empty/(60*sample))*100;  

    print_fila(fila_avg, 60, 5);
    time_span = t2 - t1;
    std::cout << "Elapsed time without threads: " << time_span.count() << "ms" << std::endl;
    std::cout << "Standard deviation = " << std << std::endl;
    std::cout << "Average usage rate:  " << usage_rate << "%" << std::endl;



    // ------------------------ With threads --------------------------------------
    this_thread::sleep_for(chrono::seconds(2));
    cout << string(35,'-') << endl;

    const unsigned int sample_thr{10000}; // number multiple of samples per thread
    double fila_avg_1[sample_thr]{0.0}, fila_avg_2[sample_thr]{0.0}, fila_avg_3[sample_thr]{0.0}, fila_avg_4[sample_thr]{0.0};
    double empty_1{0.0}, empty_2{0.0}, empty_3{0.0}, empty_4{0.0};

    t3 = std::chrono::high_resolution_clock::now();

    thread thr1(simulation, 0*sample_thr, 1*sample_thr, fila_avg_1, &empty_1);
    thread thr2(simulation, 1*sample_thr, 2*sample_thr, fila_avg_2, &empty_2);
    thread thr3(simulation, 2*sample_thr, 3*sample_thr, fila_avg_3, &empty_3);
    thread thr4(simulation, 3*sample_thr, 4*sample_thr, fila_avg_4, &empty_4);

    thr1.join();
    thr2.join();
    thr3.join();
    thr4.join();

    t4 = std::chrono::high_resolution_clock::now();


    double fila_avg_thr[sample_thr]{0.0};
    for (int i{1}; i<60; ++i) {
        fila_avg_thr[i] = (fila_avg_1[i]+fila_avg_2[i]+fila_avg_3[i]+fila_avg_4[i])/4;
    }

    
    double empty_thr {empty_1+empty_2+empty_3+empty_4};

    double std_thr = calculateSTD(fila_avg_thr, 60);
    double usage_rate_thr = (1 - empty_thr/(60*sample))*100;

    print_fila(fila_avg_thr, 60, 5);
    time_span_threads = t4 - t3;
    std::cout << "Elapsed time with threads: " << time_span_threads.count() << "ms" << std::endl;
    std::cout << "Standard deviation = " << std_thr<< std::endl;
    std::cout << "Average usage rate:  " << usage_rate_thr << "%" << std::endl;
    

    // ------------------ Statistics ---------------------------------------------------

    cout << string(35,'-') << endl;
    double per_faster = (time_span.count() - time_span_threads.count())*100/time_span.count();
    std::cout << "The usage of 4 thread resulted on a process " << per_faster << " % faster" << std::endl;

    return 0;

}



// ------------------ Function definitions -------------------






void simulation(int i0, int i1, double *fila_avg, double *empty) {
    std::random_device rd;
    std::default_random_engine g;
    g.seed( rd() );
    normal_distribution<double> chegadas(5.0,1.0); // Chegam 5 pessoas por minuto
    normal_distribution<double> atendimento1(6.0,5.0); // SÃ£o atendidos 6 pessoas por minuto (std=5, hÃ¡ atendimentos muito rÃ¡pidos e muito lentos)
    double atendido{0.0};
    double fila[60]{0.0};

    for (int i{i0}; i<i1; i++) {   // simulacao de n dias
        for (int t{1}; t<60; ++t){  // simulacao de 1 hira (60 minutos)
            fila[t] = fila[t-1] + chegadas(g); // C'hegada na fila
            atendido = min(max(atendimento1(g),0.0), fila[t]); // NÃºmeros atendidos na fila
            fila[t] -= atendido; // Reduz fila

            fila_avg[t] += fila[t];  // List that later is gonna be used to calculate the average

            if (fila[t] == 0) { 
                *empty += 1;   // Computes empty queues so later can be calculated the average usage rate
            }
        }
    }
    for (int t{1}; t<60; ++t) {  // Calculates the average number of people in the queue each minute (among the 60 analized)
        fila_avg[t] /= (i1-i0);
    }
}


double calculateSTD(double *fila, int n){
    double total_avg{0};
    double pre_std{0};
    for(int j{0}; j<n; j++){
        total_avg += fila[j];
    }
    total_avg = total_avg/n;
    
    for(int j{0}; j<n; j++){
        pre_std =+std::pow(total_avg - fila[j] , 2);
    }

    return sqrt(pre_std/n);
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
}