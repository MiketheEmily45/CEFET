#include "lode.h"
#include <iostream>

lode** lode::Inserir(lode **R, int num) {
    lode *novo = new lode();
    novo->num = num;
    if(R[0] == NULL){
        R[0] = novo;
        R[1] = novo;
        R[1]->proximo = NULL;
    }else{
        lode *ant = NULL;
        lode *atual;
        if(novo->num % 2 == 0) {
            atual = R[0];
            while (atual != NULL && atual->num % 2 == 0 && atual->num < num)
            {
                ant = atual;
                atual = atual->proximo;
            }
        } else {
            atual = R[1];
            while (atual != NULL && atual->num % 2 != 0 && atual->num > num)
            {
                ant = atual;
                atual = atual->anterior;
            }
        }
        if(ant == NULL){
            novo->proximo = R[0];
            novo->anterior = NULL;
            R[0]->anterior = novo;
            R[0] = novo;
        }else if(atual == NULL){
            novo->anterior = R[1];
            R[1]->proximo = novo;
            R[1] = novo;
            R[1]->proximo = NULL;
        }else{
            ant->proximo = novo;
            novo->anterior = ant;
            novo->proximo = atual;
            atual->anterior = novo;
        }
    }
    return R;
};
void lode::Listar(lode *I){
    lode *aux = I;
    while(aux != NULL){
        std::cout << aux->num << " ";
        aux = aux->proximo;
    }
    std::cout << std::endl;
};
