#include "lista.h"
#include <iostream>

lista** lista::Inserir(lista **R, std::string N, int I){
    lista *novo = new lista();
    novo->nome_do_cliente = N;
    novo->idade = I;
    if(I >= 60){
        novo->tipo_do_cliente = 'P';
    } else {
        novo->tipo_do_cliente = 'C';
    }
    if(R[0] == NULL){
        R[0] = novo;
        R[1] = novo;
        R[1]->anterior = NULL;
        R[1]->proximo = NULL;
    }else{
        if(novo->tipo_do_cliente == 'P'){
            R[1]->anterior = novo;
            novo->proximo = R[0];
            R[0] = novo;
            R[0]->anterior = NULL;
        }else{
            R[1]->proximo = novo;
            novo->anterior = R[1];
            R[1] = novo;
            R[1]->proximo = NULL;
        }
    }
    return R;
};

lista** lista::Excluir(lista **R, char T){
    lista *atual = R[0];
    if(T == 'P'){
        R[0] = R[0]->proximo;
        R[0]->anterior = NULL;
    }else{
        R[1] = R[1]->anterior;
        R[1]->proximo = NULL;
    }
    delete(atual);
    return R;
};

void lista::Listar(lista *I){
    lista *aux = I;
    while(aux != NULL){
        std::cout << aux->nome_do_cliente << " - " << aux->tipo_do_cliente << " - " << aux->idade << "\n";
        aux = aux->proximo;
    }
};
