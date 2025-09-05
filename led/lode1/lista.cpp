#include "lista.h"
#include <iostream>

lista** lista::Inserir(lista **R, std::string U, int I, int T, std::string Raca){
    lista *novo = new lista();
    novo->nome_do_pet = U;
    novo->idade = I;
    if(R[0] == NULL){
        R[0] = novo;
        R[1] = novo;
        R[1]->proximo = NULL;
    }else{
        lista *ant = NULL;
        lista *atual = R[0];
        while (atual != NULL && (novo->tipo > atual->tipo || (novo->tipo == atual->tipo && novo->nome_do_pet > atual->nome_do_pet)))
        {
            ant = atual;
            atual = atual->proximo;
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

lista* lista::Procurar(lista *I, std::string N, int T){
    lista *aux = I;
    while(aux != NULL && (aux->tipo != T && aux->nome_do_pet != N)){
        aux = aux->proximo;
    }
    return aux;
};

lista** lista::Excluir(lista **R, std::string N, int T){
    lista *atual = R[0];
    while((atual != NULL) && (atual->nome_do_pet != N && atual->tipo != T)){
        atual = atual->proximo;
    }
    if(atual == NULL) return R; // Not found
    if(atual->anterior == NULL){
        R[0] = R[0]->proximo;
        if(R[0] != NULL) R[0]->anterior = NULL;
    }else if(atual == R[1]){
        R[1] = atual->anterior;
        R[1]->proximo = NULL;
    }else{
        atual->anterior->proximo = atual->proximo;
        atual->proximo->anterior = atual->anterior;
    }
    delete(atual);
    return R;
};

void lista::Listar(lista *I){
    lista *aux = I;
    while(aux != NULL){
        std::cout << aux->nome_do_pet << " - " << aux->raca << " - " << aux->idade << " - ";
        if(aux->tipo == 1) std::cout << "Cachorro\n";
        else if(aux->tipo == 2) std::cout << "Gato\n";
        aux = aux->proximo;
    }
};

void lista::Listar_cachorros(lista *I){
    lista *aux = I;
    while(aux != NULL && aux->tipo == 1){
        std::cout << aux->nome_do_pet << " - " << aux->raca << " - " << aux->idade << " - ";
        aux = aux->proximo;
    }
};

void lista::Listar_gatos(lista *I){
    lista *aux = I;
    while(aux != NULL && aux->tipo == 2){
        std::cout << aux->nome_do_pet << " - " << aux->raca << " - " << aux->idade << " - ";
        aux = aux->anterior;
    }
};
