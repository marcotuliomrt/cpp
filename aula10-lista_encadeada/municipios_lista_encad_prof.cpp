#include <iostream>
#include <string>

using namespace std;

struct municipio{
    string nome;
    int pop;
    municipio *prox;
};

void imprime_encadeado(municipio *head);
municipio *inclui(municipio *head, string nome, int pop);
municipio *apaga_ultimo(municipio *head);
municipio *apaga_tudo(municipio *head);

int main() {
    municipio *head{nullptr}; // Ponteiro para o inÃ­cio da lista (nenhum municÃ­pio existe, ainda)

    head = inclui(head, "SÃ£o Paulo", 13'000'000);
    head = inclui(head, "BrasÃ­lia", 3'055'149);
    head = inclui(head, "Salvador", 2'886'698);
    head = inclui(head, "Fortaleza", 2'686'612);

    cout << "Lista de municÃ­pios:" << endl;
    imprime_encadeado(head);
    head = apaga_ultimo(head); // Remove Ãºltimo 
    cout << endl << "Lista de municÃ­pios, apÃ³s remover o Ãºltimo:" << endl;    
    imprime_encadeado(head);
    head = apaga_tudo(head); // Remove tudo
    cout <<  endl << "Lista de municÃ­pios, apÃ³s remover tudo:" << endl;    

    return 0;
}

municipio *inclui(municipio *head, string nome, int pop){
    municipio *novo{nullptr};
    novo = new municipio;
    novo->nome = nome;
    novo->pop = pop;
    novo->prox = nullptr;

    if (!head) // Se a lista estiver vazia, a cabeÃ§a da lista é o novo municÃ­pio
        return novo;
    
    municipio *i{head};
    while(i->prox) // Enquanto existir "prÃ³ximo"
        i=i->prox;
    
    i->prox = novo;

    return head; // Se a lista nÃ£o estiver vazia, retorna head
}

municipio *apaga_tudo(municipio *head){
    municipio *temp;
    while(head){
        temp = head->prox;
        delete head;
        head = temp;
    }
    return nullptr; // ApÃ³s apagar tudo, head Ã© nullptr
}

municipio *apaga_ultimo(municipio *head){
    municipio *temp;
    
    if (! head) // A lista jÃ¡ estÃ¡ vazia
        return nullptr;
    
    if (! head->prox) { // A lista contÃ©m somente um nÃ³
        delete head;
        return nullptr;
    }

    municipio *i{head};
    while(i->prox->prox) // Busca o penÃºltimo elemento
        i = i->prox;

    temp = i->prox;
    i->prox = nullptr;
    delete temp;
    return head;
}

void imprime_encadeado(municipio *head){
    while(head){
        cout << head->nome << ": " << head->pop << endl;
        head = head->prox;
    }
}