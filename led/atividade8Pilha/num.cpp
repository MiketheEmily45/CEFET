#include <iostream>
#include "num.h"

num* num::InserirPilha(num *T, int numero){
    num * aux = new num () ;
    aux->numero = numero;
    aux->elo = T ;
    T = aux ;
    return T;
};

void num::PercorrerPilha (num *T){
    num *aux = T;
    if(aux == NULL){
        std::cout << "\nPilha vazia !\n ";
    } else {
        std::cout << "\nRegistros Cadastrados\n";
        while(aux != NULL){
            std::cout << aux->numero << std::endl;
            aux = aux->elo;
        }
    }
};

num* num::RemoverPilha(num *T){
    num *aux = T;
    T = T->elo;
    delete (aux);
    return T;
};

num* num::EsvaziarPilha(num *T){
    num *aux = T;
    while(aux != NULL){
        T = T->elo;
        delete (aux);
        aux = T;
    }
    return T;
};

int num::Somar(num *T){
    int soma = 0;
    num *aux = T;
    if(aux == NULL){
        std::cout << "\nPilha vazia !\n ";
    } else {
        while(aux != NULL){
            soma += aux->numero;
            aux = aux->elo;
        }
        return soma;
    }
};
