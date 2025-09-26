#include "lose.h"
#include <iostream>

lose** lose::Inserir(lose **R, int num){
    lose *novo = new lose();
    novo->num = num;
    if(R[0] == NULL){
        R[0] = novo;
        R[1] = novo;
        R[1]->elo = NULL;
    }else{
        lose *ant = NULL;
        lose *atual = R[0];
        while((atual != NULL) && (novo->num > atual->num)){
            ant = atual;
            atual = atual->elo;
        }
        if(ant == NULL){
            novo->elo = R[0];
            R[0] = novo;
        }else if(atual == NULL){
            R[1]->elo = novo;
            R[1] = novo;
            R[1]->elo = NULL;
        }else{
            ant->elo = novo;
            novo->elo = atual;
        }
    }
    return R;
};
void lose::Listar(lose *I){
    lose *aux = I;
    while(aux != NULL){
        std::cout << aux->num << " ";
        aux = aux->elo;
    }
    std::cout << std::endl;
};
