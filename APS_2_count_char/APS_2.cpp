//---------------------------------------------------------------------------------------------------------------------
// Autor: Marco Tulio Masselli Rainho Teixeira
// Data: 21-09-2022
// Conteúdo: APS 2 - Programação para alto Desempenho
//---------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <fstream>
#include <map>
#include <algorithm>


typedef std::pair<char, int> pair; //define o data type Pair

// Funcões do item 1
std::vector<std::string> txt_to_vector(std::string file_name);
// Funções do item 2
std::string clear_word(std::string s);
std::map<char, int> count_char(std::vector<std::string> vec);
// Funções do item 3
void swap_value(int *v1, int *v2);
void swap_key(int *c1, int *c2);
std::vector<pair> sort(std::map<char, int> dic);
// Funções do item 4
std::map<char, int> count_all_char(std::vector<std::string> vec);
// Funcões auxiliares
std::string iso_8859_1_to_utf8(std::string str);
void print_string_vector(std::vector<std::string> vec);
void print_mapped_vector(std::vector<pair>(vec));


//---------------------------------------------------------------------------------------------------------------------
// Função main()
//---------------------------------------------------------------------------------------------------------------------

int main(){

    std::vector<std::string> vec = txt_to_vector("Lista_Municípios_com_IBGE_Brasil.txt");

    // ---- Para realizar a contagem apenas das letras sem caracteres especiais e sem minísculas -----
    print_mapped_vector(sort(count_char(vec)));

    // ---- Para realizar a contagem de TODAS as letras com maiúsculas e caracteres especiais -----
    //print_mapped_vector(sort(count_all_char(vec)));
}





//---------------------------------------------------------------------------------------------------------------------
// Item 1: Crie uma função em C++ que receba o nome do arquivo e retorne um vetor de strings em que cada string contém o
// nome de um município brasileiro contido nesse arquivo (2.5 pontos)
//---------------------------------------------------------------------------------------------------------------------
std::vector<std::string> txt_to_vector(std::string file_name){
    std::vector<std::string> municipios;
    std::ifstream myfile;
    std::string line;
    myfile.open(file_name);
    if (myfile.is_open()){
        while (myfile.good()){  // myfile.good() == False no fim do arquivo
            getline(myfile, line);
            municipios.push_back(line); // adiciona a linha no vetor
            
        }
    }
    myfile.close();
    return municipios;
}



//---------------------------------------------------------------------------------------------------------------------
// Item 2: Crie uma função que receba os nomes dos municípios e retorne quantas vezes cada letra aparece no conjunto de
// município (2.5 pontos).
//---------------------------------------------------------------------------------------------------------------------

std::string clear_word(std::string s){  //Funcao para tirar acentos e tornar todas as letras maiúsculas
    std::string out{};
    for (unsigned int c: s) {
        if (c>0xC0) {
            c = (c & 0xDF);
            switch(c) {  // substitui as letras acentuadas pela letra sem o acento
                case 0xC1:
                case 0xC2:
                case 0xC3:
                case 0xC4: c='A'; 
                break;
                case 0xC7: c='C'; 
                break;
                case 0xC8:
                case 0xC9:
                case 0xCA:
                case 0xCB: c='E'; 
                break;
                case 0xCC:
                case 0xCD:
                case 0xCE:
                case 0xCF: c='I'; 
                break;
                case 0xD2:
                case 0xD3:
                case 0xD4:
                case 0xD5:
                case 0xD6: c='O'; 
                break;
                case 0xD9:
                case 0xDA:
                case 0xDB:
                case 0xDC: c='U'; 
                break;
                
            }
        }
        out.push_back(std::toupper(c)); //passa todas as letras para maiúscula
    }
    return out;
}

std::map<char, int> count_char(std::vector<std::string> vec){ // Conta a recorrencia das letras e mapeia a letra com a sua contagem em um dicionario (map em c++)

    std::map<char, int>charcount;
    size_t len {vec.size()};

    for(int i{0}; i<len; i++){
        std::string clean_vec {clear_word(vec[i])};  // Passa a palavra pela funcao clear_word
        for (unsigned char c:clean_vec){
            if (charcount.find(c) != charcount.end()){  // Se o dicionario ja possui o char (c) como uma Chave
                charcount[c] += 1;  // Soma 1 no seu valor
            }
            else {  // caso contrario (Se o dicionario não possui o char (c) como um Valor)
                charcount[c] = 1;  // Cria a Chave com Valor 1
            }
        }
    }
    return charcount;
}



//---------------------------------------------------------------------------------------------------------------------
// 3. Crie uma função que mostre a incidência das letras, ordenando pelas letras com maior incidência (2.5 pontos).
//---------------------------------------------------------------------------------------------------------------------

void swap_value(int *v1, int *v2){ // funcao q recebe 2 ponteiros e troca o valor de um pelo do outro 
    int tmp = *v1;
    *v1 = *v2;
    *v2 = tmp;
}

void swap_key(char *c1, char *c2){ // funcao q recebe 2 ponteiros e troca o valor de um pelo do outro 
    char tmp = *c1;
    *c1 = *c2;
    *c2 = tmp;
}

std::vector<pair> sort(std::map<char, int> dic){  // função para ordenar a recorrencia de letras do maior pro menor (utiliza o algoritimo Bubble-Sort)
    std::vector<pair> vec;
    
    std::copy(dic.begin(), dic.end(), std::back_inserter<std::vector<pair>>(vec)); //Copia os pares do dicionario em um vetor cujos elementos do do tipo ¨pair¨, definido no inicio

    size_t len {vec.size()};
    for (int i{0}; i<len; i++){
        for (int j{0}; j<len-1; j++){
            if (vec[j].second < vec[j+1].second){
                swap_value(&vec[j].second, &vec[j+1].second);
                swap_key(&vec[j].first, &vec[j+1].first);
            }
        }
    }
    
    return std::vector<pair>(vec);
}






//---------------------------------------------------------------------------------------------------------------------
// 4. Crie uma função aperfeiçoada da contagem de letras que considere as versões de cada letra, sejam elas maiúsculas,
// minúsculas e com acentos como a letra sem acento (2.5 pontos).
//---------------------------------------------------------------------------------------------------------------------

std::map<char, int> count_all_char(std::vector<std::string> vec){  // função para ordenar a recorrencia de letras do maior pro menor

    std::map<char, int>charcount;
    size_t len {vec.size()};

    for(int i{0}; i<len; i++){
        //std::string clean_vec {clear_word(vec[i])};  // Passa a palavra pela funcao clear_word
        for (unsigned char c:vec[i]){
            //c = static_cast<char> (iso_8859_1_to_utf8(static_cast<std::string>(c)));
            if (charcount.find(c) != charcount.end()){  // Se o dicionario ja possui o char (c) como uma Chave
                charcount[c] += 1;  // Soma 1 no seu valor
            }
            else {  // caso contrario (Se o dicionario não possui o char (c) como um Valor)
                charcount[c] = 1;  // Cria a Chave com Valor 1
            }
        }
    }

 
    return charcount;

}






//---------------------------------------------------------------------------------------------------------------------
// Funções auxiliares
//---------------------------------------------------------------------------------------------------------------------

std::string iso_8859_1_to_utf8(std::string str){ // Converte iso_8859_1 para utf8
    std::string strOut;
    for (std::string::iterator it = str.begin(); it != str.end(); ++it){
        uint8_t ch = *it;
        if (ch < 0x80) {
        strOut.push_back(ch);
        }
        else {
        strOut.push_back(0xc0 | ch >> 6);
        strOut.push_back(0x80 | (ch & 0x3f));
        }
    }
    return strOut;
}

void print_string_vector(std::vector<std::string> vec){
    size_t len {vec.size()};
    for(int i{0}; i<len; i++){
        std::string iso = iso_8859_1_to_utf8(vec[i]);
        
        std::cout << iso << std::endl;
    }

}

void print_mapped_vector(std::vector<pair>(vec)){
    size_t len {vec.size()};
    for (int i{0}; i<len; i++){
        std::string s(1, vec[i].first);
        std::cout <<  '{' << iso_8859_1_to_utf8(s) << "," << vec[i].second << '}' << std::endl;
    }
}



