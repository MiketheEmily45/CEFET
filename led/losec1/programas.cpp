#include <unistd.h>
#include "programas.h"

programas** programas::Inserir(programas** R, std::string nome, int tempo) {
    programas *novo = new programas();
    novo->nome = nome;
    novo->tempo = tempo;
    if(R[0] == NULL){
        R[0] = novo;
        R[0]->proximo = R[1];
        R[1] = novo;
        R[1]->proximo = R[0];
    }else{
        programas *ant = NULL;
        programas *atual = R[0];
        while((atual != NULL) && (novo->nome < atual->nome)){
            ant = atual;
            atual = atual->proximo;
        }
        if(ant == NULL){
            novo->proximo = R[0];
            R[1]->proximo = novo;
            R[0] = novo;
        }else if(atual == NULL){
            R[1]->proximo = novo;
            R[1] = novo;
            R[1]->proximo = R[0];
        }else{
            ant->proximo = novo;
            novo->proximo = atual;
        }
    }
    return R;
}

programas** programas::Excluir(programas** R, std::string nome) {
    programas *ant = R[0];
    programas *atual = R[0];
    while((atual != NULL) && (atual->nome != nome)){
        ant = atual;
        atual = atual->proximo;
    }
    if(ant == R[0]){
        R[0] = R[0]->proximo;
    }else if(atual == R[1]){
        R[1] = ant;
        R[1]->proximo = R[0];
    }else{
        ant->proximo = atual->proximo;
    }
    delete(atual);
    return R;
}

programas** programas::Executar(programas** R) {
    programas *aux = R[0];
    programas L;
    while(aux != R[1]){
        std::cout << aux->nome << std::endl;
        usleep(1000000);
        aux->tempo -= 1;
        if (tempo == 0) {
            R = L.Excluir(R, aux->nome);
        }
        aux = R[0];
    }
    return R;
}

void programas::Listar(programas** R) {
    programas *aux = R[0];
    while(aux != R[1]){
        std::cout << aux->nome << " - " << aux->tempo << std::endl;
        aux = aux->proximo;
    }
}
