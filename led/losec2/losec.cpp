#include <iostream>
#include "losec.h"

losec** losec::Inserir(losec** R, int num, int qtd) {
    losec *novo = new losec();
    novo->num = num;
    novo->qtd = qtd;
    if(R[0] == NULL){
        R[0] = novo;
        R[0]->elo = novo;
        R[1] = novo;
        R[1]->elo = novo;
    }else{
        losec *ant = NULL;
        losec *atual = R[0];
        while((atual != NULL) && (novo->qtd < atual->qtd)){
            ant = atual;
            atual = atual->elo;
        }
        while((atual != NULL) && (novo->num < atual->num)){
            ant = atual;
            atual = atual->elo;
        }
        if(ant == NULL){
            novo->elo = R[0];
            R[1]->elo = novo;
            R[0] = novo;
        }else if(atual == NULL){
            R[1]->elo = novo;
            novo->elo = R[0];
            R[1] = novo;
        }else{
            ant->elo = novo;
            novo->elo = atual;
        }
    }
    return R;
}

losec** losec::Excluir(losec **R, int num) {
    losec *ant = R[1];
    losec *atual = R[0];
    while((atual != R[1]) && (atual->num != num)){
        ant = atual;
        atual = atual->elo;
    }
    if(atual == R[0]) {
        ant->elo = atual->elo;
        R[0] = atual->elo;
        delete(atual);
    } else if(atual == R[1]) {
        ant->elo = R[0];
        R[1] = ant;
        delete(atual);
    } else if (atual->num == num) {
        ant->elo = atual->elo;
        delete(atual);
    }
    return R;
}

losec* losec::Pesquisar(losec **R, int num) {
    losec *atual = R[0];
    while((atual != R[1]) && (atual->num != num)){
        atual = atual->elo;
    }
    if(atual->num != num){
        return NULL;
    }
    return atual;
}

void losec::Exibir(losec **R) {
    if (R[0] == NULL) return;
    losec *aux = R[0];
    do {
            std::cout << aux->num << " - repetiu: " << aux->qtd << " vezes" << std::endl;
            aux = aux->elo;
    } while (aux != R[0]);
}
