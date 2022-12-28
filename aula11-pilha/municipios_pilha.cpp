//aula 11 - pilha

#include <iostream>
#include <string>

using namespace std;

struct municipio{
    string nome;
    int pop;
    municipio *prev;
};

void imprime_pilha(municipio *top);
void push(municipio *&top, string nome, int pop);
municipio pop(municipio *&top);

int main() {
    municipio *top{nullptr}; // Ponteiro para o topo da pilha (nenhum municÃ­pio existe, ainda)
    municipio m;

    push(top, "SÃ£o Paulo", 13'000'000);
    push(top, "BrasÃ­lia", 3'055'149);
    push(top, "Salvador", 2'886'698);
    push(top, "Fortaleza", 2'686'612);

    cout << "Pilha de municÃ­pios:" << endl;
    imprime_pilha(top);
    
    m = pop(top); // Remove Ãºltimo 
    cout << endl << "Ãšltimo elemento:" << endl;
    cout << m.nome << " " << m.pop << endl;
    
    cout << endl << "Pilha de municÃ­pios:" << endl;
    imprime_pilha(top);
    
    m = pop(top); // Remove Ãºltimo 
    cout << endl << "Ãšltimo elemento:" << endl;
    cout << m.nome << " " << m.pop << endl;
    
    cout << endl << "Pilha de municÃ­pios:" << endl;
    imprime_pilha(top);

    while(top)
        pop(top); // Limpa pilha
    
    return 0;
}

void push(municipio *&top, string nome, int pop){
    municipio *novo{nullptr};
    novo = new municipio;
    novo->nome = nome;
    novo->pop = pop;
    novo->prev = top;
    top = novo;
}

municipio pop(municipio *&top){
    if (!top) {
        cout << "Pilha estÃ¡ vazia" << endl;
        return {"",0,nullptr};
    }
    
    if (top){
        municipio *temp{top};
        municipio content{*top};
        top = top->prev;
        delete temp;
        return content;
    }
}

void imprime_pilha(municipio *top){
    while(top){
        cout << top->nome << ": " << top->pop << endl;
        top = top->prev;
    }
}